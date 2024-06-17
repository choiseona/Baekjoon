// Run by Node.js
const readline = require("readline");

(async () => {
  let rl = readline.createInterface({ input: process.stdin });

  const input = [];
  for await (const line of rl) {
    input.push(line);
    if (!line) rl.close();
  }
  const N = input[0];
  const present = input.slice(1);
  solution(N, present);

  process.exit();
})();

function solution(N, present) {
  present.forEach((item) => {
    const [a, b] = item.split(" ").map(Number);
    if (a < b) console.log("Sunflower");
    else if (a === b) console.log("Tulip");
    else console.log("Rose");
  });
}
