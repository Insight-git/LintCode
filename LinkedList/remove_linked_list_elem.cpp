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
     * @param val: An integer
     * @return: a ListNode
     */
    ListNode * removeElements(ListNode * head, int val) {
    	ListNode *p = new ListNode(0);//增加一个结点作为链表的头结点
    	p->next = head;
    	head = p;
    	while(head->next)
    	{
    		if(head->next->val==val)
    		{
    			head->next = head->next->next;
    		}
    		else
    		{
    			head = head->next;
    		}
    	}
    	return p->next;
    }
}