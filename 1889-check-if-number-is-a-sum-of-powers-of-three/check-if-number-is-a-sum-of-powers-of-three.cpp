//A simple way to find the binary representation of a number is by repeatedly taking ////its remainder when divided by 2 (mod 2)
class Solution {
public:
    bool checkPowersOfThree(int n) {
        //3^0+3^1+.....+3^(n-1) = (3^n-1)/2 <3^n
        
        //first check the greatest power which is equal or less than n
        int power = 0;
        while(pow(3,power)<=n){
            power++;
        }

        while(n>0){
            if(n>=pow(3,power)) n=n-pow(3,power);
            // We cannot use the same power twice
            if(n>=pow(3,power)) return false;
            // Move to the next power
            power--;
        }
        //if n becomes zero
        return true;
    }
};