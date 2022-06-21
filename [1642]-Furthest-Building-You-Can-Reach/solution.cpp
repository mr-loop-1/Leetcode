int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int size = heights.size();
        vector<int> diff(size-1);
        
        // for(int i=1; i!=size; i++) {
        //     diff[i-1] = heights[i] - heights[i-1];
        // }
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=1; i!=size; i++) {
            
            if(heights[i] > heights[i-1]) {
            
            pq.push(heights[i] - heights[i-1]);
            
            if(pq.size() > ladders) {
                bricks -= pq.top();
                // cout << pq.top() << endl;
                pq.pop();
                
                if(bricks < 0) return i-1;
            }
                
            }
        }
        
        return size-1;
        
    }
