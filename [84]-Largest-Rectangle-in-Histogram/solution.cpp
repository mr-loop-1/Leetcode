int largestRectangleArea(vector<int>& arr) {
        int len[arr.size()];
    // stack<pair<long long, int>> nextg;
    stack<pair<int, int>> nextg;
    nextg.push({0, 0});
    for (int i = 1; i != arr.size(); i++)
    {
        // cout << arr[i] << " " << arr[nextg.top().first] << endl;
        if (arr[i] >= arr[nextg.top().first])
        {
            nextg.push({i, 0});
            // cout << "1push " << i << endl;
        }
        else
        {
            int carry = 0;
            int j;
            for (j = 0; nextg.size() && arr[i] < arr[nextg.top().first]; j++)
            {
                pair<int, int> popped = nextg.top();
                len[popped.first] = j + carry;
                // cout << "carry " << popped.first << " " << carry << " " << j << endl;
                carry += popped.second;
                // cout << "carrynew " << carry << endl;
                nextg.pop();
            }
            nextg.push({i, j + carry});
            // cout << "2push " << i << " " << j << endl;
        }
    }
    // len[n - 1] = 0;
    int carry = 0;
    for (int j = 0; nextg.size(); j++)
    {
        pair<int, int> popped = nextg.top();
        len[popped.first] = j + carry;
        carry += popped.second;
        nextg.pop();
    }

    // cout << "asd " << endl;
    // for (int i = 0; i != n; i++)
    // {
    //     cout << len[i] << endl;
    // }

    stack<pair<int, int>> prevs;
    prevs.push({arr.size() - 1, 0});

    for (int i = arr.size() - 2; i != -1; i--)
    {
       // cout << arr[i] << " " << arr[prevs.top().first] << endl;
        if (arr[i] >= arr[prevs.top().first])
        {
            prevs.push({i, 0});
          //  cout << "1push " << i << endl;
        }
        else
        {
            carry = 0;
            int j;
            for (j = 0; prevs.size() && arr[i] < arr[prevs.top().first]; j++)
            {
                pair<int, int> popped = prevs.top();
                len[popped.first] += j + carry;
               // cout << "carry " << popped.first << " " << carry << " " << j << endl;
                carry += popped.second;
               // cout << "carrynew " << carry << endl;
                prevs.pop();
            }
            prevs.push({i, j + carry});
           // cout << "2push " << i << " " << j << endl;
        }
    }
   // cout << "end" << endl;

    carry = 0;
    for (int j = 0; prevs.size(); j++)
    {
        pair<int, int> popped = prevs.top();
       // cout << popped.first << " " << popped.second << " " << carry << endl;
        len[popped.first] += j + carry;
        carry += popped.second;
        prevs.pop();
    }

    // cout << "asd " << endl;
    // for (int i = 0; i != n; i++)
    // {
    //     cout << len[i] << endl;
    // }

    int maximum = arr[0] * (len[0] + 1);
    for (int i = 0; i != arr.size(); i++)
    {
        maximum = max(maximum, arr[i] * (len[i] + 1));
    }

    return maximum;
    }
