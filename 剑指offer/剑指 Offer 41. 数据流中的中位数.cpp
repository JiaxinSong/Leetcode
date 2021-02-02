//大顶堆放前n+1个元素 小顶堆放后n和元素
//注意double

class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;


    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();
        if(max_heap.size()!=min_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

    }
    
    double findMedian() {
        return max_heap.size()>min_heap.size()? (double)max_heap.top():(double)(max_heap.top()+min_heap.top())/2;
    }
};
