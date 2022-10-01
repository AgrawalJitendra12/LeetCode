//Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
/*class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        if(x<0){
            negative = true;
        }
        string s = to_string(x);
        std::reverse(s.begin(), s.end());
        x = std::stoi(s);
        if(negative){
            x=0-x;
        }
        return x;
    }
};*/

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};