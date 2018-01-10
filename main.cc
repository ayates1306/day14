// day 14
// polymorphism continued
// adding multiple inheritance

#include <iostream>
using std::cout;
using std::cin;

class Horse {
public:
  Horse() { cout << "Horse constructor\n"; }
  virtual ~Horse() { cout << "Horse destructor "; }
  virtual void Whinny() const { cout << "Whinny!!\n"; }
private:
  int itsAge;
};

class Bird {
public:
  Bird() { cout << "Bird constructor\n";}
  virtual ~Bird() { cout << "Bird destructor ";}
  virtual void Chirp() const { cout << "Chirp!!\n";}
  virtual void Fly() const { cout << "I can fly!\n";}
private:
  int itsWeight;
};

class Pegasus : public Horse , public Bird
{
public:
  void Chirp() const { Whinny(); }
  Pegasus() { cout << "Pegasus constructor\n";}
  ~Pegasus() { cout << "Pegasus destructor ";}
};

const int MagicNumber =2;

int main(void)
{
  Horse *pHorse1, *pHorse2;
  Bird *pBird1, *pBird2;
  
  pHorse1 = new Horse;
  pHorse2 = new Pegasus;
  pBird1 = new Bird;
  pBird2 = new Pegasus;

  pHorse1->Whinny();
  pHorse2->Whinny();

  pBird1->Chirp();
  pBird2->Chirp();

  delete pHorse1;
  cout << "\n";
  delete pHorse2;
  cout << "\n";
  delete pBird1;
  cout << "\n";
  delete pBird2;
  cout << "\n";
}

