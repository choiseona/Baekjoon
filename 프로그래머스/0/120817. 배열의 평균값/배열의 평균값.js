function solution(numbers) {
  const sum = numbers.reduce((pre, cur) => pre + cur, 0)
  return sum / numbers.length
}
