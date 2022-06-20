int minimumNumbers(int num, int k) {
        if(num == 0) {
            return 0;
        }
        
        vector<int> mult(10);
        
        for(int i=0; i!=10; i++)
            mult[i] = k*(i+1);
        
        int flag = -1;
        for(int i=0; i!=10; i++) {
            // cout << mult[i] << endl;
            if((mult[i]%10) == num%10) {
                if(mult[i] > num) return -1;
                return (i+1);
            }
        }
        
        return -1;
    }
