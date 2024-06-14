// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	let testCaseCount;
	const input = [];
	for await (const line of rl) {
		if(!testCaseCount) {
			testCaseCount = line;
			continue;
		}
		if(!line) rl.close();
		input.push(line.split(" ").map(Number));
	}
	solution(input);
	process.exit();
})();

function solution(input) {
	const [volumeA,volumeB] = input;
	const selectedAMouth = selectMouth(volumeA);
	const selectedBMouth = selectMouth(volumeB);
	console.log(selectedAMouth, selectedBMouth);
	selectedAMouth > selectedBMouth ? console.log("good") : console.log("bad");

}

function selectMouth(volumes) {
    const countMap = {};
    let maxCount = -Infinity;
    let selectedMouth = Infinity;
    volumes.forEach(volume => {
        for (let i = volume - 2; i <= volume + 2; i++) {
            countMap[i] = (countMap[i] || 0) + 1;
            if (countMap[i] > maxCount || (countMap[i] === maxCount && i < selectedMouth)) {
                maxCount = countMap[i];
                selectedMouth = i;
            }
        }
    });
    return selectedMouth;
}
	