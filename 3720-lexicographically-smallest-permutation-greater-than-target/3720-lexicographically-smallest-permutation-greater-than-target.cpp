class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // Frequency of characters in s
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = "";

        // Try every position as the first position
        // where our answer becomes greater than target.
        for (int i = n - 1; i >= 0; i--) {

            // We need to construct target[0 ... i-1] exactly.
            vector<int> cnt = freq;
            string prefix = "";
            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (cnt[x] == 0) {
                    possible = false;
                    break;
                }

                prefix += target[j];
                cnt[x]--;
            }

            if (!possible)
                continue;

            // At position i, choose the smallest
            // available character strictly greater than target[i].
            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                string cur = prefix;
                cur += char('a' + c);
                cnt[c]--;

                // Fill remaining positions with smallest chars
                for (int k = 0; k < 26; k++) {
                    while (cnt[k] > 0) {
                        cur += char('a' + k);
                        cnt[k]--;
                    }
                }

                return cur;
            }
        }

        return "";
    }
};