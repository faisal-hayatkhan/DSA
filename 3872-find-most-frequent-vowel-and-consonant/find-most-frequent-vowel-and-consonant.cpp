class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26] = {};
        for (char c : s) freq[c - 'a']++;

        int maxVowel = 0, maxCons = 0;
        for (int i = 0; i < 26; ++i) {
            char ch = 'a' + i;
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                maxVowel = max(maxVowel, freq[i]);
            else
                maxCons = max(maxCons, freq[i]);
        }
        return maxVowel + maxCons;
    }
};