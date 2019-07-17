#include <Windows.h>
#include <iostream>

using namespace std;

int main(void){

	char x;
	cout << "ÇëÊäÈëÒ»¸ö×Ö·û: "<<endl;
	cin >> x;
	if( x >= 'a' && x <= 'z'){
		x = x - 'a' + 'A';
	}else if(x >= 'A' && x <= 'Z'){
		x = x - 'A' + 'a';
	}
	cout << x <<endl;

	system("pause");
	return 0;

}