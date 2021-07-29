#include <iostream>
using namespace std;

int main()
{
	string binaryNumber = "-10000100101010101001";
	string num = "4";
	
	
	cout << stol(binaryNumber, 0, 2) << "\n";
	//cout << stoi(binaryNumber, 0, 10);

	return 0;
}

