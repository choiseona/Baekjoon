function solution(dots) {
    dots.sort((a,b) => a[0]-b[0] || a[1] - b[1]);
    return Math.abs(dots[0][0] - dots[3][0]) * Math.abs(dots[0][1] - dots[3][1]);
}