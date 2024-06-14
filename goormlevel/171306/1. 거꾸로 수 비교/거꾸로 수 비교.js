// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	
	let number1, number2;
	for await (const line of rl) {
		[number1, number2] = line.split(" ");
		rl.close();
	}
	
	solution(number1, number2);
	
	process.exit();
})();

function solution (number1, number2) {
	const reversedNumber1 = Number([...number1].reverse().join(""));
	const reversedNumber2 = Number([...number2].reverse().join(""));
	reversedNumber1 > reversedNumber2 ? console.log(number1) : console.log(number2)
}