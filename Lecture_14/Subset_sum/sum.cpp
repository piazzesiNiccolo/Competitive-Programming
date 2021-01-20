int equalPartition(int N, int arr[])
    {
        int sum = accumulate(arr, arr+N, 0);
        if(sum % 2 != 0) return 0;
        sum /= 2;
        bool sol[N+1][sum+1];
        for(int i = 0; i <=N; i++ ) sol[i][0] = true;
        for(int j = 1; j <=sum; j++ ) sol[0][j] = false;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j<=sum;j++){
                sol[i][j] =  j < arr[i-1] ? sol[i-1][j] : 
                                            sol[i-1][j] || sol[i-1][j-arr[i-1]];
            }
        }
        return sol[N][sum];
    }