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
void rotate_list(node **head){
    node *last=*head;
    node *secondlast;
    while(last->next!=NULL){
        if(last->next->next==NULL){
            secondlast=last;
        }
        last=last->next;
    }
    secondlast->next=NULL;
    last->next=*head;
    *head=last;
}
int main(){
    int n,data,k;
    cout<<"Enter number of elements: ";
    cin>>n;
    node *head=NULL;
    cout<<"Enter space separated data elements: ";
    for(int i=0;i<n;i++){
        cin>>data;
        insert_end(&head,data);
    }
    cout<<"Enter the number of rotations: ";
    cin>>k;
    for(int i=0;i<k;i++){
    rotate_list(&head);
    }
    printlist(head);
    cout<<endl;
    return 0;
}
