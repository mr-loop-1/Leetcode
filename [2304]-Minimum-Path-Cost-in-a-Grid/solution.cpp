int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        // ans = INT_MAX;
        int totRow = grid.size();
        int totCol = grid[0].size();
        
        
        vector<int> reach = grid[0];
        
        
        for(int i=0; i!=totRow-1; i++) {
            // for(auto r: reach) {
            //     cout << r << " ";
            // }
            
            vector<int> temp(totCol, INT_MAX);
            for(int j=0; j!=totCol; j++) {
                for(int to=0; to!=totCol; to++) {
                    temp[to] = min(temp[to], moveCost[grid[i][j]][to] + grid[i+1][to] + reach[j]);
                }
            }
            reach = temp;
            
        }
        
        // for(auto r: reach) {
        //     cout << r << " ";
        // }
        
        
        
//         for(int i=0; i!=grid[0].size(); i++) {
//             for(int newC = 0; newC!=totCol; newC++) {
//                 if((moveCost[grid[0][i]][newC] + grid[0][i]) >= ans) {
//                 continue;
//             }
//                 recur(1, newC, moveCost[grid[0][i]][newC]+grid[0][i], grid, moveCost);
//             }
//         }
        
        return *min_element(reach.begin(), reach.end());
    }
