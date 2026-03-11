#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
using namespace std;
#define ll long long
struct Node
{
	int value;
	Node* next;
};
class LinkedList
{
public:
	Node* head;
	LinkedList()
	{
		head = nullptr;
	}
	void insert(int val)
	{
		Node* newnode = new Node;
		newnode->value = val;
		newnode->next = nullptr;
		if (head == nullptr)
		{
			head = newnode;
		}
		else
		{
			Node* prev = head;
			while (prev->next != nullptr)
			{
				prev = prev->next;
			}
			prev->next = newnode;
		}
	}
	void display()
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << "\t";
			current = current->next;
		}
	}
	void insert_at_first(int val)
	{
		Node* newnode = new Node;
		newnode->value = val;
		newnode->next = head;
		head = newnode;
	}
	void insert_at_end(int val)
	{
		Node* newnode = new Node;
		newnode->value = val;
		newnode->next = nullptr;
		if (head == nullptr)
		{
			head = newnode;
			return;
		}
		Node* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newnode;
	}
	void insert_between_values(int v1, int v2, int v3)
	{
		if (head == nullptr)
		{
			return;
		}
		Node* prev = head;
		Node* curr = head;
		while (curr != nullptr)
		{
			if (prev->value == v1 && curr->value == v2)
			{
				Node* newnode = new Node;
				newnode->value = v3;
				newnode->next = curr;
				prev->next = newnode;
				return;
			}
			prev = curr;
			curr = curr->next;
		}
	}
	void delete_value(int val)
	{
		if (head == nullptr) // list is empty
		{
			return;
		}
		if (head->value == val) // first element
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		Node* prev = head;
		Node* curr = head;
		while (curr != nullptr)
		{
			if (curr->value == val)
			{
				prev->next = curr->next;
				delete curr;
				return;
			}
			prev = curr;
			curr = curr->next;
		}
	}
	bool search(int val)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->value == val)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
};
int main()
{
	LinkedList l;
	l.insert(9);
	l.insert(5);
	l.insert(13);
	l.insert(17);
	l.insert_at_first(15);
	l.insert_at_end(20);
	l.insert_between_values(13, 17, 12);
	l.delete_value(17);
	l.delete_value(9);
	l.display();



	cout << endl;
	int n;
	cout << "Enter a value to seacrh " << endl;
	cin >> n;
	if (l.search(n)) {
		cout << "Exist" << endl;
	}
	else
	{
		cout << "Not Exist" << endl;
	}
}