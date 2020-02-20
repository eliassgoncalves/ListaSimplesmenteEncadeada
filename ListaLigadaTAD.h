/*
*
* Computer Science Section
* Faculdades Doctum de Caratinga
* Caratinga, MG, Brazil
* Feb. 20, 2020
* author: Elias Goncalves
* email: falarcomelias@gmail.com
* Licensed under the Apache License, Version 2.0
*
*/

#ifndef _LISTA_LIGADATAD_H_INCLUDED_
#define _LISTA_LIGADATAD_H_INCLUDED_

// Incluindo as principais bibliotecas a serem usadas no projeto
#include<locale.h> // Para configurações de idioma:
#include <stdio.h> // Para scanf, printf, fgets, gets
#include <string.h> // Para strcpy
#include <stdlib.h> // Para exit e malloc


/*
 * Definindo o tipo abstrato a ser armazenado na lista. 
 * A implementação desse tipo definido pelo usuário pode ser feita em arquivo separado ItemTAD.c ou ProdutoTAD.c com sua
 * respectiva biblioteca ItemTAD.h ou ProdutoTAD.h
*/
typedef struct ProdutoTAD{
    int codigo;
    char descricao[20];
    float preco;
} DADO;

// Define a Lista:
typedef struct elemento *LISTA;

// Implementação do nó
struct elemento{
    DADO *dado; // Ponteiro de item do tipo Produto
    struct elemento *proximo; // Ponteiro do tipo elemento que apontará para o próximo elemento da lista
};

// Define o nó da lista
typedef struct elemento NO;

// Protótipos
//void apagar_no( NO* );

LISTA *criar_lista();
void destruir_lista( LISTA* );
int obter_tamanho_lista( LISTA* );
int esta_vazia_lista( LISTA* );
int inserir_item_final( LISTA*, DADO* );
int inserir_item_inicio( LISTA*, DADO* );
void imprimir_lista( LISTA* );
DADO *criar_item(int, char[20], float);
DADO *recuperar_item( LISTA*, int );

#endif // _LISTA_LIGADATAD_H_INCLUDED_
