#include "Header.h"

template<typename T>
List<T>::List():element{NULL}
{
}

template<typename T>
void List<T>::Add(T data,bool tail)
{
	if (element == NULL) {
		element = new Node<T>(data);
	}
	else if(tail){
		//append to tail
		while (element->next != NULL) {
			element = element->next;
		}
		element->next = new Node<T>(data);
		element->next->prev = element;
	}
	else {
		//insert before head
		while (element->prev != NULL) {
			element = element->prev;
		}
		element->prev = new Node<T>(data);
		element->prev->next = element;
	}

}

template<typename T>
void List<T>::Print(bool order)
{
	if (element == NULL) {
		cout<<"Empty List"<<endl;
		return;
	}
	Node<T>* tmp = element;

	while (tmp) {
		cout<<tmp->data << " ";
		tmp = tmp->prev;
	}
	while (tmp) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
}





