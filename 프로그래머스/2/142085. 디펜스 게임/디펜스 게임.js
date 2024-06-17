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

        let curIndex = 0, leftIndex = 1, rightIndex = 2;
        while (leftIndex < this.heap.length) {
          let leftIndex = curIndex * 2 + 1, rightIndex = curIndex * 2 + 2, nextIndex = curIndex;
          
          if (this.heap[nextIndex] > this.heap[leftIndex]) {
              nextIndex = leftIndex;
          }
          
          if (leftIndex < this.heap.length && this.heap[nextIndex] > this.heap[rightIndex]) {
              nextIndex = rightIndex;
          }
          
          if (curIndex === nextIndex) {
              break;
          }
          this.swap(curIndex,nextIndex);
          curIndex = nextIndex;
        }
            
        return min;
    }
}

