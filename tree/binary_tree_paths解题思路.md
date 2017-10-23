# 解题思路
- 方法：二叉树进行前序遍历或者深度优先搜索
	- 从根节点向下分别沿左右子树搜索。在保证当前结点不为空的情况下，将当前结点加入path中，如果当前结点为叶子结点，则将path加入all_path中并返回，否则向下继续搜索。
	- int转string:
		- C++11标准全局函数std::to_string函数:
		- 借助字符串流：ostringstream(写string),stringstream(读写string)
	- string转int
		- C++11标准全局函数std::stoi/stol/stoll
		- 借助字符串流：istringstream, stringstream
> **注**：返回上一层之前要从path中pop出父节点。