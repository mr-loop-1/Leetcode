
class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node == NULL) {
            // Node* temp = new Node(1);
            return NULL;
        }
        
        map<int, Node*> mp;         // address of node
        // map<int, bool> mpV;
        
        queue<int> toVis;
        queue<Node*> source;
        
        toVis.push(1);
        source.push(node);
        
        Node* ans = new Node(1);
        mp.insert({1, ans});
        
        while(!toVis.empty()) {
//             int curr = toVis.front();
//             toVis.pop();
//             mp.insert({curr, true});
            Node* nee = source.front();
            source.pop();
            
            vector<Node*> temp;
            
            for(auto to: nee->neighbors) {
                
                // cout << "to " << to->val << endl;
                
                if(!mp.count(to->val)) {
                    Node* tNode = new Node(to->val);
                    mp.insert({to->val, tNode});
                    toVis.push(to->val);
                    source.push(to);
                }
                temp.push_back(mp[to->val]);
            }
            
            // Node* n = new Node(toVis.front(), temp);
            mp[toVis.front()]->neighbors = temp;
            
            toVis.pop();
            
            // node = 

        }
        
        return ans;
    }
};
