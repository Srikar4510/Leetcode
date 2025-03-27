class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i=0,sign=1;
        long ans = 0;

        //ignore leading white spaces
        while(i<n && s[i]==' '){
            i++;
        }
        if(i==n) return 0;
        //check for sign and move to nect index
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }

        //iterate over remaining string
        while(i<n){
            //is a digit
            if(s[i]>='0'&&s[i]<='9'){
                  ans = ans*10 + (s[i]-'0');

                  if(ans*sign > INT_MAX) return INT_MAX;
                  if(ans*sign < INT_MIN) return INT_MIN;
                  i++;
            }
            else{
                 break;
            }
        }
       return (int)(ans*sign);
    }
};