#include<iostream>
#include<cstdlib>
using namespace std;
class ListError{};
template<class T>
class List{
	struct Elem{
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
	List()
	:head_(new Elem(0)),
	tail_(new Elem(0))
	{
		head_ -> next_ = tail_;
		tail_ -> prev_ = head_;
	}
	~List(){
		while(!empty()){
			pop_front();
		}
		delete head_;
		delete tail_;
	}
	bool empty(){
		return head_ -> next_ == tail_;
	}
	void push_back(const T& val){
		Elem* newElem = new Elem(val);
		newElem -> next_ = tail_;
		newElem -> prev_ = tail_ -> prev_;
		tail_ -> prev_ -> next_ = newElem;
		tail_ -> prev_ = newElem; 
	}
	void pop_back(){
		if(empty()){
			throw ListError();
		}else{
			Elem* back = tail_ -> prev_;
			tail_ -> prev_ = back -> prev_;
			tail_ -> prev_ -> next_ = tail_;
			delete back;
		}
	}
	void push_front(const T& val){
		Elem * newElem = new Elem(val);
		newElem -> prev_ = head_;
		newElem -> next_ = head_ -> next_;
		head_ -> next_ = newElem;
		newElem -> next_ -> prev_ = newElem;
	}
	void pop_front(){
		if(empty()){
			throw ListError();		
		}else{
			Elem* front = head_ -> next_;
			head_ -> next_ = front -> next_;
			head_ -> next_ -> prev_ = head_;
			delete front;
		}
	}
	T& back(){
		return tail_ -> prev_ -> data_;
	}
	const T& back() const{
		return back();
	}
	T& front(){
		return head_ -> next_ -> data_;
	}
	const T& front() const{
		return front();
	}
	void clear(){
		while(!empty()){
			pop_front();
		}
	}
};
int main(){
	List<int> l1, l2;
	l1.push_front(1);
	l1.push_back(2);
	l1.push_front(3);
	cout << l1.front()<<endl;//3
	l1.pop_front();
	cout << l1.front()<<endl;//1
	l1.pop_back();
	cout << l1.front()<<endl;//1
	l1.push_back(2);
	cout << l1.back()<<endl;//2
	cout << l1.front()<<endl;//1
	return 0;
}
