
int longestSubsequence(int n, int a[])
{
    set<int> curr;
    for(int i = 0; i < n ; i++){
        auto it = curr.lower_bound(a[i]);
        if(it != curr.end()) curr.erase(it);
        curr.insert(a[i]);
    
   }
   
   return curr.size();
}
