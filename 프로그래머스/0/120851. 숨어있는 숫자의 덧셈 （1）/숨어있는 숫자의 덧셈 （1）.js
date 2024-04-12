function solution(my_string) {
    return [...my_string.match(/[0-9]/g)].reduce((pre,cur) => pre + Number(cur),0);
}