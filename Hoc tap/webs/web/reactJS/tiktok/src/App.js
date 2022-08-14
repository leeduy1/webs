import { useState } from 'react'

//  function App() {
  // khi nào dùng useStage:
  // Khi muốn dữ liệu thay đổi thì giao diện tư đông cập nhật (render lại theo dữ liệu)
  // Component được render lại sau khi setState
  // Initial state chỉ dùng cho lần đầu
  // set state là thay thế state bằng giá trị mới

//    const orders = [100, 200, 300]
 
//   const [counter, setCounter] = useState(() => {
//     const total = orders.reduce((total,cur) => total + cur)
//     return total
//   })

//   const handleIncrease = () => {
//     setCounter(prevState => prevState + 1)
//   }

//   return (
//     <div className="App" style={{ padding:20 }}>
//         <h1>{counter}</h1>
//         <button onClick={handleIncrease}>Increase</button>
//     </div>
//   );
// }

// function App() {
//   const [info, setInfo] = useState({
//     name: 'Nguyen van A',
//     age: 18,
//     address: 'Ha Noi'
//   })

//   const handleUpdate = () => {
//     setInfo({
//       ...info,
//       bio: 'Yeu mau hong'
//     })
//   }

//   return (
//     <div className="App" style={{ padding:20 }}>
//         <h1>{JSON.stringify(info)}</h1>
//         <button onClick={handleUpdate}>Update</button>
//     </div>
//   );

// }

// function App() {

//   const [info,setInfo] = useState({
//     name: 'Nguyen van A',
//     age: 18,
//     address: 'Ha Noi'
//   })

//   const handleIncrease = function() {
//     return (
//       setInfo({
//         ...info,
//         bio: 'yeu mau hong'
//       })
//     )
//   }

//   return (
//     <div className="App">
//         <h1>{JSON.stringify(info)}</h1>
//         <button onClick={handleIncrease}></button>
//     </div>
//   )




  // ..........................Two-way binding........................

  // const gifts = [
  //   'CPU i9',
  //   'RAM 32GB RGB',
  //   'RGB Keybroad'
  // ]

  // function App() {
  //   const [gift, setGift] = useState()

  //   const randomGift = () => {
  //     const index =  Math.floor(Math.random() * gifts.length)
  //     setGift(gifts[index])
  //   }
  //   return (
  //     <div style={{ padding: 32}}>
  //       <h1>{gift || 'Chưa có phần thưởng'}</h1>
  //       <button onClick={randomGift}>Lấy thưởng</button>
  //     </div>
  //   )
  // }
// }


// function App() {
//   const [name,setName] = useState('')
//   const [email,setEmail] = useState('')

//   const handleSubmit = () => {
//     console.log({
//       name,
//       email
//     });
//   }
  
//   return (
//     <div style={{ padding: 32}}>
//       <input 
//       value={name}
//       onChange={e => setName(e.target.value)}
//       />
//        <input 
//       value={email}
//       onChange={e => setEmail(e.target.value)}
//       />
//       <button onClick={handleSubmit}>Register</button>
//     </div>
//   )
// }
// const courses = [
//   {
//     id: 1,
//     name: 'HTML, CSS'
//   },
//   {
//     id: 2,
//     name: 'javascript'
//   },
//   {
//     id: 3,
//     name: 'ReactJS'
//   }
// ]

// function App() {
//   const [checked, setChecked] = useState()


//   const handleSubmit = () => {
//     console.log({id: checked});
//   }
//   return (
//     <div style={{ padding: 32 }}>
//       {courses.map(course => (
//         <div key={course.id}>
//           <input 
//           type="radio"
//           checked={checked === course.id}
//           onChange={() => setChecked(course.id)}
//           />
//           {course.name}
//         </div>
//       ))}
//       <button onClick={handleSubmit}>Register</button>
//     </div>
//   )
// }
// function App() {
//   const [checked, setChecked] = useState([])

//   console.log(checked);

//   const handleSubmit = () => {
//     console.log({id: checked});
//   }

//   const handleCheck = (id) => {
//     setChecked(prev => {
//       const isChecked = checked.includes(id)
//       if(isChecked) {
//         return checked.filter(item => item !== id)
//       } else {
//         return [...prev,id]
//       }
//     })
//   }
  
//   return (
//     <div style={{ padding: 32 }}>
//       {courses.map(course => (
//         <div key={course.id}>
//           <input 
//           type="checkbox"
//           checked={checked.includes(course.id)}
//           onChange={() => handleCheck(course.id)}
//           />
//           {course.name}
//         </div>
//       ))}
//       <button onClick={handleSubmit}>Register</button>
//     </div>
//   )
// }





//to dolist

// function App() {

//   const [job, setJob] = useState('')
//   const [jobs,setjobs] = useState(() => {
//     const storagejobs = JSON.parse(localStorage.getItem('jobs'))
//     return storagejobs
//   })

//   const handleSubmit = () => {
//     setjobs(prev => {
//       const newJobs = [...prev, job]
//       const jsonJobs = JSON.stringify(newJobs)
//       localStorage.setItem('jobs', jsonJobs)
//       return newJobs
//     })
//     setJob('')
//   }
  
//   return (
//     <div style={{ padding: 32}}>
//       <input value={job} onChange = {e => setJob(e.target.value)}/>
//       <button onClick={handleSubmit}>Add</button>

//       <ul>
//         {jobs.map((job,index) => (
//           <li key={index}>{job}</li>
//         ))}
//       </ul>
//     </div>
//   )
// }

import Content from './Content'

function App() {
  const [show, setShow] = useState(false);

  return (
    <div className="App" style={{ padding: 32 }}>
      <button onClick={() => setShow(!show)}>Show Content</button>
      {show && <Content />}
    </div>
  );
}




export default App;
