#include <iostream>
#include <fstream>
#include <cstring>

#include "CPUTimer.h"
#include "GradebookRunner.h"
#include "gradebook.h"

using namespace std;

Operation* readFile(const char *filename, int *operationCount)
{
  char SID[12];
  ifstream inf(filename);

  inf >> *operationCount;
  if(!inf)
    cout << "Unable to open " << filename << endl;

  Operation *operations = new Operation[*operationCount];
  for(int i = 0; i < *operationCount; i++)
  {
    inf >> operations[i].type >> operations[i].CRN;

    switch(operations[i].type)
    {
      case ADD_COURSE:
        inf >> operations[i].count;
        operations[i].SIDs = new char*[operations[i].count];

        for(int j = 0; j < operations[i].count; j++)
        {
          operations[i].SIDs[j] = new char[12];
          inf >> operations[i].SIDs[j];
          strcpy(SID, operations[i].SIDs[j]);
        }  // for each student SID
        break;
      case LIST_STUDENT:
        inf >> operations[i].SID;
        inf >> operations[i].count;
        inf.ignore(1);
        operations[i].scores = new short[operations[i].count];

        for(int j = 0; j < operations[i].count; j++)
          inf >> operations[i].scores[j];
        break;
      case ADD_STUDENT:
      case REMOVE_STUDENT:
        inf >> operations[i].SID;
        break;
      case ADD_ASSIGNMENT:
        operations[i].title = new char[25];
        inf.ignore(1);
        inf.getline(operations[i].title, 25, '\t');
        inf >> operations[i].maxScore;
        break;
      case ENTER_SCORES :
        operations[i].title = new char[25];
        inf.ignore(1);
        inf.getline(operations[i].title, 25, '\t');
        inf >> operations[i].count;
        inf.ignore(1);
        operations[i].scores = new short[operations[i].count];
       // operations[i].SIDs = new char*[operations[i].count];

        for(int j = 0; j < operations[i].count; j++)
        {
       //   operations[i].SIDs[j] = new char[12];
          inf >> operations[i].scores[j];
        } // for each student with a score for this assignment

        break;
      case UPDATE :
        operations[i].title = new char[25];
        inf.ignore(1);
        inf.getline(operations[i].title, 25, '\t');
        inf >> operations[i].SID;
        inf >> operations[i].score;
        break;
      case LIST_ASSIGNMENT :
        operations[i].title = new char[25];
        inf.ignore(1);
        inf.getline(operations[i].title, 25, '\t');
        inf >> operations[i].count;
        inf.ignore(1);
        operations[i].scores = new short[operations[i].count];

        for(int j = 0; j < operations[i].count; j++)
          inf >> operations[i].scores[j];
        break;
    }  // switch
  }  // for each operation

  inf.close();
  return operations;
} // readFile()


void runTests(GradeBook *gradeBook, const Operation *operations, int
  operationCount)
{
  int count;
  short scores[600];

  for(int i = 0; i < operationCount; i++)
  {
    switch(operations[i].type)
    {
      case LIST_STUDENT :
        gradeBook->listStudent(operations[i].CRN, operations[i].SID, &count,
          scores);
        if(count != operations[i].count)
          cout << "Invalid listStudent count at operation #" << i << endl;
        else
        {
          for(int j = 0; j < count; j++)
            if(operations[i].scores[j] != scores[j])
            {
              cout << "Incorrect score in listStudent at operation #" << i
                << " index#" << j << ' ' << scores[j] << ' ' << operations[i].scores[j] <<  endl;
              break;
            }
               
        } // else correct count
        break;
      case ADD_STUDENT :
        gradeBook->addStudent(operations[i].CRN, operations[i].SID);
        break;
      case REMOVE_STUDENT :
        gradeBook->removeStudent(operations[i].CRN, operations[i].SID);
        break;
      case UPDATE:
        gradeBook->update(operations[i].CRN, operations[i].title, operations[i].SID,
          operations[i].score);
        break;
      case LIST_ASSIGNMENT :
        gradeBook->listAssignment(operations[i].CRN, operations[i].title,
          &count, scores);
        if(count != operations[i].count)
          cout << "Invalid listAssignment count at operation #" << i << endl;
        else
        {
          for(int j = 0; j < count; j++)
            if(operations[i].scores[j] != scores[j])
            {
              cout << "Incorrect score in listAssignment at operation #" << i
                << " index#" << j << ' ' << scores[j] << ' ' << operations[i].scores[j] << endl;
              break;
            }
        } // else correct count
        break;
      case ENTER_SCORES :
        gradeBook->enterScores(operations[i].CRN, operations[i].title,
          operations[i].scores);
        break;
      case ADD_ASSIGNMENT :
        gradeBook->addAssignment(operations[i].CRN, operations[i].title,
          operations[i].maxScore);
        break;
      case ADD_COURSE :
        gradeBook->addCourse(operations[i].CRN);

        for (int j = 0; j < operations[i].count ; j++ )
        	gradeBook->addStudent(operations[i].CRN, operations[i].SIDs[j]);
        break;
    } // switch
  } // for i
} // runTests()


int main(int argc, char **argv)
{
  int operationCount, count;
  short scores[600];
  const Operation *operations;
  operations = readFile(argv[1], &operationCount);
  CPUTimer ct;
  ct.reset();
  GradeBook *gradeBook = new GradeBook();

  if(argv[2][0] != '0')
    runTests(gradeBook, operations, operationCount);
  else
  {
    for(int i = 0; i < operationCount; i++)
    {
      switch(operations[i].type)
      {
        case LIST_STUDENT :
          gradeBook->listStudent(operations[i].CRN, operations[i].SID, &count,
            scores);
          break;
        case ADD_STUDENT :
          gradeBook->addStudent(operations[i].CRN, operations[i].SID);
          break;
        case REMOVE_STUDENT :
          gradeBook->removeStudent(operations[i].CRN, operations[i].SID);
          break;
        case UPDATE:
          gradeBook->update(operations[i].CRN, operations[i].title, operations[i].SID,
            operations[i].score);
          break;
        case LIST_ASSIGNMENT :
          gradeBook->listAssignment(operations[i].CRN, operations[i].title,
            &count, scores);
          break;
        case ENTER_SCORES :
          gradeBook->enterScores(operations[i].CRN, operations[i].title,
            operations[i].scores);
          break;
        case ADD_ASSIGNMENT :
          gradeBook->addAssignment(operations[i].CRN, operations[i].title,
            operations[i].maxScore);
          break;
        case ADD_COURSE :
          gradeBook->addCourse(operations[i].CRN);
          for (int j = 0; j < operations[i].count ; j++ )
          	gradeBook->addStudent(operations[i].CRN, operations[i].SIDs[j]);
          break;
      } // switch
    } // for i
  } // else no tests

  cout << "CPU Time: " << ct.cur_CPUTime() << endl;
  return 0;
} // main()
