import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import Card from './Components/Card'
function App() {
  let myobj={
     name:'car',
     photo:"./car1.jpg"
  } ;
  // console.log(myobj.photo);
  return (
    <>
       <h1 className="bg-green-400 text-black p-3 rounded-xl">
        TailWindCSS
       </h1>
       <div className='flex flex-row'>
      <Card name={myobj.name} photo={myobj.photo}/>
      <Card name="Car2" photo="./car4.jpg"/>
      <Card name="Tech" photo="./tech2.jpg"/>
      </div> 
    </>
  )
}

export default App
