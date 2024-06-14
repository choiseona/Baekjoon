// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	
	let input = [];
	for await (const line of rl) {
		input.push(line.split(" ")[0].replace(/([-+*])/g, " $1 ").split(" "));
		input.push(line.split(" ")[1].replace(/([-+*])/g, " $1 ").split(" "));
		rl.close();
	}
	solution(input);
	process.exit();
})();

function solution(input) {
	const [oper1, oper2] = input;
	console.log(Math.max(calculate(oper1), calculate(oper2)))
}

// 연산 수행
function calculate(oper) {
	// 곱셈 수행
	const array = [];
	for(const item of oper) {
		if(array[array.length-1] !== '*' ) {
			 array.push(item);
		} else {
			array.pop();
			const left = array.pop();
			array.push(Number(left) * Number(item));
		}
	}
	
	// - + 연산 수행
	let answer = 0;
	for(let i=0; i<array.length; i++) {
		if(array[i] === '+' || array[i] === '-') continue;
		if(array[i-1] !== '-'){
			answer += Number(array[i]);
		} else if(array[i-1] === '-'){
			answer -= Number(array[i]);
		}
	}
	
	return answer;
}




