function solution(array, n) {
    const answer = array.filter((i) => i===n) .length;
    return answer;
}