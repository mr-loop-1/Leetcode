int pivotIndex(vector<int>& nums) {
        
        int size = nums.size();
        
        vector<int> sum(size+1);
        
        sum[0] = 0;
        sum[1] = nums[0];
        for(int i=1; i!=size; i++) {
            sum[i+1] = sum[i] + nums[i];
        }
        
        for(int i=1; i!=size+1; i++) {
            
            // cout << sum[i] << " " << sum[size] << endl;
            
            if(sum[i-1] == (sum[size]-sum[i]))
                return i-1;
        }
        
        return -1;
    }
