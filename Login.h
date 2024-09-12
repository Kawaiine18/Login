#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* allouer(int d);
char* allouer_2(int d);
void getdata(char* nom,char* password);
FILE* ouverture(FILE* file);
void traitement(FILE* file,char* nom,char* password,int d);
void comparer(FILE* file,char* nom,char* password,int d);
