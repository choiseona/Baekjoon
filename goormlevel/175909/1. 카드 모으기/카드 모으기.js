// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	const input = [];
	for await (const line of rl) {
		input.push(line);
		if(!line) {
			rl.close();
		}
		
	}
	const [cardType, sendCardCount] = input[0].split(" ").map(Number);
	const sendCard = input.splice(1).map(Number);
	solution(cardType, sendCard);
	process.exit();
})();

function solution(cardType, sendCard) {
	const set = new Set();
	let answer;
	for(let i=0; i<sendCard.length; i++) {
		set.add(sendCard[i]);
		if(set.size === cardType) {
			answer = i+1;
			break;
		}
	}
	console.log(answer || -1);
}