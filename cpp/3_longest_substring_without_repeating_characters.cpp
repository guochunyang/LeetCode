#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        char hash[256];
        memset(hash, 0, sizeof(hash));

        int size = static_cast<int>(s.size());
        int max_len = 1;

        if (size == 0)
            return 0;

        for (int i = 0; i < size-1; ++i)
        {
            memset(hash, 0, sizeof(hash));
            for (int j = i; j < size; ++j)
            {
                if (hash[s[j]] == 0)
                {
                    if (j == size-1)
                    {
                        int len = j-i+1;
                        if (len > max_len)
                            max_len = len;
                    }
                    else
                        hash[s[j]] = 1;
                }
                else
                {
                    int len = j - i;
                    if (len > max_len)
                        max_len = len;
                    break;
                }
            }
        }

        return max_len;
    }

};

int main()
{
    string s = "abcabcbb";
    Solution solution;
    int len = solution.lengthOfLongestSubstring(s);
    cout << len << endl;

    cout << solution.lengthOfLongestSubstring("au") << endl;
    cout << solution.lengthOfLongestSubstring("a") << endl;
    cout << solution.lengthOfLongestSubstring("abcb") << endl;
}