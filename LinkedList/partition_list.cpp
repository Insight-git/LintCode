/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode * partition(ListNode * head, int x) {
        ListNode *less_head = new ListNode(0);
        ListNode *more_head = new ListNode(0);
        ListNode *p = less_head, *q = more_head;
        while(head)
        {
        	if(head->val<x)
        	{
        		p->next = head;
        		p = head;
        	}
        	else
        	{
        		q->next = head;
        		q = head;
	        }
	        head = head->next;
        }
        q->next = NULL;
        p->next = more_head->next;
        return less_head->next;
    }
};