function solution(my_string) {
    return my_string.split(/[^0-9]/).reduce((prev,cur) => prev + Number(cur) , 0)
}