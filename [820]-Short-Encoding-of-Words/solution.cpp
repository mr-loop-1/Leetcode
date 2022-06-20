int minimumLengthEncoding(vector<string>& words) {
        
        // string s;
        
        sort(words.begin(), words.end(), [](string a, string b) {
            return a.size() > b.size();
        });
        // vector<string> suff;
        
        map<string, bool> has;
        
        int ans = 0;
        int count = 0;
        
        for(auto word: words) {
            int size = word.size();
            // cout << word << endl << endl;
            
            // bool flag = 1;
            // for(auto s: suff) {
            //     // cout << s << endl;
            //     if(s.substr(s.size()-size, size) == word) {
            //         flag = 0;
            //     }
            // }
            if(!(has.count(word))) {
            // if(flag) {
                // suff.push_back(word);
                
                ans += size;
                while(size--) {
                    has[word] = true;
                    word.erase(word.begin());
                }
                count++;
            }
            
        }
        
        return count+ans;
    }
