/*
 ============================================================================
 Name        : util.c
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

#include "error.h"

int Error(int ERR, char *ARG ){
	switch(ERR){
		case FILE_NOT_FOUND:
		printf("Arquivo %s não encontrado\n",ARG);
		exit(1);
		break;
	};
	return 0;
}

