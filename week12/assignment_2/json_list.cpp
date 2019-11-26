#include "json_list.h"
#include "data/Integer.h"
json_list::json_list(){
}

json_object* json_list::parse(const char * a, int length){
	json_object* aaa = new json_list();
	json_list* ccc = dynamic_cast<json_list*>(aaa);
	a++;
	int old_index = json_object::_index;
	int i = 0;
	int c = 0;

	for( ; c>0||*a!=']'; a++){
		if(*a=='['){
			c++;
		}
		if(*a==']'&&c!=0){
			c--;
		}
		i++;
		if((json_object::_index-old_index)>=i){
				continue;
		}
		json_object* bbb = json_object::parse(a, length);
		if(bbb!=nullptr){
			ccc->v.push_back(bbb);
		}
		length--;
	}
	json_object::_index++;
	return aaa;
}

json_object* json_list::operator[](int key) const{
		return this->v[key];
		//return aaa;
}

json_object::_type json_list::type(){
	return LIST;
}

std::string json_list::to_string(){
	std::string s = "[";
	for(int i = 0; i < v.size(); i++){
			s += v[i]->to_string();
			if(i!=v.size()-1){
					s += ", ";
			}
	}
	s+="]";
	return s;
}
