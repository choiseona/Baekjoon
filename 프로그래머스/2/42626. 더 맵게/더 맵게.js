const Heap = (function() {
   function Heap() {
       this.heap = [null];
   } 
    
    Heap.prototype.front = function() {
        return this.heap[1];
    }
    
    Heap.prototype.length = function() {
        return this.heap.length-1;
    }
    
    Heap.prototype.swap = function(index1, index2) {
        [this.heap[index1], this.heap[index2]] = [this.heap[index2], this.heap[index1]];
    }
    
    Heap.prototype.heapPush = function(element) {
        this.heap.push(element);
        let curIndex = this.heap.length-1;
        let parentIndex = Math.floor(curIndex / 2);
        
        while(this.heap[curIndex] < this.heap[parentIndex]) {
            this.swap(curIndex, parentIndex);
            curIndex = parentIndex;
            parentIndex = Math.floor(curIndex / 2);
        }
    }
    
    Heap.prototype.heapPop = function() {
        const min = this.heap[1];
        
        if(this.heap.length <= 2) this.heap = [null];
        else this.heap[1] = this.heap.pop();
        
        let curIndex = 1;
        let leftIndex = 2;
        let rightIndex = 3;
        
        while(this.heap[leftIndex] && this.heap[rightIndex] && (this.heap[curIndex] > this.heap[leftIndex] || this.heap[curIndex] > this.heap[rightIndex])) {
            const minIndex = this.heap[leftIndex] <= this.heap[rightIndex] ? leftIndex : rightIndex;
            this.swap(minIndex, curIndex);
            curIndex = minIndex;
            leftIndex = curIndex * 2;
            rightIndex = curIndex * 2 + 1;
        }
        
        if(this.heap[leftIndex] && !this.heap[rightIndex] && this.heap[leftIndex] < this.heap[curIndex]) {
            this.swap(curIndex, leftIndex);            
        }
        
        return min;
    }
    return Heap;
}())

function solution(scoville, K) {
    let answer = 0;
    const heap = new Heap();
    
    scoville.forEach((e) => heap.heapPush(e));
    
    while(heap.front() < K && heap.length() >= 2) {
        const min1 = heap.heapPop();
        const min2 = heap.heapPop();
        const newScoville = min1 + min2 * 2;
        heap.heapPush(newScoville);
        
        answer++;
    }
    
    if(heap.front() < K) answer = -1;
    
    return answer;
}
