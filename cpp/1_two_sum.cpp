#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

/*
 * https://leetcode.com/problems/two-sum/
 *
 */

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int, vector<int> > m;
        size_t size = nums.size();
        for(int ix =0 ; ix < size; ++ix)
        {
            m[nums[ix]].push_back(ix);
        }

        vector<int> ret(2);

        for (int ix = 0; ix < size; ++ix) {
            int t1 = nums[ix];
            int t2 = target - t1;

            map<int, vector<int> >::const_iterator iter = m.find(t2);
            if (iter == m.end())
                continue;  // t2找不到

            const vector<int> &vec = iter->second;

            ret[0] = ix + 1;
            int res = 0;

            if (t1 == t2)
            {
                if (vec.size() == 1)
                    continue;
                else
                {
                    res = vec[1];
                    ret[0] = ix+1;
                }
            }
            else
            {
                res = vec[0];
            }

            ret[1] = res+1;
            return ret;
        }

        return ret;

    }
};


class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {


        map<int, int> m;

        int size = static_cast<int>(nums.size()); // nums.size();
        for(int ix =0 ; ix < size; ++ix)
        {
            m[nums[ix]] = ix;
        }

        vector<int> ret(2);

        for (int ix = 0; ix < size; ++ix) {
            int t1 = nums[ix];
            int t2 = target - t1;

            map<int, int>::const_iterator iter = m.find(t2);
            if (iter == m.end())
                continue;  // t2找不到

            int t2_index = iter->second; // t2的下标

            if (t1 == t2 && t2_index == ix)
                continue;

            ret[0] = ix+1;
            ret[1] = t2_index+1;
            return ret;

        }

        return ret;

    }
};


class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int m[100000];
        memset(m, -1, sizeof(int)*100000);

        int size = static_cast<int>(nums.size()); // nums.size();
        for(int ix =0 ; ix < size; ++ix)
        {
            // cout << "ix: " << ix << " nums: " << nums[ix] << endl;
            m[nums[ix]+50000] = ix;
        }

        vector<int> ret(2);

        for (int ix = 0; ix < size; ++ix) {
            int t1 = nums[ix];
            int t2 = target - t1;

            int t2_index = m[t2+50000];
            if (t2_index == -1)
                continue; // 找不到t2

            if (t1 == t2 && t2_index == ix)
                continue; // 数组中只有一个t1

            ret[0] = ix+1;
            ret[1] = t2_index+1;
            return ret;
        }

        return ret;
    }
};


class Solution4 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // map<int, int> m;
        unordered_map<int, int> m;

        int size = static_cast<int>(nums.size()); // nums.size();
        for(int ix =0 ; ix < size; ++ix)
        {
            // cout << "ix: " << ix << " nums: " << nums[ix] << endl;
            m[nums[ix]] = ix;
        }

        vector<int> ret(2);

        for (int ix = 0; ix < size; ++ix) {
            int t1 = nums[ix];
            int t2 = target - t1;

            unordered_map<int, int>::const_iterator iter = m.find(t2);
            if (iter == m.end())
                continue;  // t2找不到

            int t2_index = iter->second; // t2的下标

            if (t1 == t2 && t2_index == ix)
                continue;

            ret[0] = ix+1;
            ret[1] = t2_index+1;
            return ret;
        }
        return ret;
    }
};


class Solution5 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int, size_t>> vec(nums.size());

        int size = static_cast<int>(nums.size());
        for (int i=0; i < size; ++i)
        {
            vec[i] = make_pair(nums[i], static_cast<size_t>(i));
        }

        auto f = [](pair<int, size_t> a, pair<int, size_t> b)
        {
            return a.first < b.first;
        };

        sort(vec.begin(), vec.end(), f);

        vector<int> ret(2);
        int begin = 0;
        int end = size-1;

        while (begin < end)
        {
            int tmp = vec[begin].first + vec[end].first;
            if (tmp > target)
                end --;
            else if(tmp < target)
                begin ++;
            else
            {
                ret[0] = vec[begin].second + 1;
                ret[1] = vec[end].second + 1;
                if (ret[0] > ret[1])
                {
                    int temp = ret[0];
                    ret[0] = ret[1];
                    ret[1] = temp;
                }
                return ret;
            }
        }
        return ret;
    }
};



int main()
{

}