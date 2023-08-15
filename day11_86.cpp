//86 partition List-> the problem is quite simple which ever is greater than left side do in right side and whatever is smaller than x in right side usko left side me leke jao

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val=x;
        next=NULL;
    }  
};
//brute force
ListNode *partition(ListNode* head,int x)
{
    vector<int>ans;
    ListNode* node = new ListNode(-1);
    ListNode* curr=node;
    if(head==NULL)return head;
    while(head!=NULL){
        ans.push_back(head->val);
        head=head->next;
    }
    vector<int>res;
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]<x)res.push_back(ans[i]);
    }

    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]>=x)res.push_back(ans[i]);
    }

    for(int i=0;i<res.size();i++)
    {
        curr->next=new ListNode(res[i]);
        curr=curr->next;
    }
    return node->next;

}
//optimal solution

 ListNode* partition(ListNode* head, int x) {
        ListNode* left=new ListNode(0);
        ListNode* right=new ListNode(0);

        ListNode *leftTail=left;
        ListNode *rightTail=right;

        while(head)
        {
            if(head->val<x)
            {
                leftTail->next=head;
                leftTail=leftTail->next;
            }
            else
            {
                rightTail->next=head;
                rightTail=rightTail->next;
            }
            head=head->next;
        }
        leftTail->next=right->next;
        rightTail->next=NULL;
        return left->next;
    }

ListNode* make_linked_list(int* arr, int n) {
    ListNode* node = new ListNode(-1);
    ListNode* curr = node;
    for (int i = 0; i < n; i++) {
        curr->next = new ListNode(arr[i]);  
        curr = curr->next;
    }
    return node->next;
}

void print(ListNode* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
}

int main() {
    int n;
    cin >> n;
    int x;
    cin>>x;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ListNode* node = make_linked_list(arr, n);
    ListNode* node1=partition(node,x);
    print(node1);
}
