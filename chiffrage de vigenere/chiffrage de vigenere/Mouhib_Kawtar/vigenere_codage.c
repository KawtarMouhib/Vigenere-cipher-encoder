#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
	FILE *in  = NULL;
	FILE *out = NULL;
    int e;
	int n;
	int j=0;
    n = strlen(argv[2]);
    char c;
    char *str = argv[2];
    int mdp[n];
	in = fopen(argv[1],"r" );
	out= fopen(argv[3],"w");
	
	
	if(in==NULL){
		printf("impossible d ouvrir ce fichier");
		return EXIT_FAILURE;	
	}
	if(out==NULL){
		printf("impossible d ouvrir ce fichier");
		return EXIT_FAILURE;
	}
	   
	for(int i=0;i<n;i++)
        {
           if(str[i]>='a' && str[i]<='z'){

                 mdp[i]=str[i]-'a'+1;
           
            }
            if (str[i]>='A'&& str[i]<='Z'){

                 mdp[i]=str[i]-'A'+1;

            }
    
    }
	e=fscanf(in,"%c",&c);
	while(e!=EOF)
    {
	    printf("%c",c);
	    if((c>='a' && c<='z')||(c>='A' && c<='Z'))
            {
		   	    c=(c-'a'+mdp[j]+26)%26+'a';
		   	    fprintf(out,"%c",c);
        	    j++;
                if(j>= n) j=0;
		    }
		   
	    else{  
                fprintf(out,"%c",c);
 
            }
        e=fscanf(in,"%c",&c);
		   
      }
	
	 fclose(in);
     fclose(out);
return 0;

}
