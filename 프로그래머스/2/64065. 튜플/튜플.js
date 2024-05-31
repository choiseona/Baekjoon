function solution(s) {
    s = s.replace(/{/g,'[')
    s = s.replace(/}/g,']');
    s = JSON.parse(s);
    s = s.sort((a,b) => a.length - b.length);
    
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