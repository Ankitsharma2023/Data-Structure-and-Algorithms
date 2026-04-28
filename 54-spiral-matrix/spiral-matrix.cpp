class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        int srow = 0;       
        int erow = m - 1;    
        int scol = 0;        
        int ecol = n - 1;    

        vector<int> result;

        while (srow <= erow && scol <= ecol) { //equal to for odd matrix 

            //  1. Traverse TOP row (left → right)
            // Fix row = srow, vary column from scol → ecol
            for (int j = scol; j <= ecol; j++) {
                result.push_back(matrix[srow][j]);
            }

            //  2. Traverse RIGHT column (top → bottom)
            // Fix column = ecol, vary row from srow+1 → erow
            // (srow already used in top row)
            for (int i = srow + 1; i <= erow; i++) {
                result.push_back(matrix[i][ecol]);
            }

            //  3. Traverse BOTTOM row (right → left)
            // Only if there is more than one row
            // Otherwise we would duplicate the same row
            for (int j = ecol - 1; j >= scol; j--) {
                if (srow == erow) continue;  // odd matrix case,single row case → skip,as top has traverse already 
                result.push_back(matrix[erow][j]);
            }

            //  4. Traverse LEFT column (bottom → top)
            // Only if there is more than one column
            // Otherwise we would duplicate the same column
            for (int i = erow - 1; i >= srow + 1; i--) {
                if (scol == ecol) continue;  // odd matrix,case single column case → skip, as right travser already 
                result.push_back(matrix[i][scol]);
            }

            //  Move boundaries inward (shrink the layer)
            srow++; 
            scol++; 
            erow--;  
            ecol--;  
        }

        return result;
    }
};

//corner case when shrinking leads to => 1 × N → single row
// M × 1 → single column