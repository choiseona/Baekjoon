// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	let wordCount, maintain, words;
	for await (const line of rl) {
		if(!wordCount) {
			[wordCount, maintain]  = line.split(" ");
			continue;
		}
		if(!line) rl.close();
		words = line.split(" ");
	}
	
	let answer = 1;
	for(let i = 1; i < words.length; i++) {
		if(words[i] - words[i-1] > maintain) answer = 1;
		else answer++;
	}
	console.log(answer);
	
	process.exit();
})();
