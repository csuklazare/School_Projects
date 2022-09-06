#ifndef PHOBIC_H
#define PHOBIC_H

#include<vector>
#include<iostream>
#include<climits>
#include<algorithm>


class Phobic {


	public:
		std::vector<int> afraid;	// vector of numbers Phobic is afraid of
		Phobic(const Phobic &x);		// copy ctor
		Phobic(int y=0);		// ctor with 1 int as an argument
		Phobic& operator=(const Phobic &unchanged);		// ctor that updates LHS argument with RHS argument (unchanged)
		~Phobic();		// dtor
		Phobic add(const Phobic &x) const;		// add 2 phobic objects together producing a new object
		Phobic sub(const Phobic &x) const;		// subtract phobic object x from current object, creating new object
		Phobic mul(const Phobic &x) const;		// multiply 2 phobic objects together to create new object
		Phobic div(const Phobic &x) const; 		// divide current phobic object by specified object to create new object
		void add_to(const Phobic &x);		// Add phobic x object to current object, store in current object
		void sub_from(const Phobic &x);		// Subtract phobix object x from current object, store in current object
		void mul_by(const Phobic &x);		// multiply current object by phobic object x, store in current object
		void div_by(const Phobic &x);		// divide current object by phobic object x, store in current object
		bool eq(const Phobic &x) const;		// return true iff value in current object == phobic x
		bool lt(const Phobic &x) const;		// return true iff value in current object < phobic x
		int get() const;			// return int value associated with this object
		void make_scary(int one, int two = 13, int three = 13, int four = 13, int five  = 13, int six = 13, int seven = 13, int eight = 13, int nine = 13, int ten = 13);	// this method takes from 1 - 10 int arguments, then makes these arguments scary numbers to the object. All prev. scary numbers remain scary
		bool is_scary(int y);		// returns true iff current object fears the argument
		
	private:
		int value;	// the value each Phobic ctor has
		std::vector<int> mergeVectors(const std::vector<int> &vector1, const std::vector<int> &vector2) const;	// helper private method to combine 2 const vectors and return the combined vector
		std::vector<int> mergeVectors(std::vector<int> &vector1, std::vector<int> &vector2);		// helper private method to combine 2 non const vectors and return combined vector
		void setValue(int newValue);		// helper method to check the value to the afraid list. If value is afraid, increment by 1 until value is not afraid
		void setScary(int scary);		// helper method to check if each value inputted into make_scary is INT_MAX. if so, output print statement
		
};


#endif
