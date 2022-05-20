/*https://leetcode.com/problems/encode-and-decode-tinyurl/submissions/*/
-------------------------------------------------------------------------
/*
    M1: Random
*/
class Codec:

    alphabet = string.ascii_letters + '0123456789'

    def __init__(self):
        self.url2code = {}
        self.code2url = {}

    def encode(self, longUrl):
        while longUrl not in self.url2code:
            code = ''.join(random.choice(Codec.alphabet) for _ in range(6))
            if code not in self.code2url:
                self.code2url[code] = longUrl
                self.url2code[longUrl] = code
        return 'http://tinyurl.com/' + self.url2code[longUrl]

    def decode(self, shortUrl):
        return self.code2url[shortUrl[-6:]]

-------------------------------------------------------------------------
/*
    M2: Rolling Hash
*/
#define ll long long

class Solution {
public:

    // s -> s0 + s1 * p^1 + s2 * p^2 + ..
    // p > max(s)
    // p < mod -> any big prime
    
    ll pivot = 100;
    ll mod = 1e9 + 7;
    
    map<ll, string> mp;
    
    Solution(){
        mp.clear();
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        int n = longUrl.size();
        ll hash = 0;
        pivot = 100;
        ll power = 1;
        
        for(int i = 0; i < n; i ++){
            hash += (longUrl[i] - '0') * power;
            hash %= mod;
            power *= pivot;
            power %= mod;
        }
        
        mp[hash] = longUrl;
        
        return to_string(hash);
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        return mp[stoll(shortUrl)];
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
-------------------------------------------------------------------------