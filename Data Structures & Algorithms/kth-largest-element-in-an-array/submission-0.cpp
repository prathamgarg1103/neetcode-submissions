class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>q;
        for(auto it:nums)q.push(it);
        int x=0;
        while(k--){
             x=q.top();
            q.pop();
        }return x;
    }
};
