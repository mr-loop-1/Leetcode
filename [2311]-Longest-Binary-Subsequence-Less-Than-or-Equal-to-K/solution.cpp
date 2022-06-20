int longestSubsequence(string s, int k) {
        
        int size = s.size();
        
        vector<int> zeroLeft(size, 0);
        
        for(int i=1; i!=size; i++) {
            if(s[i-1] == 0)
                zeroLeft[i] = zeroLeft[i-1]+1;
            else 
                zeroLeft[i] = zeroLeft[i-1];
        }
        
        int ans = 0;
        string ss;
        
        for(int i=size-1, j=size-1; i!=-1; i--) {
            
            bitset<32> bt(s[i]+ss);

            if(bt.to_ulong() > k) {
                bt = bitset<32>(ss);
            }
            else {
                ss = s[i]+ss;
            }
            
            ans = max(ans, zeroLeft[i]+(int)ss.size());
            
        }
        
        return ans;
        
    }
