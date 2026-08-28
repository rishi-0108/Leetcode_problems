class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);
        for (char ch : s) count[ch - 'a']++;

        int oddCount = 0, oddChar = -1;
        for (int c = 0; c < 26; c++)
            if (count[c] % 2 == 1) { oddCount++; oddChar = c; }

        bool nOdd = (n % 2 == 1);
        if ((nOdd && oddCount != 1) || (!nOdd && oddCount != 0)) return "";

        int h = n / 2;
        vector<int> half(26, 0);
        for (int c = 0; c < 26; c++) half[c] = count[c] / 2;
        char m = nOdd ? char('a' + oddChar) : 0;

        vector<int> avail = half;
        vector<vector<int>> snap(h);
        bool tieOk = true;
        int breakFree = -1;

        for (int i = 0; i < h; i++) {
            snap[i] = avail;
            int c = target[i] - 'a';
            if (avail[c] > 0) avail[c]--;
            else { tieOk = false; breakFree = i; break; }
        }

        int start = h - 1;

        if (tieOk) {
            if (nOdd) {
                int tc = target[h] - 'a', mc = m - 'a';
                if (tc == mc) {
                    string halfStr = target.substr(0, h);
                    string full = halfStr + m + string(halfStr.rbegin(), halfStr.rend());
                    if (full > target) return full;
                } else if (tc < mc) {
                    string halfStr = target.substr(0, h);
                    string full = halfStr + m + string(halfStr.rbegin(), halfStr.rend());
                    return full;
                }
                // tc > mc: cannot use middle here, fall through to backtrack with start = h-1
            } else {
                string halfStr = target.substr(0, h);
                string full = halfStr + string(halfStr.rbegin(), halfStr.rend());
                if (full > target) return full;
            }
        } else {
            start = breakFree;
        }

        for (int i = start; i >= 0; i--) {
            vector<int> avail2 = snap[i];
            int tchar = target[i] - 'a';
            int found = -1;
            for (int c = tchar + 1; c < 26; c++)
                if (avail2[c] > 0) { found = c; break; }
            if (found == -1) continue;

            avail2[found]--;
            string halfArr(h, ' ');
            for (int j = 0; j < i; j++) halfArr[j] = target[j];
            halfArr[i] = char('a' + found);

            int pos = i + 1;
            for (int c = 0; c < 26 && pos < h; c++)
                while (avail2[c] > 0 && pos < h) { halfArr[pos++] = char('a' + c); avail2[c]--; }

            string full = halfArr;
            if (nOdd) full += m;
            full += string(halfArr.rbegin(), halfArr.rend());
            return full;
        }

        return "";
    }
};