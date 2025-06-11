import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function App() {
  const [color, setcolor] = useState('white');
  document.body.style.backgroundColor = color;
  return (
    <>
      <div className="buttonBar"style={{background:"rgb(119, 187, 117)"}} onClick={()=>setcolor("rgb(119, 187, 117)")}> 
      <button className="buttonColor" style={{background:"red"}} onClick={(e)=>{e.stopPropagation();setcolor("Red")}}>Red</button>    
      <button className="buttonColor" style={{background:"blue"}} onClick={(e)=>{e.stopPropagation();setcolor("blue")}}>Blue</button>    
      <button className="buttonColor" style={{background:"green"}} onClick={(e)=>{e.stopPropagation();setcolor("green")}}>Green</button>    
      <button className="buttonColor" style={{background:"purple"}} onClick={(e)=>{e.stopPropagation();setcolor("purple")}}>Purple</button>    
      <button className="buttonColor" style={{background:"gold"}} onClick={(e)=>{e.stopPropagation();setcolor("gold")}}>Golden</button>    
      <button className="buttonColor" style={{background:"teal"}} onClick={(e)=>{e.stopPropagation();setcolor("teal")}}>Teal</button>    
      <button className="buttonColor" style={{background:"black"}} onClick={(e)=>{e.stopPropagation();setcolor("black")}}>black</button>    
      </div>
    </>
  )
}
export default App
