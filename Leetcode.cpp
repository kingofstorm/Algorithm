
//234. Palindrome Linked List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*O(1)*/
 
 class Solution {
public:
   bool isPalindrome(ListNode* head) {
      if( head==NULL || head->next==NULL ) return true;
      // list has at least two nodes
      ListNode *pre = NULL, *pfirst, *psecond;
      auto px1 = head, px2 = head;
      // traversal 1: reverse the first half and get pfirst&psecond in position
      while(true) {
         px2 = px2->next->next;        // move px2 forward
         pfirst = px1; px1 = px1->next;// move px1 forward
         pfirst->next = pre;           // point curent next back
         if( px2 == NULL ) {           // 2n Nodes
            psecond = px1; break;
         } else if( px2->next == NULL ) { // 2n+1 Nodes
            psecond = px1->next; break;
         }
         pre = pfirst;
      }
      // traversal 2: check node values
      while( pfirst!=NULL ) {
         if( pfirst->val != psecond->val ) return false;
         pfirst = pfirst->next; psecond = psecond->next;
      }
      return true;
   }
};



class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //cout<<1<<endl;
        ListNode *pre=new ListNode(-1);
        pre->next=head;
        vector<int> num;
        int len=0;
        //cout<<1<<endl;
        while(pre->next!=NULL)
        {
            num.push_back(pre->next->val);
            pre=pre->next;
        }
       
        int tmp=-1;
        int i=0;
        int j=num.size()-1;
        for(;i<j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                tmp=1;
                break;
            }
        }
        cout<<tmp;
        return tmp==1? false:true;
    }
};








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
