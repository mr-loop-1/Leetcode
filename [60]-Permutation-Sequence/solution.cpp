vector<int> flook;
    
    int fact(int n) {
        if(n==1)
            return 1;
        int f = n*fact(n-1);
        flook.push_back(f);
       // cout << f << endl;
        return f;
    }
    
//     int findrank(int n, int k) {
//         for(int i=n-2; i!=-1; i++) {
//             if(flook[i] < k)
//                 return flook[i];
//         }
//     }
    
    string getPermutation(int n, int k) {
        
        if(n==1)
            return "1";
        else if(n==2) {
            if(k==1)
                return "12";
            else 
                return "21";
        }

        vector<int> stock;
        for(int i=0; i!=n; i++) {
            stock.push_back(i+1);
        }
        
        fact(n);
        string s;
        
        if(flook[n-2] == k) {
            for(int i=n-1; i!=-1; i--)
                s += i+'1';
            return s;
        }
        
        int q;
        
        for(int i=0, j=n-3; stock.size(); i++, j--) {
           // div = findrank(n, k);
         //   cout << s << endl;
            
            if(flook[j] < k) {
                q = k/flook[j];
                k = k%flook[j];
                
                if(k!=0) {
                    s+=stock[q] + '0';
                    stock.erase(stock.begin()+q);
                }
                else {
                    s+=stock[q-1] + '0';
                    stock.erase(stock.begin()+q-1);
                }
            }
            else if(flook[j] > k) {
                s+= stock[0] + '0';
                stock.erase(stock.begin());
            }
            else {
                s+= stock[0] + '0';
                stock.erase(stock.begin());
                
                for(auto z=stock.end()-1; stock.size(); z--) {
                    s+= (*z) + '0';
                    stock.erase(stock.end()-1);
                }
                break;
            }
            
            if(k == 1) {
                for(int z=i; stock.size(); z++) {
                    s+=stock[0] + '0';
                    stock.erase(stock.begin());
                }
                break;
            }
            if(k == 0) {
                for(auto z=stock.end()-1; stock.size(); z--) {
                    s+= (*z) + '0';
                    stock.erase(stock.end()-1);
                }
                break;
            }
                    
            
        }
        
         return s;
    }
