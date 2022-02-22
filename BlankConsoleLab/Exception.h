#ifndef EXCEPTION_H
#define EXCEPTION_H

#include<ostream>
#include <cstring> 

class Exception {
public:
	Exception() : m_msg(nullptr) {};
	~Exception();
	Exception(const char* msg);
	Exception(Exception& copy);
	Exception(Exception&& copy);
	Exception& operator =(const Exception& rhs);
	Exception& operator =(Exception&& rhs);
	const char* getMessage();
	void setMessage(const char* msg);
	friend std::ostream& operator <<(std::ostream& stream, const Exception& except);
private:
	char* m_msg;
};

#endif


