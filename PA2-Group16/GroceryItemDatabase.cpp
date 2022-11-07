///////////////////////// TO-DO (1) //////////////////////////////
/// Include necessary header files
/// Hint:  Include what you use, use what you include
///
/// Do not put anything else in this section, i.e. comments, classes, functions, etc.  Only #include directives
#include <iostream>
#include <vector>
#include <string>
#include "GroceryItemDatabase.hpp"
/////////////////////// END-TO-DO (1) ////////////////////////////

// Return a reference to the one and only instance of the database
GroceryItemDatabase &GroceryItemDatabase::instance()
{
  std::string filename;

  // Look for a prioritized list of database files in the current working directory to use
  // Don't forget to #include <filesystem> to get visibility to the exists() function
  if (filename = "Grocery_UPC_Database-Full.dat"; std::filesystem::exists(filename)) /* intentionally empty*/
    ;
  else if (filename = "Grocery_UPC_Database-Large.dat"; std::filesystem::exists(filename)) /* intentionally empty*/
    ;
  else if (filename = "Grocery_UPC_Database-Medium.dat"; std::filesystem::exists(filename)) /* intentionally empty*/
    ;
  else if (filename = "Grocery_UPC_Database-Small.dat"; std::filesystem::exists(filename)) /* intentionally empty*/
    ;
  else if (filename = "Sample_GroceryItem_Database.dat"; std::filesystem::exists(filename)) /* intentionally empty*/
    ;
  else
    filename.clear();

  static GroceryItemDatabase theInstance(filename);
  return theInstance;
}

// Construction
GroceryItemDatabase::GroceryItemDatabase(const std::string &filename)
{
  std::ifstream fin(filename, std::ios::binary);

  // The file contains GroceryItems separated by whitespace.  A GroceryItem has 4 pieces of data delimited with a comma.  (This
  // exactly matches the previous assignment as to how GroceryItems are read)
  //
  //       Field            Type            Notes
  //  1.   UPC Code         String          Unique identifier (primary key), always enclosed in double quotes
  //  2.   Brand Name       String          May contain spaces, always enclosed in double quotes
  //  3.   Product Name     String          May contain spaces, always enclosed in double quotes
  //  4.   Price            Floating Point  In dollars
  //
  //  Example:
  //    "00024600017008",   "Morton",         "Morton Kosher Salt Coarse",                                    15.17
  //    "00033674100066",   "Nature's Way",   "Nature's Way Forskohlii - 60 Ct",                               6.11
  //    "00041520893307",   "Smart Living",   "Smart Living 10.5\" X 8\" 3 Subject Notebook College Ruled",   18.98
  //
  //  Note: double quotes within the string are escaped with the backslash character
  //

  ///////////////////////// TO-DO (2) //////////////////////////////
  /// Hint:  Use your GroceryItem's extraction operator to read GroceryItems, don't reinvent that here.
  ///        Read grocery items until end of file pushing each grocery item into the data store as they're read.

  GroceryItem val;

  while (fin >> val)
  {
    ds.push_back(value);
  }

  /////////////////////// END-TO-DO (2) ////////////////////////////

  // Note:  The file is intentionally not explicitly closed.  The file is closed when fin goes out of scope - for whatever
  //        reason.  More precisely, the object named "fin" is destroyed when it goes out of scope and the file is closed in the
  //        destructor. See RAII
}

///////////////////////// TO-DO (3) //////////////////////////////
/// Implement the rest of the interface, including functions find (recursively) and size
///
/// See the SinglyLinkedList's extended interface in our Sequence Container Implementation Examples (SinglyLinkedList.hpp) for a
/// recursive find function example. Instead of starting at the head of the list, you want to start at the beginning of your data
/// store.
///
/// Programming note:  An O(n) operation, like searching an unsorted vector, would not generally be implemented recursively.  The
///                    depth of recursion may be greater than the program's function call stack size.  But for this programming
///                    exercise, getting familiar with recursion is a goal.
size_t GroceryItemDatabase::size() const
{
  return ds.size();
}

// public function for find
GroceryItem *GroceryItemDatabase::find(const std::string &isbn)
{
  return find_helper(i, ds, isbn);
}

// private helper function for find
GroceryItem *GroceryItemDatabase::find_helper(size_t i, std::vector<GroceryItem> vect, const std::string &isbn)
{
  // Base case : reached the end of the data without finding what we're lookinf for
  if (vect.size() <= i) // pointer is pointing to the end of datastore or there is no item in the datastore//if aVect.size() == 0;
  {
    return nullptr; // return nullptr if grocery item can't be found
  }

  // Visit : found what we are looking for
  if (vect[i].upcCode() == isbn)
  {
    *ptr = vect[i];
    return ptr;
  }

  // Call function again to keep looking
  return find_helper(i + 1, vect, isbn);
}
/////////////////////// END-TO-DO (3) ////////////////////////////
