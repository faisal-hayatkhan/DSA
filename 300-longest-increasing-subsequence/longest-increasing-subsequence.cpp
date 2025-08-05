class Solution {
public:
    int BS(vector<int>& arr, int target){
        int n = arr.size();
        int st = 0, end = n - 1;
        int res = n;

        while(st <= end){
            int mid = st + (end - st) / 2;
            if(arr[mid] >= target){
                res = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return res;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(res.empty() || res.back() < nums[i]){
                res.push_back(nums[i]);
            } else {
                int idx = BS(res, nums[i]);
                res[idx] = nums[i]; 
            }
        }
        return res.size();
    }
};
