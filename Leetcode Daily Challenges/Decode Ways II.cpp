// bottom up dp

class Solution {
    vector<int> dp;
    const int MOD = 1000000007;
    long decodeWays(string const &s, int start) {
        if (start == s.size()) return 1;
        if (dp[start] != -1) return dp[start];
        const char ch = s[start];
        long ways = 0;
        if (ch == '0') {
            return dp[start] = 0;
        } else if (ch == '1') {
            ways = decodeWays(s, start + 1);
            if (start + 1 < s.size()) {
                const long mul = s[start + 1] == '*' ? 9L : 1L;
                ways += ((mul * decodeWays(s, start + 2)) % MOD);
            }
        } else if (ch == '2') {
            ways = decodeWays(s, start + 1);
            if (start + 1 < s.size() && (s[start + 1] == '*' || s[start + 1] < '7')) {
                const long mul = s[start + 1] == '*' ? 6L : 1L;
                ways += ((mul * decodeWays(s, start + 2)) % MOD);
            }
        } else if (ch == '*') {
            ways = (9L * decodeWays(s, start + 1)) % MOD;
            if (start + 1 < s.size()) {
                const char next = s[start + 1];
                const long mul = (next == '*') ? 15L : (next < '7' ? 2L : 1L);
                ways += ((mul * decodeWays(s, start + 2)) % MOD);
            }
        } else {
            ways = decodeWays(s, start + 1);
        }
        ways %= MOD;
        return dp[start] = ways;
    }
public:
    int numDecodings(string s) {
        dp.clear();
        dp.resize(s.size(), -1);
        if (s.size() > 1000) {
            int idx = s.size() - 1000;
            while (idx >= 0) {
                decodeWays(s, idx);
                if (idx == 0) {
                    idx = -1;
                } else {
                    idx -= 1000;
                    idx = std::max(idx, 0);
                }
            }
        }
        return decodeWays(s, 0);
    }
};