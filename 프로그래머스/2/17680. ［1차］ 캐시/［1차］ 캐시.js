function solution(cacheSize, cities) {
    // DB 캐시 크기에 따른 실행시간 측정
    // cacheSize: 캐시 크기, cities: 도시 이름
    // LRU: 가장 오랫동안 참조되지 않은 것 교체
    let cache = [];
    let answer = 0;
    
    if(cacheSize === 0) return 5 * cities.length;
    
    cities.forEach((city) => {
        const cachedIndex = cache.findIndex((cachedCity) => cachedCity.toLowerCase() === city.toLowerCase());
        // cache hit
        if(cachedIndex > -1){
            answer++;
            cache.splice(cachedIndex,1);
        }
        
        // cache miss
        else {
            cache.length >= cacheSize ? cache.shift() : null;
            answer += 5;
    
        }  

        cache.push(city);
    })
    
    return answer;
    
}