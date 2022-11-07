#pragma once

///////////////////////// TO-DO (1) //////////////////////////////
/// Include necessary header files
/// Hint:  Include what you use, use what you include
///
/// Do not put anything else in this section, i.e. comments, classes, functions, etc.  Only #include directives
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include "GroceryItem.hpp"
/////////////////////// END-TO-DO (1) ////////////////////////////

// Singleton Design Pattern
class GroceryItemDatabase
{
public:
  // Get a reference to the one and only instance of the database
  static GroceryItemDatabase &instance();

  // Locate and return a reference to a particular record
  GroceryItem *find(const std::string &isbn); // Returns a pointer to the item in the database if
                                              // found, nullptr otherwise
  // Queries
  std::size_t size() const; // Returns the number of items in the database

private:
  GroceryItemDatabase(const std::string &filename);

  GroceryItemDatabase(const GroceryItemDatabase &) = delete;            // intentionally prohibit making copies
  GroceryItemDatabase &operator=(const GroceryItemDatabase &) = delete; // intentionally prohibit copy assignments

  ///////////////////////// TO-DO (2) //////////////////////////////
  /// Private implementation details
  /// Add any necessary private helper functions, member attributes, etc.
  GroceryItem *find_helper(size_t i, std::vector<GroceryItem> vect, const std::string &isbn);
  GroceryItem *ptr = nullptr;
  std::vector<GroceryItem> ds;
  size_t i = 0;
  /////////////////////// END-TO-DO (2) ////////////////////////////
};
