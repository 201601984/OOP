#include "Integer.h"

Integer::Integer(int value){
	this->_val = value;
}

int Integer::val(){
	return this->_val;
}

void Integer::set_val(const int& value){
	this->_val = value;
}

json_object* Integer::parse(const char * a, int length){
	std::string result = "";
	json_object* aaa = new Integer(0);
	Integer* ccc = dynamic_cast<Integer*>(aaa);
	for( ; *a>='0'&&*a<='9'; a++){
		result += *a;
	}
	ccc->_val = atoi(result.c_str());
	return aaa;
}

json_object::_type Integer::type(){
	return INT;
}

std::string Integer::to_string(){
	return std::to_string(this->_val);
	//return "int to str";
}
