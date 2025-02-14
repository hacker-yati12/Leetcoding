class ProductOfNumbers {
    vector<int> arr;
public:
    ProductOfNumbers() {}
    
    void add(int num) {
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        long long prod = 1;
        int i = arr.size()-1;
        while(k--) {
            prod *= arr[i];
            i--;
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */