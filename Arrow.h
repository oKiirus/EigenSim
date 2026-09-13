#pragma once
#include <vector>
#include <string>
#include <iostream>




class Arrow
{
	private:
		std::vector<double> components;

	public:

		Arrow();
		Arrow(double x);
		Arrow(double x, double y);
		Arrow(double x, double y, double z);
		Arrow(double x, double y, double z, double w);
		Arrow(const std::vector<double>& vec);
		Arrow(const Arrow& arrow);
		Arrow(int dim);

		Arrow add(const Arrow& other) const;
		Arrow operator+(const Arrow& other) const;
		Arrow sub(const Arrow& other) const;
		Arrow operator-(const Arrow& other) const;
		Arrow mult(double scalar) const;
		Arrow operator*(double scalar) const;
		Arrow div(double scalar) const;
		Arrow operator/(double scalar) const;
		double dot(const Arrow& other) const;
		Arrow cross(const Arrow& other) const;
		Arrow negate() const;
		Arrow normalize() const;

		double get(int i) const;
		void set(int i, double value);
		void set(Arrow newArrow);
		
		

		int length() const;
		int length(const Arrow& A) const;
		int length(const Arrow& A, const Arrow& B) const;
		int length(const Arrow& A, const Arrow& B, const Arrow& C) const;

		double size() const;
		void extend(int newLength);
	
		void print() const;
		void print(std::string prefix) const;
		void print(std::string prefix, std::string suffix) const;
		
		std::string toString() const {
			std::string s;

			s += "{ ";
			for (int i = 0; i < length(); i++) {
				s += +" " + std::to_string(get(i)) + " ";
			}
			s += " }";

			return s;
		}

		friend std::ostream& operator<<(std::ostream& os, const Arrow& arrow) {
			os << arrow.toString();
			return os;
		}
};

