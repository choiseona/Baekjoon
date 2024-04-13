function solution(s1, s2) {

    return s1.filter((word) => s2.includes(word)).length;
}