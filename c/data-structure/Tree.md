# Tree
## 存储结构
- 双亲存储结构：数组下标表示节点，数组内容表示节点的双亲
- 孩子存储结构：图的邻接表

## 二叉树
- 二叉树有5种基本形态
- 特殊二叉树
    1. 满二叉树
    2. 完全二叉树：叶子节点只能出现在最下层和次下层，并且最下面一层的节点都集中在该层最左边.
    3. 平衡二叉树：AVL树-一棵空树或者他的左右两个子树的高度差的绝对值不超过1.
    4. 二叉搜素树：任何一个节点都大于其左节点的数值，且小于他右节点的数值.
- 性质
    1. 总分支数 = 总节点数 - 1
    2. 节点可划分为：叶子节点，单分支节点，双分支节点.
    3. 二叉树中空指针的数目 = 总节点数目 + 1 (2n - (n - 1))
    4. 非空二叉树叶子节点数量 = 双分支节点数目 + 1
    5. i层上最后有 2的i-1次方个节点 (i > 1)
    6. 满二叉树中前k层的节点数目为 2的k次方 - 1
    7. 完全二叉树中子节点于双亲的位置关系

- 存储结构
    1. 顺序存储结构：更适合完全二叉树，依赖二叉树子节点与其父节点之间的位置关系建立。
    2. 链式存储结构：
    ```c
    typedef struct BTNode {
        char data;
        struct BTNode *left;
        struct BTNode *right;
    
    }BTNode;
    ```
    3. 二叉树遍历：先序遍历，后序遍历，中序遍历，层次遍历。
    ```c
    // 循环队列实现二叉树的层次遍历。
    void level(BTNode *p) {
        int front, rear;
        BTNode *que[maxSize];
        front, rear = 0;
    
        BTNode *q;
        if(p != NULL) {
            rear = (rear + 1) % maxSize:
            que[rear] = p;
            while(front != rear) {
                front = (front + 1) % maxSize;
                q = que[front];
                if(q->left != NULL) {
                    rear = (rear + 1) % maxSize;
                    que[rear] = q.left;
                }
                if(q->right != NULL) {
                    rear = (rear + 1) % maxSize;
                    que[rear] = q.right;
                }
            }
        }
    }
    ```

