int minJumps(int arr[], int n){
    int maxJump = arr[0];
    int steps = arr[0];
    int jumps = 1;
    for(int i =0; i < n-1;i++){
        maxJump = max(maxJump, arr[i] + i);
        if(maxJump == i) return -1;
        else if(steps <= 0){
            jumps++;
            steps = maxJump -i;
        }
        steps--;
    }
    return jumps;
}