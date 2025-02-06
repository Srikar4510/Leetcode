class Solution {
public:
//
//The pairProductsFrequency can grow up to  n×(n−1)/2=O(n^2) in size
//O(N^2) O(N^2)
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> pairProductsFrequency;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                  pairProductsFrequency[nums[i]*nums[j]]++;
            }
        }
        for(auto [productVal,freq] :pairProductsFrequency){
            int pairswithEqualProduct = freq*(freq-1)/2;
            ans += 8*pairswithEqualProduct;  
        }
    return ans;
    }
};