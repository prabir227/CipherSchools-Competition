#include <iostream>
#include <stdlib.h>
using namespace std;
struct node{
    int data;
    node *next;
};
void insert_end(node **head,int element){
    node *newnode=(node*) malloc(sizeof(node));
    newnode->data=element;
    newnode->next=NULL;
    node *last=*head;
    if(*head==NULL){
        *head=newnode;
        return;
    }
    else{
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=newnode;
    }
}
void printlist(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void reorderlist(node *head){
    node *oddpointer=head;
    node *evenpointer=head->next;
    node *starteven=evenpointer;
    while (oddpointer->next!=NULL && evenpointer->next!=NULL){
        oddpointer->next=evenpointer->next;
        oddpointer=oddpointer->next;
        evenpointer->next=oddpointer->next;
        evenpointer=evenpointer->next;
    }
    oddpointer->next=starteven;
    if(oddpointer==NULL){
        evenpointer->next=NULL;
    }
}
int main(){
    int n,data;
    cout<<"Enter number of elements: ";
    cin>>n;
    node *head=NULL;
    cout<<"Enter space separated data elements: ";
    for(int i=0;i<n;i++){
        cin>>data;
        insert_end(&head,data);
    }
    reorderlist(head);
    cout<<"The reordered list is: ";
    printlist(head);
    return 0;
}
