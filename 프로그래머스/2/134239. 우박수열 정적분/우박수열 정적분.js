function solution(k, ranges) {
  const graph = getGraph(k);
  const n = graph.length - 1;
  const area = getArea(graph, k);
  const result = getRangeArea(ranges, area, n);
  return result;
}

function getRangeArea(ranges, area, n) {
  const rangeArea = ranges.map(([x1, x2]) => {
    x2 = x2 <= 0 ? x2 + n : x2;
    if (x1 > x2) return -1;
    return area.slice(x1, x2).reduce((cul, cur) => cul + cur, 0);
  });
  return rangeArea;
}

function getGraph(k) {
  const graph = [];
  while (true) {
    graph.push(k);
    if (k === 1) break;
    k = k % 2 === 0 ? k / 2 : k * 3 + 1;
  }
  return graph;
}

function getArea(graph, k) {
  const area = [];
  for (let i = 0; i < graph.length - 1; i++) {
    const x1 = i,
      y1 = graph[i];
    const x2 = i + 1,
      y2 = graph[i + 1];
    const square = Math.max(y1, y2) * Math.abs(x2 - x1);
    const upper = (Math.abs(y1 - y2) * Math.abs(x2 - x1)) / 2;
    area.push(square - upper);
  }
  return area;
}
