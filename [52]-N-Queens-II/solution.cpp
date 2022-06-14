int ans = 0;
    
    void queenHandler(int row, int n, vector<pair<int, int>> vec, set<int> col) {

        if(n==1) {
            ans = 1;
            return;
        }
        
        
        if(row == 0) {
            for(int i=0; i!=n; i++) {
                vec.push_back({0,i});
                auto it = (col.insert(i)).first;
                queenHandler(1, n, vec, col);
                col.erase(it);
                vec.pop_back();
            }
            return;
        }
        bool flag2 = 0;

        for(int i=0; i!=n; i++) {
            flag2 = 0;
            
            if(!col.count(i)) {
                for(auto v:vec) {
                    if(v.first-row)

                        if(abs(float(v.second-i)/float(v.first-row)) == 1) flag2 = 1;
                }
                
                // cout << "FLAG " << flag2 << endl;
                
                if(!flag2) {
                    vec.push_back({row, i});
                        
                    auto it = (col.insert(i)).first;
                        
                    if(row == n-1) {
                        // vector<string> item;
                        // for(auto vans: vec) {
                        //     string temp = string(vans.second,'.') + 'Q' + string(n-1-vans.second, '.');
                        //     cout << "temp " << temp << endl;
                        //     item.push_back(temp);
                        // }
                        // ans.push_back(item);
                        ans++;
                        col.erase(it);
                        vec.pop_back();
                        continue;
                    }
                    queenHandler(row+1, n, vec, col);
                    vec.pop_back();
                    col.erase(it);
                }
            }
        }

    }
    
    int totalNQueens(int n) {
        queenHandler(0, n, vector<pair<int,int>>{}, set<int>{});
        return ans;
    }
