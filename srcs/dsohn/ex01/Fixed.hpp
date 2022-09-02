#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int value;
	static const int bits;

public:
	Fixed();
	Fixed(const Fixed& fixed);
	~Fixed();
	Fixed& operator=(const Fixed& fixed);
	
	Fixed(const int value);
	Fixed(const float value);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif
