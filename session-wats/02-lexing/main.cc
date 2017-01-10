// vim: ft=text
#include <iostream>


int yaba() { return 100; }
int daba() { return 110; }
int doo()  { return 011; }
int dodo() { return 0x0; }


int main() {
  using std::cout;
  using std::cin;
  using std::endl;

  int doodeedoo[10];
  for (int i = 0; i < sizeof(doodeedoo); i++) ??<
    doodeedoo[i] = 2 * i;
  %>

  http://www.first-class-url-support.com

  cout << "you don't get it, hm??! ... "
          "ah, no worries, just enjoy the show." << endl;
  
  cout << (5[doodeedoo]) << endl;

  cout << (yaba(),daba(),doo()) << endl;

  int in;
  if (cin>>in,in&2,in<4) { cout << "okee" << endl; }

  if (int ret = dodo()) {
    cout << "dodo! " << ret << endl;
  } else {
    cout << "dodo? " << ret << endl;
  }

  int x1 = 1;
  int x2 = 2;
  if (x1 == 1)
    if (x2 == 3)
      (cout << "boopiedoop" << endl);
  else
    (cout << "doodiedoo" << endl);

  [](){}();

  return EXIT_SUCCESS;
}

