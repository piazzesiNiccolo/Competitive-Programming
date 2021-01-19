bool compare(const pair<int, int> &m1, const pair<int, int> &m2){
    return m1.second != m2.second ? m1.second < m2.second :
                        m1.first < m2.first;
}
int maxMeetings(int start[], int end[], int n) {
    // Your code here
    vector<pair<int, int>> meetings(n);
    for(int i = 0; i < n; i++){
        meetings[i] = make_pair(start[i], end[i]);
    }
    sort(meetings.begin(), meetings.end(), compare);
    int sum = 1;
    int curr_end = meetings[0].second;
    for(int i = 1; i < n; i++){
        if(meetings[i].first > curr_end){
            sum++;
            curr_end = meetings[i].second;
        }
    }
    return sum;
}