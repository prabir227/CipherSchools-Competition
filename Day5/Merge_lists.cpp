#include <iostream>
#include <stdlib.h>
#include <vector>
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
node *sort(node *head){
    node *temp=head;
    node *temp2=head->next;
    while(temp!=NULL){
        temp2=temp->next;
        while(temp2!=NULL){
            if((temp->data)>(temp2->data)){
                int dummy=temp->data;
                temp->data=temp2->data;
                temp2->data=dummy;
            }
            temp2=temp2->next;
        }
        temp=temp->next;
    }
    return head;
}
int main()
{
    int rows,cols;
    cout << "Enter number of Linked Lists: ";
    cin >> rows;
    node *head = NULL;
    int **arr = new int *[rows];
    int data;
    vector<vector<int>> matrix(rows);
    for(int i=0;i<rows;i++){
        cout<<"Enter number of elements: ";
        cin>>cols;
        matrix[i].resize(cols);
        cout<<"Enter space separated elements: ";
        for(int j=0;j<cols;j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0; i<rows;i++){
        for(int j=0;j<matrix[i].size();j++){
            insert_end(&head,matrix[i][j]);
        }
    }
    cout<<"The final sorted linked list is: ";
    printlist(sort(head));
    cout << endl;
    return 0;
}
