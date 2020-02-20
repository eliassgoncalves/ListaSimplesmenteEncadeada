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

#include "ListaLigadaTAD.c"

int main ( void ){
	setlocale(LC_ALL, "Portuguese");
	
	/*
	 * Para melhor utilização, add nesse programa um menu para 
	 * informar ao usuário as opções que o programa implementa. 
	 * Desenvolva casos de teste para cada função do programa.
	 */

	// Criar e preencher items a serem inseridos na lista. Dica: Pegue esses dados do usuário.
	DADO *p1, *p2, *p3, *procurar;
	p1 = criar_item(123, "Batata", 2.56);
	p2 = criar_item(456, "Laranja", 5.33);
	p3 = criar_item(789, "Cebola", 0.98);
	
	// Criar a lista
	LISTA *L = criar_lista();

	if( L != NULL )
		printf( "Lista criada com sucesso!\n" );
	else
		printf( "Erro ao criar lista!\n" );

	// Verifica se a lista está vazia
	if( esta_vazia_lista( L ) )
		printf( "Lista vazia!\n" );
	else
		printf( "Lista não vazia!\n" );


	// Imprimir itens da lista
	imprimir_lista( L );


	// Inserir item no final
	if( inserir_item_final( L, p1 ) )
		printf( "Inserido no final!\n" );
	else
		printf( "Erro ao inserir!\n" );

	if( inserir_item_final( L, p2 ) )
		printf( "Inserido no final!\n" );
	else
		printf( "Erro ao inserir!\n" );

	if( inserir_item_final( L, p3 ) )
		printf( "Inserido no final!\n" );
	else
		printf( "Erro ao inserir!\n" );

	if( inserir_item_inicio( L, p3 ) )
		printf( "Inserido no inicio!\n" );
	else
		printf( "Erro ao inserir!\n" );

	procurar = recuperar_item(L, p3->codigo);

	if( inserir_item_inicio( L, procurar ) )
		printf( "Inserido no inicio!\n" );
	else
		printf( "Erro ao inserir!\n" );
	
	// Imprimir itens da lista
	imprimir_lista( L );


	// Destruir a lista
	destruir_lista( L );
	
	return 0;
}