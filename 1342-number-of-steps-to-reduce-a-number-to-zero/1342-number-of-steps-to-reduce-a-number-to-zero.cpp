class Solution {
public:
    int numberOfSteps(int num) 
    {
        int c = 0;
        while(num)
        {
            if(num%2)
            {
                num--;
            }
            else
            {
                num/=2;
            }
            c++;
        }
        return c;
    }
};