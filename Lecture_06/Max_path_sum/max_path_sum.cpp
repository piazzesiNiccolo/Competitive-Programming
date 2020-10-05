#include <iostream>
#include <algorithm>

int maxSum(Node* n,int &maxsum){
    if(n == NULL){
        return 0;
    }
    if(n->right&&n->left){
        int l = maxSum(n->left,maxsum);
        int r = maxSum(n ->right, maxsum);
        maxsum = std::max(maxsum, l+r+n->data);
        return n->data + max(l,r);
    }
    return (!n->left)?  maxSum(n ->right, maxsum) + n->data: 
                        maxSum(n ->left, maxsum) + n->data; 
        
}      

int maxPathSum(Node* root)
{   
    int maxsum = INT_MIN;
    maxSum(root,maxsum);
    return maxsum;
}


