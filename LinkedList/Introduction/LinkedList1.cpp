#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node* ArrayToLinkedList(vector<int>&arr)
{   
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < n; i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

int lengthOfLinkedList(Node* head)
{
    int count = 0;
    Node* temp = head;

    while(temp)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

int main()
{
    vector<int> arr = {4, 14, 15, 1, 7, 9};

    //head is the pointer to the linked list created
    Node* head = ArrayToLinkedList(arr);
    cout<<head->data<<"\n";
    Node* temp = head;
    //Traversing a linkedList ; T.C --> O(N)
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    int length = lengthOfLinkedList(head);  //T.C --> O(N)
    cout<<"\nLength of LL: "<<length;

    return 0;
}