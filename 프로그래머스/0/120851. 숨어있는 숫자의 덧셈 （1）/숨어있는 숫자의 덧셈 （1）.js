function solution(my_string) {
    return [...my_string.match(/\d/g)].reduce((pre,cur) => pre + Number(cur),0);
}