class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string>ans;

        if(n==0) return ans;

        for(int i=0; i<n;i++){
            int low=i;
            
            while(i+1<n && nums[i]+1== nums[i+1]){
                i++;
            }

            int high=i;

            if(low==high){
                 ans.push_back(to_string(nums[low]));
            }
            else{
                ans.push_back(to_string(nums[low])+"->"+ to_string(nums[high]));
            }
        }
        return ans;
    }
};