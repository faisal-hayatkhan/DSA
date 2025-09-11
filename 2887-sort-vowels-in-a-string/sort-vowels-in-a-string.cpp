class Solution {
public:
    bool is_vowel(char ch) {
        if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'o' ||
            ch == 'O' || ch == 'i' || ch == 'I' || ch == 'u' || ch == 'U')
            return true;
        return false;
    }
    string sortVowels(string s) {
        int n = s.size();
        vector<char> vowel;
        vector<char> arr(n,'/0');
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!is_vowel(s[i])) {
                arr[i] = s[i];
            } else {
                vowel.push_back(s[i]);
                q.push(i);
            }
        }
        sort(vowel.begin(), vowel.end());
        int i = 0;
        while (q.size() != 0) {
            int idx = q.front();
            q.pop();
            arr[idx] = vowel[i];
            i++;
        }
        string result;
        for (auto ele : arr) {
            result += ele;
        }
        return result;
    }
};