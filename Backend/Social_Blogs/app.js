const express=require('express');
const cookieParser=require("cookie-parser");
const jwt=require("jsonwebtoken");
const bcrypt=require("bcrypt");
const userModel=require("./Models/user");
const postModel=require("./Models/post");

const app=express();
app.set("view engine","ejs");
app.use(express.json());
app.use(express.urlencoded({extended:true}));
app.use(cookieParser());

app.get("/",(req,res)=>{
    res.render("index");
})

app.get("/register",(req,res)=>{
   res.send("Registered"); 
})

app.get("/login",(req,res)=>{
    res.render("login");
})

app.post("/login",(req,res)=>{
   console.log(req.body);
})

app.listen(3000);