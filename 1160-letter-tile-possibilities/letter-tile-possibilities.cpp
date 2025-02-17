class Solution {
public:
    void backtrack(const string &tiles,string current,set<string> &ans){
        if(!current.empty()){
            ans.insert(current);
        }
        for(int i=0;i<tiles.size();i++){
            if(i>0 && tiles[i]==tiles[i-1]){
                continue;
            }
            backtrack(tiles.substr(0,i)+tiles.substr(i+1),current+tiles[i],ans);
        }
    }
    int numTilePossibilities(string tiles) {
        set<string> ans;
        backtrack(tiles,"",ans);
        return ans.size();
    }
};