function solution(X, Y) {
    const mapX = new Map();
    let result = ""
    
    for(const number of [...X]) {
        mapX.set(number, (mapX.get(number) || 0) + 1);
    }
    
    for(const number of [...Y]) {
        if(!mapX.has(number)) continue;
        result += number;
        mapX.set(number, mapX.get(number) - 1);
        if(mapX.get(number) === 0) mapX.delete(number);
    }
    
    if(result.length === 0) {
        return "-1";
    } else if(result.replaceAll("0","").length === 0) {
        return "0";
    } else {
        return [...result].sort((a,b) => b-a).join("").toString();
    }
}