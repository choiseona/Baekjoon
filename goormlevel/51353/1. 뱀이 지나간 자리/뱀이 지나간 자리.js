// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	let row = '', column = '';
	for await (const line of rl) {
		[row, column] = line.split(" ");
		rl.close();
	}
	
	let right = true;
	for(let i=0; i<row; i++) {
		if(i % 2 === 0) {
			console.log("#".repeat(column))
		} 
		else if(right) {
			console.log('.'.repeat(column-1) + '#')
			right = false;
		}
		else {
			console.log('#' + '.'.repeat(column-1))
			right = true
		} 
	}
	
	process.exit();
})();
