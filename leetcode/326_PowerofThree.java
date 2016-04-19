/*
326. Power of Three
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
public class Solution {
    public boolean isPowerOfThree(int n) {
        while(n!=1&&n%3==0&&n>0) {
            n/=3;
        }
        return n==1;
    }
}
