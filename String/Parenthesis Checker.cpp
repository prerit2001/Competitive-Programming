//https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1#

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> s;
        for(auto it : x){
            if(it == '(' or it == '[' or it == '{') s.push(it);
            else{
                if(it == '}' and !s.empty() and s.top() == '{') s.pop();
                else if(it == ')' and !s.empty() and s.top() == '(') s.pop();
                else if(it == ']' and !s.empty() and s.top() == '[') s.pop();
                else return false;
            }
        }
        if(s.size() == 0) return true;
        else return false;
    }

};