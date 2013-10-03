#include <iostream>
#include "md5.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "Ingrese el texto: ";
	string text;
	cin >> text;
    cout << "\n md5 of "<< text << " : " << md5(text)<<endl;
    return 0;
}
