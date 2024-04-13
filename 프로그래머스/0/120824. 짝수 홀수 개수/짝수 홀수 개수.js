function solution(num_list) {
    const answer= [0,0];
    num_list.map((number) => number % 2 === 0 ? answer[0]++ : answer[1]++);
    return answer;
}