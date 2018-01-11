// day 14
// polymorphism continued:
// Adding multiple inheritance.
// Inheritance from shared base classes; this is (can be) virtual derivation

#include <iostream>
using std::cout;
using std::cin;

#define RESOLVE_AMBIGUOUS_METHOD

class Animal { // will be a common base class for Horse and Bird
public:
  Animal() {itsAge = 0;}
  Animal(int);
  ~Animal() {};
  virtual int GetItsAge() const { return itsAge; }
private:
  int itsAge;
};

Animal::Animal(int age):
  itsAge(age)
{
}

enum COLOUR {white, brown, black};

class Horse : virtual public Animal {
public:
  Horse() { cout << "Horse constructor "; }
  Horse(int);
  virtual ~Horse() { cout << "Horse destructor "; }
  virtual void Whinny() const { cout << "Whinny!!\n"; }
  //  virtual int GetItsAge() const { return itsAge;}
  virtual COLOUR GetItsColour() const { return itsColour; }
private:
  COLOUR itsColour;
};

Horse::Horse(int a):
  Animal(a)
{
  cout << "Horse(int) constructor\n";
}

class Bird : virtual public Animal {
public:
  Bird() { cout << "Bird constructor "; itsWeight = 1; }
  Bird(int, int);
  virtual ~Bird() { cout << "Bird destructor ";}
  virtual void Chirp() const { cout << "Chirp!!\n";}
  virtual void Fly() const { cout << "I can fly!\n";}
  virtual int GetItsWeight() const { return itsWeight; }
  virtual COLOUR GetItsColour() const { return itsColour; }
private:
  int itsWeight;
  COLOUR itsColour;
};

Bird::Bird(int w, int a):
  Animal(a),
  itsWeight(w)
{
  cout << "Bird(int) constructor\n";
}


class Pegasus : public Horse , public Bird
{
public:
  void Chirp() const { Whinny(); }
  Pegasus(int magic_rank, int age, int weight);
  virtual ~Pegasus() { cout << "Pegasus destructor ";}
  int GetItsMagicRanking() const { return magic_ranking; }
#ifdef RESOLVE_AMBIGUOUS_METHOD
  COLOUR GetItsColour() const { return Bird::GetItsColour(); }
#endif
  //  int GetItsAge() const { return Horse::GetItsAge(); } // not necessarily needed with virtual derivation; of course, I can override it and do other work in the function before chaining up, ie calling the base class method
private:
  int magic_ranking;
};

Pegasus::Pegasus(int magic_rank, int age, int weight):
  Animal(age*2), // this call trumps the Animal initialisers in Horse and Bird
  Horse(age),
  Bird(age, weight),
  magic_ranking(magic_rank)
{
  cout << "Pegasus constructor\n";
}

const int MagicNumber =2;

int main(void)
{
  Horse *pHorse1;
  Bird *pBird1;
  Pegasus *pPegasus;
  
  cout << "Create a horse\n";
  pHorse1 = new Horse(5);
  cout << "\n";
  cout << "Create a pegasus in a horse ptr\n";
  pBird1 = new Bird(4,5);
  cout << "\n";

  cout << "Now create a pegasus in a pegasus ptr\n";
  pPegasus = new Pegasus(4,5,6); // age = 5
  cout << "\n";

  cout << "Horse Age: " << pHorse1->GetItsAge() << "\n";
  cout << "Bird Age: " << pHorse1->GetItsAge() << "\n";
  cout << "Pegasus Age: " << pPegasus->GetItsAge() << "\n";


  cout << "Pegasus class methods:\n";
  pPegasus->Whinny();
  pPegasus->Chirp();
  pPegasus->Fly();
  cout << "its magic " << pPegasus->GetItsMagicRanking() << "\n";

  // this line is problematic because Pegasus inherits from both
  // Horse and Bird, both of which inherit from Animal.
  // In effect, there is the Bird::Animal::GetItsAge() and also
  // Horse::Animal::GetItsAge() method to choose from.
  cout << "its age " << pPegasus->GetItsAge() << "\n";
  
  cout << "its weight " << pPegasus->GetItsWeight() << "\n";
  // GetItsColour() is ambiguous since both base classes
  // has the same method
  // I can resolve this via fully specifying the class:
  //  cout << "its colour " << pPegasus->GetItsColour() << "\n";
  cout << "its colour " << pPegasus->GetItsColour() << "\n";
  // or modifying the Pegasus class (as above I return the bird colour)
  cout << "its colour " << pPegasus->GetItsColour() << "\n";


  delete pHorse1;
  cout << "\n";
  delete pBird1;
  cout << "\n";
  delete pPegasus;
  cout << "\n";
}

