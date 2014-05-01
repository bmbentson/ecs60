#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Assignment
{
public:
  bool scored;
  char title[25];
  int maxScore;
  short scores[600];
  Assignment() : scored(false)
  {
    for(int i = 0; i < 600; i++)
      scores[i] = 0;
  } // Assignment()

}; // class Assignment

class Course
{
public:
  bool added;
  int assignmentsAdded;
  int assignmentsScored;
  int CRN;
  char SIDs[600][12];
  int numStudents;
  Assignment assignments[25];
  int numAssignments;
  Course(): added(false), assignmentsAdded(0), assignmentsScored(0) {}
}; // class Course

Course* createCourses(int numCourses, int maxStudents)
{
  Course *courses = new Course[numCourses];
  bool OK;
  char SID[12];

  for(int i = 0; i < numCourses; i++)
  {
    do
    {
      courses[i].CRN = rand() % 90000 + 10000;
      OK = true;

      for(int j = 0; j < i; j++)
        if(courses[i].CRN == courses[j].CRN)
        {
          OK = false;
          break;
        } // if duplicated CRN
    } while(!OK);  // while duplicated CRN

    courses[i].numStudents = rand() % (maxStudents - 5) + 5;

    for(int j = 0; j < courses[i].numStudents; j++)
    {
      do
      {
        OK = true;
        sprintf(SID, "%03d-%02d-%04d", rand() % 1000, rand() % 100, rand() % 10000);
        for(int k = 0; k < j; k++)
          if(!strcmp(SID, courses[i].SIDs[k]))
          {
            OK = false;
            break;
          } // if duplicated SID
      } while(!OK);

      strcpy(courses[i].SIDs[j], SID);
    } // for each student
  } // for each course

  return courses;
} // createCourses()

int createAssignments(Course *courses, int numCourses, int maxAssignments)
{
  const char *TITLES[] = {"Program", "Written Homework", "Midterm", "Term Paper", "Extra Credit"};
  int totalAssignments = 0, type, count;
  bool OK;

  for(int i = 0; i < numCourses; i++)
  {
    totalAssignments += courses[i].numAssignments = rand() % (maxAssignments - 1) + 1;

    for(int j = 0; j < courses[i].numAssignments - 1; j++)
    {
      do
      {
        OK = true;
        type = rand() % 5;
        if(type < 2)  // Program or Written Homework
        {
          count = 0;
          for(int k = 0; k < j; k++)
            if(strstr(courses[i].assignments[k].title, TITLES[type]))
              count++;
          sprintf(courses[i].assignments[j].title, "%s #%d", TITLES[type], ++count);
          courses[i].assignments[j].maxScore = rand() % 25 + 25;
        } // if homework type
        else // non-homework type
        {
          strcpy(courses[i].assignments[j].title, TITLES[type]);
          courses[i].assignments[j].maxScore = rand() % 50 + 150;

          if(type == 4) // extra credit
            courses[i].assignments[j].maxScore = 50;

          for(int k = 0; k < j; k++)
            if(!strcmp(courses[i].assignments[k].title, TITLES[type]))
            {
              OK = false;
              break;
            } // if duplicated assignment title
        } // else one time assignment
      } while(!OK);
    } // for each assignment

    strcpy(courses[i].assignments[courses[i].numAssignments - 1].title, "Final");  // Finals always last assignment
    courses[i].assignments[courses[i].numAssignments - 1].maxScore = rand() % 100 + 250;


  } // for each course
 
  return totalAssignments;
} // createAssignments()


void sortSIDs(char SIDs[600][12], int numStudents)
{


}  // sortSIDS

int strCmp(const void *ptr1, const void *ptr2)
{
  return strcmp((const char*) ptr1, (const char*) ptr2);
}

void addCourse(Course *courses, int courseIndex, ofstream &outf)
{
  outf << "1 " << courses[courseIndex].CRN << ' ' << courses[courseIndex].numStudents;

  for(int i = 0; i < courses[courseIndex].numStudents; i++)
    outf << ' ' << courses[courseIndex].SIDs[i];

  outf << endl;
  courses[courseIndex].added = true;
  qsort(courses[courseIndex].SIDs, courses[courseIndex].numStudents, 12, strCmp);
 // sortSIDs(courses[courseIndex].SIDs, [courseIndex].numStudents);
} // addCourse()


void addAssignment(Course *courses, int numCourses, ofstream &outf)
{
  int courseIndex, assignmentIndex;

  do // find a course that needs an assignment added
  {
    courseIndex = rand() % numCourses;
  } while(!courses[courseIndex].added
    || courses[courseIndex].numAssignments == courses[courseIndex].assignmentsAdded);

  assignmentIndex = courses[courseIndex].assignmentsAdded++;
  outf << "4 " << courses[courseIndex].CRN << ' '
    << courses[courseIndex].assignments[assignmentIndex].title << '\t'
    << courses[courseIndex].assignments[assignmentIndex].maxScore << endl;
} // addAssignment()

void scoreAssignment(Course *courses, int numCourses, ofstream &outf)
{
  int courseIndex, assignmentIndex;
  short score;

  do // find a course that needs an assignment added
  {
    courseIndex = rand() % numCourses;
  } while(!courses[courseIndex].added
    || courses[courseIndex].assignmentsScored == courses[courseIndex].assignmentsAdded);

  assignmentIndex = courses[courseIndex].assignmentsScored++;
  outf << "5 " << courses[courseIndex].CRN << ' '
    << courses[courseIndex].assignments[assignmentIndex].title << '\t'
    << courses[courseIndex].numStudents;

  for(int i = 0; i < courses[courseIndex].numStudents; i++)
  {
    score = rand() % (courses[courseIndex].assignments[assignmentIndex].maxScore + 1);
    courses[courseIndex].assignments[assignmentIndex].scores[i] = score;
    outf << ' ' << score;
  } // for each student

  outf << endl;
} // scoreAssignment()


void listAssignment(Course *courses, int numCourses, ofstream &outf)
{
  int courseIndex, assignmentIndex;

  do // find a course that needs an assignment added
  {
    courseIndex = rand() % numCourses;
  } while(courses[courseIndex].assignmentsScored == 0);

  assignmentIndex = rand() % courses[courseIndex].assignmentsScored;
  outf << "8 " << courses[courseIndex].CRN << ' '
    << courses[courseIndex].assignments[assignmentIndex].title << '\t'
    << courses[courseIndex].numStudents;

  for(int i = 0; i < courses[courseIndex].numStudents; i++)
    outf << ' ' << courses[courseIndex].assignments[assignmentIndex].scores[i];

  outf << endl;
} // listAssignment()


void addStudent(Course *courses, int numCourses, ofstream &outf)
{
  int courseIndex, i;
  char SID[12];
  bool OK;

  do // find a course that has been added and is not full
  {
    courseIndex = rand() % numCourses;
  } while(!courses[courseIndex].added || courses[courseIndex].numStudents == 600);

  do
  {
    OK = true;
    sprintf(SID, "%03d-%02d-%04d", rand() % 1000, rand() % 100, rand() % 10000);

    for(int k = 0; k < courses[courseIndex].numStudents; k++)
      if(!strcmp(SID, courses[courseIndex].SIDs[k]))
      {
          OK = false;
          break;
      } // if duplicated SID
  } while(!OK);

  for(i = courses[courseIndex].numStudents - 1;
    i > -1 && strcmp(courses[courseIndex].SIDs[i], SID) > 0; i--)
  {
    strcpy(courses[courseIndex].SIDs[i + 1], courses[courseIndex].SIDs[i]);
    for(int j = 0; j < courses[courseIndex].assignmentsScored; j++)
      courses[courseIndex].assignments[j].scores[i + 1]
        = courses[courseIndex].assignments[j].scores[i];  // shift right
  }  // move assignment scores and SIDs to right to make room for new student

  i++;

  for(int j = 0; j < courses[courseIndex].assignmentsScored; j++)
   courses[courseIndex].assignments[j].scores[i]  = 0;

  strcpy(courses[courseIndex].SIDs[i], SID);
  courses[courseIndex].numStudents++;
  outf << "2 " << courses[courseIndex].CRN << ' ' << SID << endl;
} // addStudent()


void removeStudent(Course *courses, int numCourses, ofstream &outf)
{
  int courseIndex, studentIndex, i, j;

  do // find a course that has been added and does not have below 5 students
  {
    courseIndex = rand() % numCourses;
  } while(!courses[courseIndex].added || courses[courseIndex].numStudents < 3);

  studentIndex = rand() % courses[courseIndex].numStudents;
  outf << "3 " << courses[courseIndex].CRN << ' ' << courses[courseIndex].SIDs[studentIndex] << endl;


  for(j = 0; j < courses[courseIndex].assignmentsScored; j++)
  {
    for(i = studentIndex; i < courses[courseIndex].numStudents - 1; i++)
      courses[courseIndex].assignments[j].scores[i]
        = courses[courseIndex].assignments[j].scores[i + 1];

    courses[courseIndex].assignments[j].scores[i]  = 0; // set last to zero
  }  // move assignment scores to left

  for(i = studentIndex; i < courses[courseIndex].numStudents - 1; i++) // move SIDs to left
    strcpy(courses[courseIndex].SIDs[i], courses[courseIndex].SIDs[i + 1]);

  courses[courseIndex].numStudents--;
} // removeStudent()


void updateStudent(Course *courses, int numCourses, ofstream &outf)
{
  int courseIndex, studentIndex, assignmentIndex, score;

  do // find a course that has an assignment scored
  {
    courseIndex = rand() % numCourses;
  } while(courses[courseIndex].assignmentsScored == 0);

  assignmentIndex = rand() % courses[courseIndex].assignmentsScored;
  score = rand() % (courses[courseIndex].assignments[assignmentIndex].maxScore + 1);
  studentIndex = rand() % courses[courseIndex].numStudents;
  courses[courseIndex].assignments[assignmentIndex].scores[studentIndex] = score;
  outf << "6 " << courses[courseIndex].CRN  << ' '
    << courses[courseIndex].assignments[assignmentIndex].title
    << '\t' << courses[courseIndex].SIDs[studentIndex] << ' ' << score << endl;

} // updateStudentt()


void listStudent(Course *courses, int numCourses, ofstream &outf)
{
  int courseIndex, studentIndex, assignmentIndex;

  do // find a course that has an assignment scored
  {
    courseIndex = rand() % numCourses;
  } while(courses[courseIndex].assignmentsScored == 0);

  studentIndex = rand() % courses[courseIndex].numStudents;
  outf << "7 " << courses[courseIndex].CRN << ' '
    << courses[courseIndex].SIDs[studentIndex] << ' '
    << courses[courseIndex].assignmentsAdded;

  for(assignmentIndex = 0;
    assignmentIndex < courses[courseIndex].assignmentsAdded; assignmentIndex++)
      outf << ' ' << courses[courseIndex].assignments[assignmentIndex].scores[studentIndex];

  outf << endl;

} // listStudentt()


int writeFile1(Course *courses, int numCourses, int maxStudents,
  int numOperations, int *unAddedAssignments,
  ofstream &outf, int *assignmentsScored, int *assignmentsAdded )
{
  int operationCount = 0, maxOperations = numOperations / 10, coursesAdded = 0,
    value, value2;

  *assignmentsAdded = *assignmentsScored = 0;
  outf << numOperations << endl;

  while(maxOperations - operationCount - numCourses + coursesAdded > 0
    && coursesAdded < numCourses)
  {
    value = rand() % 80;

    if(value < 10) // add course
    {
      if(coursesAdded < numCourses)
      {
        do
        {
          value2 = rand() % numCourses;
        } while(courses[value2].added);

        addCourse(courses, value2, outf);
        coursesAdded++;
        operationCount++;
      } // if still coursese to add
    } // add course
    else
      if(value < 20) // add an assignment
      {
        if(*unAddedAssignments > 0 && coursesAdded > 0)
        {
          addAssignment(courses, numCourses, outf);
          --(*unAddedAssignments);
          (*assignmentsAdded)++;
          operationCount++;
        } // if still assignments to add
      } // if add assignment
      else
        if(value < 30) // score assignment
        {
          if(*assignmentsScored < *assignmentsAdded)
          {
            scoreAssignment(courses, numCourses, outf);
            (*assignmentsScored)++;
            operationCount++;
          } // if assignments available to score
        } // if score assignment
        else
          if(value < 40) // list assignment scores
          {
            if(*assignmentsScored > 0)
            {
              listAssignment(courses, numCourses, outf);
              operationCount++;
            } // if assignments available to list
          } // if provide complete list of scores
          else
            if(value < 50) // add student
            {
              if(coursesAdded > 0)
              {
                addStudent(courses, numCourses, outf);
                operationCount++;
              } // if courses added
            } // if add student
            else
              if(value < 60) // remove a student
              {
                if(coursesAdded > 0)
                {
                  removeStudent(courses, numCourses, outf);
                  operationCount++;
                } // if courses added
              } // if remove student
              else
                if(value < 70) // update a student
                {
                  if(*assignmentsScored > 0)
                  {
                    updateStudent(courses, numCourses, outf);
                    operationCount++;
                  } // if assignments scored
                } // if update a student
               else
                  if(value < 80) // list a student
                  {
                    if(*assignmentsScored > 0)
                    {
                      listStudent(courses, numCourses, outf);
                      operationCount++;
                    } // if assignments scored
                  } // if list a student

  }  // while haven't reached halfway and still room to add remaining courses

  for(int i = 0; i < numCourses; i++)  // add remaining unadded courses;
    if(!courses[i].added)
    {
      addCourse(courses, i, outf);
      operationCount++;
    } // if this course not added
  return operationCount;
} // writeFile1()


void writeFile2(Course *courses, int numCourses, int maxStudents,
  int numOperations, int unAddedAssignments, ofstream &outf,
  int assignmentsScored, int assignmentsAdded, int operationCount)
{
  int value;


  while(operationCount < numOperations)
  {

    value = rand() % 70 + 10;

    if(value < 20) // add an assignment
      {
        if(unAddedAssignments > 0)
        {
          addAssignment(courses, numCourses, outf);
          --unAddedAssignments;
          assignmentsAdded++;
          operationCount++;
        } // if still assignments to add
      } // if add assignment
      else
        if(value < 30) // score assignment
        {
          if(assignmentsScored < assignmentsAdded)
          {
            scoreAssignment(courses, numCourses, outf);
            assignmentsScored++;
            operationCount++;
          } // if assignments available to score
        } // if score assignment
        else
          if(value < 40) // list assignment scores
          {
            if(assignmentsScored > 0)
            {
              listAssignment(courses, numCourses, outf);
              operationCount++;
            } // if assignments scored
          } // if provide complete list of scores
          else
            if(value < 50) // add student
            {
                addStudent(courses, numCourses, outf);
                operationCount++;
            } // if add student
            else
              if(value < 60) // remove a student
              {
                  removeStudent(courses, numCourses, outf);
                  operationCount++;
              } // if provide complete list of scores
              else
                if(value < 70) // update a student
                {
                  if(assignmentsScored > 0)
                  {
                    updateStudent(courses, numCourses, outf);
                    operationCount++;
                  } // if assignments scored
                } // if update a student
               else
                  if(value < 80) // list a student
                  {
                    if(assignmentsScored > 0)
                    {
                      listStudent(courses, numCourses, outf);
                      operationCount++;
                    } // if assignments available to list
                  } // if list a student
  }  // while haven't done all operations
} // writeFile2()

int main ()
{
  int numCourses, maxStudents, seed, maxAssignments, numOperations,
    minOperations, unAddedAssignments, operationCount, assignmentsScored,
    assignmentsAdded;
  Course *courses;
  char filename[80];

  cout << "Number of courses (1 - 1000): ";
  cin >> numCourses;
  cout << "Maximum number of students per course (5 - 600): ";
  cin >> maxStudents;
  cout << "Maximum number of assignments per course (1 - 25): ";
  cin >> maxAssignments;
  minOperations = numCourses * maxAssignments * 5;
  cout << "Number of operations ( # > " << minOperations << "): ";
  cin >> numOperations;
  cout << "Seed: ";
  cin >> seed;
  srand(seed);
  courses = createCourses(numCourses, maxStudents);
  unAddedAssignments = createAssignments(courses,
    numCourses, maxAssignments);
  sprintf(filename, "grades-%d-%d-%d-%d-%d.txt", numCourses, maxStudents,
    maxAssignments, numOperations, seed);
  ofstream outf(filename);
  operationCount = writeFile1(courses, numCourses, maxStudents, numOperations,
    &unAddedAssignments, outf, &assignmentsScored, &assignmentsAdded);
  writeFile2(courses, numCourses, maxStudents, numOperations,
    unAddedAssignments, outf, assignmentsScored, assignmentsAdded, operationCount);

  delete [] courses;
  return 0;
} // main()
