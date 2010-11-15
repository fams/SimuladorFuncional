/*
 * data.h
 *
 *  Created on: 14/11/2010
 *      Author: Fernando Augusto
 */

#ifndef DATA_H_
#define DATA_H_


#endif /* DATA_H_ */
#define NUMLINES 100
#define MEMSIZE  100

/*
 * Componentes
 */
//Memoria
extern char *memory[MEMSIZE];
//Banco de Registradores
extern int  *regbank[8];
//Program Counter
extern int PC;
//Codigo do programa
extern char *code[NUMLINES];
//Registrador de instrucao
extern char RI[32];
//Registrador
struct RI {
	char *inst;
	int A;
	int B;
	int W;
};
/*
 * ALU
 */
struct ULA {
	int A;
	int B;
	int Saida;
	int OP;
} ;


