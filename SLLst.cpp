#include "SLLst.h"
#include <iostream>

template <class T>
SLLst<T>::~SLLst() {
    for (SLLstNode<T> * p;!isEmpty();) {
    	p=head->next;
    	delete head;
        head=p;
    }
}
template <class T>
void SLLst<T>::addToHead(const T & el) {
    head=new SLLstNode<T>(el,head);
    if(tail == 0)
    	tail=head;
}
template <class T>
void SLLst<T>::addToTail (const T & el){
	if(tail!=0){
		tail->next=new SLLstNode<T>(el,0);
		tail=tail->next;
	}
	else  
		head=tail=new SLLstNode<T>(el);
}
template <class T>
T SLLst<T>::deletFromHead() {
	T el= head->info;
	SLLstNode<T> * tmp =head;
	if (head==tail) 
		head=tail=0;
	else 
 		head=head->next;
	delete tmp;
	return el;
}
template <class T>
T SLLst<T>::deletFromTail() {
	T el = tail->info;
	if (head == tail) {
		delete head;
		head =tail =0 ;
	}
	else  {
		SLLstNode<T> * tmp;
		for (tmp = head;tmp->next != tail ; tmp=tmp->next) ;
			delete tail;
		    tail =tmp;
		    tail->next = 0;
	}
	return el;
}
template <class T>
bool SLLst<T>::isInList(const T & el) const {
	for (SLLstNode<T> * tmp = head;tmp!=tail && !(tmp->info==el);tmp=tmp->next) ;
		return tmp !=0;
}