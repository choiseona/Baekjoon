// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	const input = [];
	for await (const line of rl) {
		input.push(line.split(" "));
		if(!line) {
			rl.close();
		}
	}
	const inAndOut = input.slice(1);
	solution(inAndOut);
	
	process.exit();
})();

function solution(inAnOut) {
	let answer;
	let totalMoney = 0;
	for(const [type, money] of inAnOut) {
		if(type === "in") {
			totalMoney += Number(money);
		} else {
			totalMoney -= Number(money)
		}
		if(totalMoney < 0) {
			answer = "fail";
			break;
		}
		answer = "success";
	}
	console.log(answer);
}