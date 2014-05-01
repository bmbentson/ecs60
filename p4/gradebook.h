#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include <stdio.h>
#include <string.h>
#include "BinarySearchTree.h"
#include "course.h"
#include "QuadraticProbing.h"

using namespace std;









class GradeBook
{
QuadraticHashTable<Course> list;
public:
  GradeBook(){}
  void addAssignment(int CRN, const char *title, int maxScore);
  void addCourse(int CRN);
  void addStudent(int CRN, const char SID[12]);
  void enterScores(int CRN, const char *title,  short scores[600]);
  void listAssignment(int CRN, const char *title, int *count, short scores[600]);
    // set count and insert scores of the assignment in scores
  void listStudent(int CRN, const char SID[12], int *count, short scores[600]);
    // set count and insert scores of the student in scores
  void removeStudent(int CRN, const char SID[12]);
  void update(int CRN, const char *title, const char SID[12], int score);
}; // class GradeBook



#endif // GRADEBOOK_H
