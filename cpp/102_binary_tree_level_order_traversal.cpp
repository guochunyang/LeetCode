#include <queue>
#include <set>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret; // 结果集合
        if (root == NULL)
            return ret;

        queue<pair<TreeNode *, size_t>> nodeQueue;
        set<size_t> levelSet;  // 层数集合

        nodeQueue.push(make_pair(root, 0));

        while (!nodeQueue.empty())
        {
            pair<TreeNode *, size_t > nodePair = nodeQueue.front();
            nodeQueue.pop();
            TreeNode *node = nodePair.first;
            size_t level = nodePair.second;

            auto iter = levelSet.find(level);
            if (iter == levelSet.end())
            {
                // 该节点是这一层第一个结点
                vector<int> levelVec;
                levelVec.push_back(node->val);
                ret.push_back(levelVec); // 放入最终结果中
                levelSet.insert(level);
            }
            else
            {
                auto &levelVec = ret[level];
                levelVec.push_back(node->val);
            }

            // 左右结点分别入队
            if (node->left != NULL)
                nodeQueue.push(make_pair(node->left, level+1));
            if (node->right != NULL)
                nodeQueue.push(make_pair(node->right, level+1));
        }

        return ret;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret; // 结果集合
        if (root == NULL)
            return ret;

        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        nodeQueue.push(NULL);  // NULL 表示该层结束

        vector<int> levelData;  // 缓存每层的数据

        while (!nodeQueue.empty())
        {
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();


            if (node == NULL)
            {
                // 这层已经结束
                ret.push_back(levelData);
                levelData.clear();  // 清空，开始存储下一层

                if (nodeQueue.empty())
                    break;  // 全部遍历完毕
                else
                {
                    // 不为空，说明下面一层的结点已经放入
                    nodeQueue.push(NULL);
                    continue;
                }
            }

            levelData.push_back(node->val);

            if (node->left)
                nodeQueue.push(node->left);
            if (node->right)
                nodeQueue.push(node->right);
        }

        return ret;
    }
};


int main()
{
    TreeNode *node = new TreeNode(1);
    Solution solution;
    vector<vector<int>> ret = solution.levelOrder(node);

    cout << ret.size() << endl;
    cout << ret[0].size() << endl;

}