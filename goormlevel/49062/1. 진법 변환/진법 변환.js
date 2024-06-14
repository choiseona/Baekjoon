// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	let input;
	for await (const line of rl) {
		input = line.split(" ");
		if(!line) rl.close();
	}
	solution(input);
	process.exit();
})();

function solution(input) {
	const [num1, num2] = input;
	let answer;
	for (let i = 2; i <= 16; i++) {
		if(parseInt(num1,10) === parseInt(num2,i)) {
			answer = i;
			break;
		}
	}
	console.log(answer);
}