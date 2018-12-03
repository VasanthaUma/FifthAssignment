/* Developed by Vasantha Buddiga 
-  using Classes in Project */

#include <iostream>
#include <string>
using namespace std;
// Cake  Class
class Cake
{
private:
	int ID;
	static int IDGenerator;
	string cType;
	string cFlavour;
	string cTopping;
	int qty;
	double price;

public:
	Cake();
	void getCake();
	friend ostream& operator<<(ostream &o, Cake& i);
};

/* intialize the static variable to be used
when generating the ID */
int Cake::IDGenerator = 1;

// Cake List Class
class CakeList
{
private:
	int numItems;
	Cake iList[1000];
public:
	CakeList();
	void addItem();
	void showList();

};

// Constructor
Cake::Cake()
{
	ID = IDGenerator++;
	cType = "";
	cFlavour = "";
	cTopping = "";
	qty = 0;
	price = 0;
}

/* overloaded insertion operation
<< for printing object to the console */
ostream& operator<<(ostream &o, Cake& i)
{

	o << i.ID << "\t" << i.cType
		<< "\t" << "  " << i.cFlavour
		<< "\t" << "  " << i.cTopping
		<< "\t" << i.qty
		<< "\t" << i.price << endl;

	return o;
}

// gets input from the user for the cake object
void Cake::getCake()
{
	cout << "Enter Cake Type" << endl;
	getline(cin, cType);
	cout << "Enter Cake Flavour" << endl;
	getline(cin, cFlavour);
	cout << "Enter Cake topping" << endl;
	getline(cin, cTopping);
	cout << "Enter Quantity" << endl;
	cin >> qty;
	cout << "Enter Price" << endl;
	cin >> price;
	cin.ignore();
	cin.clear();
}

// Cake List constructor
CakeList::CakeList()
{
	numItems = 0;
}

// adds an Cake item to the list
void CakeList::addItem()
{
	iList[numItems].getCake();
	numItems++; // keeps track of the number of items

}
// shows the contents of the list
void CakeList::showList()
{
	int i;
	for (i = 0; i < numItems; i++)
		cout << iList[i] << endl;
}


int main()
{
	system("color F0");
	char answer = 'N';

	do
	{
		CakeList myList; // create list object 
	// loop to add Cake to the list
		for (int i = 0; i < 2; i++)
			myList.addItem();
		cout << "ID" << "\t" << "CakeType   "
			<< "Flavour"
			<< "\t" << "Topping" << "   "
			<< "\t" << "qty"
			<< "\t" << "Price" << endl;
		myList.showList();

		cout << "do you want to enter another word? enter Y to continue  ?";
		cin >> answer;

		// need to clear teh input buffer before asking for another word
		cin.ignore();
		cin.clear();

	} while (answer == 'Y' || answer == 'y');

	cout << "good bye!" << endl;
	system("pause");
	return 0;
}