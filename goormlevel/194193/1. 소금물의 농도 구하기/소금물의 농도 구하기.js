// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	let saltWater = '', additionalWater = '';
	for await (const line of rl) {
		[saltWater, additionalWater] = line.split(" ").map(Number);
		rl.close();
	}

	const salt = 7 * saltWater / 100; 
	const density = (Math.floor(salt / (saltWater + additionalWater) * 100 * 100) / 100).toFixed(2); 
	console.log(density);
	
	process.exit();
})();
