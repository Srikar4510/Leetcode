class Solution {
public:

/*
we will remove last digit from binary representation of both left
and right number until we reach a point where both have same 
element at the same position.
And will also keep track of how many times we removed elements 
by keeping a count of it.

lets apply it practically:

first loop:
            101 >> 1 = 10
            111 >> 1 = 11
            cnt = 1

Second loop:
            10 >> 1 = 1
            11 >> 1 = 1
            cnt = 2

Third loop:
            1 == 1 
So now since they are equal we will add those many 0's at the 
end of the current element we have by using left shift operator.

            1 << cnt  = 1 << 2  => 100(4) 


    Result = 4

*/
    int rangeBitwiseAnd(int left, int right) {
        int cnt =0;
        while(left!=right){
            left = left>>1;
            right = right>>1;
            cnt++;
        }
        return (left<<cnt);
    }
};