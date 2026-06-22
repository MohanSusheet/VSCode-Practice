#include<iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode* next;
    
    ListNode()
    {
        this->data = 0;
        this->next = nullptr;
    }
    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    ListNode(int data, ListNode* next)
    {
        this->data = data;
        this->next = next;
    }
};


ListNode* getMiddleNodeApproach1(ListNode* head)
{
    //Better Approach - using 2 passes.
    // 1st pass to count the number of nodes in the LL
    // 2nd to find the target node and return it.
    // T.C -->(2 * n), S.C --> O(1)
    if(head == NULL || head->next == NULL)return head;

    int count = 0;
    ListNode* temp = head;

    while(temp)
    {
        count++;
        temp = temp->next;
    }

    cout<<"\nCount of nodes in the LL is: "<<count<<"\n";
    
    int target = count / 2;
    temp = head;

    while(target--)
    {
        temp = temp->next;
    }

    return temp;
}
    
ListNode* getMiddleNodeOptimalApproach(ListNode* head)
{
    //Optimal Approach - 2 Pointers (Slow + Fast pointers)
    //Only one pass is required to identify the middle node
    //T.C -->(n), S.C --> O(1)
    if(head == NULL || head->next == NULL)return head;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    ListNode* head = n1;
    
    ListNode* middle1 = getMiddleNodeApproach1(head);
    ListNode* middle2 = getMiddleNodeOptimalApproach(head);

    cout<<middle1->data<<"\n";
    cout<<middle2->data<<"\n";

    return 0;
}