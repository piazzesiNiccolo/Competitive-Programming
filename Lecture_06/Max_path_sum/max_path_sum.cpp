/*
NOTE: this wont work on his own. This code was written as a solution for the corresponding problem formulation on geeksforgeeks, and
therefore needs the auxiliary code provided by the site
*/


int maxSum(Node* n,int &maxsum){
    if(n == NULL){
        return 0;
    }
    else {
        if(n->right&&n->left){
            int l = maxSum(n->left,maxsum);
            int r = maxSum(n ->right, maxsum);
            maxsum = std::max(maxsum, l+r+n->data);
            return n->data + max(l,r);
        }   
}      

int maxPathSum(Node* root)
{   
    int maxsum = INT_MIN;
    maxSum(root,maxsum);
    return maxsum;
}


