int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string a, string b) {
            return a.size() < b.size();
        });
        
        vector<vector<int>> adj(words.size());
        
        for(int i=0, j=0; i!=words.size(); i++, j=i) {
            
            while(words[j].size()!=words[i].size()-1) {
                j--;
                if(j == -1) break;
            }
            
            if(j==-1) continue;
            
            // cout << j << endl;
            
            while(words[j].size() == words[i].size()-1) {
                // if(j == words.size()-1) break;
                
                int flag = 0;
                
                for(int l=0, k=0; l!=words[i].size(); l++, k++) {
                    if(words[i][l] != words[j][k]) {
                        if(l==k) k--;
                        else {
                            flag = 1; break;
                        }
                    }
                }
                
                // cout << words[i] << " " << words[j] << " " << flag << endl;
                
                if(!flag) adj[i].push_back(j);
                // cout << adj[i].back() << endl;
                
                j--;
                if(j == -1) break;
            }
        }
        
        
        // for(auto a:adj) {
        //     for(auto j:a) cout << j << " ";
        //     cout << endl;
        // }
        
        vector<int> val(words.size(), 0);
        
        for(int i=0; i!=adj.size(); i++) {
            if(adj[i].empty()) val[i] = 1;
            else {
                for(auto j: adj[i]) {
                    val[i] = max(val[i], val[j]+1);
                }
            }
        }
        
        return *max_element(val.begin(), val.end());
        
    }
