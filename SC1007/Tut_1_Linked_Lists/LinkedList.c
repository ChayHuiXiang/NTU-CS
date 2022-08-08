#include <stdio.h>

int main() {
  struct person {
    char firstName [15];
    char lastName [15];
    struct {
      int age ;
      float height ;
      float weight ;
      char firstName [15];
    } * InfoPtr, Info ;
    struct person *personP ;
  } student1 ;
  typedef struct person person_t ;
  person_t * studentPtr = & student1 ;
  person_t ** studentPtrPtr = & studentPtr ;

  student1.Info.age = 15;

  printf("%d", studentPtr->Info.age);

  printf("%d", ((person_t*)*studentPtrPtr)->Info.age);

  return 0;
}
