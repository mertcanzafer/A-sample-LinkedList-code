#include <iostream>

using namespace std;

class Node {
public:
	int Value;

	Node* Next; //Node pointer to point the next elemet
};


void print_values(Node* ptr)
{
	cout << "The elements are: " << endl;

	for (; ptr != NULL; ptr = ptr->Next)
	{
		cout << ptr->Value << " ";
	}

	cout << endl;
}

void Front(Node** ptr,int new_value)
{
   // To insert an element in front of the head 
   // 1. Prepare a new Node.
   // 2. Put it in front of the current head.
   // 3. Move head of the list to point to the new node

	Node* newHead = new Node();

	newHead->Value = new_value;
	newHead->Next = *ptr;

	*ptr = newHead;
}

void Back(Node** ptr, int new_value)
{
	//1. Prepare a new Node.
	Node* newNode = new Node();
	newNode->Value = new_value;
	// knowing the fact that our new node will be the last node, its next pointer will point Null!!
	newNode->Next = NULL;

	//2. If linked list is empty , New node will be a head node.
	if (*ptr == NULL)
	{
		*ptr = newNode;
		return;
	}

	//3. Find the last node.

	Node* lastnode = *ptr;

	while (lastnode->Next != NULL)
	{
		lastnode = lastnode->Next;
	}
	
	//4. Insert newNode after last node(at the end)

	lastnode->Next = newNode;

}

void insert_after(Node* previous, int new_value)
{
	//1. Check if previous node is null.
	if (previous == NULL)
	{
		cout << "The previous can not be null." << endl;
		return;
	}
	//2. Prepare a new node.
	Node* newNode = new Node();
	newNode->Value = new_value;
	//3. Insert newnode after the previous one.
	newNode->Next = previous->Next;
	previous->Next = newNode;

}

int main()
{
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	head->Value = 1;

	head->Next = second;

	second->Value = 2;

	second->Next = third;

	third->Value = 3;

	third->Next = NULL;

	print_values(head);

	//Front(&head,0);
	//Back(&head, 4);
	insert_after(head, -1);
	insert_after(second, -2);
	insert_after(third, -3);

	print_values(head);

	delete head;
	delete second;
	delete third;
	
	cout << endl;
	return 0;
}