// day 14
// polymorphism continued
// adding multiple inheritance

#include <iostream>
using std::cout;
using std::cin;

enum COLOUR {white, brown, black};

class Horse {
public:
  Horse() { cout << "Horse constructor "; itsAge = 1;}
  Horse(int);
  virtual ~Horse() { cout << "Horse destructor "; }
  virtual void Whinny() const { cout << "Whinny!!\n"; }
  virtual int GetItsAge() const { return itsAge;}
  virtual COLOUR GetItsColour() const { return itsColour; }
private:
  int itsAge;
  COLOUR itsColour;
};

Horse::Horse(int a):
  itsAge(a)
{
  cout << "Horse(int) constructor\n";
}

class Bird {
public:
  Bird() { cout << "Bird constructor "; itsWeight = 1; }
  Bird(int);
  virtual ~Bird() { cout << "Bird destructor ";}
  virtual void Chirp() const { cout << "Chirp!!\n";}
  virtual void Fly() const { cout << "I can fly!\n";}
  virtual int GetItsWeight() const { return itsWeight; }
  virtual COLOUR GetItsColour() const { return itsColour; }
private:
  int itsWeight;
  COLOUR itsColour;
};

Bird::Bird(int w):
  itsWeight(w)
{
  cout << "Bird(int) constructor\n";
}


class Pegasus : public Horse , public Bird
{
public:
  void Chirp() const { Whinny(); }
  Pegasus(int magic_rank, int age, int weight);
  ~Pegasus() { cout << "Pegasus destructor ";}
  int GetItsMagicRanking() const { return magic_ranking; }
private:
  int magic_ranking;
};

Pegasus::Pegasus(int magic_rank, int age, int weight):
  Horse(age),
  Bird(weight),
  magic_ranking(magic_rank)
{
  cout << "Pegasus constructor\n";
}

const int MagicNumber =2;

int main(void)
{
  Horse *pHorse1, *pHorse2;
  Bird *pBird1, *pBird2;
  Pegasus *pPegasus;
  
  cout << "Create a horse\n";
  pHorse1 = new Horse;
  cout << "\n";
  cout << "Create a pegasus in a horse ptr\n";
  pHorse2 = new Pegasus(7,8,9);
  cout << "\n";
  cout << "Create a bird\n";
  pBird1 = new Bird;
  cout << "\n";
  cout << "Create a pegasus in a bird ptr\n";
  pBird2 = new Pegasus(1,2,3);
  cout << "\n";

  cout << "Now create a pegasus in a pegasus ptr\n";
  pPegasus = new Pegasus(4,5,6);
  cout << "\n";

  cout << "pHorse1 whinny: ";
  pHorse1->Whinny();
  cout << "Age: " << pHorse1->GetItsAge() << "\n";
  cout << "pHorse2 whinny: ";
  pHorse2->Whinny();
  cout << "Age: " << pHorse2->GetItsAge() << "\n";
  cout << "Horse2 colour " << pHorse2->GetItsColour() << "\n";

  cout << "pBird 1 chirp: ";
  pBird1->Chirp();
  cout << "its weight " << pBird1->GetItsWeight() << "\n";
  cout << "pBird 1 chirp: ";
  pBird2->Chirp();
  cout << "its weight " << pBird1->GetItsWeight() << "\n";
  cout << "Bird1 colour " << pBird1->GetItsColour() << "\n";

  cout << "Pegasus class methods:\n";
  pPegasus->Whinny();
  pPegasus->Chirp();
  pPegasus->Fly();
  cout << "its magic " << pPegasus->GetItsMagicRanking() << "\n";
  cout << "its age " << pPegasus->GetItsAge() << "\n";
  cout << "its weight " << pPegasus->GetItsWeight() << "\n";
  // GetItsColour() is ambiguous since both base classes
  // has the same method
  // cout << "its colour " << pPegasus->GetItsColour() << "\n";


  delete pHorse1;
  cout << "\n";
  delete pHorse2;
  cout << "\n";
  delete pBird1;
  cout << "\n";
  delete pBird2;
  cout << "\n";
  delete pPegasus;
  cout << "\n";
}

