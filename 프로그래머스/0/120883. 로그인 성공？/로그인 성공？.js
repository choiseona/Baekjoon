function solution(id_pw, db) {
    const [targetId, targetPw] = db.filter((item) => id_pw[0] === item[0])[0] || [];
    const [inputId, inputPw] = id_pw;
   
    if (!targetId || !targetPw) {
        return "fail";
    } else if(targetId === inputId && targetPw === inputPw) {
        return "login";
    } else if(targetId === inputId && targetPw !== inputPw) {
        return "wrong pw"
    }
}