#ifndef BIG_INT_BCD
#define BIG_INT_BCD

#include <vector>
#include <ostream>
#include "abstract_big_int.h"

// TODO: they should all inherit from an abstract base big int class.

// This class provides an integer data type that can store arbitrarily large values.
// It has the advantage of maintaining a binary coded decimal representation, allowing
// for quick access to any digit or span of digits.
class BCD_Int : public AbstractBigInt {
  public:
    BCD_Int(unsigned int x);
    BCD_Int(unsigned long x);
    BCD_Int(unsigned long long x);
    BCD_Int(std::string x);
    BCD_Int& operator+(const BCD_Int& rhs) const;
    BCD_Int& operator%(const BCD_Int& rhs) const;
    BCD_Int& operator*(const BCD_Int& rhs) const;
    BCD_Int& operator/(const BCD_Int& rhs) const;
    BCD_Int& operator&(const BCD_Int& rhs) const;
    BCD_Int& operator^(const BCD_Int& rhs) const;
    BCD_Int& operator|(const BCD_Int& rhs) const;
    BCD_Int& operator>>(unsigned long rhs) const; // performs the shift in base 2?
    BCD_Int& operator<<(unsigned long rhs) const; // performs the shift in base 2?
    bool operator==(const int &index) const;
    uint8 & operator[](const int &index);
    const uint8 & operator[](const int &index) const;
    friend ostream operator<<(const ostream &stream) const;
  private:
    std::vector<int8> digits;
    init(unsigned long long x);
};

#endif //BIG_INT_BCD
