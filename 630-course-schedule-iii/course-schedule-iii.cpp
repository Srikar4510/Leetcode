class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // Step 1: Sort courses by lastDay (earliest deadline first)
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1]; 
        });

        priority_queue<int> maxHeap; // Max heap to track longest durations
        int totalTime = 0;

        // Step 2: Iterate over sorted courses
        for (auto &course : courses) {
            int duration = course[0];
            int lastDay = course[1];

            totalTime += duration;
            maxHeap.push(duration);

            // If total time exceeds lastDay, remove the longest course
            if (totalTime > lastDay) {
                totalTime -= maxHeap.top(); 
                maxHeap.pop(); 
            }
        }
        return maxHeap.size(); // Maximum number of courses that can be taken
    }
};
