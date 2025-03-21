class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        // Step 1: Store available supplies in a set
        unordered_set<string> avaiableSupplies(supplies.begin(),supplies.end());

        // Step 2: Create mapping from recipe name to index
        int n = recipes.size();
        unordered_map<string,int> recipeToIndex;
        for(int i=0;i<n;i++){
            recipeToIndex[recipes[i]]=i;
        }

        // Step 3: Create an adjacency list and in-degree array
        unordered_map<string,vector<string>> adj;//ingridient to recipe
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto& ingredient:ingredients[i]){
                // If ingredient is not available, it becomes a dependency
                if(avaiableSupplies.find(ingredient)==avaiableSupplies.end()){
                    adj[ingredient].push_back(recipes[i]);
                    indegree[i]++;
                }
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<string> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            string recipe = recipes[node];
            ans.push_back(recipe);

            // If no recipe depends on this one, continue
            if(adj.count(recipe)==0) continue;
            
            // Reduce in-degree for dependent recipes
            for(auto& dependentRecipe:adj[recipe]){
                int idx = recipeToIndex[dependentRecipe];
                indegree[idx]--;

                if(indegree[idx]==0){
                    q.push(idx);
                }
            }
            
        }
        return ans;
    }
};