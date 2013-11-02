#include "SLLst.h"
#include <iostream>

template <class T>
SLLst<T>::~SLLst() {
    for (SLLstNode * p;!isEmpty();) {
    	p=head->next;
    	delet head;
        head=p;
    }
}
template <class T>
SLLst<T>::addToHead(const T & el) {
    head=new SLLstNode(el,head);
    if(tail == 0)
    	tail=head;
}
template <class T>
T SLLst<T>::deletFromTail() {
	T el = tail->info;
	if (head == tail) {
		delete head;
		head =tail =0 ;
	}
	else  {
		SLLstNode * tmp;
		for (tmp = head;tmp->next != tail ; tmp=tmp->next) ;
			delete tail;
		    tail =tmp;
		    tail->next = 0;
	}
	return el;
}