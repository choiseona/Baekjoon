function solution(my_string, num1, num2) {

    const changedString = [...my_string];
    changedString[num1] = my_string[num2];
    changedString[num2] = my_string[num1];
    return changedString.join("");
}