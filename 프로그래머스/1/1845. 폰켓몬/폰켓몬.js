function solution(nums) {
    const numberSet = new Set();
    nums.forEach((e) => numberSet.add(e));
    const setLength = numberSet.size;
    const maxLength = nums.length / 2;
    
    return maxLength >= setLength ? setLength : maxLength; 
}