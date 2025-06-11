import React from 'react'

function Card(props) {
  return (
  
   <div className="w-80 rounded-xl flex flex-col rounded-xl bg-black min-h-[19rem] ">
          <div>
            <img
              src={props.photo}
              alt="test"
              className="object-cover object-center rounded-t-xl"
            />
          </div>
          <div className="flex flex-col w-full p-4 border border-gray-300 rounded-lg">
           <div className="flex justify-between">
             <h1 className="font-bold text-lg truncate">{props.name}</h1>
             <h1 className="text-lg">Price</h1>
           </div>
           <div className="flex justify-between mt-2">
             <p className="text-sm">#345</p>
             <p className="text-sm">0.01</p>
           </div>
          </div>
       </div>
    
  )
}

export default Card