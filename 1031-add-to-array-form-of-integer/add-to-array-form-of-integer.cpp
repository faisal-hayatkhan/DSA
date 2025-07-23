class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        if(k==0) return num;
        int i = num.size()-1;
        int carry =0;
        while(i>=0 || carry>0 || k>0){
            int m = k%10;
            int l = (i>=0 ? num[i] : 0)+m+carry;
            if(i>=0)
                num[i] =  l%10;
            else
                num.insert(num.begin(),l%10);
            carry = l/10;
            k/=10;
            i--;
        } 
        return num;
    }
};