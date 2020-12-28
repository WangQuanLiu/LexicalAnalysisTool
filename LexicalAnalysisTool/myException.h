#pragma once
#ifndef _myException_
#define _myException_
#include<iostream>
#include<stdexcept>
using namespace std;
class myException :public exception {
public:
	myException(char*c) {
		m_p = c;
	}
	virtual char*what() {
		cout << "异常类型为 myException:" << m_p << endl;
		return m_p;
	}
private:
	char*m_p;
};
#endif // !_myException_

