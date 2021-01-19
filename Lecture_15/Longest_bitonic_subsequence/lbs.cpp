int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
	    vector<int> lis(n);
	    vector<int> lds(n);
	    set<int> curr;
	    for(int i = 0; i < n; i++){
	        auto e = curr.lower_bound(nums[i]);
	        if (e != curr.end()) curr.erase(e);
	        curr.insert(nums[i]);
	        lis[i] = curr.size();
	    }
	    curr.clear();
	    for(int i = n-1; i >= 0; i--){
	        auto e = curr.lower_bound(nums[i]);
	        if (e != curr.end()) curr.erase(e);
	        curr.insert(nums[i]);
	        lds[i] = curr.size();
	    }
	    int sol = 0;
	    for(int i = 0; i < n; i++) sol = max(sol, lis[i] + lds[i] - 1);
	    return sol;
	}