function solution(rsp) {
    const test = (item) => {
        if(item === "2")
            return "0";
        else if(item === "0")
            return "5";
        else if(item === "5")
            return "2";
    }
    
    return [...rsp].map((item) => test(item)).join("");
    
}