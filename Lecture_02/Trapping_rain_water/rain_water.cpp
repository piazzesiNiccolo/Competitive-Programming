int trappingWater(int arr[], int n){
    
    int left_max[n], right_max[n];
    int maxH = 0, rain = 0;
    for (int i = 0; i< n; i++){
        maxH = max(maxH, arr[i]);
        left_max[i] = maxH;
    }
    maxH = 0;
    for(int j = n-1; j >= 0; j--){
        maxH = max(maxH, arr[j]);
        right_max[j] = maxH;
    }
    for(int i = 0; i < n; i++){
        rain += min(left_max[i], right_max[i]) - arr[i];
        
    }
    return rain;
    
}