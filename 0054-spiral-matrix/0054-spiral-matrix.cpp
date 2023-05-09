class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> ans;

    int rows = matrix.size();
    int cols = matrix[0].size();
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int i = left; i <= right; ++i)
            ans.push_back(matrix[top][i]);
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; ++i)
            ans.push_back(matrix[i][right]);
        right--;

        // Traverse from right to left
        if (top <= bottom) {
            for (int i = right; i >= left; --i)
                ans.push_back(matrix[bottom][i]);
            bottom--;
        }

        // Traverse from bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                ans.push_back(matrix[i][left]);
            left++;
        }
    }

    return ans;
    }
};