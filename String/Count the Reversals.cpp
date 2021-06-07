 // https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1#


int countRev (string s)
{
    if(s.size()%2 == 1) return -1;
    // your code here
    stack<int> ss;
    int cnt = 0;
    for(auto it : s){
        if(it == '{') ss.push(1);
        else{
            if(ss.empty()) cnt ++,ss.push(1);
            else ss.pop();
        }
    }
    cnt += ss.size()/2;
    return cnt;
}