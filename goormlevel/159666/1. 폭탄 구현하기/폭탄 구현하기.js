// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	let length, bombCount;
	let bombLocation = [];
	for await (const line of rl) {
		if(!length) {
			[length, bombCount] = line.split(" ").map(Number);
			continue;
		}
		if(!line) {
			rl.close();
		}
		bombLocation.push(line.split(" ").map(Number));
	}
	solution(bombLocation, length);
	process.exit();
})();

function solution(bombLocation, length) {
	const yDirection = [-1,1,0,0];
	const xDirection = [0,0,-1,1];
	const road = Array.from({length:length+1},() => Array.from({length:length+1}, () => 0));
	bombLocation.forEach(([yLocation, xLocation]) => {
		road[yLocation][xLocation]++;
		for(let i=0; i<4; i++) {
			const newYLocation = yLocation + yDirection[i];
			const newXLocation = xLocation + xDirection[i];
			if(newXLocation < 1 || newYLocation < 1 || newYLocation > length || newXLocation > length) continue;
			road[newYLocation][newXLocation]++;
		}
	})
	
	const sum = road.reduce((cul,cur) => cul + cur.reduce((subCul,subCur) => subCul + subCur,0),0);
	console.log(sum)
}





