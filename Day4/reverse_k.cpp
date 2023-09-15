#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
void insert_end(node **head, int element)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = element;
    newnode->next = NULL;
    node *last = *head;
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    else
    {
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newnode;
    }
}
void printlist(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
node *reverse_list(node *head, int k)
{
   node *prevptr=NULL;
   node *curr=head;
   node *nextptr;
   int counter=k;
   int remaining=0;
   node *temp =head;
   while(temp!=NULL){
    remaining++;
    temp=temp->next;
   }
   if(remaining < k){
    return head;
   }
   while(curr!=NULL and counter>0){
        nextptr=curr->next;
        curr->next=prevptr;
        prevptr=curr;
        curr=nextptr;
        counter--;
   }
   if(nextptr!=NULL){
   head->next=reverse_list(nextptr,k);
   }
   return prevptr;

}
int main()
{
    int n, data, k;
    cout << "Enter number of elements: ";
    cin >> n;
    node *head = NULL;
    cout << "Enter space separated data elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        insert_end(&head, data);
    }
    cout << "Enter k: ";
    cin >> k;
    printlist(reverse_list(head, k));
    cout << endl;
    return 0;
}
