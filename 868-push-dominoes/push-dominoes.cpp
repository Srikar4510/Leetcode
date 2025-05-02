class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> force(n, 0);

        // Left to right: handle 'R'
        int f = 0;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R') {
                f = n; // Maximum force
            } else if (dominoes[i] == 'L') {
                f = 0; // Left blocks rightward force
            } else {
                f = max(f - 1, 0); // Decay force
            }
            force[i] += f;
        }

        // Right to left: handle 'L'
        f = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') {
                f = n;
            } else if (dominoes[i] == 'R') {
                f = 0;
            } else {
                f = max(f - 1, 0);
            }
            force[i] -= f; // Subtract because L = negative force
        }

        // Build result
        string result;
        for (int f : force) {
            if (f == 0)
                result += '.';
            else if (f > 0)
                result += 'R';
            else
                result += 'L';
        }

        return result;
    }
};
