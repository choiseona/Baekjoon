function solution(nums) {
    const setLength = new Set(nums).size;
    const maxLength = nums.length / 2;
    
    return maxLength >= setLength ? setLength : maxLength; 
}