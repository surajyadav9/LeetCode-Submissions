class Stack
{
    char *stk;
    int i;
    public:
        Stack(int n) : i(-1) , stk(new char[n]) {  };
        void push(char p) { stk[++i] = p;cout << stk[i] << endl; }
        char pop() { return stk[i--]; }
        bool match() { return (stk[i] == ')') && (stk[i-1] == '('); }
        int top()  { return i;}
};

class Solution {
public:
    int minAddToMakeValid(string S) {
        
        int count , str_len;
        
        str_len = S.length();
        Stack s(str_len); // stack
        
        count =0;
        for(int i=0;i<str_len;i++)
        {
            s.push(S[i]);
            count++;
            if(s.top()>0 && s.match())
            {
                s.pop();
                s.pop();
                count -= 2;
            }
        }
        return count;
    }
};