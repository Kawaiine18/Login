void getdata_name(char** name)
{
	*name = (char*)malloc(d*sizeof(char)),
	printf("entrez votre nom: ");
	scanf("%s",*name);
} 
void getdata_password(char** password)
{
	*password = (char*)malloc(d*sizeof(char));
	printf("Entrez votre mot de passe: ");
	scanf("%s",*password);
}
FILE* ouverture(FILE* file)
{
	FILE* fichier = NULL;
	fichier = fopen("login","a+");	
	if(fichier == NULL)
	{
		printf("Erreur lors de l'ouverture du fichier\n");
		exit(1);
	}
	return (fichier);
}
void inscription(char* name,char* password,FILE* file)
{
	ouverture(file);
	fprintf(file, "%s %s\n", name, password);
	fclose(file);
	printf("vous etes maintenant inscrit\n");
}
void connecter(char* name,char* password,FILE* file)
{
	char* chaine = (char*)malloc(d*sizeof(char));
	char* phrase = (char*)malloc(d*sizeof(char));
	char* nom = (char*)malloc(d*sizeof(char));
	char* pwd = (char*)malloc(d*sizeof(char));
	int choix;
	file = fopen("login","r");
	do
	{
		fgets(chaine,d,file);
		strcpy(phrase,chaine);
		sscanf(phrase,"%s %s",nom,pwd);
		if(strcmp(name,nom) == 0)
		{
			while(1)
			{														
				if(strcmp(password,pwd) != 0)
				{	
				printf("mot de passe incorecte!!,Veuillez ressaiez\n");	 							
				getdata_password(&password);
				}
				else
				{
					printf("bienvenu\n");
				break;
				}
			}
			break;
		}
		else 
		{
		printf("Vous n'avez pas encore de compte, Veuillez vous s'incrire\n");				printf("Vous voulez s'inscrire ?: \n\tsi oui entrez 0\n\tsi vous vous vouliez revenir sur le menu entrez 1\n\tPour quitter taper n'importe quel nombre: ");
		if(scanf("%d",&choix) !=1)
		{
			printf("Veuillez entrez un nombre!\n");
		}
		switch(choix)
		{
			case 0:
				getdata_name(&name);
				getdata_password(&password);
				file = ouverture(file);
				inscription(name,password,file);
			break;
			case 1:
				menu(nom,password,file);
			default:
				exit(0);
		}
		break;
		}
	}
	while(!feof(file));
	free(chaine);
	free(phrase);
	free(nom);
	free(pwd);
	fclose(file);
}
void Free_All_Array(char* name,char* password)
{
	free(name);
	free(password);	
}		
void menu(char* name,char* password,FILE* file)
{
	int choix;
	int result;
	int input;
	while(1)
	{
		printf("Entrez:\n\t0 pour s'incrire\n\t1 pour connecter\n\tn'importe quel nombre pour quitter: ");
		result = scanf("%d",&choix);
		if(result != 1)	
		{
			while((input=getchar()) != '\n' && input != EOF);
			printf("veuillez entrez un nombre!\n");
		}
		else
		{
			break;
		}
	}
	switch(choix)
	{
		case 0:
			getdata_name(&name);
			getdata_password(&password);
			file = ouverture(file);
			inscription(name,password,file);
			break;
		case 1:
			getdata_name(&name);
			getdata_password(&password);
			connecter(name,password,file);
			break;	
		default:
			exit(0);
			break;
		}	
	Free_All_Array(name,password);
}
