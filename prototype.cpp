#include <iostream>
#include <vector>
using namespace std;

class Stooge {
public:
   virtual Stooge* clone() = 0;
   virtual void slap_stick() = 0;
};


/*********************************
* a clone method has been added to the Stooge hierarchy.
* Each derived class implements that method by returning an instance of itself
* 
*/
class Larry : public Stooge {
public:
   Stooge*   clone() { return new Larry; }
   void slap_stick() {
      cout << "Larry: poke eyes\n"; }
};
class Moe : public Stooge {
public:
   Stooge*   clone() { return new Moe; }
   void slap_stick() {
      cout << "Moe: slap head\n"; }
};
class Curly : public Stooge {
public:
   Stooge*   clone() { return new Curly; }
   void slap_stick() {
      cout << "Curly: suffer abuse\n"; }
};

/********************************
* A Factory class has been introduced that main-tains a suite of 
* "breeder" objects aka prototypes
* the factory knows how to delegate to the correct prototype
*/
class Factory {
private:
	static Stooge* s_prototypes[4];

public:
   static Stooge* make_stooge( int choice ) {
		return s_prototypes[choice]->clone();
   }
};
static Stooge* s_prototypes[] = {
	0, new Larry, new Moe, new Curly
};

/*************************
* MAIN
*/
int main() {
   vector<Stooge *> roles;
   int             choice;

   while (true) {
      cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
      cin >> choice;
      if (choice == 0)
         break;
      roles.push_back(
         Factory::make_stooge( choice ) );
   }

   for (int i=0; i < roles.size(); ++i)
      roles[i]->slap_stick();
   for (int i=0; i < roles.size(); ++i)
      delete roles[i];
}
