/* CS270 
 *
 * Author: Brock Fisher
 * Date:   6/29/21
 */

#include "struct.h"
#include<stdio.h>
#include <stdlib.h>


/********** FUNCTION DEFINITIONS **********************************************/

void readStudentAndEnroll(Student **slot)
{
  Student **newStudent = (Student**)calloc(1, sizeof(Student));
  int credits = 0;
  char fName[80];
  float qPoints = 0;
  scanf("%s", &fName[0]);
  scanf("%f", &qPoints);
  scanf("%d", &credits);
  (*newStudent)->firstName[0] = fName[0];
  (*newStudent)->qualityPoints = qPoints;
  (*newStudent)->numCredits = credits;
  slot = newStudent;
}

void displayStudent(Student s)
{
  double GPA = s.qualityPoints/s.numCredits;
  printf("%s, %.2f\n", &s.firstName[0], GPA); 
}
