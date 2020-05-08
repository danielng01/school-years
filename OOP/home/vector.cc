#include<iostream>
#include<stdlib.h>
#include<cstdlib>
using namespace std;
class VectorError{};
template<class T>
class Vector{
	int capacity_;
	int size_;
	T* buffer_;
public:
	Vector(int capacity =10)
	: capacity_(capacity),
	size_(0),
	buffer_(new T[capacity_])
	{}
	~Vector(){
		delete [] buffer_;
	}
	bool empty(){
		if(size_==0)
			return 1;
		return 0;
	}
	void resize(){
		if(size_+1 >= capacity_){
			capacity_+=10;		
		}
		T* temp = buffer_;
		buffer_ = new T[capacity_];
		for(int i =0;i<size_;i++){
			buffer_[i]=temp[i];
		}
		delete [] temp;
	}
	void push_back(const T& val){
		resize();
		buffer_[size_]=val;
		size_++;
	}
	void pop_back(){
		if(empty()){
			cout << "vector is empty"<<endl;		
		}else{
			size_--;
		}
	}
	void push_front(const T& val){
		if(size_+2 >= capacity_){
			capacity_+=10;		
		}
		T* temp = buffer_;
		buffer_=new T[capacity_];
		buffer_[0]=val;
		for(int i =0;i<size_;i++){
			buffer_[i+1]=temp[i];
		}
		size_++;
	}
	void pop_front(){
		T* temp = buffer_;
		buffer_=new T[capacity_];
		for(int i =0;i<size_;i++){
			buffer_[i]=temp[i+1];
		}
		size_--;
	}
	T& front(){
		return buffer_[0];
	}
	const T& front() const{
		return &buffer_[0];
	}
	T& back(){
		return buffer_[size_-1];
	}
	const T& back() const{
		return &buffer_[size_-1];
	}
	T& operator[](int n){
		return buffer_[n];
	}
	const T& operator[](int n) const {
		return buffer_[n];
	}
	Vector& operator=(const Vector& other){
		if(this!=other){
			delete []  buffer_;
			size_=other.size_;
			capacity_=other.capacity_;
			buffer_ = new T[size_];
			for(int i =0;i<size_;i++){
				buffer_[i]=other.buffer_[i];
			}
		}
		return *this;
	}
	Vector(const Vector& other)
	: capacity_(other.capacity_),
	 size_(other.size_),	
	buffer_(new T[other.size_])
	{
		for(int i=0;i<size_;i++){
			buffer_[i]=other.buffer_[i];
		}	
	}
};
int main(){
	
	Vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	cout<<v1.front()<<endl;
	cout<<v1.back()<<endl;
	cout<<v1[0]<<endl;
	Vector<int> v2 = v1;
	Vector<int> v3(v1);
	cout<<v2.front()<<endl;
	cout<<v3.front()<<endl;
	cout<<"--------------"<<endl;
	Vector<int> v4;
	v4.push_front(1);
	v4.push_front(2);
	v4.push_front(3);
	v4.push_front(4);
	cout<<v4.front()<<endl;
	cout<<v4.back()<<endl;
	v4.pop_back();
	cout<<v4.front()<<endl;
	cout<<v4.back()<<endl;
	v4.pop_front();

	cout<<v4.front()<<endl;
	cout<<v4.back()<<endl;
	return 0;
}