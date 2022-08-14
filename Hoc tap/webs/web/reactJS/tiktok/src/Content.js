import  { useEffect, useLayoutEffect, useState, useRef } from 'react'

// Side effects noi toi mot chuong trinh phan mem khi co mot tac dong xay ra no dan toi du lieu cua chuong trinh bi thay doi

// 1.useEffect(callback)
    // - Gọi callback mỗi khi component re-render
    // - Gọi callback sau khi component thêm element vào Dom
    // 2.useEffect(callback, [])
    // - Chỉ gọi callback 1 lần sau khi component mounted
    // 3.useEffect(callback, [deps])
    // - Callback sẽ được gọi lại mõi khi deps thay đổi

    // 1. Callback luôn được gọi sau khi component mounted
    // 2. Clenup function luôn được gọi trước khi component unmounted
    // 3. Clenup function luôn được gọi trước khi callback được gọi (trừ lần mounted)

// const tabs = ['posts', 'comments', 'albums']

// function Content() {

//     const [title, setTitle] = useState('')
//     const [posts, setPosts] = useState([])
//     const [type, setType] = useState('posts')
//     const [showGoToTop, setShowGoToTop] = useState(false)

//     useEffect(() => {
//         fetch(`https://jsonplaceholder.typicode.com/${type}`)
//             .then(res => res.json())
//             .then(posts => {
//                 setPosts(posts)
//             })
//     },[type])

//     useEffect(() => {

//         const handelScroll = () => {
//             if(window.scrollY >= 200) {
//                 setShowGoToTop(true)
//             } else {
//                 setShowGoToTop(false)
//             }
//         }

//         window.addEventListener('scroll', handelScroll)

//          Cleanup function
//         return () => {
//             window.removeEventListener('scroll', handelScroll)
//         }
//     }, [])

//     return (
//         <div>
//             {tabs.map(tab => (
//                 <button
//                     key={tab}
//                     style={type == tab ? {
//                         color: '#fff',
//                         backgroundColor: '#333'
//                     } : {}}
//                     onClick={() => setType(tab)}
//                 >
//                     {tab}
//                 </button>
//             ))}

//             <input
//             value={title}
//             onChange={e => setTitle(e.target.value)}
//             />
//             <ul>
//                 {posts.map(post => (
//                     <li key={post.id}>{post.title || post.name}</li>
//                 ))}
//             </ul>
//             {showGoToTop && (
//                 <button
//                     style={{ 
//                         position: 'fixed',
//                         right: 20,
//                         bottom: 20,    
//                     }}
//                 >
//                     Go to Top
//                 </button>
//             )}
//         </div>
//     )
// }

// function Content() {
//     const [width, setWidth] = useState(window.innerWidth)

//     useEffect(() => {

//         const handleResize = () => {
//             setWidth(window.innerWidth)
//         }

//         window.addEventListener('resize', handleResize)

//         return () => {
//             window.removeEventListener('resize', handleResize)
//         }
//     }, [])

//     return (
//         <div>
//             <h1>{width}</h1>
//         </div>    
//     )
// }

// useEffect with time functions
// function Content() {
//     const [countdown, setCountdown] = useState(180)

//     useEffect(() => {
//         const timerId = setInterval(() => {
//             setCountdown(prevState => prevState - 1)
//         }, 1000)
//         return () => clearInterval(timerId)
//     }, [])

   

//     return (
//         <div>
//             <h1>{countdown}</h1>
//         </div>
//     )
// }

// useEffect with preview avatar
// function Content() {
//     const [count, setCount] = useState(1)

//     useEffect(() => {
//         console.log(`Mounted or Re-render lần ${count}`);

//         // Cleanup func
//         return () => {
//             console.log(`Cleanup lần ${count}`);
//         }
//     }, [count])

//     return (
//         <div>
//             <h1>{count}</h1>
//             <button
//                 onClick={() => setCount(count + 1)}
//             >Click me!</button>
//         </div>    
//     )
// }

// function Content() {
//     const [avatar, setAvatar] = useState()

//     useEffect(() => {
//         // cleanup
//         return () => {
//             avatar && URL.revokeObjectURL(avatar.preview)
//         }
//     }, [avatar])

//     const handlePreviewAvatar = (e) => {
//         const file = e.target.files[0]
//         file.preview = URL.createObjectURL(file)
//         setAvatar(file)
//     }
//     return (
//         <div>
//             <input
//                 type='file'
//                 onChange={handlePreviewAvatar}
//             >
//             </input>
//             {avatar && (
//                 <img src={avatar.preview} alt="" width="80%" />
//             )}
//         </div>
//     )
// }

// useEffect with fake Chat App

// const lessons = [
//     {
//         id: 1,
//         name: 'ReactJs là gì? Tại sao nên học ReactJs'
//     },
//     {
//         id: 2,
//         name: 'SPA/MPA là gì '
//     },
//     {
//         id: 3,
//         name: 'Arrow function'
//     }
// ]

// function Content() {
//     const [lessonId, setLessonId] = useState(1)

//     const handleComment = ({detail}) => {
//         console.log(detail);
//     }
//     useEffect(() => {
//         window.addEventListener(`lesson-${lessonId}`, handleComment)

//         return() => {
//             window.removeEventListener(`lesson-${lessonId}`, handleComment)
//         }
//     }, [lessonId])

//     return (
//         <div>
//             <ul>
//                 {lessons.map(lesson => (
//                     <li
//                         key={lesson.id}
//                         style={{ 
//                             color: lessonId === lesson.id ?
//                             'red': 
//                             '#333'
//                          }}
//                          onClick={() => setLessonId(lesson.id)}
//                     >
//                         {lesson.name}
//                     </li>
//                 ))}
//             </ul>
//         </div>
//     )
// }



// useEffect
// 1.Cập nhật lại state
// 2. Cập nhật DOM (mutated)
// 3. render lại UI
// 4. Gọi cleanup nếu deps thay đổi
// 5. Gọi useEffect callback

// useLayoutEffect
// 1.Cập nhật lại state
// 2. Cập nhật DOM (mutated)
// 3. Gọi cleanup nếu deps thay đổi
// 4. Gọi useEffect callback
// 5. render lại UI

function Content() {
    const [count,setCount] = useState(0)

    useLayoutEffect(() => {
        if(count > 3) {
            setCount(count + 1)
        }
    },[count])

    const handleRun = () => {
        setCount(count + 1)
    }
   

    return (
        <div>
            <h1>{count}</h1>
            <button onClick={handleRun}>Run</button>
        </div>
    )
}



// useRef
// Lưu lại các giá trị qua một tham chiếu bên ngoài
// function component




export default Content