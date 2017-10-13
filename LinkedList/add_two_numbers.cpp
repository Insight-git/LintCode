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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode * addLists(ListNode * l1, ListNode * l2) {
    	unsigned int plus = 0;
    	ListNode *head = new ListNode(0);
    	ListNode *p = head;
        while(l1||l2||plus)
        {
        	ListNode *node = new ListNode(0);
        	if(l1)
        	{
        		node->val += l1->val;
        		l1 = l1->next;
        	}
        	if(l2)
        	{
        		node->val += l2->val;
        		l2 = l2->next;
        	}
        	node->val += plus;
        	plus = node->val / 10;//进位
        	node->val %= 10;
        	p->next = node;
        	p = node;
        }
        return head->next;
    }
};