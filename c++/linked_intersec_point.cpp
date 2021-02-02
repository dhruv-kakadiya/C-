#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n,m;
    cin>>n>>m;
    struct node *head1=0,*temp,*newnode;
    for(int i=0;i<n;i++)
    {
        newnode=(struct node*) malloc(sizeof(struct node));
        cin>>newnode->data;
        newnode->next=0;
        if(head1==0)
        {
            head1=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }

    struct node *head2=0, *temp2;
    for(int i=0;i<m;i++)
    {
        newnode=(struct node*) malloc(sizeof(struct node));
        cin>>newnode->data;
        newnode->next=0;
        if(head2==0)
        {
            head2=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    int diff=abs(n-m);
    if(n>m)
    {
        temp=head1;
        temp2=head2;
        for(int i=0;i<diff;i++)
        {
            temp=temp->next;
        }
        while(temp->data!=temp2->data)
        {
            temp=temp->next;
            temp2=temp2->next;
        }
        cout<<temp->data<<"\n";
    }
    else
    {
        temp=head1;
        temp2=head2;
        for(int i=0;i<diff;i++)
        {
            temp2=temp2->next;
        }
        while(temp->data!=temp2->data)
        {
            temp=temp->next;
            temp2=temp2->next;
        }
        cout<<temp->data<<"\n";
    }
    return 0;
}
