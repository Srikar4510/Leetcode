class Solution {
public:
    double calculateGain(int p,int t){
        double before = (double)p/t;
        double after = (double)(p+1)/(t+1);
        return after - before;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>> maxheap;

        for(auto& c:classes){
            int p = c[0];
            int t =c[1];

            double g = calculateGain(p,t);
            maxheap.push({g,{p,t}}); 
        }

        while(extraStudents>0){
            auto topClass = maxheap.top();
            maxheap.pop();

            int p = topClass.second.first;
            int t = topClass.second.second;

            p += 1;
            t += 1;

            double newGain = calculateGain(p,t);
            maxheap.push({newGain,{p,t}});

            extraStudents--;
        }

        double totalRatio = 0.0;
        int n = classes.size();

        while(!maxheap.empty()){
            auto topClass = maxheap.top();
            maxheap.pop();

            int p = topClass.second.first;
            int t = topClass.second.second;
            totalRatio += (double)p/t; 
        }

        return totalRatio/n;
    }
};