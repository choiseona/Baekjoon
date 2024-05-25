function solution(s) {
    const alphabet = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"];
        
    alphabet.forEach((word, index) => {
        s = s.split(word).join(index)
    })
    
    return parseInt(s);
    
}