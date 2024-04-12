function solution(my_string, letter) {
    return [...my_string].filter((word) => word !== letter).join("");
}