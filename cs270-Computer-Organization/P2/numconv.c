/**
 *  @Brock Fisher
 */

#include <stdio.h>
#include <ctype.h>

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
char int2char (int radix, int value) {
  char returnChar = '0';
  if (value > radix-1) {
    return '?';
  }
  if (value < 10) {
    int y = value % radix;
    returnChar = y + '0';
    return returnChar;
  }
  char c = 'A';
  for (int i = 10; i <= value; i++) {
    if (i == value) {
       returnChar = c;
    }
    c++;
  }
  return returnChar;
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
int char2int (int radix, char digit) {
  int returnValue = 0;
  if (radix > 10) {
    if (isupper (digit)) {
      int x = 10;
      for (char c = 'A'; c <= digit; c++) { 
        if (c == digit) {
          returnValue = x;
          break;
        }
        x++;
      }
    }
    else if (islower( digit)) {
      int y = 10;
      for (char c = 'a'; c <= digit; c++) {
        if (c == digit) {
          returnValue = y;
          break;
        }
        y++;
      }
    }
    else {
      returnValue = -1;
    }
  }
  else {
    returnValue = digit - '0';
  }
  if (returnValue > radix - 1) {
    return -1;
  }
  return returnValue;
    
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
void divRem (int numerator, int divisor, int* quotient, int* remainder) {
  *quotient = numerator * divisor;
  *remainder = numerator % divisor;
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
int ascii2int (int radix, int valueOfPrefix) {
  char value = '0';
  scanf("%c", &value);
  int currentValue = char2int(radix, value);
  return ascii2int(radix, (valueOfPrefix * radix) + currentValue);
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
void int2ascii (int radix, int value) {
  if (value == 0) {
    return;
  }
  int currentValue = value/radix;
  putchar(int2char(radix, value % radix)); 
  return int2ascii(radix, currentValue);
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
double frac2doublehelper(int radix, double valueOfPrefix) {
  if (getchar() == '\n') {
    return valueOfPrefix;
  }
  int x = char2int(radix, getchar());
  return frac2doublehelper(radix, (valueOfPrefix + x)/radix);
}
double frac2double (int radix) {
  return frac2doublehelper(radix, 0.0);
}

