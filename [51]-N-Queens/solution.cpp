vector<vector<string>> ans;
    
    void queenHandler(int row, int n, vector<pair<int, int>> vec, set<int> col) {
        // cout << "fresh row " << row << endl;
        // cout << "fresh vector" << endl;
        // for(auto v: vec) {
        //     cout << v.first << " " << v.second << " | ";
        // }
        // cout << endl;
        // cout << "fresh set" << endl;
        // for(auto c: col) {
        //     cout << c << " ,";
        // }
        // cout << endl;
        if(n==1) {
            ans.push_back({"Q"});
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
                        // cout << v.second-i << " " << v.first-row << endl;
                    // cout << abs((v.second-i)/(v.first-row)) << " " << ((v.second-i)/(v.first-row)) << endl;
                        if(abs(float(v.second-i)/float(v.first-row)) == 1) flag2 = 1;
                }
                
                // cout << "FLAG " << flag2 << endl;
                
                if(!flag2) {
                    vec.push_back({row, i});
                        
                    auto it = (col.insert(i)).first;
                        
                    if(row == n-1) {
                        vector<string> item;
                        for(auto vans: vec) {
                            string temp = string(vans.second,'.') + 'Q' + string(n-1-vans.second, '.');
                            cout << "temp " << temp << endl;
                            item.push_back(temp);
                        }
                        ans.push_back(item);
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
        
        // cout << "exiting row " << row << endl;
        // cout << "exiting vector" << endl;
        // for(auto v: vec) {
        //     cout << v.first << " " << v.second << " | ";
        // }
        // cout << endl;
        // cout << "exiting set" << endl;
        // for(auto c: col) {
        //     cout << c << " ,";
        // }
        // cout << endl;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        queenHandler(0, n, vector<pair<int,int>>{}, set<int>{});
        return ans;
    }
