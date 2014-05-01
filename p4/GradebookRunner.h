#ifndef GRADEBOOKRUNNER_H
  #define GRADEBOOKRUNNER_H

enum {ADD_COURSE = 1, ADD_STUDENT, REMOVE_STUDENT, ADD_ASSIGNMENT, ENTER_SCORES,
  UPDATE, LIST_STUDENT, LIST_ASSIGNMENT};

struct Operation
{
  short type;
  int CRN;
  char **SIDs;
  union
  {
    short count;
    short score;
    short maxScore;
  };
  char *title;
  char SID[12];
  short *scores;
}; // struct Operation


#endif
