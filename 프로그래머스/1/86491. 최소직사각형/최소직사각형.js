function solution(sizes) {
    const sortedSizes = sizes.map((e) => e.sort((a,b) => b - a));
    const leftMax = sortedSizes.slice().sort((a,b) => b[0]-a[0])[0][0];
    const rightMax = sortedSizes.slice().sort((a,b) => b[1]-a[1])[0][1];

    return leftMax * rightMax;

}