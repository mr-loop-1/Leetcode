vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        int size = searchWord.size();
        
        sort(products.begin(), products.end());
        
        vector<vector<string>> ans(size);
        // cout << ans.size() << endl;
        
        // set<int> index;
        // for(auto p:products) {
        //     index.insert(p);
        // }
        
        for(int i=0; i!=size; i++) {
            
            // cout << "i " << i << endl;
            
            // string s = searchWord.substr(0, i+1); 
            char c = searchWord[i];
            
            // cout << "s " << s << endl;

            vector<string> temps;
            
            for(auto str:products) {
                
                // cout << str[i] << " " << c << endl;
                if(str[i] == c){

                    temps.push_back(str);
                    
                }
            }
            // cout << temps.size() << endl;
            
            vector<string> temp;
            for(int i=0; i!=3 && i!=temps.size(); i++)
                temp.push_back(temps[i]);
            
            ans[i] = temp;
            
            products = temps;
        }
        
        return ans;
    }
