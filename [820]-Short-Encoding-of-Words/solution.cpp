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

            if(!(has.count(word))) {

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
