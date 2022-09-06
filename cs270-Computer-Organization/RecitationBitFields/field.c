#include "field.h"

/** @file field.c
 *  @brief You will modify this file and implement five functions
 *  @details Your implementation of the functions defined in field.h.
 *  You may add other function if you find it helpful. 
 * <p>
 * @author <b>Your name</b> goes here
 */

/** @todo Implement in field.c based on documentation contained in field.h */
int getBit (int value, int position) {

    int mask = 1<<position;
    unsigned int returnValue = mask & value;    
    return returnValue>>position;
    
}

/** @todo Implement in field.c based on documentation contained in field.h */
int setBit (int value, int position) {
    int mask = 1<<position;
    unsigned int returnValue = mask | value;
    return returnValue;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int clearBit (int value, int position) {
    int mask = ~(1<<position);
    unsigned int returnValue = mask & value;
    return returnValue;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int getField (int value, int hi, int lo, bool isSigned) {
    int maskFinal =  ((1<<hi)-1) << lo;
    
    if (isSigned) {
      int returnValue = maskFinal & value;
      returnValue = returnValue | -(1<<hi);
      return returnValue;
    }
    else {
    unsigned int returnValue = maskFinal & value;
    return returnValue>>lo;
    }
    return 0;
}
