vector<int> avoidFlood(vector<int>& rains) {
        
        map<int, int> full;
        
        // vector<int> fullIdx;
        
        // queue<int> dryIdx;
        list<int> dryIdx;
        
        vector<int> ans(rains.size());
        
        for(int i=0; i!=rains.size(); i++) {

            if(rains[i] > 0) {
                ans[i] = -1;

                if(full.count(rains[i])) {
                    // int fullIdx = (*found).second;
                    int fullIdx = full[rains[i]];
                    
                    // cout << fullIdx << endl;
                    auto toFound = lower_bound(dryIdx.begin(), dryIdx.end(), fullIdx);
                    
                    if(toFound != dryIdx.end()) {
                        ans[*toFound] = rains[i];
                        dryIdx.erase(toFound);
                    }
                    else return {};
                }
                full[rains[i]] = i;
            }
            
            if(rains[i] == 0) {
                ans[i] = 1;
                dryIdx.push_back(i);
            }
            
            
//             for(auto p: full) {
//                 cout << p.first << " " << p.second << " | ";
//             }
//             cout << endl;
//             for(auto d:dryIdx) {
//                 cout << d << " ";
//             }
//             cout << endl;
        }
        
        return ans;
    }
