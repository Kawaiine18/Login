char* allouer(int d)
{
    char* A = NULL;
    A = (char*)malloc(d*sizeof(char));
    if(A == NULL)
    {
        printf("Erreur d'allocation !!");
        exit (1);
    }
    return (A);
}
char* allouer_2(int d)
{
    char* B = NULL;
    B = (char*)malloc(d*sizeof(char));
    if(B == NULL)
    {
        printf("Erreur d'allocation !!");
        exit (1);
    }
    return (B);
}
void getdata(char* nom, char* password)
{
    if(nom != NULL)
    {
        printf("Entrez votre nom:");
        scanf("%s",nom);
    }
    if(password != NULL)
    {
        printf("Entrez votre mot de passe:");
        scanf("%s",password);
    }
}
FILE* ouverture(FILE* file)
{
    FILE* fichier = NULL;
    fichier = fopen("/home/mit/login.txt","a+");
    if(fichier == NULL)
    {
        printf("Erreur de l'ouverture du fichier!");
        exit (1);
    }
    return (fichier);
}
void traitement(FILE* file,char* nom,char* password,int d)
{
    fprintf(file,"%s %s\n",nom,password);
    fclose (file);
}
void comparer(FILE* file,char* nom,char* password,int d)
{
    file = fopen("/home/mit/login.txt","r");
    char chaine[d];
    char phrase[d];
    char pwd[d];
    char name[d];
    do
    {
        fgets(chaine,d,file);
        strcpy(phrase,chaine);
        sscanf(phrase,"%s %s",name,pwd);
        if(strcmp(nom,name)==0)
        {
           printf("deja inscrit\n");
            if(strcmp(password,pwd) == 0)
            {
                printf("bienvenue");
            }
            else if(strcmp(password,pwd) != 0)
            {
                printf("mot de passe incorect");
            }
           break;
        }
        else
        {
            printf("Veulluier vous s'inscrire\n");
            fclose(file);
            ouverture(file);
            getdata(nom,password);
            traitement(file,nom,password,d);
            printf("Vous etes maintenant inscrit\n");
            break;
        }
    }
    while(!feof(file));
}
