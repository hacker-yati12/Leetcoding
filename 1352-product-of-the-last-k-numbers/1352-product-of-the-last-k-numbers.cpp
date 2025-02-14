class ProductOfNumbers {
    vector<int> arr{1};
public:
    ProductOfNumbers() {}
    
    void add(int num) {
        if(num!=0)
            arr.push_back(arr.back()*num);
        else {
            arr.clear();
            arr.push_back(1);
        }
    }
    
    int getProduct(int k) {
        return (k<arr.size())?(arr.back()/arr[arr.size()-1-k]):0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */