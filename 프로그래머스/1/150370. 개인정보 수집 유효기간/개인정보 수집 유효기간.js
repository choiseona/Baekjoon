function solution(today, terms, privacies) {
    const [todayYear, todayMonth, todayDay] = today.split(".").map(Number);
    const todayNumber = todayYear * 12 * 28 + todayMonth * 28 + todayDay;
    
    const termsMap = {};
    terms.forEach((item) => {
        const [type, validate] = item.split(" ");
        termsMap[type] = Number(validate);
    });
    
    let answer = [];
    privacies.forEach((item,index) => {
        const [date, type] = item.split(" ");
        const [startYear, startMonth, startDay] = date.split(".").map(Number);
        const endNumber = startYear * 12 * 28 + (startMonth + termsMap[type]) * 28 + startDay;
        if(todayNumber >= endNumber) answer.push(index+1)
    })

    return answer;
}
