function solution(numbers) {
    alphaNumbers = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"];
    
    alphaNumbers.map((item,index)=>
         numbers = numbers.split(item).join(index)
    );
    
    return Number(numbers);
}