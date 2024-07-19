class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> min_row, max_col(matrix[0].size(), INT_MIN);
        
        // Find the minimum in each row
        for (const auto& row : matrix) {
            min_row.push_back(*min_element(row.begin(), row.end()));
        }
        
        // Find the maximum in each column
        for (int j = 0; j < matrix[0].size(); ++j) {
            for (int i = 0; i < matrix.size(); ++i) {
                max_col[j] = max(max_col[j], matrix[i][j]);
            }
        }
        
        // Find the lucky numbers
        vector<int> lucky_numbers;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == min_row[i] && matrix[i][j] == max_col[j]) {
                    lucky_numbers.push_back(matrix[i][j]);
                }
            }
        }
        
        return lucky_numbers;
    }
};
