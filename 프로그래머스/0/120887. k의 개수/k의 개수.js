function solution(i, j, k) {
    let answer = 0;
    for (let iter=i;iter<=j;iter++){
      [...String(iter)].forEach((number) => Number(number) === k && answer++)
    }
    return answer;
}