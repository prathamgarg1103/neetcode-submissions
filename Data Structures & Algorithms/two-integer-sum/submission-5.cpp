class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>> v;

        for(int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        int low = 0;
        int high = v.size() - 1;

        while(low < high) {

            int sum = v[low].first + v[high].first;

            if(sum == target) {
                int i = v[low].second;
                int j = v[high].second;

                if(i > j) swap(i, j);

                return {i, j};
            }

            else if(sum > target) {
                high--;
            }

            else {
                low++;
            }
        }

        return {};
    }
};