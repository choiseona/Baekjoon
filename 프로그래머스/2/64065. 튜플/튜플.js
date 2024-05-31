function solution(s) {
    s = JSON.parse(s.replace(/{/g,'[').replace(/}/g,']')).sort((a,b) => a.length - b.length);
    
    const visitedNumber = [];
    const set = [];

    s.forEach((element) => {
        element.forEach((number)=> {
            if(visitedNumber.includes(number)) return;
            set.push(number)
            visitedNumber.push(number)
        })
    })
    
    return set

}