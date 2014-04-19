/******************************************************************************/
/*                       Author and Date                                      */
/*

Author: Claudius Christian 
Date: 2/26/2013 

/******************************************************************************/
/*                       Summary                                              */
/*

simulate sales at a store that sells books, DVDs, and software, as well as the 
accounting of the day's sales on one cash register. The register will keep 
track of a list of the most recent sales. You will need to finish the writing 
of two classes: Sale and Register. The full header file for the Sale class has 
been provided in a file called sale.h.

/******************************************************************************/
/*                       Header Files                                         */


#include "register.h"                      // needed for register.cpp
#include <iostream>                        // for input and output
using namespace std;

/******************************************************************************/
/*                       Constants                                            */

const int BLOCKSIZE = 2;      // array size 

/******************************************************************************/
/*                       Default Constructor                                  */
/*

Author: Claudius Christian
Date:  2/26/2013

Description: The constructor should take in two parameters, which allow the ID 
number and starting amount in the register to be initialized when the Register 
object is created. To create a Register object, this data must be passed in.
*/

Register::Register( int registerID, double registerAmount )
{
	ID       = registerID;
	amount   = registerAmount;
	capacity = BLOCKSIZE;
	numSales = 0;

	// created 5 elements in the sales array to start
	salesArray = new Sale [ capacity ];

} // end Register::Register( int registerID, double registerAmount ) 

/******************************************************************************/
/*                       Destructor Constructor                               */
/*

Author: Claudius Christian
Date:  2/26/2013

Description: The destructor should do any appropriate clean-up tasks needed to 
manage the dynamic memory
*/

Register::~Register()
{
	delete [] salesArray;
	
} // end of Register::~Register()

/******************************************************************************/
/*                       Cancel Purchase  Function                            */
/*

Author: Claudius Christian
Date:  2/27/2013

Description: This function should cancel the last sale in the list. This means 
that the amount in the cash register, as well as the data in the sale list, 
should be adjusted accordingly (as if the sale had never happened). This 
simulates the idea that a sale rung up incorrectly can be voided out by the 
cashier. If the sale list is empty, print an appropriate error message and 
abort the cancel operation.
*/

void Register::Cancel()
{
	// check to see if any sales have been made
	if( numSales > 0 )
	{
    
	// decrement the number of sales and store the new sum in amount
	amount -= salesArray[ numSales - 1 ].Total();

	// decrement the number of sales by 1
	numSales--;

	// call resize to determine if the array size needs to be adjusted.
	resize();

	} // end if( numSales > 0 )

	else
	{
		cout << "No Sales have been made. \n";

	} // end else
} // end void Register::Cancel()

/******************************************************************************/
/*                       Get Amount Function                                  */
/*

Author: Claudius Christian
Date:  2/27/2013

Description: accessor function should return the current amount in the 
registerto the caller.
*/

double Register::GetAmount()
{
	return amount;

} // end double Register::GetAmount() 

/******************************************************************************/
/*                       Get ID Function                                      */
/*

Author: Claudius Christian
Date:  2/27/2013

Description: accessor function should return the current ID number and 
current amount in the register, respectively, to the caller.
*/

int Register::GetID()
{
	return ID;

} // end int Register::GetID()

/******************************************************************************/
/*                       Grow Function                                        */
/*

Author: Claudius Christian
Date:  2/27/2013

Description: increases the dynamically allocated array. There should never be 
more than 5 unused slots in this array (i.e. the number of allocated spaces may 
be at most 5 larger than the number of slots that are actually filled with real 
data). 
*/

void Register::grow()
{

		// declare dynamic array
		static Sale * tempArray;

		// create a sale array of size numSales and assign it to tempArray
		tempArray = new Sale [ numSales ];

		// copies salesArray data and assings it to tempArray
		for( int i = 0; i < numSales; i++ )
		{
			// tempArray[ i ] = salesArray[ i ];
			tempArray[ i ].MakeSale(salesArray[ i ].Item(), salesArray[ i ].Price() ) ;

		} // end for( int i = 0; i < numSales; i++ )

		// deletes salesArray
		//delete [] salesArray;
	
		// declares salesArray of type Sale
		//Sale * salesArray;

		
		// creates a salesArray of size BLOCKSIZE(5) + number of sales
		//salesArray[ capacity + BLOCKSIZE ];

		// create sale array of size (capacity - BLOCKSIZE) and assign it to 
		// salesArray
		salesArray=new Sale[  capacity + BLOCKSIZE ];

		capacity += BLOCKSIZE;

		// copies tempArray data and assings it to salesArray
		for( int i = 0; i < numSales; i++ )
		{
			//salesArray[ i ] = tempArray[ i ];
			salesArray[ i ].MakeSale(tempArray[ i ].Item(), tempArray[ i ].Price() ) ;


		} // end for( int i = 0; i < numSales; i++ )

		// notify the user the array has been resized
		cout << "** Array being resized to " << capacity 
			 << " allocated slots";
		this->salesArray = salesArray;
		delete [] tempArray;
} // end void Register::grow()

/******************************************************************************/
/*                       Resize Function                                      */
/*
Author: Claudius Christian
Date:  2/27/2013

Description: There is no size limit to the sales list, so it should be 
implemented with a dynamically allocated array. (This means you'll need an 
array of Sale objects). There should never be more than 5 unused slots in this 
array (i.e. the number of allocated spaces may be at most 5 larger than the 
number of slots that are actually filled with real data). This means that you 
will need to ensure that the array allocation expands or shrinks at appropriate 
times. Whenever the array is resized, print a message (for testing purposes) 
that states that the array is being resized, and what the new size is. Example: 
"** Array being resized to 10 allocated slots". Correct memory management
*/

void Register::resize()
{

	// to grow the salesArray
	if( (capacity - numSales) == 0 )
	{
		grow();

	} // end if( (capacity - numSales) == 0 )

	else if( (capacity - numSales) >= BLOCKSIZE )
	{
		shrink();

	} // end if( (capacity - numSales) == 5 )
} // end resize function

/******************************************************************************/
/*                       Ring Up Sale Function                                */
/*

Author: Claudius Christian
Date:  2/26/2013

Description: This function allows the item type and base price of a sale to be 
passed in as parameters. This function should store the sale in the sale list, 
and it should update the amount of money in the cash register appropriately. 
Items that are bought will add money to the register. Remember that sales tax 
must be added to the base price of any item sold. If the sale type is CREDIT, 
then you should deduct the amount from the register.
*/

void Register::RingUpSale( ItemType x, double amt )
{
	// makes a sale object and calculates tax, item price
	salesArray[ numSales ].MakeSale( x, amt );


	// checks to see if the sales type is not a credit
	if( x != CREDIT )
	{
		// increases the cash register amount by the price of the sale
		amount += salesArray[ numSales ].Total();

	} // end if( x != CREDIT )

	else
	{
		// decreases the cash register amount by the price of the sale
		amount -= salesArray[ numSales ].Total();

	} // end else

	numSales++;
	resize();

} // end of void Register::RingUpSale( ItemType x, double amt )

/******************************************************************************/
/*                       Sales Tax Function                                   */
/*

Author: Claudius Christian
Date:  2/27/2013

Description: This function should calculate and return the total amount of 
sales tax for the last n sales (i.e. the most recent ones), where n is an 
integer passed in as a parameter. If n is higher than the number of sales 
currently stored, just calculate the total tax for all sales currently in the 
sale list. If n is invalid (a negative number), print an appropriate error 
message and return 0.
*/

double Register::SalesTax( int n )
{
	// holds the total tax calculated
	double totalTax = 0;

	// verifies the number entered is valid
	if( (n <= numSales) && (n >= 0) )
	{
		// cycle through array
		for( int i = 1; i <= n; i++)
		{
			// find the total tax and store it in totalTax
			totalTax += salesArray[ numSales - i ].Tax();

		} // end of for( int i; i < n; i++) 
	} // end of if( n <= numSales )

	// if user entered number is greater than total sales
	// calculate total sales tax
	else if( n > numSales )
	{
		// cycle through array
		for( int i = 1; i < n; i++)
		{
			// find the total tax and store it in totalTax
			totalTax += salesArray[ numSales - 1 ].Tax();

		} // end of for( int i; i < n; i++)
	} // else if( n > numSales )

	// error case
	else
	{
		cout <<"You entered an invalid number.\n";
	}

	return totalTax;

} // end double Register::SalesTax()

/******************************************************************************/
/*                       Show All Function                                    */
/*

Author: Claudius Christian
Date:  2/27/2013

Description: ShowAll should show all of the sales currently in the sale 
list, one per line. This display should be in the order oldest to newest. 
(i.e. the most recent sale is displayed last). If there are no sales currently 
in the list, then output an appropriate message instead (like "No sales have 
been made").
*/

void Register::ShowAll()
{
	// check to see if any sales have been made
	if( numSales > 0 )
	{
		// loop through the sales
		for( int i = 0; i < numSales; i++ )
		{
			salesArray[ i ].Display();

			cout << "\n";

		} // end for( int i = 0; i < numSales; i++ )
	} // end if( numSales > 0 )

	else
	{
		cout << "No Sales have been made. \n";

	} // end else
} // end of void Register::ShowAll()

/******************************************************************************/
/*                       Show Last Function                                   */
/*

Author: Claudius Christian
Date:  2/27/2013

Description: ShowLast should display only the information about the last 
sale that was made.
*/

void Register::ShowLast()
{
	salesArray[ numSales - 1 ].Display();

} // end void Register::ShowLast() 

/******************************************************************************/
/*                       Shrink  Function                                     */
/*

Author: Claudius Christian
Date:  2/27/2013

Description: decreases the dynamically allocated array. There should never be 
more than 5 unused slots in this array (i.e. the number of allocated spaces may 
be at most 5 larger than the number of slots that are actually filled with real 
data). 
*/

void Register::shrink()
{

		// declare dynamic array
		static Sale * tempArray;

		// create a sale array of size numSales and assign it to tempArray
		tempArray = new Sale [ numSales ];

		// copies salesArray data and assings it to tempArray
		for( int i = 0; i < numSales; i++ )
		{
			tempArray[ i ].MakeSale(salesArray[ i ].Item(), salesArray[ i ].Price() ) ;

		} // end for( int i = 0; i < numSales; i++ )

		// deletes salesArray
		//delete [] salesArray;
	
		// declares salesArray of type Sale
		Sale * salesArray;

		// creates a salesArray of size capacity - BLOCKSIZE(5)
		//salesArray[ capacity - BLOCKSIZE ];

		// create sale array of size (capacity - BLOCKSIZE) and assign it to 
		// salesArray
		salesArray = new Sale[ capacity - BLOCKSIZE ];

		// reduce the the array index by BLOCKSIZE
		capacity -= BLOCKSIZE;

		// copies tempArray data and assings it to salesArray
		for( int i = 0; i < numSales; i++ )
		{
			salesArray[ i ].MakeSale(tempArray[ i ].Item(), tempArray[ i ].Price() ) ;


		} // end for( int i = 0; i < numSales; i++ )

		// notify the user the array has been resized
		cout << "** Array being resized to " << capacity 
			 << " allocated slots";

		delete [] tempArray;

} // end void Register::shrink()



/******************************************************************************/
/*                      E N D   P R O G R A M                                 */