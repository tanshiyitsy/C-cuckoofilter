#include "cuckoofilter.h"

#include <assert.h>
#include <math.h>

#include <iostream>
#include <vector>

#include "string"
#include "fstream"

using cuckoofilter::CuckooFilter;
using namespace std;
void test(){
  size_t total_items = 100;
  cout<<"input total_item"<<endl;
  cin>>total_items;
  // Create a cuckoo filter where each item is of type size_t and
  // use 12 bits for each item:
  //    CuckooFilter<size_t, 12> filter(total_items);
  // To enable semi-sorting, define the storage of cuckoo filter to be
  // PackedTable, accepting keys of size_t type and making 13 bits
  // for each key:
  //   CuckooFilter<size_t, 13, cuckoofilter::PackedTable> filter(total_items);
  cout<<"input finger_size"<<endl;
  int finger_size;
  cin>>finger_size;
//   CuckooFilter<size_t, 12> filter(total_items);
  CuckooFilter<size_t, finger_size> filter(total_items);

  // Insert items to this cuckoo filter
  size_t num_inserted = 0;
  for (size_t i = 0; i < total_items; i++, num_inserted++) {
    if (filter.Add(i) != cuckoofilter::Ok) {
      break;
    }
  }

  // Check if previously inserted items are in the filter, expected
  // true for all items
  for (size_t i = 0; i < num_inserted; i++) {
    assert(filter.Contain(i) == cuckoofilter::Ok);
  }

  // Check non-existing items, a few false positives expected
  size_t total_queries = 0;
  size_t false_queries = 0;
  for (size_t i = total_items; i < 2 * total_items; i++) {
    if (filter.Contain(i) == cuckoofilter::Ok) {
      false_queries++;
    }
    total_queries++;
  }

  // Output the measured false positive rate
  std::cout << "false positive rate is "
            << 100.0 * false_queries / total_queries << "%\n";

}
void expriment(){
  fstream logFile;
  char *file_path = "/home/hduser/testFiles/allLog.txt";
  logFile.open(file_path, ios::in | ios::out);
  int index = 0, numAll = 10;
  string log_entry;
 

  // Check if previously inserted items are in the filter, expected
  // true for all items
  for (size_t i = 0; i < num_inserted; i++) {
    assert(filter.Contain(i) == cuckoofilter::Ok);
  }

 
  while(index++ < numAll && getline(logFile, log_entry)){
        //cout<<index<<endl;
        //cout<<log_entry<<endl;
        
  }
  
  logFile.close();
}
int main(int argc, char **argv) {
  test();
  //expriment();
  return 0;
}
