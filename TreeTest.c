/*****************************************/
/****************树的练习题***************/
/*****************************************/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//二叉树中和为某一值的路径
 void FindPath(TreeNode* pRoot, int sum)
 {
	 if (pRoot == nullptr)
		 return;
	 
	 vector<int> path;
	 int curSum = 0;
	 _FindPath(pRoot, sum, path, curSum);
 }

 void _FindPath(TreeNode* root, int sum, vector<int> path, int curSum)
 {
	 curSum += root->val;
	 path.push_back(root->val);
	 
	 //如果是叶节点，并且路径上节点值的和等于输入的值
	 //则打印出这条路径
	 bool isLeaf = root->left == NULL && root->right == NULL;
	 if (curSum == sum && isLeaf)
	 {
		 vector<int>::iterator it = path.begin();
		 for (; it != path.end(); ++it)
		 {
			 printf("%d\t",*it);
		 }
		 printf("\n");
	 }

	 //如果不是叶节点，则遍历它的子节点
	 if (root->left != NULL)
		 _FindPath(root->left, sum, path, curSum);
	 if (root->right != NULL)
		 _FindPath(root->right, sum, path, curSum);
	 //在返回父节点前，在路径上删除当前节点
	 path.pop_back();
 }




 //二叉搜索树的后续遍历序列
 bool VerifyBST(int seq[], int len)
{
	 if (seq == NULL || len <= 0)
	 {
		 return false;
	 }
	 
	 int root = seq[len - 1];
	 
	 //在二叉树中左子树的值小于根节点的值
	 int i = 0;
	 for (; i < len - 1; ++i)
	 {
		 if (seq[i] > root)
			 break;
	 }
	 
	 //在二叉树中右子树的值大于根节点的值
	 int j = i;
	 for (;j < len - 1; j++)
	 {
		 if (seq[j] < root)
			 return false;
	 }
	 //判断左子树是不是二叉树
	 bool left = true;
	 if (i > 0)
		 left = VerifyBST(seq, i);
	 //判断右子树
	 bool right = true;
	 if (i < len - 1)
		 right = VerifyBST(seq + i, len - i - 1);
}

 //从上到下打印二叉树，每一层打印一行
 class Solution {
 public:
	 vector<vector<int> > Print(TreeNode* pRoot)
	 {
		 queue<TreeNode*> Q;
		 vector<vector<int>> V;
		 vector<int> v1;
		 if (pRoot == NULL)
			 return V;
		 int tmp, cnt = 1;
		 Q.push(pRoot);
		 while (!Q.empty())
		 {
			 tmp = cnt;
			 v1.clear();
			 cnt = 0;
			 while (tmp--)
			 {
				 v1.push_back(Q.front()->val);
				 if (Q.front()->left != NULL)
				 {
					 Q.push(Q.front()->left);
					 cnt++;
				 }

				 if (Q.front()->right != NULL)
				 {
					 Q.push(Q.front()->right);
					 cnt++;
				 }
				 Q.pop();
			 }
			 V.push_back(v1);
		 }
		 return V;
	 }
 };


 //判断一棵树是不是对称
 //用值判断
 class Solution {
 public:
	 bool isSymmetrical(TreeNode* pRoot)
	 {

		 return _isSymmetrical(pRoot, pRoot);
	 }

	 bool _isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2)
	 {
		 if (pRoot1 == NULL && pRoot2 == NULL)
			 return true;
		 if (pRoot1 == NULL || pRoot2 == NULL)
			 return false;
		 if (pRoot1->val != pRoot2->val)
			 return false;
		 return _isSymmetrical(pRoot1->left, pRoot2->right) && _isSymmetrical(pRoot1->right, pRoot2->left);
	 }
 };

 
 
 //根据前序和中序重建二叉树
class Solution {
public:
	TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) 
	{
		int PreLen = pre.size();
		int VinLen = vin.size();
		if (PreLen == 0 || VinLen == 0 || PreLen != VinLen)
		{
			return NULL;
		}
		TreeNode* head = new TreeNode(pre[0]);  //根
		int root_in = 0;  //root在中序的下标
		for (int i = 0; i < PreLen; i++)
		{
			if (vin[i] == pre[0])
			{
				root_in = i;
				break;
			}
		}
		vector<int> in_left, in_right, pre_left, pre_right;
		for (int j = 0; j < root_in; j++)
		{
			in_left.push_back(vin[j]);
			pre_left.push_back(pre[j + 1]);
		}
		for (int j = root_in + 1; j < PreLen; j++)
		{
			in_right.push_back(vin[j]);
			pre_right.push_back(pre[j]);
		}
		head->right = reConstructBinaryTree(pre_right, in_right);
		head->left = reConstructBinaryTree(pre_left, in_left);
		return head;
	}
};

//树的高度
int Height(TreeNode* Root)
{
	if (Root == NULL)
		return 0;
	int LeftH = 0;
	int RightH = 0;
	LeftH = Height(Root->left);
	RightH =  Height(Root->right);
	return LeftH > RightH ? LeftH + 1 : RightH + 1;
}

//镜像二叉树
void Mirror(TreeNode* Root)
{
	if (Root == NULL)
		return;
	if (Root)
	{
		TreeNode* p = Root->left;
		Root->left = Root->right;
		Root->right = p;
		if (Root->left)
			Mirror(Root->left);
		if (Root->right)
			Mirror(Root->right);
	}
}