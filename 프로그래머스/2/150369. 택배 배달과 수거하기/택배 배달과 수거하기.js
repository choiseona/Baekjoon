function solution(cap, n, deliveries, pickups) {
  // cap: 트럭에 실을 수 있는 재활용 택배 상자 최대 개수
  // n: n개의 집
  // deliveries: i+1번째 집에 배달할 재활용 택배 상자 개수
  // pickups: i+1번째 집에서 수거할 빈 재활용 택배 상자의 개수

  // 모든 배달과 수거 마치고 물류창고까지 돌아오는 최소 이동 거리 반환

  let answer = 0;
  let delivery = 0,
    pickup = 0;

  // delivery-cap 과 pickup-cap의 누적값을 통해 답 구하기
  for (let i = n - 1; i >= 0; i--) {
    delivery += deliveries[i];
    pickup += pickups[i];

    while (delivery > 0 || pickup > 0) {
      delivery -= cap;
      pickup -= cap;
      answer += (i + 1) * 2;
    }
  }
  return answer;
}
