#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char* string_substring(char str[], int start, int end);

int main(){
	char form[100], *substring;
	int i,ini,pos=0;
    	File *arquivo;
    
    	arquivo = fopen("arquivo.txt", "w");
    
    
    	printf("Insira o conjunto de cláusulas na forma de conjuntos: ");

	gets(form); 
	
	for(i=0;(i+1)<strlen(form);i++){
		ini = i+1;
	
		while(form[i]!='}'){
			i++;
		}
	
		pos= i+1;
	
		substring = string_substring(form,ini,pos); 
	
		//usando fprintf para armazenar a string no arquivo
 	   	fprintf(arquivo, "%s", substring);
 
		
		//printf("A substring: %s\n", substring);
    	}
    
    	
    	//usando fclose para fechar o arquivo
    	fclose(arquivo);

	/*printf("%d",strlen(form));*/

 exit(0);
}

char* string_substring(char str[], int start, int end) {
    int i, j;
    char *sub; 
     
    // Verifica valores incompatíveis e 
    // retorna NULL
    if(start >= end || end > strlen(str)) {
        return NULL;
    }
     
    // Aloca memória para a substring
    sub = (char *) malloc(sizeof(char) * (end - start + 1));
     
    // Copia a substring para a variável
    for(i = start, j = 0; i < end; i++, j++) {
        sub[j] = str[i];
    }
     
     
    return sub;
}