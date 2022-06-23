int findKthLargest(vector<int>& nums, int k) {
        
        // set<int> has;
        priority_queue<int, vector<int>, greater<int>> pool;
        
        int size = nums.size();
        
        int ans;
        
        for(int i=0; i!=size; i++) {
            
//             if(!has.count(nums[i])) {
                
                pool.push(nums[i]);
                
                if(pool.size() == k+1) {
                    // cout << pool.top() << endl;
                    pool.pop();
                }
                
//                 has.insert(nums[i]);
//             }
        }
        
        ans = pool.top();
        
        return ans;
    }
