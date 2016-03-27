/*Remove Duplicate from sorted List*/

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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL)
            return NULL;

        ListNode * currNode = head;
        ListNode * nextNode = head->next;

        while(nextNode != NULL)
        {
            if(currNode->val == nextNode->val)
            {
                ListNode * temp = nextNode;
                nextNode        = nextNode->next;
                currNode->next  = nextNode;
                free(temp);

            }
            else
            {
                nextNode = nextNode->next;
                currNode = currNode->next;
            }
        }

        return head;
    }
};




/*258. Add Digits*/
/*easy*/
class Solution {
public:
    int addDigits(int num) {
        int result=(num-1)%9+1;
        return result;
    }
};




/* 292 Nim Game       Easy */
class Solution {
public:
    bool canWinNim(int n) {
        if(n<=3)
            return true;
        if(n%4==0)
            return false;
        else
            return true;
    }
};
