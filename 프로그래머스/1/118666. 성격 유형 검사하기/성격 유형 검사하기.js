function solution(survey, choices) {
    const scores = [,3,2,1,0,1,2,3];
    const typesScore = {"R":0, "T":0, "C":0, "F":0, "J":0, "M":0, "A":0, "N":0};
    const typesMapping = {"R":"T","C":"F","J":"M","A":"N"};

    // 데이터 구조: 딕셔너리(key: 유형, value: 점수)
    survey.forEach((type, index) => {
        const choice = choices[index];
        const score = scores[choice];
        const [type1, type2] = type.split("");
        
        if(choice < 4 ) typesScore[type1]+=score;
        else if(choice > 4) typesScore[type2]+=score;
    })
    
    let userType = '';
    for(const typeKey in typesScore) {
        if(!typesMapping[typeKey]) continue;
        const type1 = typeKey, type2 = typesMapping[typeKey];
        const type1Score = typesScore[type1];
        const type2Score = typesScore[type2];
        
        if(type1Score === type2Score) userType += type1 < type2 ? type1 : type2;
        else userType += type1Score > type2Score ? type1 : type2;
    }
    
    return userType;
    
}