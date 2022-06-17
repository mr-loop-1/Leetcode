int count;
    
    // True - needs camera
    // False - doesn't need camera
    
    // 0 - not needed
    // 1 - 
    
    int inorder(TreeNode* node) {
        
        if(!node) {
            return 1;
        }
        
        // cout << (bool)node->left << " " << (bool)node->right << endl;

        int f1 = inorder(node->left);
        int f2 = inorder(node->right);

        if(!f1 || !f2) {
            count++;
            return 2; 
        }
        else if(f1==2 || f2==2) {
            return 1;
        }
        return 0;
        
    }
    
    int minCameraCover(TreeNode* root) {
        
        if(!root->left && !root->right) return 1;
        
        count = 0;
        if(!inorder(root)) count++;
        return count;
        
    }
