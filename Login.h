#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//dimension de tous les tableaux
#define d 255	
//Entrez nom et mot de passe
void getdata_name(char** name);
void getdata_password(char** password);
//ouverture du fichier contenant les noms et mot de passe
FILE* ouverture(FILE* file);
//Ecrire dans le fichier pour s'inscrire
void inscription(char* name,char* password,FILE* file);
//Pour se connecter, s'inscrire si n'a pas de compte
void connecter(char* name,char* password,FILE* file);
//liberer tous les tableaux
void Free_All_Array(char* name,char* password);
//pour s'inscrire ou se connecter
void menu(char* name,char* password,FILE* file);
