function solution(array) {
    const maxNumber = Math.max(...array);
    const maxIndex = array.indexOf(maxNumber)
    return [maxNumber, maxIndex];
}