const readline = require('readline');

(async () => {
	let rl = readline.createInterface({
		input: process.stdin,
		output: process.stdout,
	});
	
	let length, bombCount;
	let road = [], bombLocation = [];
	let count = 0;
	
  for await (const line of rl) {
    if(!length) {
		[length, bombCount] = line.split(" ").map(Number);
		continue;
		}
		
		if(!line){
			rl.close();
		}
	
		if(count < length) {
			road.push(line.split(" "));
		}
	
		if(count >= length) {
			bombLocation.push(line.split(" ").map(Number));
		}

		count++;
  }
	solution(road, bombLocation);
  process.exit();
})();

function solution(road, bombLocation) {
	const maxBomb = bomb(road, bombLocation);
	console.log(maxBomb);
}

function bomb(road, bombLocation) {
	let maxBomb = -Infinity;
	const xDirection = [-1,1,0,0];
	const yDirection = [0,0,-1,1];
	const newRoad = Array.from({length:road.length + 1}, () => Array.from({length:road.length + 1}, () => 0));
	bombLocation.forEach(([yLocation, xLocation]) => {
		newRoad[yLocation][xLocation] += getCount(road[yLocation-1][xLocation-1]);
		if(newRoad[yLocation][xLocation] > maxBomb) maxBomb = newRoad[yLocation][xLocation];
		for(let i=0; i<4; i++) {
			const newYLocation = yLocation + yDirection[i];
			const newXLocation = xLocation + xDirection[i];
			if(newYLocation<1 || newXLocation<1 || newYLocation > road.length || newXLocation >road.length) continue;
			newRoad[newYLocation][newXLocation] += getCount(road[newYLocation-1][newXLocation-1]);
			if(newRoad[newYLocation][newXLocation] > maxBomb) maxBomb = newRoad[newYLocation][newXLocation];
		}
	})
	return maxBomb;
}


function getCount(character) {
	if(character === '0') return 1;
	else if(character === '@') return 2;
	else if(character === '#') return 0;
}
