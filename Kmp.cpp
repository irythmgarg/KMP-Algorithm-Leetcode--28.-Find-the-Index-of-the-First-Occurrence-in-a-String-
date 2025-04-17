class Solution {
public:
    // Function to compute the prefix (LPS) array used in KMP algorithm
    void longestPrefix(vector<int>& lps, string pattern) {
        int n = pattern.length();
        lps[0] = 0;
        int len = 0; // Length of the previous longest prefix suffix

        int i = 1;
        while (i < n) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // Try the shorter prefix
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    // Function to search for 'small' string in 'large' string using KMP
    int strStr(string large, string small) {
        if (small.empty()) return 0;
        
        vector<int> lps(small.size());
        longestPrefix(lps, small);

        int i = 0; // index for large
        int j = 0; // index for small

        while (i < large.size()) {
            if (large[i] == small[j]) {
                i++;
                j++;
            }

            if (j == small.size()) {
                return i - j; // Match found
            } else if (i < large.size() && large[i] != small[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return -1; // No match found
    }
};
