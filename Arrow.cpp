#include "stdafx.h"

#include "Arrow.h"




Arrow::Arrow() : Arrow(std::vector<double>{0, 0, 0, 0, 0}) {}

Arrow::Arrow(double x) : Arrow(std::vector<double>{x}) {}
Arrow::Arrow(double x, double y) : Arrow(std::vector<double>{x, y}) {}
Arrow::Arrow(double x, double y, double z) : Arrow(std::vector<double>{x, y, z}) {}
Arrow::Arrow(double x, double y, double z, double w) : Arrow(std::vector<double>{x, y, z, w}) {}

Arrow::Arrow(const std::vector<double>& vec) : components(vec) {};
Arrow::Arrow(const Arrow& arrow) : components(arrow.components) {};
Arrow::Arrow(int dim) : components(std::vector<double>(dim, 0)) {};

int Arrow::length() const { return (int)components.size(); }
int Arrow::length(const Arrow& A) const
{
	return (int) std::max(length(), A.length());
}
int Arrow::length(const Arrow& A, const Arrow& B) const
{
	return (int) std::max(length(A), B.length());
}
int Arrow::length(const Arrow& A, const Arrow& B, const Arrow& C) const
{
	return (int) std::max(length(A, B), C.length());
}

double Arrow::get(int i) const {
	if (i < length()) {
		return components[i];
	}
	else {
		return 0;
	}
}

void Arrow::set(int i, double value) {
	if (i < length()) {
		components[i] = value;
	}
	else {
		extend(i);
		components[i] = value;
	}
}

void Arrow::set(Arrow newArrow)
{
	components = newArrow.components;
}

Arrow Arrow::normalize() const
{
	Arrow temp(*this);

	return temp / temp.size();
}

Arrow Arrow::add(const Arrow& other) const {
	Arrow temp(std::max(length(), other.length()));
	
	for (int i = 0; i < length(); i++) {
		temp.set(i, get(i) + other.get(i));
	}

	return temp;
}
Arrow Arrow::operator+(const Arrow& other) const
{
	return add(other);
}

Arrow Arrow::sub(const Arrow& other) const { 
	return add(other.negate()); 
};
Arrow Arrow::operator-(const Arrow& other) const
{
	return sub(other);
}

Arrow Arrow::mult(double scalar) const {
	Arrow temp(*this);

	for (int i = 0; i < temp.length(); i++) {
		temp.set(i, temp.get(i) * scalar);
	}

	return temp;
}
Arrow Arrow::operator*(double scalar) const
{
	return mult(scalar);
}

Arrow Arrow::div(double scalar) const { 
	return mult(1 / scalar); 
};
Arrow Arrow::operator/(double scalar) const
{
	return div(scalar);
}

Arrow Arrow::negate() const {
	return mult(-1);
};

double Arrow::dot(const Arrow& other) const
{
	double product = 0;

	for (int i = 0; i < length(other); i++) {
		product += get(i) * other.get(i);
	}

	return product;
}



double Arrow::size() const
{
	/*
		gets the length of the arrow
	*/

	double squared_sum = 0;

	for (int i = 0; i < length(); i++) {
		squared_sum += pow(get(i), 2);
	}

	return std::sqrt(squared_sum);
}

void Arrow::extend(int newLength) {
	if (newLength <= length()) {
		return; 
	}

	Arrow temp(*this);

	components = std::vector<double>(newLength, 0);
	
	for (int i = 0; i < newLength; i++) {
		if (i < temp.length())
			set(i, temp.get(i));
		else
			set(i, 0);
	}
}

void Arrow::print() const {
	std::cout << this->toString() << "\n";
}
void Arrow::print(std::string prefix) const {
	std::cout << prefix;
	print();
}
void Arrow::print(std::string prefix, std::string suffix) const {
	std::cout << prefix;
	print();
	std::cout << suffix;
}








