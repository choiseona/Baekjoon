function solution(n) {
    return [...n.toString()].reduce((pre,cur) => pre + Number(cur),0);
}