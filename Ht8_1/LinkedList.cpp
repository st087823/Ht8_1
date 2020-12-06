#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList& list)
{
	count = 0;
	head = tail = nullptr;
	Node* temp = list.head;
	while (temp != nullptr) {
		addToTail(temp->data); //(*temp).data;
		temp = temp->next; //(*temp).next;
	}
}

LinkedList::~LinkedList()
{
	Node* temp = head;
	while (temp != nullptr) {
		Node* node = temp;
		temp = temp->next;
		delete node;
	}
}

bool LinkedList::addToHead(int element)
{
	if (head == nullptr) 
	{
		head = tail = new Node(element);
	}
	else 
	{
		/*
		Node* newHead = new Node(element, head);
		head = newHead;
		*/
		head = new Node(element, head);
	}
	count++;
	return true;
}

bool LinkedList::addToTail(int element)
{
	if (tail == nullptr)
	{
		head = tail = new Node(element);
	}
	else
	{
	    /* Node* newTail = new Node(element);
	    (*tail).next = newTail;*/
		tail->next = new Node(element);
		tail = tail->next; //tail = (*tail).next;
	}
	count++;
	return true;
}

bool LinkedList::add(int index, int element)
{
	if (index == 0) 
	{
		return addToHead(element);
	}
	if (index == count) 
	{
		return addToTail(element);
	}
	if (!indexValid(index)) 
	{
		return false;
	}
	Node* temp = head;
	for (int i = 0; i < index - 1; i++) 
	{
		temp = temp->next;
	}
	temp = new Node(element, temp->next);
	count++;
	return true;
}

int LinkedList::get(int index)
{
	if (!indexValid(index)) return -1;
	if (index == 0) return head->data;
	if (index == count - 1) return tail->data;

	Node* temp = head;
	for (int i = 0; i < index; i++) 
	{
		temp = temp->next;
	}
	return temp->data;
}

bool LinkedList::set(int index, int element)
{
	if (!indexValid(index)) return false;
	if (index == 0) head->data = element;
	if (index == count - 1) tail->data = element; 
	else
	{
		Node* temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		temp->data = element;
	}
	return true;
}

bool LinkedList::indexValid(int index)
{
	return index >= 0 && index < count;
}

void LinkedList::inserHeadtNode(Node*& node)
{
	node->next = head;
	head = node;
	count++;
}

void LinkedList::insertTailNode(Node*& node)
{
	tail->next = node;
	tail = node;
	tail->next = nullptr;
	count++;
}

void LinkedList::insertNode(int index, Node*& node)
{
	if (index == 0){
		return inserHeadtNode(node);
	}
	if (index = count - 1){
		return insertTailNode(node);
	}

	Node* temp = head;
	for (int i = 0; i < index - 1; i++) {
		temp = temp->next; 
	}
	node->next = temp->next;
	temp->next = node;
	count++;
}

int LinkedList::length()
{
	return count;
}

int& LinkedList::operator[](int index)
{
	if (head == nullptr)
	{
		addToHead(0);
		return head->data;
	}
	if (index <= 0)
	{
		return head->data;
	}
	if (index >= count)
	{
		addToTail(0);
		return tail->data;
	}
	if (index == count - 1)
	{
		return tail->data;
	}

	Node* temp = head;
	for (int i = 0; i < index; ++i)
	{
		temp = temp->next;
	}
	return temp->data;
}

void LinkedList::operator+=(int element)
{
	addToTail(element);
}

int LinkedList::extractHead()
{
	if (head == nullptr) // список пуст
	{
		return -1;
	}
	if (head == tail) // 1 эл-т
	{
		int elem_head = head->data;
		delete head;
		head = tail = nullptr;
		count = 0;
		return elem_head;
	}
	int elem_head = head->data;
	Node* temp = head;
	head = head->next;
	delete head;
	count--;
	return elem_head;
}

int LinkedList::extractTail()
{
	if (count < 2)
	{
		return extractHead();
	}

	Node* temp = head;
	while (temp->next->next != nullptr) //temp->next->next  предпоследн эл-т
	{
		temp = temp->next;
	}
	int elem_tail = temp->data;
	delete tail;
	tail = temp;
	tail->next = nullptr;
	count--;
	return elem_tail;
}

int LinkedList::extract(int index)
{
	if (!indexValid(index)) return -1;
	if (index == 0) return extractHead();
	if (index = count - 1) return extractTail();
	if (head == nullptr) return 0;
	
	Node* temp = head;
	for (int i = 0; i < index - 1; temp = temp->next);
	Node* deleted = temp->next;
	int result = deleted->data;
	temp->next = temp->next->next;
	delete deleted;
	count--;
	return result;
}

void LinkedList::operator-=(int index)
{
	extract(index);
}

LinkedList& LinkedList::operator=(const LinkedList& list)
{
	if (this == &list) 
	{
		return *this;
	}

	Node* temp = head;
	while (temp != nullptr)
	{
		Node* node = temp;
		temp = temp->next;
		delete node;
	}

	count = 0;
	temp = list.head;
	while (temp != nullptr) 
	{
		addToTail(temp->data);
		temp = temp->next;
	}
	return *this;
}

int LinkedList::indexOf(int element)
{
	int i = 0;
	Node* temp = head;
	while (temp != nullptr)
	{
		if (temp->data == element)
		{
			return i;
			break;
		}
		temp = temp->next;
		i++;
	}
	return -1;
}

bool LinkedList::contains(int element)
{
	if (indexOf(element) > -1) return true;
	return false;
}

std::ostream& operator<<(std::ostream& stream, const LinkedList list)
{
	stream << "[" << list.count << "] { ";
	if (list.head == nullptr) 
	{
		stream << " }";
	}
	else 
	{
		Node* temp = list.head;
		while (temp != nullptr) 
		{
			stream << temp->data;
			if (temp->next != nullptr) 
			{
				stream << ", ";
			}
			temp = temp->next;
		}
		stream << " }";
	}
	return stream;
}

bool LinkedList::swap(int index1, int index2)
{
	if (!indexValid(index1) || !indexValid(index2)) return false;
	if (index1 == index2) return true;
	if (index1 > index2) return swap(index1, index2);

	Node* node1 = head;
	if (index1 == 0) 
	{
		head = head->next;
	}
	else
	{
		for (int i = 0; i < index1 - 1; i++)
		{
			node1 = node1->next;
		}
		Node* temp = node1;
		node1 = node1->next;
		temp->next = temp->next->next;
	}
	count--;


	Node* node2 = head;
	if (index2 == count - 1)
	{
		while (node2->next->next != nullptr) 
		{
			node2 = node2->next;
		}
		tail = node2;
		node2 = node2->next;
		tail->next = nullptr;
	}
	else
	{
		for (int i = 0; i < index2 - 1; i++)
		{
			node2 = node2->next;
		}
		Node* temp = node2;
		node2 = node2->next;
		temp->next = temp->next->next;
	}
	count--;

	insertNode(index1, node2);
	insertNode(index2, node1);
	return false;
}


