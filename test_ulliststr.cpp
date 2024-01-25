#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr l1;
  //cout << l1.get(0) << endl;

  /*
  for(int i = 1; i <= 30; i++){
    l1.push_back("YO" + to_string(i));
  }
  */

/*
  for(int i = 1; i <= 30; i++){
    l1.push_front("YO" + to_string(i));
  }
*/
/*
  l1.push_front("YO1");
  l1.push_front("YO2");
  l1.push_front("YO3");
  l1.push_front("YO4");
  cout << l1.back() << endl;
  cout << "FRONT: " << l1.front() << endl;

  l1.pop_front();
  l1.pop_front();
*/

/*
  int set = 22;

  for(int i = 0; i <= set; i++){
    l1.push_back("YO" + to_string(i));
  }
  
  l1.set(set, "YO NEW");
  //l1.set(4, "YO NEW");
  
  cout << "BACK: " << l1.back() << endl;


  for(int i = 0; i < set ; i++){
    cout << "---->" << endl;
      cout << "B" << endl;
     l1.pop_back();
      cout << "A" << endl;
  }

  
  cout << "BACK: " << l1.back() << endl;
*/

/*
int set = 20;
for(int i = 0; i <= set; i++){
    l1.push_front("YO" + to_string(i));
}

for(int i = 0; i < set; i++){
  l1.pop_front();
}

*/

//l1.push_front("768");
//l1.push_front("1024");
//l1.push_front("1536");

/*
for(int i = 0; i < 20; i++){
  l1.push_front("Push_front: " + to_string(i));
}
*/
//l1.push_back("YOYO");
//l1.push_back("YOYO2");
//string* answer = l1.getValAtLoc(0);
//string* answer = l1.getValAtLoc(1);

//l1.push_back("END");
/*for(int i = 0; i < 14; i++){
  l1.push_back("END" + to_string(i));
  l1.push_front("bob" + to_string(i));
}*/
//l1.push_back("bob");
//l1.push_back("bob2");
//l1.push_front("fred");

//string* answer = l1.getValAtLoc(28);
//cout << "answer: " << *answer << endl;

//cout << "BACK: " << l1.back() << endl;
//cout << "FRONT: " << l1.front() << endl;


for(int i= 0 ; i < 4; i++){

  cout << "---------->" << endl;
  l1.push_back("test");
  l1.get(0);

  l1.pop_back();
  cout << "SIZE: " << l1.size() << endl;
  cout << "EMPTY: " << l1.empty() << endl;
  cout << "---------->" << endl;
}
  //Front back
}
