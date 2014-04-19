/******************************************************************************/
/*                       Author and Date                                      */
/*
CHR
Author: Claudius Christian 
Date: 2/23/2013 

/******************************************************************************/
/*                       Summary                                              */
/*

An object of type Sale will store information about a single sale.
The variable "item" stores the type of item being sold (one of the four
items in the enumerated type ItemType).  Books, music, and software are
the types of items sold.  CREDIT stands for store credit, which incurs
a negative monetary charge.

/******************************************************************************/
/*                       Input                                                */
/*

This menu program will start by prompting the user to input a cash register ID 
and the starting amount in the register. Then it will create a Register object 
and enter a menu loop -- the menu options will work with both lower and upper 
case inputs:

S: Show current amount in the cash register
R: Ring up a sale
D: Display the last sale
L: Display the entire sale List
C: Cancel the last stored sale
T: Find the Total sales tax for recent sales
M: Show this Menu
X: eXit the program

The user will also:

Enter cash register id
Enter starting amount in register
Enter the items price
Choose between selling a book, DVD, software, or credit

/******************************************************************************/
/*                       Output                                               */
/*

Output the sale item, the price, the tax, and the total (all on one line). 
For store credit, the amounts should be enclosed in < > symbols, to indicate a 
negative charge. All monetary output should be in dollars and cents format, 
to two decimal places. 

Examples: Book    $ 20.00 Tax: $ 1.40 Total: $ 21.40 
          Credit <$ 15.00> Tax: $ 0.00 Total: <$ 15.00>

Further output appropriate error messages to users.

/******************************************************************************/
/*                       Header Files                                         */


#include "sale.h"                       // needed for sales.cpp
#include <iostream>                     // for input and output
#include <iomanip>                      // used for setprecision
using namespace std;


/******************************************************************************/
/*                       Default Constructor                                  */
/*

Author: Claudius Christian
Date:  2/26/2013

Description: sets numerical member data to 0
*/

Sale::Sale()
{
	price = 0;   // price of item or amount of credit
	tax   = 0;	 // amount of sales tax (does not apply to credit)	
    total = 0;	 // final price once tax is added in.

} // end default constructor Sale::Sale() 

/******************************************************************************/
/*                       Make Sale Function                                   */
/*

Author: Claudius Christian
Date:  2/26/2013

Description: The MakeSale function loads data into the Sale object. The item 
and price are passed in.  Compute tax and total. (For store credits, tax is 0).
*/

void Sale::MakeSale(ItemType x, double amt)
{
	price = amt;
	item = x;

	// checks to see if the item type is not a credit
	if( (item != CREDIT) )
	{
		tax   = amt * .07;

	} // end if( (x != CREDIT) )

	else
	{
		tax   = 0;

	} // end else

	total = amt + tax;

} // end void Sale::MakeSale(ItemType x, double amt)

/******************************************************************************/
/*                       Item Function                                        */
/*

Author: Claudius Christian
Date:  2/26/2013

Description: Returns the type of item in the sale
*/

ItemType Sale::Item()
 {
	 return item;

 } // end of ItemType Sale::Item()

/******************************************************************************/
/*                       Price Function                                       */
/*

Author: Claudius Christian
Date:  2/26/2013

Description: Return the cost of the item purchased.
*/

double Sale::Price()
{
	return price;

} // end double Sale::Price()

/******************************************************************************/
/*                       Tax Function                                         */
/*

Author: Claudius Christian
Date:  2/26/2013

Description: Return the charged tax amount of the item purchased.
*/

double Sale::Tax()
{
	return tax;

} // end double Sale::Tax()

/******************************************************************************/
/*                       Total Function                                       */
/*

Author: Claudius Christian
Date:  2/26/2013

Description: Return the total of the item purchased.
*/

double Sale::Total()
{
	return total;

} // end double Sale::Total()

/******************************************************************************/
/*                       Display Function                                       */
/*

Author: Claudius Christian
Date:  2/26/2013

Description: for the Display function, output the sale item, the price, the tax,
  // and the total (all on one line).  For store credit, the amounts
  // should be enclosed in < > symbols, to indicate a negative charge.  
  // All monetary output should be in dollars and cents format, to two
  // decimal places. 
  // Examples:	Book         $ 20.00    Tax:  $ 1.40   Total:  $ 21.40
  //		    Credit	    <$ 15.00>   Tax:  $ 0.00   Total: <$ 15.00>
*/

void Sale::Display()
{
	switch ( item )
	{
	case BOOK:
		cout << "Book ";
		break;
	case DVD:
		cout << "DVD ";
		break;
	case SOFTWARE:
		cout << "Software ";
		break;
	case CREDIT:
		cout << "Credit ";
		break;

	} // end of switch ( item ) 

	if( item != CREDIT )
	{
		cout << setprecision(2) << fixed << "$" << price << " Tax: $" 
			 << tax << " Total: $" << total;
	
	} // end if( item != CREDIT )

	else
	{ 
		cout << setprecision(2) << fixed << "<$" << price << "> Tax: $" 
			 << tax << " Total: <$" << total << ">";

	} // end else
} // end of void Sale::Display() 



/******************************************************************************/
/*                      E N D   P R O G R A M                                 */
