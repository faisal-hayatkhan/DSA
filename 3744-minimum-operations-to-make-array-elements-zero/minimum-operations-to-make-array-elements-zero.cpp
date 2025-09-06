class Solution {
    long long func(long long l, long long r) {
        long long total = 0;
        long long base = 1;
        long long step = 1;

        while(base <= r) {
            long long low = base;
            long long high = min(base*4-1, r);

            if(high>=l) {
                long long left = max(l, low);
                long long right = high;

                long long temp = right - left + 1;
                total += (temp * step);
            }

            base*=4;
            step++;
        }
        return (total+1)/2;   // ceil(total/2);
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long totalCount=0;
        for(auto vec: queries) {
            totalCount += func(vec[0], vec[1]);
        }
        return totalCount;
    }
};