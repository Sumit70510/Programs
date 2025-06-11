const mainContainer=document.querySelector('#root');

function customRender(reactElement,Container)
{
  const domElement=document.createElement(reactElement.type);
  domElement.innerHTML=reactElement.children;
  for(prop in reactElement.props)
     {
   domElement.setAttribute(prop,reactElement.props[prop]);       
     }
  Container.appendChild(domElement);
}

const reactElement={
    type:'a',
    props:{
      href : 'https://www.google.co.in/',
      target: '_Blank' 
    },
    children:'Click Here to Visit Google'
}

customRender(reactElement,mainContainer);