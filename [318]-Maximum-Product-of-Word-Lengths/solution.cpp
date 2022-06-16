int maxProduct(vector<string>& words) {
        
        vector<int> m;
        for(auto x : words)
        {
            int mask = 0;
            for(auto y : x)
            {
                mask |= (1<<(y-'a'));
            }
            m.push_back(mask);
        }
        int maxi = 0;
        for(int i =0;i<m.size();i++)
        {
            for(int j = i+1 ; j < m.size();j++)
            {
                if((m[i] & m[j])==0)
                {
                    maxi = max((int)words[i].size()*(int)words[j].size(), maxi);
                }
            }
        }
        return maxi; 
    }
