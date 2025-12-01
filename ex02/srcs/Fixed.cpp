#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed& other) { this->_value = other._value; }

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

Fixed::Fixed(const int cint) : _value(cint << _fractionalBits) {}

Fixed::Fixed(const float cfloat) : _value(roundf(cfloat * (1 << this->_fractionalBits))) {}

int Fixed::getRawBits( void ) const { return this->_value;}

void Fixed::setRawBits( int const raw ) { this->_value = raw;}

int Fixed::toInt ( void ) const { return _value >> _fractionalBits;}

float Fixed::toFloat( void ) const { return static_cast<float>(this->_value) / (1 << this->_fractionalBits);}


// comparison operators
bool Fixed::operator>(const Fixed& other) const { return this->_value > other._value;}

bool Fixed::operator<(const Fixed& other) const { return this->_value < other._value;}

bool Fixed::operator>=(const Fixed& other) const { return this->_value >= other._value;}

bool Fixed::operator<=(const Fixed& other) const { return this->_value <= other._value;}

bool Fixed::operator==(const Fixed& other) const { return this->_value == other._value;}

bool Fixed::operator!=(const Fixed& other) const { return this->_value != other._value;}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const { return Fixed(this->toFloat() + other.toFloat());}

Fixed Fixed::operator-(const Fixed& other) const { return Fixed(this->toFloat() - other.toFloat());}

Fixed Fixed::operator*(const Fixed& other) const { return Fixed(this->toFloat() * other.toFloat());}

Fixed Fixed::operator/(const Fixed& other) const { return Fixed(this->toFloat() / other.toFloat());}

// Increment/decrement operators
Fixed& Fixed::operator++() {      // Pre-increment
    this->_value += 1;
    return *this;
}

Fixed Fixed::operator++(int) {    // Post-increment
    Fixed temp(*this);
    this->_value += 1;
    return temp;
}

Fixed& Fixed::operator--() {      // Pre-decrement
    this->_value -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {    // Post-decrement
    Fixed temp(*this);
    this->_value -= 1;
    return temp;
}

// Static min/max functions
Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b;}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b;}

Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b;}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b;}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}


