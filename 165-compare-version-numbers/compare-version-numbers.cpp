class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(),n2 = version2.size();
        int nums1 =0,nums2 =0;
        int i=0,j=0;

        while(i<n1 || j<n2){
            //add num1 upto dot
            while(i<n1 && version1[i]!='.'){
                nums1 = nums1*10 + (version1[i]-'0');
                i++;
            }
            //add num2 upto dot
            while(j<n2 && version2[j] != '.'){
                nums2 = nums2*10 + (version2[j]-'0');
                j++;
            }

            if(nums1>nums2) return 1;
            else if(nums2>nums1) return -1;

            //reset numbers to add after .
            nums1=0;
            nums2=0;
            //move next to dot character
            i++;
            j++;
        }
        return 0;
    }
};