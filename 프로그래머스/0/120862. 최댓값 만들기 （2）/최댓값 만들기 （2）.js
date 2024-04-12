function solution(numbers) {
    const sortedNumbers = [...numbers].sort((a,b) => a-b);
    const 음수곱최대값 = sortedNumbers[0] * sortedNumbers[1];
    const 양수곱최대값 = sortedNumbers[sortedNumbers.length-1] * sortedNumbers[sortedNumbers.length-2];
    return Math.max(음수곱최대값, 양수곱최대값);
}