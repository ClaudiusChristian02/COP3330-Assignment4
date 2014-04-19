/******************************************************************************/
/*                       Author and Date                                      */
/*

Author: Claudius Christian 
Date: 2/26/2013 

/******************************************************************************/
/*                       Summary                                              */
/*

An object of type Sale will store information about a single sale.
The variable "item" stores the type of item being sold (one of the four
items in the enumerated type ItemType).  Books, music, and software are
the types of items sold.  CREDIT stands for store credit, which incurs
a negative monetary charge.

A Register object should store at least the following information: an 
identification number (an integer) for the cash register object, the amount of 
money in the cash register object, and a list of sales. All member data must be 
private. There is no size limit to the sales list, so it should be implemented with 
a dynamically allocated array. (This means you'll need an array of Sale objects). 
There should never be more than 5 unused slots in this array (i.e. the number of 
allocated spaces may be at most 5 larger than the number of slots that are actually 
filled with real data). This means that you will need to ensure that the array 
allocation expands or shrinks at appropriate times. Whenever the array is resized, 
print a message (for testing purposes) that states that the array is being resized, 
and what the new size is. Example: "** Array being resized to 10 allocated slots". 
Correct memory management
*/

/******************************************************************************/
/*                       Header Files                                         */


#include "sale.h"                      // needed for sales.cpp

class Register
{
public:
	Register( int registerID, double registerAmount );
	~Register();

	void Cancel();                                  // cancel the last sale in the
	                                                // list
	double GetAmount();                             // return amount in the 
	                                                // register
	int GetID();                                    // return the current ID number
	void grow();                                    // grows the dynamic array
	void resize();                                  // determines if the array 
	                                                // should
	                                                // grow or shrink
	void RingUpSale( ItemType x, double amt );      // claculates a sale
	double SalesTax( int n );                       // claculates sales tax
	void ShowAll();                                 // display entire sale list
	void ShowLast();                                // display the last sale made

	void shrink();
	
private:
	double amount;        // total amount in the register
	int capacity;         // keeps track of the current array size
	int ID;               // register ID number
	int numSales;         // holds the total number of sales
	double totalTax;      // holds the sum of all taxes collected on purchases
	Sale * salesArray;    // pointer to sales array for dynamic array
	
};