function solution(my_string) {
    const isUpperCase = (word) => {
        return word === word.toUpperCase();
    }
    
    return [...my_string].map((item) => isUpperCase(item) ? item.toLowerCase() : item.toUpperCase()).join("");
 
}