//--------------------------------------------
// NAME: Daniel Georgiev
// CLASS: XIb
// NUMBER: 11
// PROBLEM: #3
// FILE NAME: List.cc (unix file name)
// FILE PURPOSE:
// class String implementation
//---------------------------------------------

#include <iostream>
#include <cstdlib>
using namespace std;

class ListError {};

template<class T> class List {
	struct Elem {
		T data_;
		Elem* next_;
		Elem* prev_;
		
		Elem(T val)
		: data_(val),
		  next_(0),
		  prev_(0)
		{}
	};
	
	Elem* head_;
	Elem* tail_;
public:
	List();
	~List();
	
	void push_back(const T& val);
	void pop_back();
	void push_front(const T& val);
	void pop_front();
	
	T& back();
	const T& back() const;
	T& front();
	const T& front() const;
	
	int size() const;
	bool empty() const;
	void clear();
	void swap(List& other);
	
	List(const List& other);
	List& operator=(const List& other);
	
	class iterator {
		friend class List;
		
		Elem* current_;
		
		iterator(Elem* elem)
		: current_(elem)
		{}
	public:
		iterator& operator++() {
			current_ = current_ -> next_;
			return *this;
		}
		
		iterator& operator++(int) {
			current_ = current_ -> next_;
			return *this;
		}
		
		bool operator==(const iterator& other) const {
			return current_ == other.current_;
		}
		
		bool operator!=(const iterator& other) const {
			return !operator==(other);
		}
				
		T& operator*() {
			return current_ -> data_;
		}
		
		T* operator->() {
			return &current_ -> data_;
		}
	};
	
	class const_iterator {
		friend class List;
		
		Elem* current_;
		
		const_iterator(Elem* elem)
		: current_(elem)
		{}
	public:
		const_iterator& operator++() {
			current_ = current_ -> next_;
			return *this;
		}
		
		const_iterator& operator++(int) {
			current_ = current_ -> next_;
			return *this;
		}
		
		bool operator==(const const_iterator& other) const {
			return current_ == other.current_;
		}
		
		bool operator!=(const const_iterator& other) const {
			return !operator==(other);
		}
				
		const T& operator*() {
			return current_ -> data_;
		}
		
		const T* operator->() {
			return &current_ -> data_;
		}
	};
	
	class reverse_iterator {
		friend class List;
		
		Elem* current_;
		
		reverse_iterator(Elem* elem)
		: current_(elem)
		{}
	public:
		reverse_iterator& operator++() {
			current_ = current_ -> prev_;
			return *this;
		}
		
		reverse_iterator& operator++(int) {
			current_ = current_ -> prev_;
			return *this;
		}
		
		bool operator==(const reverse_iterator& other) const {
			return current_ == other.current_;
		}
		
		bool operator!=(const reverse_iterator& other) const {
			return !operator==(other);
		}
				
		T& operator*() {
			return current_ -> data_;
		}
		
		T* operator->() {
			return &current_ -> data_;
		}
	};
	
	class const_reverse_iterator {
		friend class List;
		
		Elem* current_;
		
		const_reverse_iterator(Elem* elem)
		: current_(elem)
		{}
	public:
		const_reverse_iterator& operator++() {
			current_ = current_ -> prev_;
			return *this;
		}
		
		const_reverse_iterator& operator++(int) {
			current_ = current_ -> prev_;
			return *this;
		}
		
		bool operator==(const const_reverse_iterator& other) const {
			return current_ == other.current_;
		}
		
		bool operator!=(const const_reverse_iterator& other) const {
			return !operator==(other);
		}
				
		const T& operator*() {
			return current_ -> data_;
		}
		
		const T* operator->() {
			return &current_ -> data_;
		}
	};
	
	iterator begin();
	iterator end();
	
	const_iterator begin() const;
	const_iterator end() const;
	
	reverse_iterator rbegin();
	reverse_iterator rend();
	
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
	
	iterator insert(iterator pos, const T& x);
	iterator erase(iterator pos);
	iterator erase(iterator first, iterator last);
};

//--------------------------------------------
// FUNCTION: List
// default constructor of List
// PARAMETERS:
// void
//---------------------------------------------
template<class T>
List<T>::List()
: head_(new Elem(0)),
  tail_(new Elem(0))
{
	head_ -> next_ = tail_;
	tail_ -> prev_ = head_;
}

//--------------------------------------------
// FUNCTION: List
// List destructor
// PARAMETERS:
// void
//---------------------------------------------
template<class T>
List<T>::~List() {
	while(!empty()) {
		pop_front();
	}

	delete head_;
	delete tail_;
}

//--------------------------------------------
// FUNCTION: push_back
// adds elem to end of the list
// PARAMETERS:
// const T& val:
// elem to add
//---------------------------------------------
template<class T>
void List<T>::push_back(const T& val) {
	Elem* newElem = new Elem(val);
	
	newElem -> prev_ = tail_ -> prev_;
	newElem -> next_ = tail_;
	
	tail_ -> prev_ -> next_ = newElem;
	tail_ -> prev_ = newElem;
}

//--------------------------------------------
// FUNCTION: pop_back
// deletes last elem of list
// PARAMETERS:
// void
//---------------------------------------------
template<class T>
void List<T>::pop_back() {
	if(empty()) {
		throw ListError();
	} else {
		Elem* back = tail_ -> prev_;
		tail_ -> prev_ = back -> prev_;
		tail_ -> prev_ -> next_ = tail_;
		
		delete back;
	}
}

//--------------------------------------------
// FUNCTION: push_front
// adds elem to beginning of list
// PARAMETERS:
// const T& val:
// elem to add
//---------------------------------------------
template<class T>
void List<T>::push_front(const T& val) {
	Elem* newElem = new Elem(val);
	
	newElem -> prev_ = head_;
	newElem -> next_ = head_ -> next_;
	
	head_ -> next_ = newElem;
	newElem -> next_ -> prev_ = newElem;
}

//--------------------------------------------
// FUNCTION: pop_front
// deletes elem from beginning of list
// PARAMETERS:
// void
//---------------------------------------------
template<class T>
void List<T>::pop_front() {
	if(empty()) {
		throw ListError();
	} else {
		Elem* front = head_ -> next_;
		head_ -> next_ = front -> next_;
		head_ -> next_ -> prev_ = head_;
		
		delete front;
	}
}

//--------------------------------------------
// FUNCTION: back
// returns reference to last elem of list
// PARAMETERS:
// void
//---------------------------------------------
template<class T>
T& List<T>::back() {
	return tail_ -> prev_ -> data_;
}

//--------------------------------------------
// FUNCTION: back
// returns const reference to last elem of list
// PARAMETERS:
// void
//---------------------------------------------
template<class T>
const T& List<T>::back() const {
	return back();
}

//--------------------------------------------
// FUNCTION: front
// returns reference to first elem of list
// PARAMETERS:
// void
//---------------------------------------------
template<class T>
T& List<T>::front() {
	return head_ -> next_ -> data_;
}

//--------------------------------------------
// FUNCTION: front
// returns const reference to first elem of list
// PARAMETERS:
// void
//---------------------------------------------
template<class T>
const T& List<T>::front() const {
	return front();
}

//--------------------------------------------
// FUNCTION: size
// returns the size of list
// PARAMETERS:
// void
//---------------------------------------------
template<class T>
int List<T>::size() const {
	int size = 0;
	
	for(List::const_iterator it = begin();it != end();it++) {
		size++;
	}
	
	return size;
}

//--------------------------------------------
// FUNCTION: empty
// returns true if list is empty
// PARAMETERS:
// void
//---------------------------------------------
template<class T>
bool List<T>::empty() const {
	return head_ -> next_ == tail_;
}

//--------------------------------------------
// FUNCTION: clear
// deletes the content of list
// PARAMETERS:
// void
//---------------------------------------------
template<class T>
void List<T>::clear() {
	while(!empty()) {
		pop_front();
	}
}

//--------------------------------------------
// FUNCTION: swap
// swaps the content of this list with
// content of the other list
// PARAMETERS:
// List& other
//---------------------------------------------
template<class T>
void List<T>::swap(List& other) {
	if(this != &other) {
		List temp = *this;
		
		clear();
		for(List::iterator it = other.begin();it != other.end();it++) {
			push_back(*it);
		}
		
		other.clear();
		for(List::iterator it = temp.begin();it != temp.end();it++) {
			other.push_back(*it);
		}
	}
}

//--------------------------------------------
// FUNCTION: List
// copying constructor of class List
// PARAMETERS:
// const List& other
//---------------------------------------------
template<class T>
List<T>::List(const List& other)
: head_(new Elem(0)),
  tail_(new Elem(0))
{
	head_ -> next_ = tail_;
	tail_ -> prev_ = head_;
	
	for(List::const_iterator it = other.begin();it != other.end();it++) {
		push_back(*it);
	}
}

//--------------------------------------------
// FUNCTION: operator=
// assignment operator of class List
// PARAMETERS:
// const List& other:
// list to be assigned
//---------------------------------------------
template<class T>
List<T>& List<T>::operator=(const List& other) {
	if(this != &other) {
		clear();
		
		for(List::const_iterator it = other.begin();it != other.end();it++) {
			push_back(*it);
		}
		
		return *this;
	}
}

//--------------------------------------------
// FUNCTION: begin
// iterator to beginning of list
// PARAMETERS:
// void
//---------------------------------------------
template<class T>
typename List<T>::iterator
List<T>::begin() {
	return iterator(head_ -> next_);
}

//--------------------------------------------
// FUNCTION: end
// iterator to end of list
// PARAMETERS:
// void
//---------------------------------------------	
template<class T>
typename List<T>::iterator
List<T>::end() {
	return iterator(tail_);
}

//--------------------------------------------
// FUNCTION: begin
// const iterator to beginning of list
// PARAMETERS:
// void
//---------------------------------------------
template<class T>
typename List<T>::const_iterator
List<T>::begin() const {
	return const_iterator(head_ -> next_);
}

//--------------------------------------------
// FUNCTION: end
// const iterator to end of list
// PARAMETERS:
// void
//---------------------------------------------
template<class T>
typename List<T>::const_iterator
List<T>::end() const {
	return const_iterator(tail_);
}

//--------------------------------------------
// FUNCTION: rbegin
// iterator to reversed beginning(end) of list
// PARAMETERS:
// void
//---------------------------------------------
template<class T>
typename List<T>::reverse_iterator
List<T>::rbegin() {
	return reverse_iterator(tail_ -> prev_);
}

//--------------------------------------------
// FUNCTION: rend
// iterator to reversed end(beginning) of list
// PARAMETERS:
// void
//---------------------------------------------
template<class T>
typename List<T>::reverse_iterator
List<T>::rend() {
	return reverse_iterator(head_);
}

//--------------------------------------------
// FUNCTION: rbegin
// const iterator to reversed begining(end)
// of list
// PARAMETERS:
// void
//---------------------------------------------
template<class T>
typename List<T>::const_reverse_iterator
List<T>::rbegin() const {
	return const_reverse_iterator(tail_ -> prev_);
}

//--------------------------------------------
// FUNCTION: rend
// const iterator to reversed end(beginning)
// of list
// PARAMETERS:
// void
//---------------------------------------------	
template<class T>
typename List<T>::const_reverse_iterator
List<T>::rend() const {
	return const_reverse_iterator(head_);
}

//--------------------------------------------
// FUNCTION: erase
// deletes the elem on the position of the
// given iterator, returns iterator to the
// element after deleted
// PARAMETERS:
// iterator pos
//---------------------------------------------
template<class T>
typename List<T>::iterator
List<T>::erase(iterator pos) {
	Elem* ptr = pos.current_;
	Elem* prev = pos.current_ -> prev_;
	Elem* next = pos.current_ -> next_;
	
	prev -> next_ = next;
	next -> prev_ = prev;
	
	delete pos.current_;
	
	return pos++;
}

//--------------------------------------------
// FUNCTION: insert
// inserts new elem on the position before 
// given iterator, returns iterator to the
// new elem
// PARAMETERS:
// iterator pos
// const T& x:
// the new elem
//---------------------------------------------
template<class T>
typename List<T>::iterator 
List<T>::insert(iterator pos, const T& x) {
	Elem* ins = new Elem(x);
	Elem* prev = pos.current_ -> prev_;
		
	ins -> next_ = pos.current_;
	pos.current_ -> prev_ = ins;
	
	prev -> next_ = ins;
	ins -> prev_ = prev;
	
	return iterator(ins);
}

//--------------------------------------------
// FUNCTION: erase
// deletes all elements between the 2 
// iterators, returns iterator to the first 
// not deleted elem
// PARAMETERS:
// iterator first
// iterator last
//---------------------------------------------
template<class T>
typename List<T>::iterator
List<T>::erase(iterator first, iterator last) {
	for(List::iterator it = first;it != last;it++) {
		erase(it);
	}
	
	return last;
}

//--------------------------------------------
// FUNCTION: dump
// prints the elements of the given list
// PARAMETERS:
// const List<T>& l:
// the list
// const char* name:
// list name
//---------------------------------------------
template<class T>
void dump(const List<T>& l, const char* name) {
	cout << name << ": {";
	for(typename List<T>::const_iterator it = l.begin();it != l.end();it++) {
		cout << *it << ",";
	}
	cout << "}" << endl;
}

int main(int argc, char* argv[]) {
	if(argc != 5) {
		cout << "wrong number of arguments" << endl;
		return 0;
	}
	
	List<int> l1, l2;
	
	for(int i = atoi(argv[1]);i < atoi(argv[2]);i++) {
		l1.push_back(i);
	}
	
	for(int i = atoi(argv[3]);i < atoi(argv[4]);i++) {
		l2.push_back(i);
	}
	
	dump(l1, "l1");
	dump(l2, "l2");
	
	int count = 0;
	for(List<int>::iterator it1=l1.begin();it1 != l1.end();it1++) {
		for(List<int>::iterator it2=l2.begin();it2 != l2.end();it2++) {
			if(*it1 == *it2)
				count++;
		}
	}
	cout << "equal element in v1 and v2: " << count << endl;
	
	l1.push_back(-100);
	l2.push_back(-100);
	
	dump(l1, "l1");
	dump(l2, "l2");
	
	List<int> l = l2;
	dump(l, "l");
	
	for(List<int>::reverse_iterator rit = l1.rbegin();rit != l1.rend();rit++) {
		l.push_front(*rit);
	}
	
	dump(l, "l");

	for(List<int>::iterator it = l.begin();it != l.end();it++) {
		if(*it == -100) {
			List<int>::iterator bit = it;
			l.erase(bit, l.end());
			break;
		}
	}

	dump(l, "l");
	
	return 0;
}
