#include <stdio.h>
#include <iostream>
using namespace std;

void Add_head(int a[100], int &n, int d) // Thêm vào đầu (Array) = Push (Stack) = Enqueue (Queue)
{
	if (n == 100)
	{
		cout << "Mảng đã đầy\n";
	}
	else
	{
		if (n == 0)
		{
			a[0] = d;
		}
		else
		{
			for (int i = n - 1; i >= 0; i--)
			{
				a[i + 1] = a[i];
			}
			a[0] = d;
		}
		n++;
	}
}
void Delete_head(int a[100], int &n) // Xoá ở đầu (Array) = Pop (Stack)
{
	if (n == 0)
	{
		cout << "Mảng rỗng";
	}
	else
	{
		n--;
		for (int i = 0; i < n; i++)
		{
			a[i] = a[i + 1];
		}
	}
}
void Delete_tail(int a[100], int &n) // Xoá ở đuôi (Array) = Dequeue (Queue)
{
	if (n == 0)
	{
		cout << "Mảng rỗng";
	}
	else
	{
		n--;
	}
}

void Print(int a[100], int n) // Duyệt mảng và in ra số phần tử (Array) = Size (Stack và Queue)
{
	cout << "Các phần tử của mảng là:\n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\n";
	}
	cout << "Số phần tử của mảng là: " << n << "\n";
}

void Find(int a[100], int n, int d) // Tìm phần tử d trong list
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == d)
		{
			count++;
		}
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
	int a[100];
	int n = 0;
	Add_head(a, n, 9);
	Add_head(a, n, 10);
	Add_head(a, n, 12);
	Add_head(a, n, -34);
	Delete_tail(a, n);
	Delete_head(a, n);
	Print(a, n);
	Find(a, n, 10);
	return 0;

	return 0;
}
