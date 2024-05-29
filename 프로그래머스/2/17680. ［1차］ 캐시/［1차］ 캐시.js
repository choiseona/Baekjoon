function solution(cacheSize, cities) {
    // DB 캐시 크기에 따른 실행시간 측정
    // cacheSize: 캐시 크기, cities: 도시 이름
    // LRU: 가장 오랫동안 참조되지 않은 것 교체
    let cache = [];
    let answer = 0;
    
    cities.forEach((city) => {
        const cachedIndex = cache.findIndex((cachedCity) => cachedCity.toLowerCase() === city.toLowerCase());
        // cache hit
        if(cachedIndex > -1){
            answer++;
            cache = [...cache.slice(0,cachedIndex), ...cache.slice(cachedIndex+1),cache[cachedIndex]];
        }
        
        // cache miss
        else if(cacheSize === 0) {
            answer += 5;
        }
        
        else if(cache.length < cacheSize){
            answer += 5;
            cache.push(city);
        }
        
        else if(cache.length === cacheSize){
            answer += 5;
            cache.shift();
            cache.push(city)
            
        }         
    })
    
    return answer;
    
}