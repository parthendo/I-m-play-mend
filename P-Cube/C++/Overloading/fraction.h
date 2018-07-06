#ifndef FRACTION_H
#define FRACTION_H

#include <ostream>
#include <vector>

class fraction{

private:
  int numerator;
  int denominator;
public:
  fraction();
  fraction(int a,int b);
  fraction operator+(fraction &obj);
  fraction operator-(fraction &obj);
  fraction operator*(fraction &obj);
  fraction operator/(fraction &obj);
  bool operator<(fraction &obj);
  bool operator>(fraction &obj);
  bool operator<=(fraction &obj);
  bool operator>=(fraction &obj);
  bool operator!=(fraction &obj);
  bool operator==(fraction &obj);
  int lcm(fraction &obj);
  fraction operator-()const;
  fraction operator++();
  fraction operator++(int);
  fraction operator--();
  fraction operator--(int);
  void swap(fraction &obj);
  friend std::ostream &operator<<(std::ostream &output,fraction &obj);
  int getNumerator();
  int getDenominator();
  void sort(std::vector <fraction> obj);
};

#endif
