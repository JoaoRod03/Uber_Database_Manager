/**
 * @file randomfuncs.h
 * 
 * Este ficheiro contém as assinaturas das funções aleatórias que podem ser usadas em vários assuntos.
 * 
 */

#ifndef RANDOM_FUNCS_H
#define RANDOM_FUNCS_H

#include <ctype.h>

/**
 *
 * Este é o header da função que dada uma string, verifica se a string é um dígito, e se for, é porque é driver, caso contrário é user.
 * 
 */
int isDriver(char str[], int N);

/**
 *
 * Este é o header da função que dada uma string de doubles e o tamanho da mesma, calcula o maior valor (a partir do índice 1 apenas).
 * 
 */
int larger_double(double *doubles, int N);

#endif