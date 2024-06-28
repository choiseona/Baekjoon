function solution(users, emoticons) {
  const permutations = generatePermutations([10, 20, 30, 40], emoticons.length);
  const salePrices = calculateSalePrices(emoticons, permutations);

  let maxEmoticonPlusCount = -Infinity;
  let maxRevenue = 0;

  for (const prices of salePrices) {
    let emoticonPlusCount = 0;
    let totalPurchase = 0;

    for (const [criterion, budget] of users) {
      const userPurchase = calculateUserPurchase(prices, criterion);

      if (userPurchase >= budget) emoticonPlusCount++;
      else totalPurchase += userPurchase;
    }

    if (emoticonPlusCount > maxEmoticonPlusCount) {
      maxEmoticonPlusCount = emoticonPlusCount;
      maxRevenue = totalPurchase;
    } else if (emoticonPlusCount === maxEmoticonPlusCount) {
      maxRevenue = Math.max(maxRevenue, totalPurchase);
    }
  }

  return [maxEmoticonPlusCount, maxRevenue];
}

function calculateUserPurchase(prices, criterion) {
  return prices.reduce(
    (acc, [percent, price]) => (criterion > percent ? acc : acc + price),
    0
  );
}

function calculateSalePrices(emoticons, permutations) {
  return permutations.map((permutation) => {
    return permutation.map((salePercent, index) => {
      const discountedPrice = (emoticons[index] * (100 - salePercent)) / 100;
      return [salePercent, discountedPrice];
    });
  });
}

function generatePermutations(arr, selectCount) {
  if (selectCount === 1) return arr.map((el) => [el]);

  const result = [];
  arr.forEach((item) => {
    const permutations = generatePermutations(arr, selectCount - 1);
    const attached = permutations.map((el) => [item, ...el]);
    result.push(...attached);
  });

  return result;
}
