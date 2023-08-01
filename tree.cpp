#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};




node* createBinaryTree(node *root)
{
    cout<<"Enter the root data : "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    
    if(root->data==-1)
    {
        return NULL;
    }
    
    cout<<"Enter the data to left of "<<root->data<<endl;
    root->left=createBinaryTree(root->left);
    cout<<"Enter the data to right of "<<root->data<<endl;
    root->right=createBinaryTree(root->right);
    
    return root;
}






void ReverselevelOrderTraversal(node *root)
{
    stack <int> s;
    if(root==NULL)
    {
        return ;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    s.push(-1);
    
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        
        if(temp==NULL)
        {
            
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
                s.push(-1);
            }
        }
        else {
            
        if(temp->right)
        {
            q.push(temp->right);
        }
        if(temp->left)
        {
            q.push(temp->left);
        }
        s.push(temp->data);
        
        }
        
        
    }
    while(!s.empty())
    {
        if(s.top()==-1){
            cout<<endl;
            s.pop();
        }
        cout<<s.top()<<" ";
        s.pop();
    }
    
}






node* levelOrderTraversal(node *root)
{
    if(root==NULL)
    {
        return root;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        
        if(temp==NULL)
        {
            
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else {
            
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        cout<<temp->data<<" ";
        
        }
        
        
    }
    return root;
    
}






void inorderTraversal(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    
    node *temp=root;
    inorderTraversal(temp->left);
    cout<<temp->data<<" ";
    inorderTraversal(temp->right);
    
    // return root;
}






void preorderTraversal(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    
    // node *temp=root;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    
    // return root;
}






void postorderTraversal(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    
    // node *temp=root;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
    
    // return root;
}


int main(){
    node *root=NULL;
    root=createBinaryTree(root);
    //5 10 6 -1 -1 17 -1 -1 2 -1 20 -1 -1
    root=levelOrderTraversal(root);
    // ReverselevelOrderTraversal(root);
    cout<<"Inorder Traversal for root is : "<<endl;
    inorderTraversal(root);
    cout<<endl<<"Preorder Traversal for root is : "<<endl;
    preorderTraversal(root);
    cout<<endl<<"Postorder Traversal for root is : "<<endl;
    postorderTraversal(root);
}



