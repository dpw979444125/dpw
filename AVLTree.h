#pragma once
#include<iostream>
#include<cstdlib>
#include <algorithm>
#include<cassert>

using namespace std;

template<typename K, typename V>
struct AVLTreeNode
{
	typedef AVLTreeNode<K, V> Node;
	AVLTreeNode(const K& key, const V& value)
		: _left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _key(key)
		, _value(value)
		, _bf(0)
	{}
	Node* _left;
	Node* _right;
	Node* _parent;

	int _bf;
	K _key;
	V _value;
};

template<typename K, typename V>
class AVLTree
{
public:
	typedef AVLTreeNode<K, V> Node;

	//构造
	AVLTree()
		:_root(NULL)
	{}
	//析构
	~AVLTree()
	{
		_Destroy(_root);
	}
	//插入节点
	bool Insert(const K& key, const V& value)
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
			return true;
		}

		Node* parent = NULL;
		Node* cur = _root;
		
		while (NULL != cur)
		{
			parent = cur;
			if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else if(key < cur->_key)
			{
				cur = cur->_left;
			}
			else          //因为搜索树不存在相同的值，所以返回错误
			{
				return false;
			}
		}
		cur = new Node(key, value);
		if (cur->_key > parent->_key)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		//插入完成，更新平衡因子
		while (parent)
		{
			if (parent->_left == cur)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}
			if (parent->_bf == 0)
			{
				break;//
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}//向上调整平衡因子
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)  //左单旋
					{
						_RotateL(parent);
					}
					else                //右左旋转
					{
						_RotateRL(parent);
					}
				}
				if(parent->_bf == -2)
				{
					if (cur->_bf == 1)  //左右旋转
					{
						_RotateLR(parent);
					}
					else                //右单旋
					{
						_RotateR(parent);
					}
				}
				break;//
			}
		}
	}
	
	void _RotateL(Node* parent)
	{
		assert(parent);
		Node* ppNode = parent->_parent;
		Node* prNode = parent->_right;
		Node* prlNode = prNode->_left;

		parent->_right = prlNode;      //***
		if (prlNode)
		{
			prlNode->_parent = parent;
		}
		prNode->_left = parent;
		parent->_parent = prNode;
		if (ppNode == NULL)
		{
			_root = prNode;
			prNode->_parent = NULL;
		}
		else
		{
			if (parent == ppNode->_left)
			{
				ppNode->_left = prNode;
			}
			else
			{
				ppNode->_right = prNode;
			}
			prNode->_parent = ppNode;
		}
		parent->_bf = prNode->_bf = 0;
	}

	void _RotateR(Node* parent)
	{
		assert(parent);
		Node* ppNode = parent->_parent;
		Node* plNode = parent->_left;
		Node* plrNode = plNode->_right;

		parent->_left = plrNode;
		if (plrNode)
		{
			plrNode->_parent = parent;
		}
		plNode->_right = parent;
		parent->_parent = plNode;
		if (ppNode == NULL)
		{
			_root = plNode;
			plNode->_parent = NULL;
		}
		else
		{
			if (parent == ppNode->_left)
			{
				plNode = ppNode->_left;
			}
			else
			{
				plNode = ppNode->_right;
			}
			plNode->_parent = ppNode;
		}
		parent->_bf = plNode->_bf = 0;
	}

	void _RotateLR(Node *parent)
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;
		int bf = SubLR->_bf;

		_RotateL(SubL);
		_RotateR(parent);
		//如果bf为0，代表插入点就是这个节点，这个时候所有旋转后的bf皆为0
		if (bf == 0)
		{
			SubL->_bf = parent->_bf = 0;
		}
		//当bf为1时，这个时候相当于是给sublr的右树插入
		else if (bf == 1)
		{
			SubL->_bf = -1;
			parent->_bf = 0;
		}
		//bf是-1时，相当于给sublr的左树插入
		else
		{
			SubL->_bf = 0;
			parent->_bf = 1;
		}
		SubLR->_bf = 0;
	}

	void _RotateRL(Node *parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;

		int bf = SubRL->_bf;
		_RotateR(SubR);
		_RotateL(parent);

		if (bf == 0)
		{
			SubR->_bf = parent->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			SubR->_bf = 1;
		}
		else
		{
			SubR->_bf = 0;
			parent->_bf = -1;
		}
		SubRL->_bf = 0;
	}

	bool _Find(const K& key)
	{
		if (_root == NULL)
			return false;
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else if (key > cur->_key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	int _Height(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int LeftLen = _Height(root->_left);
		int RightLen = _Height(root->_right);
		return LeftLen > RightLen ? LeftLen + 1 : RightLen + 1;
	}
	////O(N^2)
	//bool  _IsBalance(Node* root)
	//{
	//	if (root == NULL)
	//	{
	//		return true;
	//	}
	//	int left = _Height(root->_left);
	//	int right = _Height(root->_right);
	//	int diff = left - right;
	//	if (diff > 1 || diff < -1)
	//	{
	//		return false;
	//	}
	//	return _IsBalance(root->_left) && _IsBalance(root->_right);
	//}

	bool _IsBalance2(Node* root, int &height)
	{
		if (root == NULL)
		{
			height = 0;
			return true;
		}
		int leftHeight = 0, rightHeight = 0;
		bool leftRet = _IsBalance2(root->_left, leftHeight);
		bool rightRet = _IsBalance2(root->_right, rightHeight);
		
		height = max(leftHeight, rightHeight) + 1;
		if (abs(leftHeight - rightHeight) > 1)
		{
			return false;
		}
		return leftRet && rightRet;
	}

	bool IsBalance()
	{
		int height = 0;
		return _IsBalance2(_root, height);
	}

	void _Destroy(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
		root = NULL;
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key<< "->" << endl;
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
	}

private:
	Node * _root;
	//拷贝构造
	AVLTree(const AVLTree<K, V> & a);
	//赋值
	AVLTree<K, V>& operator=(const AVLTree<K, V> & a);
};


void test()
{
	AVLTree<int, int> AVLtree;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		AVLtree.Insert(a[i], a[i]);
	}
	AVLtree.InOrder();
	bool ret =  AVLtree.IsBalance();
	if (ret)
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}
}
