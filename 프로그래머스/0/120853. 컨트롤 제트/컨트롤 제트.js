function solution(s) {
    return [...s.split(" ")].reduce((prev,cur,index,array) => 
        isNaN(cur) 
        ? prev- Number(array[index-1] )
        :  prev + Number(cur) ,0)
}