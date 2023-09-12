#include <iostream>
#include <stdlib.h>
using namespace std;
struct node{
    int data;
    node *next;
};
void push(node **head,int element){
    node *newnode = (node*) malloc(sizeof(node));
    newnode->data=element;
    newnode->next=*head;
    *head=newnode;
}
node *reverse(node *head){
    node *currptr=head;
    node *prevptr=NULL;
    node *nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}
void printlist(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}
node *returnmid(node *head){
    node *slowptr=head;
    node *fastptr=head;
    while(fastptr!=NULL && fastptr->next!=NULL){
        fastptr=fastptr->next->next;
        slowptr=slowptr->next;
    }
    return slowptr;
}
int main(){
    int n,data;
    node *head=NULL;
    cout<<"Enter number of elements: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data;
        push(&head,data);
    }
    node *mid =returnmid(head);
    node *rev=reverse(mid);
    int max=head->data+rev->data;
    for(int i=0;i<n/2;i++){
        if(head->data+rev->data>max){
            max=head->data+rev->data;
        }
        head=head->next;
        rev=rev->next;
    }
    cout<<"The required output is:"<<max<<endl;
    return 0;
}
