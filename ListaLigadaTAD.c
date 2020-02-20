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

#include "ListaLigadaTAD.h" // Incluir biblioteca ListaLigadaTAD.h

// OPERAÇÕES PARA MANIPULAR A LISTA:

/*
 * Cria e inicializa a lista;
 * L != NULL: Lista criada com sucesso;
 * L == NULL: Erro ao criar lista.
 */
LISTA *criar_lista(){
    LISTA *L = ( LISTA* ) malloc( sizeof( LISTA ) );

    if( L != NULL ){
        *L = NULL; // O conteúdo da lista recebe NULL.
    }

    return L;
}

/*
 * Libera a memória alocada para a lista;
 */
void destruir_lista( LISTA *L ){    
    if( L!= NULL ){
        NO * elemento;

        while( (*L) != NULL ){ // Percorre os nós até liberar todos
            elemento = *L; // Guarda a referência para resgatar o próximo
            *L = (*L)->proximo; // Recebe o próximo nó da lista
            free( elemento );
        }

        free( L );
    }
}

int obter_tamanho_lista(LISTA *L){
    if( L == NULL )
        return 0;
    
    int cont = 0;
    
    NO *elemento = *L;

    while( elemento != NULL ){
        cont++;
        elemento = elemento->proximo;
    }
    return cont;
}

/*
 * Verifica se a lista está vazia;
 * @return 1: vazia;
 * @return 0: não vazia.
 */
int esta_vazia_lista( LISTA * L ){
    if( L == NULL || *L == NULL )
        return 1;
    else
        return 0;
}


DADO *criar_item(int codigo, char descricao[20], float preco){
    DADO *p1 = (DADO*) malloc (sizeof(DADO));
    if(p1 == NULL){
        printf("Erro ao criar item.\n");
        exit(1);   
    }

    p1->codigo = codigo;
    strcpy(p1->descricao, descricao);
    p1->preco = preco; 
    return p1;
}

/*
 * Insere um item no início da lista.
 */
int inserir_item_inicio( LISTA *L, DADO *d ){
    if( L == NULL ) // Se a lista está vazia
        return 0;

    NO *novo = ( NO* ) malloc( sizeof( NO ) ); // Aloca espaço para o nó

    if( novo == NULL )
        return 0;

    novo->dado = d; // Atualiza o início da lista com o nó criado
    novo->proximo = (*L);

    *L = novo;

    return 1;
}


/*
 * Insere um item no fim da lista.
 */
int inserir_item_final( LISTA *L, DADO *d ){
    if( L == NULL ) // Se a lista está vazia
        return 0;

    NO *novo = ( NO* ) malloc( sizeof( NO ) ); // Aloca espaço para o nó

    if( novo == NULL )
        return 0;

    novo->dado = d; // Atualiza o início da lista com o nó criado    
    novo->proximo = NULL;

    if( (*L) == NULL )
        *L = novo;
    else{
        NO *aux = *L;
        while( aux->proximo != NULL )
            aux = aux->proximo;

        aux->proximo = novo;
    }
    return 1;
}


/*
 * Imprime os itens da lista;
 */
void imprimir_lista( LISTA *L ){
    printf( "L -> " ); // Representação gráfica do início da lista

    NO *elemento = *L; // Guarda o nó do início da lista

    while( elemento != NULL ){
        printf( "%d -> ", elemento -> dado -> codigo ); // Imprime o código do elemento
        elemento = ( NO* ) elemento -> proximo; // Atualiza o elemento com o próximo no da lista
    }

    printf( "NULL\n" ); // Representação gráfica do final da lista
}

DADO *recuperar_item( LISTA *L, int codigo){
    NO *elemento = *L; // Guarda o nó do início da lista
    while( elemento != NULL ){
        
        if(elemento->dado->codigo == codigo){
            printf( "Elemento com codigo %d encontrado!\n", codigo);
            return elemento->dado;
        }
        else
            elemento = ( NO* ) elemento -> proximo; // Atualiza o elemento com o próximo no da lista
    }
}