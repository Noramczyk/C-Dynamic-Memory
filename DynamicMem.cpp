#include <iostream>
#include <assert.h>

using namespace std;

int main()
{
	char answer;


	do
	{
		int *inPtr = new int[10];
		assert(inPtr != 0);

		cout << "Another memory address allocated! " << endl;

		delete [] inPtr;

		cout << "Another round? \n";
		cin >> answer;



	}while (answer != 'n');

	

}