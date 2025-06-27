#include <iostream>
using namespace std;


class node{
    public:
    int data;
    node* right;
    node* left;
    public: 
    node(int data)
    {
        this->data=data;
        this->right=nullptr;
        this->left=nullptr;
    }
};


node* tree(node* &root)
{
    int data;
    cout<<"Enter data for root"<<endl;
    cin>>data;

    root=new node(data);
    
    if (data == -1)
    {
        return NULL;
    }

    cout<<"Enter data for right root of"<< data <<endl;
    root->right=tree(root->right);

    cout<<"Enter data for left root of"<< data <<endl;
    root->left=tree(root->left);

    return root;
}

int main()
{

    node* root=nullptr;
    root=tree(root);
}