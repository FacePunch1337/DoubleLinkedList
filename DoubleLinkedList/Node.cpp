#include "Header.h"

template<typename T>
Node<T>::Node():data{data},next{NULL},prev{NULL}
{
}

template<typename T>
Node<T>::Node(T data): data{ data }, next{ NULL }, prev{ NULL }
{
}

