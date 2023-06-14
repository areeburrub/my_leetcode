#include <iostream>

using namespace std;

class Solution {
public:
    static string countAndSay(int n) {
        if(n==1){
            return "1";
        }else{
            string cur_str = countAndSay(n-1);
            char cur_char = cur_str[0];
            int count=0;
            string result;
            for (char i: cur_str){
                if (cur_char == i){
                    count ++;
                }else{
                    result += to_string(count) + cur_char;
                    cur_char = i;
                    count = 1;
                }
            }
            result += to_string(count) + cur_char;
            return result;
        }
    }
};

int main () {
    cout << Solution::countAndSay(2);
    return 0;
}