class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int alt=1,ans=0,lastcolor=colors[0];
        for(int i=0;i<n+2;i++){
             int index = i%n;
             if(colors[index]==lastcolor){
                alt=1;
                lastcolor=colors[index];
                continue;
             }
             alt+=1;
             if(alt>=3) ans++;
             lastcolor=colors[index];

        }
        return ans;
    }
};