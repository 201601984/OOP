#include "String.h"

String::String(const std::string& str){
	this->_val = str;
}

std::string String::val(){
	return this->_val;
}

void String::set_val(const std::string& str){
	this->_val = str;
}

json_object* String::parse(const char * a, int length, char base){
	json_object* aaa = new String("");
	String* ccc = dynamic_cast<String*>(aaa);
	ccc->_val+=*a;
	a++;
	for( ; *a!=base; a++){
		ccc->_val+=*a;
		json_object::_index++;
	}
	json_object::_index++;
	ccc->_val+=base;
	return aaa;
}

json_object::_type String::type(){
	return STRING;
}

std::string String::to_string(){
	return this->_val;
	//return "\'str to str\'";
}
