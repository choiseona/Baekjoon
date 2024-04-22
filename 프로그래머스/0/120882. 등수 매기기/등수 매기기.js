function solution(score) {
    return score.map((scores) => {
        return score.filter((item) => (item[0] + item[1]) / 2 > (scores[0] + scores[1]) / 2 ).length + 1;
    })
}