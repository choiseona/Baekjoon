function solution(s1, s2) {
    const hasSameWord = (words, word) => {
        return !!words.find((element) => element === word)
    }
    return s1.reduce((pre,cur) => pre + hasSameWord(s2, cur),0);
}