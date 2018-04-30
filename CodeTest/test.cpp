using namespace std;

#include<iostream>
#include<iomanip>

int main() {
	int a1 = ~0;
	unsigned char a2 = ~0;
	unsigned short a3 = ~0;
	float a4 = ~0;
	double a5 = ~0;
	cout << setbase(16) << a1 << endl;
	cout << setbase(16) << a2 << endl;
	cout << setbase(16) << a3 << endl;
	cout << setbase(16) << a4 << endl;
	cout << setbase(16) << a5 << endl;
	system("pause");
	return 0;
}