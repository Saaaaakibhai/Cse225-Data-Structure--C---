#include <iostream>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* newNode(int item)
{
    node* temp = new node();
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

node* Insert(node* root, int item)
{
    if(root == NULL)
    {
        root = newNode(item);
        return root;
    }
    else if(item <= root->data)
    {
        root->left = Insert(root->left, item);
    }
    else
    {
        root->right = Insert(root->right, item);//5
    }

    return root;
}

void PreOrder(node* root)
{
    if(root == NULL)
        return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

int Bigger(int n1, int n2) {
    if (n1 < n2) return n2;
    else return n1;
}

int GetHeight(node* root) {
    if (root == NULL) return 0;
    else return Bigger(GetHeight(root->left), GetHeight(root->right)) + 1;
}


void InOrder(node* root)
{
    if(root == NULL)
        return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(node* root)
{
    if(root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

node* findMin(node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node* findMax(node* root)
{
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

bool Search(node* root, int item)
{
    if(root == NULL)
    {
        return false;
    }
    else if(root->data == item)
    {
        return true;
    }
    else if(item < root->data)
    {
        return Search(root->left, item);
    }
    else
    {
        return Search(root->right, item);
    }
}

node* Delete(node* root, int item)
{
    if(root == NULL)
    {
        return root;
    }
    else if(item < root->data)
    {
        root->left = Delete(root->left, item);
    }
    else if(item > root->data)
    {
        root->right = Delete(root->right, item);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if(root->left == NULL)
        {
            node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            node* temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    node* root = NULL;
    root = Insert(root,25);
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,50);
    root = Insert(root,40);
    root = Insert(root,60);


    PreOrder(root);
    cout << endl;

    InOrder(root);
    cout << endl;

    root = Delete(root,60);

    PostOrder(root);
    cout << endl;

    cout << findMin(root)->data << endl;
    cout << findMax(root)->data << endl;

    cout<< GetHeight(root);

    return 0;
}
