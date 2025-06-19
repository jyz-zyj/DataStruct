// n个节点组成的不同二叉树数量为卡特兰数
class Solution {
public:
    int numTrees(int n) {
        if(n==1)
            return 1;
        long res = 1;
        for(int i = 1;i<n;i++){
            res = res*(4*i+2)/(i+2);
        }
        return int(res);
    }
};