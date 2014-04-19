#include <iostream>
#include <iomanip>
#include <cctype>
#include "register.h"

using namespace std;

void ShowMenu()
{
	cout << "\nPlease select one of the following options\n";
	cout << "    by pressing the indicated key:\n";
	cout << "\tS: Show current cash register amount\n";
	cout << "\tR: Ring up a sale\n";
	cout << "\tD: Display the last sale\n";
	cout << "\tL: Display all sales in List\n";
	cout << "\tC: Cancel the last sale\n";
	cout << "\tT: Find total sales Tax for recent sales\n";
	cout << "\tM: Show this Menu\n";
	cout << "\tX: eXit the program\n";
}

int main()
{
   int num, id;
   double cash, amt;
   char kind, choice = 'X';

   cout << "\nEnter cash register id: ";
   cin >> id;
   cout << "\nEnter starting amount in register: ";
   cin >> cash;

   Register a(id,cash);
   ShowMenu();

   cout << setprecision(2) << fixed;	// set print flags

   do
   {
	cout << "\n> ";			// Prompt the user,
	cin >> choice;			// get a new command,
	choice = toupper(choice);	// and convert it to upper-case
	cin.get();			// extract white space

	switch (choice)
	{
	   case 'S':
		cout << "\nRegister # " << a.GetID() << "  Balance = $ "
		  << a.GetAmount() << endl;
		break;

	   case 'R':
		cout << "\nWhat kind of sale?\n";
		cout << "(b)ook, (d)vd, (s)oftware, or (c)redit: ";
		cin >> kind;
		cout << "\nPlease enter the price: ";
		cin >> amt;
		if (kind == 'b')	a.RingUpSale(BOOK,amt);
		else if (kind == 'd')	a.RingUpSale(DVD,amt);
		else if (kind == 's')	a.RingUpSale(SOFTWARE,amt);
		else if (kind == 'c')	a.RingUpSale(CREDIT,amt);

		break;

	   case 'D':
		a.ShowLast();		break;
	   case 'L':
		a.ShowAll();		break;
	   case 'C':
		a.Cancel();
		cout << "\nCancel operation complete\n";
		break;
	   case 'T':
	   {	cout << "\nCompute tax for how many recent sales: ";
		cin >> num;
		double tot = a.SalesTax(num);
		cout << "\nThe total tax is:  $ " << tot << '\n';
		break;
           }

	   case 'M':	ShowMenu();	break;
	   case 'X':	break;

	   default:
		cout << "** Illegal menu option.  Try again...\n";
	}
   } while (choice != 'X');

   cout << "\nFinal balance for register # " << a.GetID() << " is $ "
        << a.GetAmount() << '\n';
}
