#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[50], int studentAge);
void copyStr(char *source, char *target);
struct student * append(struct student * end, struct student * newStudptr);
void printStudents(struct student *start);
void freeStudents(struct student *start);


int main(void) {
    struct student *start, *newStudptr, *end, *tmp;
    int ageP, ageR, ageM;
    printf("Please enter the ages\n");
    scanf("%d %d %d", &ageP, &ageR, &ageM);

    start = createStudent("Amy", ageP);
    end = start;

    newStudptr = createStudent("Gabriel", ageR);
    end = append(end, newStudptr);

    newStudptr = createStudent("Tom", ageM);
    end = append(end, newStudptr);

    printStudents(start);
    freeStudents(start);

    return 0;
}

struct student *createStudent(char studentName[], int studentAge) {
    struct student *ptr;
    ptr = (struct student *) malloc(sizeof(struct student));
    copyStr(studentName, ptr->name);
    ptr->age = studentAge;
    ptr->next = NULL;
    return ptr;
}
//for assigning the name
void copyStr(char *source, char *target) {
    int i = 0;
    while (source[i]!='\0') {
        target[i] = source[i];
        i++;
    }
    target[i] = '\0';
}
// assigning the new element to end
struct student *append(struct student * end, struct student * newStudptr){
    end->next = newStudptr;
    end =  newStudptr;
    return(end);
}
//printing out function
void printStudents(struct student *start){
    struct student *ptr = start;
    while(ptr!=NULL){
        printf("%s is %d years old.\n",ptr->name,ptr->age);
        ptr = ptr->next;
    }
}
//free the space
void freeStudents(struct student *start){
    struct student * ptr = start;
    struct student * tmp;
    while(ptr!=NULL){
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}
