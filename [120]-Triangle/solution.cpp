int minimumTotal(vector<vector<int>>& triangle) {
        
        // int ans = triangle[0][0];
        vector<int> ans = {triangle[0][0]};
        
        for(int i=1; i!=triangle.size(); i++) {
            
            vector<int> temp(triangle[i].size(), INT_MAX);
            
            for(int j=0; j!=triangle[i-1].size(); j++) {
                temp[j] = min(temp[j], ans[j]+triangle[i][j]);
                temp[j+1] = min(temp[j+1], ans[j]+triangle[i][j+1]);
            }
            
            ans = temp;
        }
        
        return *min_element(ans.begin(), ans.end());
    }
