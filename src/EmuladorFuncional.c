/*
 ============================================================================
 Name        : EmuladorFuncional.c
 Author      : Fernando Augusto Medeiros Silva
 Version     :
 Copyright   : GNU GPL
 Description : MIPS Emulador Funcional
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define vp if(verboseFlag)

#include "data.h"
#include "execute.h"

// Global Data
char *memory[MEMSIZE];
char *code[NUMLINES];
// Global Flags
int verboseFlag = 0;
int memLinhas   = 0;

/*
 * Prototype
 */
int loadCode(char *codeFile);
int loadData(char *dataFile);
int Help();


int main(int argc,char **argv) {
	/*
	 * Local Vars
	 */
	char datafile[254], codefile[254];
	int c;

	/* Opts
	 * -h Help
	 * -d dados
	 * -c programa
	 * -v verboso
	 * -m imprime n linhas de memoria
	 */
	while ((c = getopt (argc, argv, "hvm:d:c:")) != -1)
	         switch (c)
	           {
	           case 'h':
	               Help();
	               return 0;
	               break;
	           case 'v':
	               verboseFlag = 1;
	               break;
	           case 'm':
	               memLinhas = atoi(optarg);
	               break;
	           case 'd':
	        	   strcpy(datafile,optarg);
	        	   break;
	           case 'c':
	        	   strcpy(codefile,optarg);
	        	   break;
	           case '?':
	                      if (optopt == 'c')
	                        fprintf (stderr, "Opcao -%c requer nome do arquivo de programa.\n", optopt);
	                      else if (optopt == 'd')
	                        fprintf (stderr, "Opcao -%c requer nome do arquivo de dados.\n", optopt);
	                      else if (isprint (optopt))
	                        fprintf (stderr, "Opcao desconhecida `-%c'.\n", optopt);
	                      else
	                        fprintf (stderr,
	                                 "Unknown option character `\\x%x'.\n",
	                                 optopt);
	                      return 1;
	           default:
	             abort ();
	           }

	loadCode(codefile);
	loadData(datafile);
	Execute();
	puts("Finish"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

int loadCode(char *codefile){
	FILE *fp;
	char buf[21];
	int line=0;
	fp = fopen(codefile,"r");
	while (fgets(buf, 31, fp) != NULL)
	{
		code[line]=malloc(32*sizeof(char));
	    strcpy(code[line], buf);
	    code[line][sizeof(buf)]=0;
	    vp 	printf("Lendo %s \n", code[line]);
	    line++;
	}
	fclose(fp);
	return 0;
};

int loadData(char *datafile){
	FILE *fp;
		char buf[4];
		int line=0;
		int data=0;
		fp = fopen(datafile,"r");
		int *memint;
		memint = (int *) memory;
		while (fgets(buf, 4, fp) != NULL)
		{
		    data = (int)strtol(buf,NULL,16);
		    memint[line] = data;
		    printf("Lendo %i \n", data);
		    line++;
		}
		fclose(fp);
		return 0;
	return 0;
};

int Help(){
	printf(" Uso:\n"
			" -h Help\n"
			" -d dados\n"
			" -c programa\n"
			" -v verboso\n"
			" -m imprime n linhas de memoria\n");
	return 0;
}

