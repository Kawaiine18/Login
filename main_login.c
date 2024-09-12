int main()
{
    char* nom = NULL;
    char* password = NULL;
    int d = 255;
    char phrase[d];
    FILE* file = NULL;
    nom = allouer(d);
    password = allouer_2(d);
    getdata(nom,password);
    file = ouverture(file);
    comparer(file,nom,password,d);
    free(nom);
    free(password);
    return 0;
}
