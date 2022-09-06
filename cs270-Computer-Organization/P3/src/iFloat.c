#include "Debug.h"
#include "iFloat.h"

/** @file iFloat.c
 *  @brief You will modify this file and implement nine functions
 *  @details Your implementation of the functions defined in iFloat.h.
 *  You may add other function if you find it helpful. Added function
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file.
 *  <p>
 *  @author Brock Fisher
 */

/* declaration for useful function contained in testFloat.c */
const char* getBinary (iFloat_t value);

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatGetSign (iFloat_t x) {
  iFloat_t returnValue = 1;
  int mask = 0x8000;
  if ((x & mask) == 0) {
	returnValue = 0;
  }
  return returnValue; /* implement this */
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatGetExp (iFloat_t x) {
  int value = x;
  int mask = 0x7C00;
  iFloat_t returnValue = mask & value;
  returnValue = returnValue >> 10;
  return returnValue; /* implement this */
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatGetVal (iFloat_t x) {
  int mask = 0x03FF;
  int sign = floatGetSign(x);
  int maskForMantissa = 0x0400;
  iFloat_t returnValue = x & mask;
  returnValue = returnValue | maskForMantissa;
  if (sign == 1) {
	returnValue =(~returnValue)+1;
  }
  return returnValue;
}

/** @todo Implement based on documentation contained in iFloat.h */
void floatGetAll(iFloat_t x, iFloat_t* sign, iFloat_t*exp, iFloat_t* val) {
  iFloat_t storeSign = floatGetSign(x);
  iFloat_t storeExp = floatGetExp(x);
  iFloat_t storeVal = floatGetVal(x);

 *sign = storeSign;
  *exp = storeExp;
 *val = storeVal;
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatLeftMost1 (iFloat_t bits) {
  if (bits == 0) {
	return -1;
  }
  
  iFloat_t msb = 0;
  bits = bits/2;
  while (bits != 0) {
	bits = bits/2;
	msb++;
  }
  return msb;
}
/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatAbs (iFloat_t x) {
  iFloat_t returnValue = x;
  iFloat_t sign = floatGetSign(x);

  if (sign == 0) {
	return returnValue;
  }
  int mask= 0x7FFF;
  returnValue = returnValue & mask;
  return returnValue;
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatNegate (iFloat_t x) {
  iFloat_t returnValue = x;
  int mask = 0x8000;
  return returnValue^mask;

}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatAdd (iFloat_t x, iFloat_t y) {
  debug("%s: bits of x (IEEE 754)", getBinary(x)); // example only
  debug("%s: bits of y (IEEE 754)", getBinary(y)); // example only
  // get necessary values
  iFloat_t expX = floatGetExp(x);
  iFloat_t expY = floatGetExp(y);
  iFloat_t valueX = floatGetVal(x);
  iFloat_t valueY = floatGetVal(y);
  debug("x value = %s", getBinary(valueX));
  debug("y value = %s", getBinary(valueY));
  iFloat_t finalExp = 0;
  //shifting exponents/values as needed
  if (expX > expY) {
	valueY = valueY >> (expX-expY);
	finalExp = expX;
  }
  else if (expX == expY) {
	finalExp = expX;
  }
  else {
	valueX = valueX >> (expY-expX);
	finalExp = expY;
  }
  debug("x value after equalizign exp: %s", getBinary(valueX));
  debug("y value after equalizing exp: %s", getBinary(valueY));
  // add the values
  iFloat_t sum = valueX + valueY;
  iFloat_t sign = 0;
  if (sum < 0) {
	sum = (~sum)+1;
	sign = 1;
  }
  debug("sum = %s", getBinary(sum));
  // normalize result
	
	iFloat_t leftBit = floatLeftMost1(sum);
	debug("finalExp before loop = %s", getBinary(finalExp));
	debug("leftBit = %s", getBinary(leftBit));
	if (leftBit > 10) {
		sum = sum >> (leftBit-10);
		finalExp = finalExp + (leftBit-10);
	}
	else if (leftBit < 10) {
		sum = sum << (10-leftBit);
		finalExp = finalExp - (10-leftBit);
	}
	else {
	}
  //reassemble value
  finalExp = finalExp << 10;
  sign = sign << 15;
  int clearMantissaMask = 0xFBFF;
  sum = sum & clearMantissaMask;
  debug("sign = %s", getBinary(sign));
  debug("finalExp = %s", getBinary(finalExp));
  debug("sum = %s", getBinary(sum));
  iFloat_t returnValue = sign | finalExp | sum;
  debug("returnValue = %s", getBinary(returnValue));
  return returnValue;
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatSub (iFloat_t x, iFloat_t y) {
  iFloat_t returnValue = floatAdd(x,floatNegate(y));
  return returnValue;
}

