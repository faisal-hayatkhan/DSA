class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v;

        int i1 = 1;
        int j1 = -1;
        if (n == 1) {
            return {0};
        }
        if (n % 2 == 0) {
            for (int i = n; i > 0; i -=2) {
                v.push_back(i1);
                v.push_back(j1);
                i1++;
                j1--;
            }
        } else {
            v.push_back(0);
            for (int i = n; i > 1; i-=2) {
                v.push_back(i1);
                v.push_back(j1);
                i1++;
                j1--;
            }
        }

        return v;
    }
};