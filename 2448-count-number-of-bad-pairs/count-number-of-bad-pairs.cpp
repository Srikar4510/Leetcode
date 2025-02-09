class Solution {
public:
    /*
    Time Complexity: O(N) 
    - We iterate through the array once, performing O(1) operations per element.

    Space Complexity: O(N) 
    - We use an unordered_map to store differences, which in the worst case can store all N elements.
    */
    long long countBadPairs(vector<int>& nums) {
        long long goodPairs = 0, badPairs = 0;
        unordered_map<int, int> diffCount; // Stores frequency of (index - nums[index])

        /*
        We iterate over the array and compute a unique "difference" value for each index:
            diff = index - nums[index]
        If two elements have the same diff value, they satisfy the condition:
            j - i == nums[j] - nums[i]
        This means they form a "good pair".
        */

        for (int pos = 0; pos < nums.size(); pos++) {
            int diff = pos - nums[pos]; // Compute the difference for the current index
            
            /*
            The number of good pairs that can be formed with nums[pos] is the count of 
            previous elements that had the same difference (stored in diffCount[diff]).
            */
            goodPairs = diffCount[diff]; 

            /*
            The number of bad pairs formed with nums[pos] is calculated as:
                total elements seen so far (pos) - goodPairs
            Because every previous element (0 to pos-1) forms a pair with pos,
            and only goodPairs among them are valid, the rest must be bad pairs.
            */
            badPairs += pos - goodPairs; 

            /*
            Update the frequency of the current difference in the map,
            so that future elements can check for good pairs.
            */
            diffCount[diff]++;
        }
        
        return badPairs;
    }
};
