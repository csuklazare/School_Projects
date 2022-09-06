#ifndef PHOBIC_H
#define PHOBIC_H

#include<vector>
#include<iostream>
#include<climits>
#include<algorithm>
#include<string>



class Phobic {


	public:
		std::vector<int> afraid;			// vector of numbers Phobic is afraid of
		Phobic(const Phobic &x);			// copy ctor
		Phobic(int y=0);				// ctor with 1 int as an argument
		Phobic& operator=(const Phobic &unchanged);	// ctor that updates LHS argument with RHS argument (unchanged)
		~Phobic();					// dtor
		[[nodiscard]] int get() const;			// return int value associated with this object
		Phobic operator<<(int one);			// this operator makes the phobic object afraid of the int. All prev. scary numbers remain scary
		[[nodiscard]] bool is_scary(int y);		// returns true iff current object fears the argument
		void setValue(int newValue);			// helper method to check the value to the afraid list. If value is afraid, increment by 1 until value is not afraid
		void setScary(int scary);			// helper method to check if each value inputted into make_scary is INT_MAX. if so, output print statement


		
	private:
		int value;	// the value each Phobic ctor has
		
};
// FREE FUNCTIONS
		std::vector<int> mergeVectors(const std::vector<int> &vector1, const std::vector<int> &vector2);	// helper private method to combine 2 const vectors and return the combined vector
		std::vector<int> mergeVectors(std::vector<int> &vector1, std::vector<int> &vector2);		// helper private method to combine 2 non const vectors and return combined vector

		[[nodiscard]] Phobic operator+(const Phobic &lhs, const Phobic &rhs);		// add 2 phobic objects together producing a new object
		[[nodiscard]] Phobic operator-(const Phobic &lhs, const Phobic &rhs);		// subtract phobic object rhs from lhs, creating new object
		[[nodiscard]] Phobic operator*(const Phobic &lhs, const Phobic &rhs);		// multiply phobic object lhs and rhs together to create new object
		[[nodiscard]] Phobic operator/(const Phobic &lhs, const Phobic &rhs); 		// divide phobic object lhs by rhs to create new object
		void operator+=(Phobic &lhs, const Phobic &rhs);				// Add phobic rhs to lhs, update lhs
		void operator-=(Phobic &lhs, const Phobic &rhs);				// Subtract phobic rhs from lhs, update lhs
		void operator*=(Phobic &lhs, const Phobic &rhs);				// multiply phobic lhs by rhs, update lhs
		void operator/=(Phobic &lhs, const Phobic &rhs);				// divide phobic lhs by rhs, update lhs
		[[nodiscard]] bool operator==(const Phobic &lhs, const Phobic &rhs);		// return true iff value in lhs == rhs
		[[nodiscard]] bool operator<(const Phobic &lhs, const Phobic &rhs);		// return true iff value in lhs < rhs
		[[nodiscard]] bool operator>(const Phobic &lhs, const Phobic &rhs);		// return true iff value in lhs > rhs
		[[nodiscard]] bool operator!=(const Phobic &lhs, const Phobic &rhs);		// return true iff value in lhs != rhs
		[[nodiscard]] bool operator<=(const Phobic &lhs, const Phobic &rhs);		// return true iff value in lhs <= rhs
		[[nodiscard]] bool operator>=(const Phobic &lhs, const Phobic &rhs);		// return true iff value in lhs >= rhs
		inline void error(const std::string& s);					// throws a runtime error




#endif
