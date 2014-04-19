// Bob Myers
// 
// sale.h -- header file for the Sale class
//
// An object of type Sale will store information about a single sale.
// The variable "item" stores the type of item being sold (one of the four
// items in the enumerated type ItemType).  Books, music, and software are
// the types of items sold.  CREDIT stands for store credit, which incurs
// a negative monetary charge.
// The variable "price" stores the base price of the item
// The variable "tax" is used to store the 7% sales tax
// The variable "total" is used to store the final charge (price + tax)

enum ItemType {BOOK, DVD, SOFTWARE, CREDIT};

class Sale
{
public:
   Sale();			// default constructor, 
				// sets numerical member data to 0

   void MakeSale(ItemType x, double amt);	

	// the MakeSale function loads data into the Sale object.  The
	// item and price are passed in.  Compute tax and total.
	// (For store credits, tax is 0).

   ItemType Item();		// Returns the type of item in the sale
   double Price();		// Returns the price of the sale
   double Tax();		// Returns the amount of tax on the sale
   double Total();		// Returns the total price of the sale
   void Display();		// outputs sale info (described below)

  // for the Display function, output the sale item, the price, the tax,
  // and the total (all on one line).  For store credit, the amounts
  // should be enclosed in < > symbols, to indicate a negative charge.  
  // All monetary output should be in dollars and cents format, to two
  // decimal places. 
  // Examples:	Book         $ 20.00    Tax:  $ 1.40   Total:  $ 21.40
  //		Credit	    <$ 15.00>   Tax:  $ 0.00   Total: <$ 15.00>

private:
   double price;	// price of item or amount of credit
   double tax;		// amount of sales tax (does not apply to credit)
   double total;	// final price once tax is added in.
   ItemType item;	// transaction type
};
