#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"

int json_object::_index = 0;

json_object* json_object::parse(const char * a, int length){
		json_object::_index++;
		//std::cout << "index ::::::   " << json_object::_index<< std::endl;
		if(*a=='{'){
				return json_dict::parse(a, length);
		}
		else if(*a=='"'){
				return String::parse(a, length, '"');
		}
		else if(*a=='\0'){
				return nullptr;
		}
		else if(*a=='\''){
				return String::parse(a, length, '\'');
		}
		else if(*a>='0'&&*a<='9'){
				return Integer::parse(a, length);
		}
		else if(*a=='['){
				return json_list::parse(a, length);
		}
		else{
				return nullptr;
		}
		return nullptr;
}
json_object* json_object::parse(const std::string& str){
	const char * a = str.c_str();
	int length = str.length();
	json_object::_index=0;

	return json_object::parse(a, length);
}
