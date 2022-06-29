vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        list<vector<int>> dyn;
        
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) {
            if(a[0] > b[0]) return true;
            else if(a[0] == b[0] && a[1]<b[1]) return true;
            return false;
        });
            
        // for(auto p: people) cout << p[0] << " " << p[1] << endl;
        
        for(int i=0; i!=people.size(); i++) {
            // cout << "here" << endl;
            auto it = dyn.begin();
            std::advance(it,people[i][1]);
            // auto it = dyn.begin() + people[i][1];
            dyn.insert(it, people[i]);
        }
        
        vector<vector<int>> ans(dyn.begin(), dyn.end());
        
        return ans;
        
    }
