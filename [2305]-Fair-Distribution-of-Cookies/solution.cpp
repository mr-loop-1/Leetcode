class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        
        if(cookies.size() == k) {
            return *max_element(cookies.begin(), cookies.end());
        }
        
        int low = *max_element(cookies.begin(), cookies.end());
        int high = accumulate(cookies.begin(), cookies.end(), 0);
        
        sort(cookies.begin(), cookies.end());
        
        int ans = high;
        
        while(low <= high) {
            int mid = (low+high)/2;

            int tsum = 0, count = 1;
            bool flag = false;
            
            for(int i=0; i!=cookies.size(); i++) {
                
                if((tsum+cookies[i]) > mid) {
                    count++;
                    tsum = cookies[i];
                }
                else {
                    tsum += cookies[i];
                }
                
                if(count==k+1) {
                    flag = true;
                    break;
                }

            }

            if(flag)
                low = mid+1;
            else {
                ans = min(ans, mid);
                high = mid-1;
            }
        }
        
        while(next_permutation(cookies.begin(), cookies.end())) {
            // cout << "here" << endl;
            low = *max_element(cookies.begin(), cookies.end());
        high = accumulate(cookies.begin(), cookies.end(), 0);
        while(low <= high) {
            int mid = (low+high)/2;

            int tsum = 0, count = 1;
            bool flag = false;
            
            for(int i=0; i!=cookies.size(); i++) {
                
                if((tsum+cookies[i]) > mid) {
                    count++;
                    tsum = cookies[i];
                }
                else {
                    tsum += cookies[i];
                }
                
                if(count==k+1) {
                    flag = true;
                    break;
                }

            }

            if(flag)
                low = mid+1;
            else {
                ans = min(ans, mid);
                high = mid-1;
            }
        }
        }
        return ans;
    }
};
