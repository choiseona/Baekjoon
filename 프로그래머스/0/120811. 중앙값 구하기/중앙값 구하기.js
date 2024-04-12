function solution(array) {
    array.sort(function(a,b){
        return a-b;
    })
    return array[Math.floor((array.length)/2)]
}