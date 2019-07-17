#include <iostream>
#include"ÐÇ¿Õ.h"

using namespace std;



bool initList(SqList &L){
	
	L.elems = new struct STARS[STAR_MAX];
	if(L.elems == 0){
		cout <<"ÄÚ´æ·ÖÅäÊ§°Ü"<<endl;
		return false;
	}
	L.length = 0;
	L.sise = STAR_MAX;
	return true;
}

bool ListAppend(SqList &L,struct STARS e){

	if(L.length == L.sise)return false;  //´æ´¢¿Õ¼äÒÑÂú
	L.elems[L.length] = e;
	L.length++;
	return true;
}

bool listDelete(SqList &L,int i){
	if(i<0 || i > L.length)return false;
	if(i<0 || i >= L.length)return false;
	if(i == L.length-1) {
		L.length--;
		return true;
	}
	for(int j = i;j<L.length-1;j++){
		L.elems[j] =L.elems[j+1];
	}
	L.length--;
	return true;
}
void destroyList(SqList &L){
	if(L.elems){
		delete [] L.elems;
	}
	L.length = 0;
	L.sise = 0;
}