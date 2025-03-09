class Solution {
public:
//O(n+k),O(1)
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int lastcolor = colors[0];
        int alt= 1;
        int ans =0;
        for(int i=1;i<n+k-1;i++){
            int index = i%n;
            if(colors[index]==lastcolor){
                alt = 1;
                lastcolor = colors[index];
                continue;
            }

            alt+=1;
            if(alt>=k){
                ans++;
            }
            lastcolor = colors[index];
        }
        return ans;
    }
};