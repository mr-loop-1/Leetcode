int minDistance(string word1, string word2) {
        
        vector<vector<int>> lcs(word1.size()+1, vector<int> (word2.size()+1, 0));
        
        // int prevM = 0;
        
        for(int i=1; i!=lcs.size(); i++) {
            // int temp = 0;
            for(int j=1; j!=lcs[0].size(); j++) {
                if(word1[i-1] == word2[j-1]) {
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                }
                else {
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
                // temp = max(temp, lcs[i][j]);
                // cout << temp << endl;
            }
            // prevM = temp;
        }
        
        // cout << lcs[word1.size()][word2.size()];
        
//         if (word1.size() == word2.size()) {
            
//         }
//         else if(word1.size() > word2.size()) {
            
//         }
        
        return word1.size() + word2.size() - 2*(lcs[word1.size()][word2.size()]);
    }
