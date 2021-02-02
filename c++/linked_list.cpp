#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n;
    cin>>n;
    struct node *head=0,*temp,*newnode;
    for(int i=0;i<n;i++)
    {
        newnode=(struct node*) malloc(sizeof(struct node));
        cin>>newnode->data;
        newnode->next=0;
        if(head==0)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }

    temp=head;
    while(temp!=0)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
