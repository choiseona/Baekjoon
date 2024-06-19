function solution(babbling) {
    let count = 0;
    const canList = ["aya", "ye", "woo", "ma"];
    
    for(let target of babbling) {
        for(const can of canList) {
            // 같은 단어 연속해서 있으면 안됨
            if(target.includes(can.repeat(2))) break;
           
            // 불가능한 단어 있으면 안됨
            target = target.split(can).join(" ");
        }
        
        if(target.split(" ").join("").length === 0) count++;
    }
    return count;
}