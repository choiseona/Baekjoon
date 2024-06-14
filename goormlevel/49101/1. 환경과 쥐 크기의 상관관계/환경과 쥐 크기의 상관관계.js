// Run by Node.js
const readline = require("readline");

(async () => {
  let rl = readline.createInterface({ input: process.stdin });
  let testCaseCount;
  const input = [];
  for await (const line of rl) {
    if (!testCaseCount) {
      testCaseCount = line;
      continue;
    }
    if (!line) rl.close();
    input.push(line.split(" ").map(Number));
  }
  solution(input);
  process.exit();
})();

function solution(input) {
  const [volumeA, volumeB] = input;
  const selectedAMouth = selectMouth(volumeA);
  const selectedBMouth = selectMouth(volumeB);
  console.log(selectedAMouth, selectedBMouth);
  selectedAMouth > selectedBMouth ? console.log("good") : console.log("bad");
}

function selectMouth(volumes) {
  // 각 volume의 [volume-2,volume+2]에 해당하는 숫자만 조사
  // countMap: key-숫자, value-쥐 마리
  const countMap = {};
  volumes.forEach((volume) => {
    for (let i = volume - 2; i <= volume + 2; i++) {
      countMap[i] = (countMap[i] || 0) + 1;
    }
  });

  // countMap 돌면서 최대쥐 && 최소숫자 찾기
  let maxCount = -Infinity;
  let selectedMouth = Infinity;
  for (const key in countMap) {
    if (
      countMap[key] > maxCount ||
      (countMap[key] === maxCount && Number(key) < selectedMouth)
    ) {
      maxCount = countMap[key];
      selectedMouth = Number(key);
    }
  }
  return selectedMouth;
}
