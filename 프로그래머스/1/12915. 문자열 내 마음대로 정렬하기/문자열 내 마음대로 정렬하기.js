function solution(strings, n) {
    const getCode = (word) => {
        return word.charCodeAt() - 'a'.charCodeAt();
    }
    const answer = strings.sort().sort((a,b) => getCode(a[n]) - getCode(b[n]));
    return answer;
}