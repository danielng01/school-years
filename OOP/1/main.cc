#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
class StringError{};
class String {
int capacity_;
int size_;
char* buffer_;
public:
String(int capacity)
 : capacity_(capacity),
 size_(0),
 buffer_(new char[capacity])
{}

String(const char* str)
 : capacity_(0),
 size_(0),
 buffer_(0)
 {
	size_=strlen(str);
	capacity_=size_+1;
	buffer_ = new char[capacity_];
	strcpy(buffer_,str);
 }  

~String(){
 delete [] buffer_;	
 }
	String(const String& other)
	: capacity_(other.capacity_),
	size_(other.size_),
	buffer_(new char[capacity_])
 {
	strcpy(buffer_,other.buffer_);	
 }
String& operator=(const String& other) {
 if(this != &other){
  delete [] buffer_;
  size_=other.size_;
  capacity_=size_+1;
  buffer_=new char[capacity_];
  strcpy(buffer_,other.buffer_);	
   }
	return *this;
   }
 char* getBuff() const {
 return buffer_;
  }	

  int size() const {
	return size_;
  }

  int length() const {
	return size_;	
  }

  int capacity() const {
	return capacity_;	
  }

  bool empty() const {
   if(size_ == 0)
	return true;
	return false;
  }

  void clear() {
	delete [] buffer_;	
  }

  char& operator[](int index) {
	return buffer_[index];
  }

  char& at(int index) {
	if((index >= 0) && (index <= size_)) {
	 return buffer_[index];
	} else {
	 throw StringError();
	}
  } 

  bool isFull() {
	if(size_ == capacity_)	
	 return true;
	 return false;	
	}

	void newMem(int added=4) {
	 String temp(size_+added);
	 temp.buffer_=this->buffer_;
	 this->~String();
	 this->capacity_ = temp.capacity_;
	 this->size_ = temp.size_;
	 this->buffer_ = temp.buffer_;
	}

	bool operator==(const String& other) {
	 if(strcmp(buffer_,other.buffer_)==0) {
	   return true;
	 }
	   return false;
	}

	bool operator!=(const String& other) {
	if(strcmp(buffer_,other.buffer_)!=0) {
	 return true;
	}
	 return false;
	}

	bool operator<(const String& other) {
	 if(strcmp(buffer_,other.buffer_)<0) {
	  return true;
	}
	 return false;
	}

	bool operator>(const String& other) {
	 if(strcmp(buffer_,other.buffer_)>0) {
	  return true;
	 }
	  return false;
	 }

	 bool operator<=(const String& other) {
	 if(strcmp(buffer_,other.buffer_)<=0) {
	  return true;
	 }
	  return false;
	 }

	 bool operator>=(const String& other) {
	 if(strcmp(buffer_,other.buffer_)>=0) {
	  return true;
	 }
	  return false;
	 }


class iterator {
 String& string_;
 int cur_;

 friend class String;
 iterator(String& string, int cur)
 : string_(string),cur_(cur)
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

	char& operator*() {
	 return string_[cur_];
	 }
	};

	iterator begin() {
	 return iterator(*this, 0);	
	}

	iterator end() {
	return iterator(*this, size_);	
	}

	String& append(const String& other) {
	 if(isFull()) 
	 newMem(strlen(other.buffer_));
		for(int i=0;i<strlen(other.buffer_);i++){
		 buffer_[size_+i] == other.buffer_[i];
		}
	 return *this;
	}

	String& operator+=(const String& other) {
	 if(isFull()) 
	 newMem(strlen(other.buffer_));
		for(int i=0;i<strlen(other.buffer_);i++){
		 buffer_[size_+i] == other.buffer_[i];
		}
	 return *this;
	}

	void push_back(char ch) {
	 if(isFull())
	 newMem();
	 buffer_[size_+1] = ch;
	}

	String operator+(const String& other) {
	String temp(size_+other.size_+1);
	temp.buffer_=this->buffer_;
	temp.size_=size_+other.size_;
	}

	unsigned find(const String& str, unsigned pos) {
	char* c = strstr(buffer_,str.buffer_);
		if(c!=NULL){
		 for(int i=pos;i<size();i++){
		if(&buffer_[i]==c){
		 return i;
	     }
		}
	}
	return -1;
	}

	unsigned find_first_of(const String& str, unsigned pos) {
	 srand(time(NULL));
	 int temp = rand() % strlen(str.getBuff());
		for(int i=pos;i<size();i++){
		 if(buffer_[i] == str.buffer_[temp]) {
    	  return i;	
		}
	}
	return -1;
	}

	String substr(unsigned pos, unsigned n) {
	String str(size());
	int j=0;
		for(int i=pos;j<n;i++) {
			j++;
		str.buffer_[j] =buffer_[i];
		}	
	return str;
	 }
	};

	std::ostream& operator<<(std::ostream& out, const String& str){
	out << str.getBuff();
	return out;
	}

	int main(int argc, char* argv[]) {
	String string1 = argv[1];
	String string2 = argv[2];
	int string_spaces = 0;
	cout << "string1: " << string1 << endl;
	cout << "string2: " << string2 << endl;
	cout << "string1 length: " << string1.size() << endl;
	cout << "string2 length: " << string2.size() << endl;
		for (String::iterator it = string1.begin(); it != string1.end(); ++it) {
		 if((*it) == ' ') {
		  string_spaces += 1;
		 }
		}
	cout << "string1 spaces: " << string_spaces << endl;
	string_spaces = 0;	
		for (String::iterator it =string2.begin(); it != string2.end(); ++it) {
		 if((*it) == ' ') {
		  string_spaces += 1; 
		 }
		}
	cout << "string2 spaces: " << string_spaces << endl;	
	string_spaces = 0;
		if(string1 >= string2) {
		 cout << string1 << " is greater than " << string2 << endl;
		} else {
		 cout << string2 << " is greater than " << string1 << endl;
		}
	string1.push_back('!');
	cout << "string1: " << string1 << endl;
	string2.push_back('!');
	cout << "string2: " << string2 << endl;
	String str = string1 + string2;
	cout << "concatenation: " << str << endl;
	cout << "concatenation length: " << str.size() << endl; 
		for (String::iterator it = str.begin(); it != str.end(); ++it) {
		 if((*it) == ' ') {
		string_spaces += 1;
		 }
		}
	cout << "concatenation spaces: " << string_spaces << endl;	
	cout << "index of '!': " << str.find("!", 0) << endl;;
	cout << "substring: " << str.substr(12, 4) << endl;
	return 0;
	}