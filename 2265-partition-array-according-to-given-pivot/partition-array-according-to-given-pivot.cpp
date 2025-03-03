class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        //count number of elements less than pivot and equal to pivot
        //no need to count elements greater than pivot because it automatically 
        //equals to N-(less+equal)
        int numOfLess=0,numOfEq =0;
        for(int num:nums){
            if(num<pivot){
              numOfLess++;
            }
            else if(num==pivot){
                numOfEq++;
            }
        }

        //lessIndex any how starts from zero
        //equalINdex starts from NumofLess(after less than pivot elements)
        //greaterIndex starts from (numOfLess+numOfEqual)
         vector<int> ans(n);
         int lessIndex =0,eqIndex =numOfLess,greaterIndex = numOfLess+numOfEq;
         for(int num:nums){
            if(num<pivot){
               ans[lessIndex]=num;
               lessIndex++;
            }
            else if(num>pivot){
               ans[greaterIndex]=num;
               greaterIndex++;
            }
            else{
                ans[eqIndex]=num;
                eqIndex++;
            }
         }
     return ans;
    }
};