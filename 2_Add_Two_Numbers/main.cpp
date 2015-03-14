#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

#define debug(x)  cout<<#x<<" = "<<x<<endl;
#define debugs(arr,num) cout<<#arr<<" = ";for(int zz=0;zz<num;zz++)cout<<arr[zz]<<" ";cout<<endl;

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void debug_list(ListNode* l){
    while (l!=NULL){
        cout<<l->val<<" ";
        l = l->next;
    }
    cout<<endl;
}

ListNode *get_node(int val, ListNode* p) {
    ListNode* a=new ListNode(val);
    a->next = p;
    return a;
}

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
    ListNode *get_node(int val, ListNode* p) {
        ListNode* a=new ListNode(val);
        a->next = p;
        return a;
    }
    void reformat(ListNode* l){
        int rest_val=0;
        while(1) {
            l->val += rest_val;
            rest_val = l->val/10;
            l->val = l->val%10;
            if (l->next!=NULL) {
                l = l->next;
            }
            else {
                break;
            }
        }
        if (rest_val!=0) {
            l->next = get_node(rest_val, NULL);
        }
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *l1_next=l1, *l2_next=l2, *sum, *head;
        head = sum = get_node(0,NULL);
        while (1){
            if (l1_next!=NULL) {
                sum->val += l1_next->val;
                l1_next = l1_next->next;
            }
            if (l2_next!=NULL) {
                sum->val += l2_next->val;
                l2_next = l2_next->next;
            }
            if (l1_next!=NULL || l2_next!=NULL) {
                sum->next = get_node(0,NULL);
                sum = sum->next;
            }
            else {
                sum->next = NULL;
                break;
            }
        }
        //debug_list(head);
        reformat(head);
        //debug_list(head);
        return head;
    }
};

int main() {
    ListNode* a=get_node(3,NULL);
    ListNode* b=get_node(4,a);
    ListNode* c=get_node(2,b);
    ListNode* a2=get_node(4,NULL);
    ListNode* b2=get_node(6,a2);
    ListNode* c2=get_node(5,b2);
    Solution sol;
    ListNode* p=sol.addTwoNumbers(c,c2);
    debug_list(p);
    return 0;
}
