// Luke Noramczyk_CISP400_TODO LIST_ 10/24/17
//

#include <iostream>
#include <string>
#include <cstring>
#include <cstddef> 
#include <cassert>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

class toDo
{
public:

	string inList;
	toDo* list = NULL;
	int date;
	int overDate = 10242017;
	int gage = 0;
	unsigned int count = 0;
	char choice;

	int getGage() const {return overDate;}
	friend ostream &operator<<(ostream &out, toDo a);


	int First()
	{
		toDo file;
		file.date = 10242017;	// System Date added to output  

		do
		{
			cout << "To enter a task use a + sign OR use a - sign to delete" << endl;
			cout << "the previous task for the list.\n " << endl;
			cout << "Enter a task to stored when ready: ";

			toDo fillList;
			getline(cin, fillList.inList);

			if (fillList.inList == " ")
				break;

			string str(fillList.inList);
			size_t found = str.find_first_of("+");
	 
								// + to add to list

			if (found != string::npos)
			{
				if (list == NULL)
				{
					list = new toDo[1];		
				// Dynamically allocated array
					list[0] = fillList;

					count++;
					

				}
				else
				{
					toDo* temp = list = list;
					list = new toDo[count + 1];
					

					for (unsigned int i = 0; i < count; i++)
					{

						list[i] = temp[i];
					}
					list[count] = fillList;
					count++;
					delete[] temp;
				}

				cout << "Enter another entry by entering a 'y' for yes to continue \n";
				cin >> choice;
				cin.ignore();
				cout << "\n\n";

				gage = gage + 1;
			}
			
				
			else
			{
			  string str(fillList.inList);
				size_t found = str.find_first_of("-"); 
			
			if (found != string::npos)
			{
				if (list == NULL)
				{
					list = new toDo[1];		
				// Dynamically allocated array
					list[0] = fillList;

					count++;
					

				}
				else
				{
					toDo* temp = list = list;
					list = new toDo[count + 1];
					

					for (unsigned int i = 0; i < count; i++)
					{

						list[i] = temp[i];
					}
					list[count] = fillList;
					count--;
					delete[] temp;
				}

				cout << "Enter another entry by entering a 'y' for yes to continue \n";
				cin >> choice;
				cin.ignore();
				cout << "\n\n";

				gage = gage - 1;
			}
			
			}
		} while (toupper(choice) == 'Y');

		cout << "\n";

		ofstream myfile("toDo_3.cpp");
		if (myfile.is_open())
		{
			myfile << "TO Do LIST \n";
			myfile << "identification #	    Task				Date	\n";
		myfile << "----------------------------------------";
		myfile <<"---------------------------------------\n";

			for (unsigned int i = 0; i < count; i++)
			{

				myfile << "( " << i << " )" << "\t\t\t" << 
				list[i].inList<< "\t\t\t" << file.date << endl;
			}
			myfile.close();
			cout << "\n\n";
		}

		else cout << "Unable to open file";


		for (unsigned int i = 0; i < count; i++)
		{

			cout << "( " << i << " )" << "\t" << list[i].inList<< endl;
		}

		
		cout << "\n\n";
		cout << "There are " << gage << " tasks left on the list to accomplish \n"; 

	//Bonus total amount of tasks increase and decrease with entries

		cout << "\n\n";

		cin.get();
		return 0;
	}



};

ostream &operator<<(ostream& out, toDo a) { // Bonus: Overload <<
out << a.getGage();
return out;
}

class readArray : public toDo	// Bonus: Object orientated inheritance
{
public:
	ifstream outFile;
	string read;


	int second()
	{
		ifstream inputfile;
		string name;

		inputfile.open("toDo_3.cpp");

		while (getline(inputfile, name))
		{

			cout << name << endl;

		}

		inputfile.close();
		cout << "\n\n";

		return 0;
	}

};


void DISPmenu();
int DeleteFile(toDo &pass);


int main()
{
	toDo* list = NULL;
	toDo pass;
	readArray disp;
	int user;

	toDo test;


cout << "Welcome! today's date is  " << test << endl;
cout << "This program dynamically stores tasks into a TODO list. \n";

	do
	{
		DISPmenu();
		cout << "\n\n";

		cout << "Enter a Menu choice: \n";
		cin >> user;
		cin.get();

		assert((user > 1) || (user < 7)); 

		// Bonus Assert validation

		cout << "\n\n";

		while ((user < 1) || (user > 7))
		{
			cout << "Please enter a valid menu choice. \n";
			cin >> user;

		}

		switch (user)
		{
		case 1:
			pass.First();
			
			break;

		case 2:		// Read out TODO list contents

			disp.second();
			break;

		case 3:
			DeleteFile(pass);	// Bonus delete file to start over
			break;

	
		case 4:
			cout << "GOODBYE!" << endl;	

					// Command symbol to quit program

			break;

		}

	} while (user != 4);

	if (list != NULL)
		delete[] list;

	return 0;

}

void DISPmenu()
{
	cout << "USER MENU: \n";
	cout << "Enter 1 to enter tasks. \n";
	cout << "Enter 2 to show the list \n";
	cout << "Enter 3 to delete the whole list \n";
	cout << "Enter 4 to quit \n";
}

int DeleteFile(toDo &pass)
{

	fstream myfile("toDo_3.cpp",
		std::ofstream::out | std::ofstream::trunc);

	myfile.close();

	return 0;

}





