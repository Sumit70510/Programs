const express=require("express");
const cookieparser=require("cookie-parser");
const jwt=require("jsonwebtoken");
const path=require("path");
const userModel=require('./models/user');
const bcrypt=require('bcrypt');

const app=express();
app.set("view engine","ejs");
app.use(express.urlencoded({extended:true}));
app.use(express.json());
app.use(cookieparser());
app.use(express.static(path.join(__dirname,'public')));

app.get("/",function(req,res){
     res.render('index');
})

app.post("/create",(req,res)=>{
   let {username,email,password,age}=req.body;
   bcrypt.genSalt(10,(err,salt)=>{
      bcrypt.hash(password,salt,async(err,hash)=>{
          let createdUser=await userModel.create({
              username,
              email,
              password:hash,
              age   
          })
         let token=jwt.sign({email},"THIS IS SECRET KEY");
         res.cookie("token",token); 
         res.send(createdUser); 
       }) 
   })  
})

app.get("/logout",function(req,res){
   res.cookie("token","");
   res.redirect("/"); 
})

app.get("/login",function(req,res){
   res.render("login"); 
})

app.post("/login",async function(req,res){
   
    let user=await userModel.findOne({email:req.body.email});
    if(!user)
      {res.send("Something Went Wrong!");}
    else
     {
       bcrypt.compare(req.body.password,user.password,function(err,result)
        {
          if(result)
           {
             let token=jwt.sign({email:user.email},"THIS IS SECRET KEY");
             res.cookie("token",token);
             res.send(user);
           }
          else
           {
             res.send("Can't Login");
           }     
        })    
     }  
})

app.listen(3000);