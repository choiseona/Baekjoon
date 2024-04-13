function solution(emergency) {
    const sortedEmergency = [...emergency].sort((a,b) => b - a);
    return emergency.map((number) => sortedEmergency.indexOf(number)+1)
}