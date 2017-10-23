# 解题思路
- 方法1：哈希表
	- 首先对两个字符串进行分词，分别存入words1和words2；
	- 用words2创建哈希表并将words2的单词存入((假定words2较短))；
	- 循环遍历words1中的单词并在哈希表中查找，如果查找不成功，则为missing string;
- 方法2：vector查找
	- 首先对两个字符串进行分词，分别存入words1和words2；
	- 循环遍历words1中的单词并在words2中查找，如果查找不成功，则为missing string;