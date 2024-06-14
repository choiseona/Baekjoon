// Run by Node.js
const readline = require('readline');
const input = [];

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	let testCaseCount , input = [];
	
	for await (const line of rl) {
		if(!testCaseCount) {
			testCaseCount = line;
			continue;
		}
		if(!line) rl.close();
		const [number1, number2] = line.split(" ");
		input.push([number1,number2]);
	}
	
	solution(input);
	process.exit();
})();

function solution(input) {
	let maxArea = -Infinity;
	for (const [number1, number2] of input) {
		maxArea = Math.max(maxArea, number1 * number2);
	}
	console.log(maxArea)
}
