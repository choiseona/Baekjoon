function solution(topping) {
    let count = 0;
    const me = new Map();
    const sister = new Map();
    
    // 철수 토핑
    for(const type of topping) {
        me.set(type,(me.get(type) || 0) + 1);
    }
   
    // 동생 토핑
    for(const type of topping) {
        me.set(type, me.get(type) - 1);
        if(me.get(type) === 0) me.delete(type)
        
        sister.set(type, (sister.get(type) || 0) + 1)
        if(sister.size === me.size) count++;
    }
    return count;
}