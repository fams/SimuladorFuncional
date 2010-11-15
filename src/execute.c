/*
 * execute.c
 *
 *  Created on: 14/11/2010
 *      Author: Fernando Augusto
 */
#include <string.h>

#include "util.h"
#include "data.h"

struct {
	char inst[32];
	int  A;
	int  B;
	int  Ext;
	int  W;
} RI ;
// Debug
int verboseFlag;

//Program Counter
int PC=0;

void IF();
void ID();
void EXEMEM();
void WB();

int Execute(){
	while(1){
		IF();
		ID();
		EXEMEM();
		WB();
	}
	return 0;
}


void IF(){
	strcpy(RI.inst, memory[PC]);
	vp printf("Instrucao Carregada %s\n", RI.inst );
	PC++;
};

void ID(){
	char *tok = strtok(RI.inst," ,()");
	if(!tok)
			return;

};

void EXEMEM(){

};
void WB(){

};
