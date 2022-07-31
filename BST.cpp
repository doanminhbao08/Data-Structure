#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
    Node *pre;
    int data;
    Node *next;
};

Node *Create_node(int d)
{
    Node *p = new Node();
    p->pre = NULL;
    p->data = d;
    p->next = NULL;
    return p;
}

Node *Add(int d, Node *&root)
{
    if (root == NULL)
    {
        root = Create_node(d);
    }
    else
    {
        if (d == root->data)
        {
            cout << "Không thể thêm " << d << " vào cây\n";
        }
        else if (d < root->data)
        {
            root->pre = Add(d, root->pre);
        }
        else
        {
            root->next = Add(d, root->next);
        }
    }
    return root;
}
void Find_min(Node *root)
{
    Node *temp;
    while (root != NULL)
    {
        temp = root;
        root = root->pre;
    }
    cout << "Giá trị nhỏ nhất là: " << temp->data << "\n";
}
void Find_max(Node *root)
{
    Node *temp;
    while (root != NULL)
    {
        temp = root;
        root = root->next;
    }
    cout << "Giá trị lớn nhất là: " << temp->data << "\n";
}

void Search(int d, Node *root)
{
    if (d == root->data)
    {
        cout << "Tồn tại " << d << " trong cây\n";
    }
    else if (d < root->data)
    {
        if (root->pre != NULL)
        {
            Search(d, root->pre);
        }
        else
            cout << "Không tồn tại " << d << " trong cây\n";
    }
    else
    {
        if (root->next != NULL)
        {
            Search(d, root->next);
        }
        else
            cout << "Không tồn tại " << d << " trong cây\n";
    }
}
int main()
{
    Node *root;
    root = NULL;
    Add(9, root);
    Add(10, root);
    Add(12, root);
    Add(1, root);
    Add(19, root);
    Add(5, root);
    Add(7, root);
    Add(9, root);
    Add(7, root);
    Find_min(root);
    Find_max(root);
    Search(5, root);
    Search(17, root);
    return 0;
}