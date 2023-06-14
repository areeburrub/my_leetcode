#include <iostream>

using namespace std;

class Solution {
public:
    static int romanToInt(const string& s) {
        int prevNum = 0,result = 0;
        for (char i : s) {
            if(getRomanValue(i) <= prevNum){
                cout<< prevNum << " " << getRomanValue(i) <<endl;
                cout << result << " + " << getRomanValue(i);
                result += getRomanValue(i);
                cout  << " = " << result << endl;
                prevNum = getRomanValue(i);
            }else{
                cout<< prevNum << " " << getRomanValue(i) <<endl;

                cout << result << " - " << prevNum ;
                result -= prevNum;
                cout << " = " << result << endl;

                cout << result << " + " << getRomanValue(i) << " - " << prevNum;
                result += getRomanValue(i)-prevNum;
                cout << " = " << result << endl;

                prevNum = getRomanValue(i);
            }
        }
        return result;
    }


    static int getRomanValue(char c){
        int value=0;
        switch (c) {
            case 'M':
                value = 1000;
                break;
            case 'D':
                value = 500;
                break;
            case 'C':
                value = 100;
                break;
            case 'L':
                value = 50;
                break;
            case 'X':
                value = 10;
                break;
            case 'V':
                value = 5;
                break;
            case 'I':
                value = 1;
                break;
            default:
                value = 0;
        }
        return value;
    }
};

int main () {
    cout << Solution::romanToInt("MCMXCIV");
    return 0;
}