/* ------------------------------------------------------------------|
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:

输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
示例 2:

输入: [1,2,2]
输出: 4
解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/candy
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	
*
*	执行用时：44 ms, 在所有 C++ 提交中击败了59.76%的用户
*	内存消耗：16.9 MB, 在所有 C++ 提交中击败了69.05%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int candy(vector<int>& ratings) {
    if (ratings.size() == 0) {
        return 0;
    }
    vector<int> candy(ratings.size(), 1);
    //如果右边的数值比左边大，就比左边多获得一个
    for (int i = 1; i < ratings.size(); i++) {
        if (ratings[i] > ratings[i - 1]) {
            candy[i] = candy[i-1] + 1;
        }
    }
    //从右边再往左遍历，如果左边比右边大，并且左边的糖果数小于右边的话，左边的糖果数要比右边多一个
    for (int i = ratings.size() - 2; i >= 0; i--) {
        if (ratings[i + 1] < ratings[i] && candy[i] <= candy[i + 1]) {
            candy[i] = candy[i + 1] + 1;
        }
    }
    int res = 0;
    for (int i:candy) {
        res += i;
    }
    return res;
}