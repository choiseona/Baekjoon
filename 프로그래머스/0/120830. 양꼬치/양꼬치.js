function solution(n, k) {
    const 양꼬치 = n * 12000;
    const 음료수 = (k - Math.floor(n/10)) * 2000;
    return 양꼬치 + 음료수;
}