class MedianFinder {
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (maxi.size() == 0)
            maxi.push(num);
        else if (maxi.size() == mini.size()) {
            int topval = mini.top();
            if (num <= topval)
                maxi.push(num);
            else {
                mini.pop();
                mini.push(num);
                maxi.push(topval);
            }
        } else {
            int mintop = maxi.top();
            if (num >= mintop) {
                mini.push(num);
            } else {
                mini.push(mintop);
                maxi.pop();
                maxi.push(num);
            }
        }
    }
    
    double findMedian() {
        if (maxi.size() == mini.size())
            return (maxi.top() + mini.top())/2.0;
        else
            return maxi.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */