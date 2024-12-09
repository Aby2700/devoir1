#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>


extern char  * optarg;
extern int optopt;

int f(int x){
	return pow(2,x);
}

int g(int x){
	return 2*x;
}

int gof(int x){
	int i= f(x);
	return g(i);
}

int fog(int x){
	int i =g(x);
	return f(i);
}

int main (int argc,char* argv[])
{
	int opt,m;
	int n;
	if(argc < 3)
	{
		perror("Erreur : nombre d'arguments insufisants \n");
		return 0;
	}
	if(argc>4){
		perror("Erreur : trop d'arguments \n");
		return 0;
	}
	while((opt = getopt (argc,argv,":f:g:" )) != -1)
	{
		switch(opt)
		{
			case 'f' :
				n=atoi(optarg);
				
				break;
		
			case 'g' :
			        m= atoi (optarg);
				
				break;
			 case ':':
			    	
				if (strcmp(argv[1],"f") == 0 &&  strcmp(argv[3],"f") == 0) 
				{
					printf("Erreur !:l'option ou argument incorrect \n ");
						
				}
				else 
				{
					if (strcmp(argv[1],"f") ==0 && strcmp(argv[3],"g") ==0  )
					{
						printf("Erreur !:l'option ou argument incorrect \n ");
					}
					else 
					{
						if (strcmp(argv[1],"g") == 0 && strcmp(argv[3],"f") ==0  ) 
						{
							printf("Erreur !:l'option ou argument incorrect \n ");		
						
						}
						else 
						{
							if (strcmp(argv[1],"g") == 0 && strcmp(argv[3],"g") ==0  ) 
							{
								printf("Erreur !:l'option ou argument incorrect \n ");	
							}
							else 
							{
								if (strcmp(argv[1],"-g") == 0 && strcmp(argv[3],"f") ==0  ) 
								{
									printf("Erreur !:l'option ou argument incorrect \n ");	
								}
								else 
								{
									if (strcmp(argv[1],"g") == 0 && strcmp(argv[3],"-f") ==0  ) 
									{
										printf("Erreur !:l'option ou argument incorrect \n ");
									}
									else {
										if (strcmp(argv[1],"-f") == 0 && strcmp(argv[3],"-f") ==0  ) 
										{
											printf("Erreur !:l'option ou argument incorrect \n ");
										}
										else {
											if (strcmp(argv[1],"-g") == 0 && strcmp(argv[3],"-g") ==0  ) 
											{
												printf("Erreur !:l'option ou argument incorrect \n ");
											}
										}
									}						
								}
							}				
						}
					}
				}
		
		

			    	break;
			case '?' :
				printf("Ereur : option %c est inconnu\n",optopt);
				break;
					
		}
		
	}

	if (strcmp(argv[1], "-f") ==0) {
		if (argc ==3){
			printf("f(%d) = %d\n",n,(int)f(n));
		}
		else {
			if(strcmp(argv[3], "-g") ==0){
				printf("fog(%d) = %d \n",n,fog(n));
			}
		}
	}
	else{
		if(strcmp(argv[1], "-g") ==0 && argc==3 ) {
			printf("g(%d) = %d \n ",m,g(m));
		}
		else{
			if(strcmp(argv[3], "-f") ==0)
				printf("gof(%d) = %d \n",m,gof(m));	
		}
	}


	return 0;
	
}