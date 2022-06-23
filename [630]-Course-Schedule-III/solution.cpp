int scheduleCourse(vector<vector<int>>& courses) {
        
        int size = courses.size();
        
        sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });

        priority_queue<int, vector<int>, less<int> > pq; 
        
        int count = 0;
        int time = 0;
        
        for(int i=0; i!=size; i++) {
            
            if(courses[i][0]<=courses[i][1]) {

                if(time+courses[i][0] <= courses[i][1]) {

                    count++;
                    time += courses[i][0];
                    pq.push(courses[i][0]);
                }
                else if(!pq.empty()) {

                    if(time-pq.top()+courses[i][0] <= courses[i][1] && pq.top() > courses[i][0]) {
                        time -= pq.top();
                        time += courses[i][0];
                        pq.pop();
                        pq.push(courses[i][0]);
                    }
                }
            }
        
        }
        
        return count;
        
    }
