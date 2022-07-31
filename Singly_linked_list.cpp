#include <stdio.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
struct List
{
    Node *head;
    Node *tail;
};

void Create_list(List &l)
{
    l.head = NULL;
    l.tail = NULL;
}

void Add_head(List &l, int d) // Thêm vào đầu (Linked List) = Push (Stack) = Enqueue (Queue)
{
    Node *p = new Node();
    p->data = d;
    p->next = NULL;
    if (l.head == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
}
void Delete_head(List &l) // Xoá ở đầu (Linked List) = Pop (Stack)
{
    if (l.head == NULL)
    {
        cout << "Danh sách rỗng";
    }
    else
    {
        l.head = l.head->next;
    }
}
void Delete_tail(List &l) // Xoá ở đuôi (Linked List) = Dequeue (Queue)
{
    Node *p;
    p = l.head;
    if (p == NULL)
    {
        cout << "Danh sách rỗng";
    }
    else
    {
        while (p->next != l.tail)
        {
            p = p->next;
        }
        p->next = NULL;
        l.tail = p;
    }
}

void Print(List l) // Duyệt list và in ra số phần tử (Linked List) = Size (Stack và Queue)
{
    int count = 0;
    Node *p;
    p = l.head;
    if (p == NULL)
    {
        cout << "Danh sách rỗng";
    }
    else
    {
        cout << "Các phần tử của danh sách là:"
             << "\n";
        while (p != NULL)
        {
            count++;
            cout << p->data << "\n";
            p = p->next;
        }
        cout << "Số phần tử của danh sách là: " << count << "\n";
    }
}

void Find(List l, int d) // Tìm phần tử d trong list
{
    int count = 0;
    Node *p;
    p = l.head;
    if (p == NULL)
    {
        cout << "Danh sách rỗng";
    }
    while (p != NULL)
    {
        if (d == p->data)
        {

            count++;
        }
        p = p->next;
    }
    if (count == 0)
    {
        cout << "Không có phần tử " << d << " trong danh sách";
    }
    else
    {
        cout << "Có phần tử " << d << " trong danh sách";
    }
}
int main()
{
    List list;
    Create_list(list);
    Add_head(list, 9);
    Add_head(list, 10);
    Add_head(list, 12);
    Add_head(list, -34);
    Delete_tail(list);
    //    Delete_head(list);
    Print(list);
    Find(list, 10);
    return 0;
}