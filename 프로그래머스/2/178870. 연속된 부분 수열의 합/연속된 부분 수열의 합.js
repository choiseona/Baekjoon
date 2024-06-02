function solution(sequence, k) {
    // sequence: 수열을 나타내는 정수 배열(오름차순), k: 부분 수열의 합
    // 길이가 가장 짧은 수열 반환, 여러개이면 시작 인덱스가 작은 수열 찾기

    let answer = [], minLength = Infinity, sum = 0, startIndex = 0, endIndex = -1;
    
    const plusNextNumber = () => {
        endIndex++;
        sum += sequence[endIndex];
    } 
    
    const minusFirstNumber = () => {
        sum -= sequence[startIndex];
        startIndex++;
    }
    
    while(endIndex < sequence.length) {
        const length = endIndex - startIndex + 1

        // 부분 수열의 합 === k && 기존 부분 수열보다 길이가 더 작을 때 갱신
        // 다음 수열 탐색을 위해 startIndex++, endIndex++, sum 갱신
        if(sum === k) {
            if(minLength > length) {
                minLength = length
                answer = [startIndex, endIndex];
            }
            minusFirstNumber();
            plusNextNumber();
        } 
        
        // 부분 수열의 합이 k보다 작으면 endIndex++, sum 갱신
        else if(sum < k) plusNextNumber();
        
        // 부분 수열의 합이 k보다 크면 startIndex++, sum 갱신
        else if(sum > k) minusFirstNumber();
        
    }

    return answer
}