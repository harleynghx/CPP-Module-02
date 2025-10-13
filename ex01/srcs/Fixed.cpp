#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "Default Concstructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy Constructor called" << std::endl;
    this->_value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int cint) : _value(cint << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float cfloat) : _value(roundf(cfloat * (1 << this->_fractionalBits))) {
    std::cout << "Float construtor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    return this->_value;
}

void Fixed::setRawBits( int const raw ) {
    this->_value = raw;
}

int Fixed::toInt ( void ) const {
    return _value >> _fractionalBits;
}

float Fixed::toFloat( void ) const {
    return static_cast<float>(this->_value) / (1 << this->_fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}


