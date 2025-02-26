#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // Step 1: Sort the courses based on their lastDay (earliest deadline first)
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Sort by lastDay in ascending order
        });

        // Step 2: Max Heap (priority_queue) to store course durations
        priority_queue<int> maxHeap; 
        int totalTime = 0; // Tracks the total time spent on selected courses

        // Step 3: Iterate over all courses
        for (const auto& course : courses) {
            int duration = course[0]; // Time required to complete this course
            int lastDay = course[1];  // Deadline to complete this course

            // Add this course to our schedule
            totalTime += duration;
            maxHeap.push(duration); // Store this course in the max heap

            // If total time exceeds the deadline, remove the longest duration course
            if (totalTime > lastDay) {
                int longestCourse = maxHeap.top(); // Get the longest duration course
                maxHeap.pop(); // Remove it from our selected courses
                totalTime -= longestCourse; // Adjust total schedule time
            }
        }

        // Step 4: The size of the maxHeap represents the maximum courses we can take
        return maxHeap.size();
    }
};
