#include "json_dict.h"
#include "data/Integer.h"
#include "data/String.h"
json_dict::json_dict(){
}
void json_dict::put(json_object* key, json_object* val){
	this->v.push_back(std::make_pair(key, val));
}
int json_dict::find(json_object* key){
	for(int i = 0; i < v.size(); i++){
		if(v[i].first->to_string() == key->to_string()){
			return i;
		}
	}
	return -1;
}
json_object* json_dict::parse(const char * a, int length){
	json_object* aaa = new json_dict();
	json_dict* ccc = dynamic_cast<json_dict*>(aaa);
	a++;
	int old_index = json_object::_index;
	int i =0;
	json_object* key_object;
	bool isIn = false;

	for( ; *a!='}'; a++){
		i++;
		if(*a==':'){
				isIn=true;
		}
		if((json_object::_index-old_index)>=i){
				continue;
		}
		json_object* bbb = json_object::parse(a, length);
		if(key_object!=nullptr&&isIn&&bbb!=nullptr){
			if(ccc->find(key_object)==-1){
				ccc->put(key_object, bbb);
			}
			else{
				ccc->v[ccc->find(key_object)]=std::make_pair(key_object, bbb);
			}
			isIn=false;
		}
		if(bbb!=nullptr){
				key_object=bbb;
		}
		length--;
	}
	//json_object* bbb = json_object::parse(a+1, length-1);
	//ccc->put(bbb, new String("\'b\'"));
	return aaa;
}
json_object* json_dict::operator[](json_object* key) const{
	for(int i = 0; i < v.size(); i++){
		if(v[i].first == key){
			return v[i].second;
		}
	}
	json_object* aaa = new json_dict();
	return aaa;
}
json_object* json_dict::operator[](const std::string& key) const{
	for(int i = 0; i < v.size(); i++){
		if(v[i].first->to_string() == "\'"+key+"\'"||
						v[i].first->to_string() == key){
			return v[i].second;
		}
	}
	json_object* aaa = new json_dict();
	return aaa;
}

json_object* json_dict::operator[](int key) const{
	for(int i = 0; i < v.size(); i++){
		if(atoi(v[i].first->to_string().c_str()) == key){
			return v[i].second;	
		}
	}
	json_object* aaa = new json_dict();
	return aaa;
}

json_object::_type json_dict::type(){
	return DICT;
}

std::string json_dict::to_string(){
	std::string s = "{";
	for(int i = 0; i < v.size(); i++){
		s+= v[i].first->to_string()+": "+v[i].second->to_string();
		if(i!=v.size()-1){
				s+= ", ";
		}
	}
	s += "}";
	return s;
}
