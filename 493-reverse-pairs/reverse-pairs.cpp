#define ll long long
class Solution {
public:

    void merge(vector<int> &nums,int low,int mid,int high){
        int left = low;
        int right=mid+1;
        vector<int> tmp;

        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
               tmp.push_back(nums[left]);
               left++;
            }
            else{
                tmp.push_back(nums[right]);
                right++;
            }
        }

        while(left<=mid){
            tmp.push_back(nums[left]);
            left++;
        }

        while(right<=high){
            tmp.push_back(nums[right]);
            right++;
        }

        for(int i=low;i<=high;i++){
            nums[i]=tmp[i-low];
        }
    }

    ll countReverses(vector<int> &nums,int low,int mid,int high){
        
        int right=mid+1;
        int cnt=0;
        //for every element in left sortedt array
        for(int i=low;i<=mid;i++){
            //find valid pairs in right sorted array
            while(right<=high && (ll)(nums[i])>(2LL*nums[right])) right++;
            cnt += (right-(mid+1)); //[mid+1..right..high]
        }
        return cnt;
    }
    ll mergeSort(vector<int>& nums,int low,int high){
        int cnt=0;
        if(low>=high)
         return cnt;

        int mid = (low+high)/2;

        cnt += mergeSort(nums,low,mid);
        cnt += mergeSort(nums,mid+1,high);
        //before merging add valid pairs
        cnt += countReverses(nums,low,mid,high);
        merge(nums,low,mid,high);

        return cnt;
    }

   
    int reversePairs(vector<int>& nums){
        int n=nums.size();
        return mergeSort(nums,0,n-1);
        
    }
};