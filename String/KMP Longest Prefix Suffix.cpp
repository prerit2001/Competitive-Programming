//https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527

class Solution{
public:
	int lps(string word){
	    vector<int> lp(word.length(), 0);
        int index = 0;
        for(int i = 1; i < word.length();){
            if(word[i] == word[index]){
                index++;
                lp[i] = index;
                i++;
            }
            else{
                if(index != 0)
                    index = lp[index-1];
                else
                    i++;
            }
        }
        return lp.back();
	}
};