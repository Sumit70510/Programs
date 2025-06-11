import { useState } from 'react'//this is a hook for updating states
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function App() {
  let [counter,setCounter]=useState(15); 
  const addValue= ()=>{
    counter=counter+1;
    if(counter>20)counter=20;
    setCounter(counter);
    console.log("Add",counter);
  }//Arrow Function

  const removeValue= ()=>{
    counter=counter-1;
    if(counter<0) counter=0;
    setCounter(counter);
    console.log("Removed",counter);
  }//Arrow Function

  return (
    <>
      <h1>This is Counter</h1>
      <h2>Value : {counter}</h2>
      <button
       onClick={addValue}//function Reference
      >Add Value By {counter}</button>
      <br/>
      <br/>
      <button
       onClick={removeValue}//function Reference
      >Remove Value {counter}</button>
    </>
  )
}

export default App
