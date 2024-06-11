function solution(today, terms, privacies) {
    const termsMap = {};
    const [todayYear, todayMonth, todayDay] = today.split(".");
    terms.forEach((item) => {
        const [type, validate] = item.split(" ");
        termsMap[type] = parseInt(validate);
    });
    
    let answer = [];
    for (let i = 0; i < privacies.length; i++) {
        const privacy = privacies[i];
        const [start, type] = privacy.split(" ");
        const [startYear, startMonth, startDay] = start.split(".").map(Number);
        let endMonth = (startMonth + termsMap[type]) % 12;
        let endYear = startYear + Math.floor((startMonth + termsMap[type]) / 12);
        if (endMonth === 0) {
            endMonth = 12;
            endYear -= 1;
        }
        const endDay = startDay.toString().padStart(2, '0');
        const todayNumber = Number(todayYear + todayMonth + todayDay);
        const endNumber = Number(String(endYear) + String(endMonth).padStart(2, '0') + endDay);
        
        if (todayNumber < endNumber) continue;
        answer.push(i + 1);
    }
    
    return answer;
}
