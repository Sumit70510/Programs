const express=require('express');
const cookieParser=require("cookie-parser");
const jwt=require("jsonwebtoken");
const bcrypt=require("bcrypt");
const userModel=require("./Models/user");
const postModel=require("./Models/post");
const upload=require("./config/multerconfig")
const app=express();
app.set("view engine","ejs");
app.use(express.json());
app.use(express.urlencoded({extended:true}));
app.use(cookieParser());

app.get("/",(req,res)=>{
    res.render("index");
})

// app.get("/register",(req,res)=>{
// //    res.send("Registered");
//       res.render("index");
// })

app.get("/profile",isloggedIn,async(req,res)=>{
   let user=await userModel.findOne({email:req.user.email}).populate("posts");
   res.render("profile",{user});
})

app.get("/like/:id",isloggedIn,async (req,res)=>{
   let post = await postModel.findOne({_id:req.params.id}).populate("user");
   if(post.likes.indexOf(req.user.userid)===-1)
    {  
     post.likes.push(req.user.userid);
    }
   else
    {
     post.likes.splice(post.likes.indexOf(req.user.userid),1);
    }  
   await post.save();
   res.redirect("/profile");
})

app.get("/edit/:id",isloggedIn,async (req,res)=>{
   let post = await postModel.findOne({_id:req.params.id}).populate("user");
   res.render("edit",{post});
})

app.post("/update/:id",isloggedIn,async (req,res)=>{
    let post= await postModel.findOneAndUpdate({_id:req.params.id},{content:req.body.content.trim()});
    res.redirect("/profile");
})

app.post("/post",isloggedIn,async(req,res)=>{
   let user= await userModel.findOne({email:req.user.email});
  //  console.log(req.body.content);
   let post=await postModel.create({
      user : user._id,
      content : req.body.content.trim(),
   });
   user.posts.push(post._id);
   await user.save();
   res.redirect("/profile");
})

app.post("/upload",isloggedIn,upload.single("image"),(req,res)=>{
  console.log(req.file);
})

app.get("/del",isloggedIn,async(req,res)=>{
   await postModel.deleteMany({});
   res.redirect("/profile");
})

app.post("/register",async (req,res)=>{
   let {name,username,age,email,password}=req.body;
  //  console.log(name);
   let user = await userModel.findOne({email:email});
   if(user)
    {return res.status(500).send("User Already Registered");}
   bcrypt.genSalt(10,(err,salt)=>{
    //  console.log(salt);
     bcrypt.hash(req.body.password,salt,async(err,hash)=>{
      //  console.log(hash);
       let user = await userModel.create({
         username,
         email,age,
         name,
         password:hash
       });
      let token=jwt.sign({email : email , userid : user._id},"THIS IS MY SECRET KEY");
      res.cookie("token",token);
      res.redirect("/profile");   
     })
   })
   
})

app.get("/login",(req,res)=>{
    res.render("login");
})

app.post("/login",async (req,res)=>{
   let {email,password} = req.body;
   let user=userModel.findOne({email});
   if(!user)
    {res.status(500).send("Something Went Wrong");}
   bcrypt.compare(password,user.password,function(err,result){
     if(result)
      {
        let token = jwt.sign({emai:email,userid:user._id},"THIS IS MY SECRET KEY");
        res.cookie("token",token); 
        res.status(200).redirect("/profile");
      }
     else
      {
        res.redirect("/login");
      }     
   }) 
});

app.get("/logout",isloggedIn,(req,res)=>{
    res.cookie("token","");
    res.redirect('/login');
})

function isloggedIn(req,res,next)
{
  if(req.cookies.token==="")
   {
    res.redirect("/login");
   }
  else
   {
     let data=jwt.verify(req.cookies.token,"THIS IS MY SECRET KEY");
     req.user=data;
     next();
   }  
}

app.listen(3000);