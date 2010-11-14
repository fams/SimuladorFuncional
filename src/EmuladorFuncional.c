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


#include "data.h"
#include "execute.h"

// Global Data
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
	return 0;
};

int loadData(char *datafile){
	return 0;
};

int Help(){

	return 0;
}

