# 解题思路
- 思路类似于求最小深度
	- 若当前结点为空，返回0；
	- 若当前结点为叶子结点，返回1；
	- 若当前结点的左子树（右子树）为空，则当前结点的左子树（右子树）的深度为无穷小，否则，递归求解左右子树最大深度+1；