#include <iostream>
using namespace std;
#define max 20

class BST
{
    struct node
    {
        int data;
        node *lc, *rc;
    }*root;

    public:
    BST()
    {
        root = NULL;
    }
    void create();
    void display();
    void preorder(node *t);
    void postorder(node *t);
    void inorder(node *t);
    int height(node *t);
    void callheight();
    void min();
    void mirror();
    void swapn(node *t);
    void search();
};

void BST::create()
{
    char ans = 'y';
    do
    {
        node *temp, *curr;
        temp = new node;
        temp->lc = NULL;
        temp->rc = NULL;
        cout<<"\nEnter data : ";
        cin>>temp->data;
        if(root==NULL)
        {
            root=temp;
        }
        else
        {
            curr=root;
            while(curr!=NULL)
            {
                if(temp->data < curr->data)
                {
                    if(curr->lc==NULL)
                    {
                        curr->lc=temp;
                        break;
                    }
                    else
                    {
                        curr = curr->lc;
                    }
                }
                if(temp->data > curr->data)
                {
                    if(curr->rc==NULL)
                    {
                        curr->rc=temp;
                        break;
                    }
                    else
                    {
                        curr = curr->rc;
                    }
                }
            }
        }
        cout<<"\nDo you want to enter more?(y/n) : ";
        cin>>ans;
    }while(ans=='y' || ans=='Y');
}

void BST::display()
{
    cout<<"\nPreorder : ";
    preorder(root);
    cout<<"\nPostorder : ";
    postorder(root);
    cout<<"\nInorder : ";
    inorder(root);
}

void BST::preorder(node *t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
        preorder(t->lc);
        preorder(t->rc);
    }
}

void BST::postorder(node *t)
{
    if(t!=NULL)
    {
        postorder(t->lc);
        postorder(t->rc);
        cout<<t->data<<" ";
    }
}

void BST::inorder(node *t)
{
    if(t!=NULL)
    {
        inorder(t->lc);
        cout<<t->data<<" ";
        inorder(t->rc);
    }
}

int BST::height(node *t)
{
    int lheight, rheight;
    if(t==NULL)
    {
        return 0;
    }
    else
    {
        lheight = height(t->lc);
        rheight = height(t->rc);
        if(lheight > rheight)
        {
            return(lheight + 1);
        }
        else
        {
            return(rheight + 1);
        }
    }
}

void BST::callheight()
{
    cout<<"\nThe height of the BST : "<<height(root);
}

void BST::min()
{
    node *t=root;
    while(t->lc!=NULL)
    {
        t=t->lc;
    }
    cout<<"\nMinimum Element of the BST : "<<t->data;
}

void BST::mirror()
{
    if(root==NULL)
    {
        cout<<"\nBST is Empty";
    }
    else
    {
        swapn(root);
    }
}

void BST::swapn(node *t)
{
    node *swap=NULL;
    if(t->lc!=NULL)
        swapn(t->lc);
    if(t->rc!=NULL)
        swapn(t->rc);
    swap = t->lc;
    t->lc = t->rc;
    t->rc = swap;
}

void BST::search()
{
    node *t=root;
    int k, cmp=1, flag=0;
    cout<<"\nEnter the element to search : ";
    cin>>k;
    if(t==NULL)
    {
        cout<<"\nBST is empty";
    }
    else
    {
        while(t!=NULL)
        {
            if(t->data == k)
            {
                flag = 1;
                break;
            }
            else if(k < t->data)
            {
                t=t->lc;
                cmp++;
            }
            else
            {
                t=t->rc;
                cmp++;
            }
        }
    }
    if(flag==0)
    {
        cout<<"\nElement is not present is BST";
    }
    else
    {
        cout<<"\nElement found in BST in "<<cmp<<" comparisons";
    }
}

int main()
{
    BST obj;
    int ch;
    do
    {
        cout<<"\n******MENU******";
        cout<<"\n1 : Create";
        cout<<"\n2 : Display";
        cout<<"\n3 : Height";
        cout<<"\n4 : Minimum Value";
        cout<<"\n5 : Mirror";
        cout<<"\n6 : Search";
        cout<<"\n7 : Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1 : 
                obj.create();
                break;
            case 2 :
                obj.display();
                break;
            case 3 :
                obj.callheight();
                break;
            case 4 :
                obj.min();
                break;
            case 5 : 
                obj.mirror();
                break;
            case 6 : 
                obj.search();
                break;
            case 7 :
                cout<<"\nEnd of Program";
                break; 
        }
    }while(ch!=7);
    return 0;
}
