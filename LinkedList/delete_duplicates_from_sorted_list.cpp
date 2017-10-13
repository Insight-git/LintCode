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
     * @param head: head is the head of the linked list
     * @return: head of linked list
     */
    ListNode * deleteDuplicates(ListNode * head) {
        ListNode *p = NULL, *q = NULL;
        unsigned int differ = 0;
        if(!head)
        	return head;
        p = head;
        q = p->next;
        while(q)
        {
        	differ = q->val - p->val;
        	if(abs(differ)==0)
        	{
        		p->next = q->next;
        		q = q->next;
        	}
        	else
        	{
        		p = p->next;
        		q = q->next;
        	}
        }
        return head;
    }
};