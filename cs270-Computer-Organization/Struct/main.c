 /** @mainpage 
   *  \htmlinclude "STRUCTS.html"
   */
/* CS270 
 *
 * Author: Brock Fisher
 * Date:   6/29/21
 */
#include<stdio.h>
#include <stdlib.h>
#include "struct.h"

int main(int argc, const char **argv)
{
  int numberOfStudents;
  scanf("%d", &numberOfStudents);
  ClassRoster *roster = 0;
  roster->numStudents = numberOfStudents;
  roster->students = (Student**)calloc(numberOfStudents, sizeof(Student*));

  for (int i = 0; i < roster->numStudents; i++) {
    readStudentAndEnroll(&(roster->students[i]));
    }

  for (int i = 0; i < roster->numStudents; i++) {
    displayStudent(*roster->students[i]);
    free(roster->students[i]);
    }
  free(roster->students);
   
    return 0;
}
