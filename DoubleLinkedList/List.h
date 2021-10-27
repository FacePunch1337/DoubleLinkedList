#pragma once
#include "Header.h"
#include "Node.h"
template<typename T>
class List
{
private:
	Node<T>* element;
	size_t size;
public:
	List();                                                                  
	size_t GetSize() const;
	void Add(const T);
	void Print(bool order = false);
	void RemoveAt(size_t);
	void InsertBefore(size_t, T);
	void DeleteIndex(const size_t);
	size_t DeleteData(const T);
	
};

template<typename T>
List<T>::List()
{
	element = NULL;
	size = -1;
}

template<typename T>
size_t List<T>::GetSize() const { return size; }


template<typename T>
void List<T>::Add(const T data)
{
	if (size == -1)
		element = new Node<T>(data);
	else
	{
		Node<T>* tmp = element;

		for (size_t i = 0; i < size; i++)
			tmp = tmp->next;

		tmp->next = new Node<T>(data);
		tmp->next->prev = tmp;
	}

	size++;
}

template<typename T>
void List<T>::DeleteIndex(const size_t index)
{
	if (index < 0 || index > size || size == -1)
		throw exception("error");

	Node<T>* tmp = element;
	Node<T>* del_item = nullptr;

	if (index == 0)
	{
		del_item = tmp;
		element = tmp->next;
	}
	else if (index == size)
	{
		for (size_t i = 0; i <= index - 1; i++)
			tmp = tmp->next;

		del_item = tmp->next;
	}
	else
	{
		for (size_t i = 0; i <= index - 1; i++)
			tmp = tmp->next;

		del_item = tmp;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}

	delete del_item;
	size--;
}

template<typename T>
size_t List<T>::DeleteData(const T data)
{
	if (size == -1)
		throw exception("empty list");

	Node<T>* tmp = element;
	size_t count = 0;

	for (size_t i = 0; i <= size; i++)
	{
		if (data == tmp->data)
		{
			DeleteIndex(i);
			tmp = element;
			count++;
		}

		tmp = tmp->next;
	}

	return count;
}

template<typename T>
void List<T>::Print(bool order)
{
	if (element == NULL) {
		cout << "Empty List" << endl;
		return;
	}

	if (order) {
		while (element->prev) {
			element = element->prev;
		}
	}
	Node<T>* tmp = element;
	cout << endl;
	while (tmp) {
		cout << tmp->data << " ";
		tmp = tmp->prev;
	}
	tmp = element->next;
	while (tmp) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
}

template<typename T>
void List<T>::RemoveAt(size_t index)
{
	if (element == NULL) {
		throw::exception("Removing from empty list");
	}
	while (element -> prev) {
		element = element->prev;
	}
	for (size_t i = 0; i < index; i++) {
		element=element->next;
		if (element == NULL) {
			throw::exception("Index out of bounds");
		}
	}
	if(element->next) element->next->prev = element->prev;
	if (element->prev) element->prev->next = element->next;
	Node<T>*tmp = element;
	if(element->prev) element = element->prev;
	else if(element->next) element = element->next;

	if(tmp==element) element = NULL;
	 
	delete tmp;


	
}


template<typename T>
void List<T>::InsertBefore(size_t index, T value) {
	if (element == NULL) {
		throw::exception("No <<Before>>");
	}
	while (element->prev) {
		element = element->prev;
	}
	for (size_t i = 0; i < index; i++) {
		element = element->next;
		if (element == NULL) {
			throw::exception("Index out of bounds");
		}
	}
	Node<T>* tmp = new Node<T>(value);
	if (index) {
		tmp->next = element;
		tmp->prev = element->prev;
		element->prev->next = tmp;
		element->prev = tmp;
	}
	else {
		
	}
	

}
