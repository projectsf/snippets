#include <stdint.h>
#include <iostream>
using namespace std;
int main()
{
	uint8_t valueOne =  154;
	char valueTwo = static_cast<char>(valueOne);
	cout << "Value: " << static_cast<int>(valueTwo) << endl;
}
