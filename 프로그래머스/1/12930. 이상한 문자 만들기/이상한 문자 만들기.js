function solution(s) {
    return s.split(" ").map(word => word.split("").map((spell,sIndex) => sIndex % 2 === 0 ? spell.toUpperCase(): spell.toLowerCase()).join('')).join(" ");
}