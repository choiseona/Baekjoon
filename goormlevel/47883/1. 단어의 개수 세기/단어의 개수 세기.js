// Run by Node.js

const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

let sentence;
rl.on("line", function(line) {
	sentence = line;
	rl.close();
}).on("close", function() {
	const wordCount = sentence.split(" ").filter((word) => word !== "").length;
	console.log(wordCount);
	process.exit();
});