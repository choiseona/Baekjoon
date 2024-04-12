function solution(my_string, n) {
    return [...my_string].map((word) => word.repeat(n)).join("");
}