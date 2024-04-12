function solution(box, n) {
    return box.reduce((pre,cur) => pre * (Math.floor(cur / n)), 1);
}