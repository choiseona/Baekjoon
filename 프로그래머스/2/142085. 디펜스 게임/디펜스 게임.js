function solution(n, k, enemy) {
    const minHeap = new MinHeap();
    for(let i=0; i<k; i++) {
        minHeap.heapPush(enemy[i]);
    }
    
    let capacity = 0;
    for(let i=k; i<enemy.length; i++) {
        minHeap.heapPush(enemy[i]);
        const next = minHeap.heapPop();
        if(capacity + next > n) return i;
        capacity+=next;
    }
    return enemy.length;
}

class MinHeap {
    constructor() {
        this.heap = [];
    }
    front() {
        return this.heap[0];
    }
    swap(index1, index2) {
        [this.heap[index1], this.heap[index2]] = [this.heap[index2], this.heap[index1]];
    }
    
    heapPush(element) {
        this.heap.push(element);
        let curIndex = this.heap.length -1;
        let parentIndex = Math.floor((curIndex - 1) / 2);
        
        while(this.heap[curIndex] < this.heap[parentIndex]) {
            this.swap(curIndex, parentIndex);
            curIndex = parentIndex;
            parentIndex = Math.floor((curIndex - 1)/2);
        }
    }
    heapPop() {
        if(this.heap.length <= 1) return this.heap.pop();
        
        const min = this.heap[0];
        this.heap[0] = this.heap.pop();

        let index = 0;
        while (index * 2 + 1 < this.heap.length) {
          let left = index * 2 + 1, right = index * 2 + 2, next = index;
          
          if (this.heap[next] > this.heap[left]) {
              next = left;
          }
          
          if (right < this.heap.length && this.heap[next] > this.heap[right]) {
              next = right;
          }
          
          if (next === index) {
              break;
          }
          this.swap(index,next);
          index = next;
        }
            
        return min;
    }
}

