function solution(array) {
    return [...array].reduce((prev,cur) => prev+String(cur),'').split(7).length-1
}