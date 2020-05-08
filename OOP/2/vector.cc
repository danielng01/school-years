//--------------------------------------------
// NAME: Daniel Georgiev
// CLASS: XIb
// NUMBER: 11
// PROBLEM: #2
// FILE NAME: vector.cc (unix file name)
// FILE PURPOSE:
// implementation of the contaner vector
//--------------------------------------------- 

#include<iostream>
#include<stdlib.h>
#include<cstdlib>
using namespace std;

class VectorError{};

template<class T> 
class Vector {
	int capacity_;
	int size_;
	T* buffer_;
public: 
	Vector(int capacity=10);
	~Vector();
	int size() const {
		return size_;
	}
	bool empty() const {
		return size()==0;
	}
	T& operator[](int n) {
		return buffer_[n];
	}
	const T& operator[](int n) const {
		return buffer_[n];
	}
	void clear() {
		delete [] buffer_;
	}
	int capacity() const {
		return capacity_;
	}
	Vector(const Vector& other) 
	: size_(other.size_),
          capacity_(other.capacity_),
	  buffer_(new T[other.size_])
	{
		delete [] buffer_;
		buffer_ = new T[size_];
		for(int i=0;i<size_;i++) {
			buffer_[i]=other.buffer_[i];
		}	
	}
	Vector& operator=(const Vector& other) {
		if(this!=other){
			delete [] buffer_;
			size_=other.size_;
			capacity_=other.capacity_;
			buffer_ = new T[size_];
			for(int i=0;i<size_;i++) {
				buffer_[i]=other.buffer_[i];
			}
		}
		return* this;
	}
	class iterator {
		Vector& vector_;		
		int cur_;
	
		friend class Vector;

		iterator(Vector& vector, int cur)
		: vector_(vector),cur_(cur)
		{}
	public:
		iterator operator++() {
			cur_++;
			return *this;
		}
		iterator operator++(int) {
			cur_++;
			return *this;
		}
		bool operator==(const iterator& other) const {
			return cur_ == other.cur_;
		}
		bool operator!=(const iterator& other) const {
			return cur_ == other.cur_;
		}
		T& operator*() {
			return vector_[cur_];
		}
		T* operator->() {
		}
	};
	iterator begin() {
		return iterator(*this, 0);	
	}
	iterator end() {
		return iterator(*this, size_);	
	}
	class const_iterator {
		Vector& vector_;		
		int cur_;
	
		friend class Vector;

		const_iterator(Vector& vector, int cur)
		: vector_(vector),cur_(cur)
		{}
	public:
		const_iterator operator++() {
			cur_++;
			return *this;
		}
		const_iterator operator++(int) {
			cur_++;
			return *this;
		}
		bool operator==(const const_iterator& other) const {
			return cur_ == other.cur_;
		}
		bool operator!=(const const_iterator& other) const {
			return cur_ == other.cur_;
		}
		const T& operator*() {
			return vector_[cur_];
		}
		const T* operator->() {
			return &vector_[cur_];
		}
	};
	const_iterator begin() const {
		return const_iterator(*this, 0);	
	}
	const_iterator end() const {
		return const_iterator(*this, size_);	
	}
	class reverse_iterator {
		Vector& vector_;		
		int cur_;
	
		friend class Vector;

		reverse_iterator(Vector& vector, int cur)
		: vector_(vector),cur_(cur)
		{}
	public:
		reverse_iterator operator++() {
			cur_--;
			return *this;
		}
		reverse_iterator operator++(int) {
			cur_--;
			return *this;
		}
		bool operator==(const reverse_iterator& other) const {
			return cur_ == other.cur_;
		}
		bool operator!=(const reverse_iterator& other) const {
			return cur_ == other.cur_;
		}
		T& operator*() {
			return vector_[cur_];
		}
		T* operator->() {
			return &vector_[cur_];
		}
	};
	reverse_iterator rbegin() {
		return reverse_iterator(*this, size_);	
	}
	reverse_iterator rend() {
		return reverse_iterator(*this, 0);	
	}
	class const_reverse_iterator {
		Vector& vector_;		
		int cur_;
	
		friend class Vector;

		const_reverse_iterator(Vector& vector, int cur)
		: vector_(vector),cur_(cur)
		{}
	public:
		const_reverse_iterator operator++() {
			cur_--;
			return *this;
		}
		const_reverse_iterator operator++(int) {
			cur_--;
			return *this;
		}
		bool operator==(const const_reverse_iterator& other) const {
			return cur_ == other.cur_;
		}
		bool operator!=(const const_reverse_iterator& other) const {
			return cur_ == other.cur_;
		}
		T& operator*() {
			return vector_[cur_];
		}
		T* operator->() {
			return &vector_[cur_];
		}
	};
	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(*this, size_);	
	}
	const_reverse_iterator rend() const {
		return const_reverse_iterator(*this, 0);	
	}
	
	T& front() {
		return &buffer_[0];	
	}
	const T& front() const {
		return &buffer_[0];
	}
	T& back() {
		return &buffer_[size_-1];
	}
	const T& back() const {
		return &buffer_[size_-1];
	}
	
	//--------------------------------------------
	// FUNCTION: push_back
	// appends elem to the end of the vector
	// PARAMETERS:
	// const T& val:
	// elem to append
	//--------------------------------------------- 
	void push_back(const T& val) {
		resize();
		buffer_[size_]=val;
		size_++;
	}
	
	//--------------------------------------------
	// FUNCTION: pop_back
	// deletes the last elem of the vector
	// PARAMETERS:
	// void
	//--------------------------------------------- 
	void pop_back() {
		if(empty()) {
			cout << "vector is empty!" << endl;
		} else {
			size_--;
		}
	}
	
	//--------------------------------------------
	// FUNCTION: insert
	// inserts value infront of pos
	// PARAMETERS:
	// iterator pos
	// const T& x:
	// value
	//--------------------------------------------- 
	iterator insert(iterator pos, const T& x) {
		int temp_pos = 0;
		Vector vector(size() + 1);
		for(int i=0;i<temp_pos;i++) {
			vector.buffer_[i]=buffer_[i];
			++temp_pos;
		}
		vector.buffer_[temp_pos] = x;
		for(int i = temp_pos; i < size(); i++) {
			vector.buffer_[i+1] = buffer_[i];
		}
		delete [] buffer_;
		buffer_ = new T[size() + 1];
		for(int i = 0; i < size() + 1; i++) {
			buffer_[i] = vector.buffer_[i];
		}
		size_ += 1;
		capacity_ += 1;
	}
	
	//--------------------------------------------
	// FUNCTION: erase
	// deletes the element at pos
	// PARAMETERS:
	// iterator pos
	//--------------------------------------------- 
	iterator erase(iterator pos) {
		if(!empty()) {
			Vector<T> temp(size());
			bool exists = false;
			for(Vector<T>::iterator it = begin(); it != end(); ++it) {
				if(it == pos) {
					exists = true;
					break;
				}
				temp.push_back((*it));
			}
			if(exists) {
				delete [] buffer_;
				size_ = temp.size();
				capacity_ = temp.capacity();
				buffer_ = new T[size()];
				for(int i = 0; i < size(); i++) {
					buffer_[i] = temp[i];
				}
			}
		} else {
			throw VectorError();
		}
	}
	
	//--------------------------------------------
	// FUNCTION: erase
	// deletes elements between first and last
	// PARAMETERS:
	// iterator first
	// iterator last
	//--------------------------------------------- 
	iterator erase(iterator first, iterator last) {
		size_ -= (last.cur_ - first.cur_);
		Vector temp = *this;
		buffer_ = new T[capacity_];

		int k = 0;
		for(int i = 0;i < size_;i++) {
			if(i <= first.cur_ || i >= last.cur_) {
				buffer_[k] = temp.buffer_[i];
				k++;
			}
		}
	}
	
	void resize() {
		if(size_+1==capacity_) {
			capacity_+=10;
		}
		T* old_buffer = buffer_;
		buffer_=new T[capacity_];
		for(int i=0;i<size_;i++) {
			buffer_[i] = old_buffer[i];
		}
		delete [] old_buffer;
	}
	void print() const {
		cout << "{";
		for(int i=0;i<size_;i++) {
			cout  << buffer_[i] << ",";
		}
		cout << "}" << endl;
	}
};

//--------------------------------------------
// FUNCTION: Vector
// constructor
// PARAMETERS:
// int capacity:
// capacity which default value is 10
//--------------------------------------------- 
template<class T>
Vector<T>::Vector(int capacity)
: capacity_(capacity),
  size_(0),
  buffer_(0)
{}

//--------------------------------------------
// FUNCTION: ~Vector
// destructor
// PARAMETERS:
// void
//--------------------------------------------- 
template<class T>
Vector<T>::~Vector() {
	delete [] buffer_;
}

int main(int argc, char* argv[]) {
	if(argc != 5) {
		cout << "wrong number of arguments" << endl;
		return 0;
	}

	Vector<int> v1;
	Vector<int> v2;

	for(int i = atoi(argv[1]);i < atoi(argv[2]);i++) {
		v1.push_back(i);
	}

	for(int i = atoi(argv[3]);i < atoi(argv[4]);i++) {
		v2.push_back(i);
	}
	cout << "v1: ";
	v1.print();
	cout << "v2: ";
	v2.print();

	int count = 0;
	for(Vector<int>::iterator it1 = v1.begin(); it1 != v1.end(); ++it1) {
	for(Vector<int>::iterator it2 = v2.begin(); it2 != v2.end(); ++it2) {
	if((*it1) == (*it2)) {
	count += 1;
	}
	}
	}
	cout << "equal element in v1 and v2: " << count << endl;

	v1.push_back(-100);
	cout << "v1: ";
	v1.print();
	v2.push_back(-100);
	cout << "v2: ";
	v2.print();

	Vector<int> v(v2);
	cout << "v: ";
	v.print();

	for(Vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); ++it) {
	v.insert(v.begin(), (*it)); // ...
	}

	cout << "v: ";
	v.print();

	Vector<int>::iterator bit = v.begin();
	for( ; bit != v.end(); ++bit) {
	if((*bit) == -100) {
	break;
	}
	}
	v.erase(bit);
	cout << "v: ";
	v.print();

	return 0;
} 
