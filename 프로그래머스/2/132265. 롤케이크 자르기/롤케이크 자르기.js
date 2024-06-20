function solution(topping) {
  let count = 0;
  const me = new Map();
  const sister = new Map();

  // 철수 토핑
  for (const type of topping) {
    me.set(type, (me.get(type) || 0) + 1);
  }

  // 동생 토핑
  for (const type of topping) {
    me.set(type, me.get(type) - 1);
    if (me.get(type) === 0) me.delete(type);

    sister.set(type, (sister.get(type) || 0) + 1);
    if (sister.size === me.size) count++;
  }
  return count;
}

// O(N^2)이 되면 시간 초과가 되는 문제이다.
// 종류마다 전체 토핑 개수를 구하고O(n)
// 앞에서부터 동생의 각 토핑 개수를 빼면서 철수와 동생의 토핑 종류 개수가 같으면 답을 1 증가시켜야한다.O(n)
// 결론은 O(n) 으로 해결이 가능하다.
