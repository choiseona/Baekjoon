function solution(users, emoticons) {
    const permutation = getPermutations([10,20,30,40], emoticons.length);
    const salePrices = getSalePrices(emoticons, permutation);
    let maxEmoticonPlusCount = -Infinity;
    let revenue;
    
    for(const prices of salePrices) {
        let emoticonPlusCount = 0;
        let totalPurchase = 0;
        for(const [criterion, budget] of users) {
            const userPurchase = prices.reduce((acc, [percent, price]) => criterion > percent ? acc : acc + price, 0);
            if(userPurchase >= budget) emoticonPlusCount++;
            else totalPurchase += userPurchase;
        }
        
        if(emoticonPlusCount === maxEmoticonPlusCount) {
            revenue = Math.max(revenue, totalPurchase);
        }
        
        else if(emoticonPlusCount > maxEmoticonPlusCount) {
            maxEmoticonPlusCount = emoticonPlusCount;
            revenue = totalPurchase;
        }
       
    }
    return [maxEmoticonPlusCount, revenue]
}

function getSalePrices(arr, permutation) {
    return permutation.map((condition) => {
        return condition.map((salePercent, index) => [salePercent, arr[index] * (100-salePercent)/100]);
    })
}

function getPermutations(arr, selectCount) {
    if(selectCount === 1) return arr.map((el) => [el]);
    
    const result = [];
    arr.forEach((item) => {
        const permutation = getPermutations(arr, selectCount-1);
        const attached = permutation.map((el) => [item, ...el]);
        result.push(...attached);
    })
    return result;
}
