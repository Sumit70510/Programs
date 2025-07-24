const mongoose=require('mongoose');

mongoose.connect("mongodb://127.0.0.1:27017/TestApp1");

const userSchema=mongoose.Schema(
   {
     image : String,
     email:String,
     name:String
   }  
);

module.exports=mongoose.model('User',userSchema);