//
// Created by 김혁진 on 14/10/2019.
//

#include "unique_immut.h"

namespace ptr {
unique_immut::unique_immut() {
    _mgr = new mgr();
	this->_mgr->count=1;
}

unique_immut::unique_immut(Object *obj) {
    _mgr = new mgr(obj);
	this->_mgr->count=1;
}

unique_immut::unique_immut(const unique_immut &immut) {
    	this->release();
		if (immut._mgr!=this->_mgr) {
        	int val = immut._mgr->ptr->get();
        	_mgr = new mgr(val);
   	 	}
}

unique_immut::~unique_immut() {
		release();
}
Object* unique_immut::get() const {
		if(this->_mgr==nullptr){
				return nullptr;
		}
		return this->_mgr->ptr;
}
void unique_immut::release(){
		if(this->_mgr!=nullptr){
				delete this->_mgr;
		}
		this->_mgr=nullptr;
}

unique_immut unique_immut::operator+(unique_immut &unique){
		int r = this->_mgr->ptr->get()+unique._mgr->ptr->get();
		unique.release();
		this->release();
		unique_immut l(new Object(r));
		return l;
}
unique_immut unique_immut::operator-(unique_immut &unique){
        int r = this->_mgr->ptr->get()-unique._mgr->ptr->get();
        unique.release();
        this->release();
        unique_immut l(new Object(r));
        return l;
}
unique_immut unique_immut::operator*(unique_immut &unique){
        int r = this->_mgr->ptr->get()*unique._mgr->ptr->get();
        unique.release();
        this->release();
        unique_immut l(new Object(r));
        return l;
}
unique_immut unique_immut::operator/(unique_immut &unique){
        int r = this->_mgr->ptr->get()/unique._mgr->ptr->get();
        unique.release();
        this->release();
        unique_immut l(new Object(r));
        return l;
}
Object* unique_immut::operator->(){
		return this->_mgr->ptr;
}
unique_immut& unique_immut::operator=(unique_immut& r){
		if(&r==this){
				return *this;
		}
		this->release();
		this->_mgr = new mgr(r._mgr->ptr);
		return *this;
}
} // end of namespace ptr
