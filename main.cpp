#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
node *head=nullptr;
node *pre;
class linkedlist{
    node *t = new node;
    public:
    linkedlist ()
    {
        t->next=nullptr;
    }
    void input(int v);
    void output();
    void insert(int s,int i);
    void dele(int s);
};
void linkedlist::input(int v)
{
    t->data=v;
    if(head==nullptr)
    {
        head=t;
        pre=t;
    }
    else
    {
        pre->next=t;
        pre=t;
    }
}
void linkedlist::output()
{
    node *it = head;
    do
    {
        cout<<it->data<<" ";
        it = it->next;
    }while(it!=nullptr);
    cout<<endl;
}
void linkedlist::insert(int s,int i)
{
    if(s==1)
    {
        node *now;
        now->data=i;
        now->next=head;
        head=now;
    }
    else
    {
        node *it = head;
        node *re;
        int count = 2;
        do
        {
            re=it;
            it=it->next;
            if(count==s)
            {
                break;
            }
            count++;
        } while (it!=nullptr);
        if(count==s)
        {
            t->data=i;
            t->next=re->next;
            re->next=t;
        }
        else
        {
            cout<<"We don't have that much elements";
        }
    }

}
void linkedlist::dele(int s)
{
    if(head->data==s)
    {
        node *it=head->next;
        delete head;
        head=it;
    }
    else
    {
        node *it=head;
        node *re;
        do
        {
            if(it->data==s)
            {
                break;
            }
            re=it;
            it=it->next;
        } while (it->next!=nullptr);
        if(it->data==s)
        {
            re->next=it->next;
            delete it;
        }
        else
        {
            cout<<"The element is not there in the linked list";
        }
    }
}
int main()
{
    while(1)
    {
        linkedlist a;
        cout<<"Enter 1 to give input"<<endl;
        cout<<"Enter 2 to see the output"<<endl;
        cout<<"Enter 3 to insert"<<endl;
        cout<<"Enter 4 to delete"<<endl;
        cout<<"Enter 5 to exit"<<endl;
        cout<<"Enter the response:- ";
        int res;
        cin>>res;
        cout<<endl;
        if(res==1)
        {
            cout<<"Enter the number:- ";
            int temp;
            cin>>temp;
            a.input(temp);
        }
        if(res==2)
        {
            a.output();
        }
        if(res==3)
        {
            cout<<"Enter the number to be inserted:- ";
            int temp1,temp2;
            cin>>temp1;
            cout<<"Enter the position where number is to be inserted:- ";
            cin>>temp2;
            a.insert(temp2,temp1);
        }
        if(res==4)
        {
            cout<<"Enter the position to be deleted:- ";
            int temp;
            cin>>temp;
            a.dele(temp);
        }
        if(res==5)
        {
            return 0;
        }
        cout<<endl;
    }
    return 0;
}
