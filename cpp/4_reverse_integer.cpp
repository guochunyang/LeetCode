#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        // 4,294,967,295
        char s[100];
        ::memset(s, 0, sizeof(s));
        bool flag = (x < 0)? true: false;

        if (x ==0)
            return 0;

        if (isNegativeOverflow(x))
            return 0;

        if (x < 0)
            x *= -1;
        ::snprintf(s, sizeof(s), "%d", x);

        int len = ::strlen(s);
        std::reverse(&s[0], &s[len]);

        // 向上溢出
        if (len == 10 && strcmp(s, "2147483647") > 0)
            return 0;

        int value = ::atoi(static_cast<const char*>(s));
        if (flag)
            value *= -1;

        return value;
    }


    static bool isNegativeOverflow(int x)
    {
        char buf[100];
        memset(buf, 0, 100);
        ::snprintf(buf, sizeof(buf), "%d", x);

        if (x < 0 && strlen(buf) == 11 && strcmp(buf, "-2147483648") >= 0)
            return true;
        return false;
    }
};



int main()
{
    Solution solution;
    cout << solution.reverse(100) << endl;

    cout << solution.reverse(-12345) << endl;
    cout << solution.reverse(345678) << endl;
    cout << solution.reverse(0) << endl;
    cout << solution.reverse(1534236469) << endl;
}