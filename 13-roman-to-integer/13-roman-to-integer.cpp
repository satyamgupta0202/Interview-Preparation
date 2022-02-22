/**
public:
    int romanToInt(string S) {
        int ans = 0, num = 0;
        for (int i = S.size()-1; ~i; i--) {
            switch(S[i]) {
                case 'I': num = 1; break;
                case 'V': num = 5; break;
                case 'X': num = 10; break;
                case 'L': num = 50; break;
                case 'C': num = 100; break;
                case 'D': num = 500; break;
                case 'M': num = 1000; break;
            }
            if (4 * num < ans) ans -= num;
            else ans += num;
        }
        return ans;        
    }
};
**/

class Solution {
public:
    int romanToInt(string s) {
        
        int ans = 0; 
        int n = s.size();
        
        int i=0;
        while(i<n)
        {
                if(i+1<n && s[i]=='C' && s[i+1]=='D')
                {
                    ans+=400;
                    i+=2;
                }
                else if(i+1<n && s[i]=='C' && s[i+1]=='M')
                {
                    ans+=900;
                    i+=2;
                }
                else if(i+1<n && s[i]=='X' && s[i+1]=='L')
                {
                    ans+=40;
                    i+=2;
                }
                else if(i+1<n && s[i]=='X' && s[i+1]=='C')
                {
                    ans+=90;
                    i+=2;
                }
            
                else if(i+1<n && s[i]=='I' && s[i+1]=='V')
                {
                    ans+=4;
                     i+=2;
                }
            
                else if(i+1<n && s[i]=='I' && s[i+1]=='X')
                {
                    ans+=9;
                    i+=2;
                }
                
            
                else if(s[i]=='M')
                {
                    ans+=1000;
                    i++;       
                }
            
                else if(s[i]=='D')
                {
                    ans+=500;
                    i++;
                }
            
                else if(s[i]=='C')
                {
                    i++;
                    ans+=100;
                }
            
                else if(s[i]=='L')
                {
                    i++;
                    ans+=50;
                }
            
               else if(s[i]=='X')
                {
                   i++;
                    ans+=10;
                }
            
                else if(s[i]=='V')
                {
                    i++;
                    ans+=5;
                }
            
                else
                {
                    i++;
                    ans++;
                }
            cout<<ans<<endl;
            
        }
        return ans;
        
    }
};