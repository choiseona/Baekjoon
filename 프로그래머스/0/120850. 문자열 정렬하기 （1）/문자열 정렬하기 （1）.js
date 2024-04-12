function solution(my_string) {
    return [...my_string].filter((item) => !isNaN(item - 0)).map((item) => Number(item)).sort();
}