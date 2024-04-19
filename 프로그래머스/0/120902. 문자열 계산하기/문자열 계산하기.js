function solution(my_string) {
    const arrayedMyString = my_string.split(" ");
    return arrayedMyString.reduce((prev,cur,index,array) => {
        if(index === 0 || isNaN(cur)) return prev;
        return array[index-1] === '-' ? prev - Number(cur) : prev + Number(cur)
    },Number(arrayedMyString[0]))
}