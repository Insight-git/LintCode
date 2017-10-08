/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    /*
     * @param head: a ListNode
     * @return: a ListNode
     */
    ListNode * swapPairs(ListNode * head) {
    	ListNode *new_head = new ListNode(0);//增加一个结点作为链表的头结点
    	int val = 0;
    	new_head->next = head;
    	head = new_head;
    	while(head->next&&head->next->next)
    	{
    		val = head->next->val;
    		head->next->val = head->next->next->val;
    		head->next->next->val = val;
    		head = head->next->next;
    	}
    	return new_head->next;
    }
}