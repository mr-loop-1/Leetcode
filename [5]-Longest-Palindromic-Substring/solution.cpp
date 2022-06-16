string longestPalindrome(string s) {
        
        if(s.size()==1) return s;
        
        map<char, vector<int>> mp;
        
        // for(auto c:s) mp[c]++;
        
        for(int i=0; i!=s.size(); i++) {
            mp[s[i]].push_back(i);
        }
        
        vector<int> markIdx(s.size(), -1);
        vector<int> mark(s.size(), 2);
        
        string ans;
        
        for(int i=0; i!=s.size()-1; i++) {
            vector<int> temp = mp[s[i]];
            for(int m = temp.size()-1; m!=-1; m--) {
                int j = temp[m];
                
                // cout << i << " " << j << endl;
                
                if(j<=i) break;
                if(ans.size() > (j-i+1)) break;
                
                if(j==i+1) {
                    ans = s.substr(i, j-i+1);
                        mark[i] = 1;
                        markIdx[i] = j;
                        break;
                }
                
                // Now we have [i ... j] space.
                // [i 2 2 0 ...     j] if 0'd element has bouncing index in range of i...j break
                // if j-i < ans.size break
                // if find palind, cmp and store in ans and break
                
                // int halfEle = ()
                
                for(int k=i+1; k!=i+((j-i)/2)+1; k++) {
                    // cout << "0" << endl;
                    if(mark[k]==0 && markIdx[k]==(j-k+i)) {
                        // cout << "1" << endl;
                        mark[i] = 0;
                        markIdx[i] = j;
                        break;
                    }
                    else if(mark[k]==1 && markIdx[k]==(j-k+i)) {
                        // cout << "2" << endl;
                        ans = s.substr(i, j-i+1);
                        mark[i] = 1;
                        markIdx[i] = j;
                        break;
                    }
                    
                    if (s[k] != s[j-k+i]) {
                        // cout << "3" << endl;
                        mark[i] = 0;
                        markIdx[i] = j;
                        break;
                    }
                    if(k==i+((j-i)/2)) {
                        // cout << "4" << endl;
                        ans = s.substr(i, j-i+1);
                        mark[i] = 1;
                        markIdx[i] = j;
                    }
                }
                
                
            }
        }
        
        if(ans=="") return string(1, s[0]);
        
        return ans;
    }
