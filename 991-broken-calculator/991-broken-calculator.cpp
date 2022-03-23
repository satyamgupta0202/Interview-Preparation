class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
       // Fermat's Algorithm
        int step = 0;
        while(target>startValue){
            if(target%2){
                target++;
            }else{
                target/=2;
            }
            step++;
        }
        
        return step + startValue-target;
    
    }
};