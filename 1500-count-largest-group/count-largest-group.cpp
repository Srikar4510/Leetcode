class Solution {
public:
    int digitSum(int x){
        int sum = 0;
        while(x>0){
            sum += x%10;
            x /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        int maxSize = 0;
        for(int i =1;i<=n;i++){
            int sum = digitSum(i);
            mp[sum]++;
            maxSize = max(maxSize,mp[sum]);
        }

        int count = 0;
        for(auto& [key,freq]:mp){
            if(freq==maxSize){
                count++;
            }
        }
        return count;
    }
};