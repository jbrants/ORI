/* ==========================================================================
 * Universidade Federal de São Carlos - Campus Sorocaba
 * Disciplina: Organização de Recuperação da Informação
 * Prof. Tiago A. Almeida
 *
 * Trabalho 01 - Indexação
 *
 * ========================================================================== *
 *   <<< IMPLEMENTE AQUI!!! COPIE E COLE O CONTEÚDO DESTE ARQUIVO NO AVA >>>
 * ========================================================================== */

/* Bibliotecas */
#include "ORI_T01_HEADER.h"

/* ===========================================================================
 * ================================= FUNÇÕES ================================= */


/* <<< COLOQUE AQUI OS DEMAIS PROTÓTIPOS DE FUNÇÕES, SE NECESSÁRIO >>> */


/* Funções auxiliares para o qsort.
 * Com uma pequena alteração, é possível utilizá-las no bsearch, assim, evitando código duplicado.
 * */

/* Função de comparação entre chaves do índice corredores_idx */
int qsort_corredores_idx(const void *a, const void *b) {
    return strcmp( ( (corredores_index *)a )->id_corredor, ( (corredores_index *)b )->id_corredor);
}

/* Função de comparação entre chaves do índice veiculos_idx */
int qsort_veiculos_idx(const void *a, const void *b) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  return strcmp( ( (veiculos_index *)a )->id_veiculo, ( (veiculos_index *)b )->id_veiculo);
}

/* Função de comparação entre chaves do índice pistas_idx */
int qsort_pistas_idx(const void *a, const void *b) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  return strcmp( ( (pistas_index *)a )->id_pista, ( (pistas_index *)b )->id_pista);
}

/* Função de comparação entre chaves do índice corridas_idx */
int qsort_corridas_idx(const void *a, const void *b) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  return strcmp( ( (corridas_index *)a )->id_pista, ( (corridas_index *)b )->id_pista) && strcmp( ( (corridas_index *)a )->ocorrencia, ( (corridas_index *)b )->ocorrencia);
}

/* Funções de comparação apenas entre data de ocorrencia do índice corridas_idx */
int qsort_data_idx(const void *a, const void *b){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  return strcmp( ( (corridas_index *)a )->ocorrencia, ( (corridas_index *)b )->ocorrencia);
}

/* Função de comparação entre chaves do índice nome_pista_idx */
int qsort_nome_pista_idx(const void *a, const void *b){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  return strcmp( ( (nome_pista_index *)a )->nome, ( (nome_pista_index *)b )->nome);
}

/* Função de comparação entre chaves do índice preco_veiculo_idx */
int qsort_preco_veiculo_idx(const void *a, const void *b){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	return ((preco_veiculo_index *)a)->preco - ((preco_veiculo_index *)b) ->preco;
}

/* Função de comparação entre chaves do índice secundário de corredor_veiculos_secundario_idx */
int qsort_corredor_veiculos_secundario_idx(const void *a, const void *b){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  return strcmp( ( (corredor_veiculos_secundario_index *)a )->chave_secundaria, ( (corredor_veiculos_secundario_index *)b )->chave_secundaria);
}

/* Cria o índice respectivo */
void criar_corredores_idx() {
    int a = 0;
    if (!corredores_idx) {
        corredores_idx = malloc(MAX_REGISTROS * sizeof(corredores_index));
        a++;
    }
 
    if (!corredores_idx) {
        printf(ERRO_MEMORIA_INSUFICIENTE);
        exit(1);
    }
 
    for (unsigned i = 0; i < qtd_registros_corredores; ++i) {
        Corredor c = recuperar_registro_corredor(i);
 
        if (strncmp(c.id_corredor, "*|", 2) == 0)
            corredores_idx[i].rrn = -1; // registro excluído
        else
            corredores_idx[i].rrn = i;
 
        strcpy(corredores_idx[i].id_corredor, c.id_corredor);
    }
 
    qsort(corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);
    if (a) printf(INDICE_CRIADO, "corredores_idx");
}

void criar_veiculos_idx() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  int a = 0;
  if (!veiculos_idx){
    veiculos_idx = malloc(MAX_REGISTROS * sizeof(veiculos_index));
    a++;
  }

  if (!veiculos_idx) {
    printf(ERRO_MEMORIA_INSUFICIENTE);
    exit(1);
  }

  for (unsigned i = 0; i < qtd_registros_veiculos; ++i) {
    Veiculo v = recuperar_registro_veiculo(i);

    if (strncmp(v.id_veiculo, "*|", 2) == 0)
        veiculos_idx[i].rrn = -1; // registro excluído
    else
        veiculos_idx[i].rrn = i;

    strcpy(veiculos_idx[i].id_veiculo, v.id_veiculo);
  }

  qsort(veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx);
  if (a) printf(INDICE_CRIADO, "veiculos_idx");
}

void criar_pistas_idx() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  int a = 0;
  if (!pistas_idx){
    pistas_idx = malloc(MAX_REGISTROS * sizeof(pistas_index));
    a++;
  }

  if (!pistas_idx) {
    printf(ERRO_MEMORIA_INSUFICIENTE);
    exit(1);
  }

  for (unsigned i = 0; i < qtd_registros_pistas; ++i) {
    Pista p = recuperar_registro_pista(i);

    if (strncmp(p.id_pista, "*|", 2) == 0)
        pistas_idx[i].rrn = -1; // registro excluído
    else
        pistas_idx[i].rrn = i;

    strcpy(pistas_idx[i].id_pista, p.id_pista);
  }

  qsort(pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx);
  if (a) printf(INDICE_CRIADO, "pistas_idx");
}

void criar_corridas_idx() {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
  int a = 0;
  if (!corridas_idx){
    corridas_idx = malloc(MAX_REGISTROS * sizeof(corridas_index));
    a++;
  }

  if (!corridas_idx) {
    printf(ERRO_MEMORIA_INSUFICIENTE);
    exit(1);
  }

  for (unsigned i = 0; i < qtd_registros_corridas; ++i) {
    Corrida c = recuperar_registro_corrida(i);

    if (strncmp(c.id_pista, "*|", 2) == 0)//
        corridas_idx[i].rrn = -1; // registro excluído
    else
        corridas_idx[i].rrn = i;

    strcpy(corridas_idx[i].ocorrencia, c.ocorrencia);//
  }

  qsort(corridas_idx, qtd_registros_corridas, sizeof(corridas_index), qsort_corridas_idx);
  if (a) printf(INDICE_CRIADO, "corridas_idx");
}

void criar_nome_pista_idx() {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
  int a = 0;
  if (!nome_pista_idx){
    nome_pista_idx = malloc(MAX_REGISTROS * sizeof(nome_pista_index));
    a++;
  }

  if (!nome_pista_idx) {
    printf(ERRO_MEMORIA_INSUFICIENTE);
    exit(1);
  }

  for (unsigned i = 0; i < qtd_registros_pistas; ++i) {
    Pista p = recuperar_registro_pista(i);

    if (strncmp(p.id_pista, "*|", 2) == 0)//
      strcpy(nome_pista_idx[i].id_pista, ""); // registro excluído
    else
        strcpy(nome_pista_idx[i].id_pista, p.id_pista);

    strcpy(nome_pista_idx[i].nome, p.nome);//
  }

  qsort(nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx);
  if (a) printf(INDICE_CRIADO, "nome_pista_idx");
}

void criar_preco_veiculo_idx() {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
  int a = 0;
  if (!preco_veiculo_idx){
    preco_veiculo_idx = malloc(MAX_REGISTROS * sizeof(preco_veiculo_index));
    a++;
  }

  if (!preco_veiculo_idx) {
    printf(ERRO_MEMORIA_INSUFICIENTE);
    exit(1);
  }

  for (unsigned i = 0; i < qtd_registros_veiculos; ++i) {
    Veiculo v = recuperar_registro_veiculo(i);

    if (strncmp(v.id_veiculo, "*|", 2) == 0)//
      strcpy(preco_veiculo_idx[i].id_veiculo, ""); // registro excluído
    else
      strcpy(preco_veiculo_idx[i].id_veiculo, v.id_veiculo);

    preco_veiculo_idx[i].preco = v.preco;//
  }

  qsort(preco_veiculo_idx, qtd_registros_veiculos, sizeof(preco_veiculo_index), qsort_preco_veiculo_idx);
  if (a) printf(INDICE_CRIADO, "preco_veiculo_idx");
}

void criar_corredor_veiculos_idx() {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
  int a = 0;
  corredor_veiculos_idx.compar = qsort_corredor_veiculos_secundario_idx;
	if (!corredor_veiculos_idx.corredor_veiculos_secundario_idx){
    	corredor_veiculos_idx.corredor_veiculos_secundario_idx = malloc(MAX_REGISTROS * sizeof(corredor_veiculos_secundario_index));
    a++;
  }

  if (!corredor_veiculos_idx.corredor_veiculos_secundario_idx) {
    printf(ERRO_MEMORIA_INSUFICIENTE);
    exit(1);
  }

  if (!corredor_veiculos_idx.corredor_veiculos_primario_idx)
    corredor_veiculos_idx.corredor_veiculos_primario_idx = malloc(MAX_REGISTROS * sizeof(corredor_veiculos_primario_index));

  if (!corredor_veiculos_idx.corredor_veiculos_primario_idx) {
    printf(ERRO_MEMORIA_INSUFICIENTE);
    exit(1);
  }

  for (unsigned i = 0; i < qtd_registros_veiculos; ++i) {
    Veiculo v = recuperar_registro_veiculo(i);

    if (strncmp(v.id_veiculo, "*|", 2) == 0)//
      continue;
    else {
      for (unsigned j = 0; j < qtd_registros_corredores; ++j) {
        Corredor c = recuperar_registro_corredor(j);
        if (strncmp(c.id_corredor, "*|", 2) == 0)
          continue;
        if (strcmp(c.veiculos[0], v.modelo) == 0 || strcmp(c.veiculos[1], v.modelo) == 0 || strcmp(c.veiculos[2], v.modelo) == 0) {
            inverted_list_insert(v.modelo, c.id_corredor, &corredor_veiculos_idx);
        }
      }
    }
  }
  qsort(corredor_veiculos_idx.corredor_veiculos_secundario_idx, corredor_veiculos_idx.qtd_registros_secundario, sizeof(corredor_veiculos_secundario_index), corredor_veiculos_idx.compar);
  if (a) printf(INDICE_CRIADO, "corredor_veiculos_idx");
}

/* Exibe um registro com base no RRN */
bool exibir_corredor(int rrn) {
    if (rrn < 0)
        return false;
 
    Corredor c = recuperar_registro_corredor(rrn);
 
    printf("%s, %s, %s, %s, %.2lf\n", c.id_corredor, c.nome, c.apelido, c.cadastro, c.saldo);
    return true;
}

bool exibir_veiculo(int rrn) {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
  if (rrn < 0)
    return false;

  Veiculo v = recuperar_registro_veiculo(rrn);

  printf("%s, %s, %s, %s, %d, %d, %d, %.2lf\n", v.id_veiculo, v.marca, v.modelo, v.poder, v.velocidade, v.aceleracao, v.peso, v.preco);
  return true;
}

bool exibir_pista(int rrn) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  if (rrn < 0)
    return false;

  Pista p = recuperar_registro_pista(rrn);

  printf("%s, %s, %d, %d, %d\n", p.id_pista, p.nome, p.dificuldade, p.distancia, p.recorde);
  return true;
}

bool exibir_corrida(int rrn) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  if (rrn < 0)
    return false;

  Corrida c = recuperar_registro_corrida(rrn);

  printf("%s, %s, %s, %s\n", c.id_pista, c.ocorrencia, c.id_corredores, c.id_veiculos);
  return true;
}

/* Recupera do arquivo o registro com o RRN informado
 * e retorna os dados nas structs corredor, Curso e Inscricao */
Corredor recuperar_registro_corredor(int rrn) {
	Corredor c;
	char temp[TAM_REGISTRO_CORREDOR + 1], *p;
	strncpy(temp, ARQUIVO_CORREDORES + (rrn * TAM_REGISTRO_CORREDOR), TAM_REGISTRO_CORREDOR);
	temp[TAM_REGISTRO_CORREDOR] = '\0';

	p = strtok(temp, ";");
	strcpy(c.id_corredor, p);
	p = strtok(NULL, ";");
	strcpy(c.nome, p);
	p = strtok(NULL, ";");
	strcpy(c.apelido, p);
	p = strtok(NULL, ";");
	strcpy(c.cadastro, p);
	p = strtok(NULL, ";");
	c.saldo = atof(p);
	p = strtok(NULL, ";");

	for(int i = 0; i < QTD_MAX_VEICULO; ++i)
		c.veiculos[i][0] = '\0';

	if(p[0] != '#') {
		p = strtok(p, "|");

		for(int pos = 0; p; p = strtok(NULL, "|"), ++pos)
			strcpy(c.veiculos[pos], p);
	}

	return c;
}

Veiculo recuperar_registro_veiculo(int rrn) {
	Veiculo v;
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	char temp[TAM_REGISTRO_VEICULO + 1], *p;
  strncpy(temp, ARQUIVO_VEICULOS + (rrn * TAM_REGISTRO_VEICULO), TAM_REGISTRO_VEICULO);
	temp[TAM_REGISTRO_VEICULO] = '\0';

  p = strtok(temp, ";");
	strcpy(v.id_veiculo, p);
  p = strtok(NULL, ";");
  strcpy(v.marca, p);
  p = strtok(NULL, ";");
  strcpy(v.modelo, p);
  p = strtok(NULL, ";");
  strcpy(v.poder, p);
  p = strtok(NULL, ";");
  v.velocidade = atoi(p);
  p = strtok(NULL, ";");
  v.aceleracao = atoi(p);
  p = strtok(NULL, ";");
  v.peso = atoi(p);
  p = strtok(NULL, ";");
  v.preco = atof(p);
  
	return v;
}

Pista recuperar_registro_pista(int rrn) {
	Pista p;
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	char temp[TAM_REGISTRO_PISTA + 1], *po;
  strncpy(temp, ARQUIVO_PISTAS + (rrn * TAM_REGISTRO_PISTA), TAM_REGISTRO_PISTA);
  temp[TAM_REGISTRO_PISTA] = '\0';

  po = strtok(temp, ";");
  strcpy(p.id_pista, po);
  po = strtok(NULL, ";");
  strcpy(p.nome, po);
  po = strtok(NULL, ";");
  p.dificuldade = atoi(po);
  po = strtok(NULL, ";");
  p.distancia = atoi(po);
  po = strtok(NULL, ";");
  p.recorde = atoi(po);

	return p;
}

Corrida recuperar_registro_corrida(int rrn) {
	Corrida c;

	/*IMPLEMENTE A FUNÇÃO AQUI*/
	char temp[TAM_REGISTRO_CORRIDA + 1];
  strncpy(temp, ARQUIVO_CORRIDAS + (rrn * TAM_REGISTRO_CORRIDA), TAM_REGISTRO_CORRIDA);
  temp[TAM_REGISTRO_CORRIDA] = '\0';

  
  strncpy(c.id_pista, temp, TAM_ID_PISTA);
  strncpy(c.ocorrencia, temp + TAM_ID_PISTA, TAM_DATETIME);
  strncpy(c.id_corredores, temp + TAM_ID_PISTA + TAM_DATETIME, TAM_ID_CORREDORES);
  strncpy(c.id_veiculos, temp + TAM_ID_PISTA + TAM_DATETIME + TAM_ID_CORREDORES, TAM_ID_VEICULOS);

	return c;
}

/* Escreve em seu respectivo arquivo na posição informada (RRN) */
void escrever_registro_corredor(Corredor c, int rrn) {
	char temp[TAM_REGISTRO_CORREDOR + 1], p[100];
	temp[0] = '\0'; p[0] = '\0';

	strcpy(temp, c.id_corredor);
	strcat(temp, ";");
	strcat(temp, c.nome);
	strcat(temp, ";");
	strcat(temp, c.apelido);
	strcat(temp, ";");
	strcat(temp, c.cadastro);
	strcat(temp, ";");
	sprintf(p, "%013.2lf", c.saldo);
	strcat(temp, p);
	strcat(temp, ";");

	for(int i = 0, k = 0; i < QTD_MAX_VEICULO; ++i) {
		if(strlen(c.veiculos[i]) > 0) {
			if (k == 0)
				k = 1;
			else
				strcat(temp, "|");
			strcat(temp, c.veiculos[i]);
		}
	}
	strcat(temp, ";");

	strpadright(temp, '#', TAM_REGISTRO_CORREDOR);

	strncpy(ARQUIVO_CORREDORES + rrn*TAM_REGISTRO_CORREDOR, temp, TAM_REGISTRO_CORREDOR);
}

void escrever_registro_veiculo(Veiculo v, int rrn) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  char temp[TAM_REGISTRO_VEICULO + 1], p[100];
  temp[0] = '\0'; p[0] = '\0';

  strcpy(temp, v.id_veiculo);
  strcat(temp, ";");
  strcat(temp, v.marca);
  strcat(temp, ";");
  strcat(temp, v.modelo);
  strcat(temp, ";");
  strcat(temp, v.poder);
  strcat(temp, ";");
  sprintf(p, "%04d", v.velocidade);
  strcat(temp, p);
  strcat(temp, ";");
  sprintf(p, "%04d", v.aceleracao);
  strcat(temp, p);
  strcat(temp, ";");
  sprintf(p, "%04d", v.peso);
  strcat(temp, p);
  strcat(temp, ";");
  sprintf(p, "%013.2lf", v.preco);
  strcat(temp, p);
  strcat(temp, ";");

  strpadright(temp, '#', TAM_REGISTRO_VEICULO);

  strncpy(ARQUIVO_VEICULOS + rrn*TAM_REGISTRO_VEICULO, temp, TAM_REGISTRO_VEICULO);
}

void escrever_registro_pista(Pista p, int rrn) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  char temp[TAM_REGISTRO_PISTA + 1], po[100];
  temp[0] = '\0'; po[0] = '\0';

  strcpy(temp, p.id_pista);
  strcat(temp, ";");
  strcat(temp, p.nome);
  strcat(temp, ";");
  sprintf(po, "%04d", p.dificuldade);
  strcat(temp, po);
  strcat(temp, ";");
  sprintf(po, "%04d", p.distancia);
  strcat(temp, po);
  strcat(temp, ";");
  sprintf(po, "%04d", p.recorde);
  strcat(temp, po);
  strcat(temp, ";");

  strpadright(temp, '#', TAM_REGISTRO_PISTA);

  strncpy(ARQUIVO_PISTAS + rrn*TAM_REGISTRO_PISTA, temp, TAM_REGISTRO_PISTA);
}

void escrever_registro_corrida(Corrida i, int rrn) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  char temp[TAM_REGISTRO_CORRIDA + 1];
  temp[0] = '\0';

  strcpy(temp, i.id_pista);
  strcat(temp, ";");
  strcat(temp, i.ocorrencia);
  strcat(temp, ";");
  strcat(temp, i.id_corredores);
  strcat(temp, ";");
  strcat(temp, i.id_veiculos);
  strcat(temp, ";");

  strpadright(temp, '#', TAM_REGISTRO_CORRIDA);

  strncpy(ARQUIVO_CORRIDAS + rrn*TAM_REGISTRO_CORRIDA, temp, TAM_REGISTRO_CORRIDA);
}

/* Funções principais */
void cadastrar_corredor_menu(char *id_corredor, char *nome, char *apelido){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  corredores_index index;
  strcpy(index.id_corredor, id_corredor);
    corredores_index *found = busca_binaria((void*)&index, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, false, 0);
  if (found == NULL || found->rrn < 0){
    Corredor c;
    strcpy(c.id_corredor, id_corredor);
    strcpy(c.nome, nome);
    strcpy(c.apelido, apelido);
    current_datetime(c.cadastro);
    c.saldo = 0;

    for (unsigned i = 0; i < QTD_MAX_VEICULO; i++)
      strcpy(c.veiculos[i], "");

    int rrn = qtd_registros_corredores;
    escrever_registro_corredor(c, rrn);
    qtd_registros_corredores++;
    criar_corredores_idx();
    criar_corredor_veiculos_idx();
    printf(SUCESSO);
  }
  else
    printf(ERRO_PK_REPETIDA, id_corredor);
}

void remover_corredor_menu(char *id_corredor) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  corredores_index index;
  strcpy(index.id_corredor, id_corredor);
    corredores_index *found = busca_binaria((void*)&index, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, false, 0);
  if (found == NULL || found->rrn < 0)
    printf(ERRO_REGISTRO_NAO_ENCONTRADO);
  else {
    memcpy(ARQUIVO_CORREDORES + found->rrn*TAM_REGISTRO_CORREDOR, "*|", 2);
    criar_corredores_idx();
    printf(SUCESSO);
  }
}

void adicionar_saldo_menu(char *id_corredor, double valor) {
	adicionar_saldo(id_corredor, valor, true);
}

void adicionar_saldo(char *id_corredor, double valor, bool flag){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  corredores_index index;
  strcpy(index.id_corredor, id_corredor);
    corredores_index *found = busca_binaria((void*)&index, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, false, 0);
  if (found == NULL || found->rrn < 0)
    printf(ERRO_REGISTRO_NAO_ENCONTRADO);
  else if (valor <= 0)
    printf(ERRO_VALOR_INVALIDO);
  else {
    Corredor c = recuperar_registro_corredor(found->rrn);
    c.saldo = valor;
    escrever_registro_corredor(c, found->rrn);
    criar_corredores_idx();
    printf(SUCESSO);
  }
}

void comprar_veiculo_menu(char *id_corredor, char *id_veiculo) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  corredores_index index;
  veiculos_index indexv;
  strcpy(index.id_corredor, id_corredor);
  strcpy(indexv.id_veiculo, id_veiculo);
  corredores_index *found = busca_binaria((void*)&index, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, false, 0);
  veiculos_index *foundv = busca_binaria((void*)&indexv, veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx, false, 0);
  if (found > 0 && foundv > 0) {
    Corredor c = recuperar_registro_corredor(found->rrn);
    Veiculo v = recuperar_registro_veiculo(foundv->rrn);
    if (c.saldo < v.preco)
      printf(ERRO_SALDO_NAO_SUFICIENTE);
    else if (strcmp(c.veiculos[0], v.modelo) == 0 || strcmp(c.veiculos[1], v.modelo) == 0 || strcmp(c.veiculos[2], v.modelo) == 0){
      printf(ERRO_VEICULO_REPETIDO, c.nome, v.modelo);
    } else {
      for (int i = 0; i < QTD_MAX_VEICULO; ++i)
        if(strlen(c.veiculos[i]) == 0)
          strcpy(c.veiculos[i], v.modelo);
      c.saldo -= v.preco;
      escrever_registro_corredor(c, found->rrn);
      criar_corredores_idx();
      criar_corredor_veiculos_idx();
      printf(SUCESSO);
    }
  } else
    printf(ERRO_REGISTRO_NAO_ENCONTRADO);
}

void cadastrar_veiculo_menu(char *marca, char *modelo, char *poder, int velocidade, int aceleracao, int peso, double preco) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  veiculos_index index;
  char id_veiculo[TAM_ID_VEICULO];
  sprintf(id_veiculo, "%07d", qtd_registros_veiculos);
  strcpy(index.id_veiculo, id_veiculo);
  veiculos_index *found = busca_binaria((void*)&index, veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx, false, 0);
  if (found == NULL || found->rrn < 0){
    Veiculo v;
    strcpy(v.id_veiculo, id_veiculo);
    strcpy(v.marca, marca);
    strcpy(v.modelo, modelo);
    strcpy(v.poder, poder);
    v.velocidade = velocidade;
    v.aceleracao = aceleracao;
    v.peso = peso;
    v.preco = preco;

    int rrn = qtd_registros_veiculos;
    escrever_registro_veiculo(v, rrn);
    qtd_registros_veiculos++;
    criar_veiculos_idx();
    criar_preco_veiculo_idx();
    printf(SUCESSO);
  }
  else
    printf(ERRO_PK_REPETIDA, id_veiculo);
}

void cadastrar_pista_menu(char *nome, int dificuldade, int distancia, int recorde){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	nome_pista_index index;
  strcpy(index.nome, nome);
  nome_pista_index *found = busca_binaria((void*)&index, nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx, false, 0);
  if (found == NULL || strlen(found->id_pista) == 0){
    Pista p;
    char id_pista[TAM_ID_PISTA];
    sprintf(id_pista, "%08d", qtd_registros_pistas);
    strcpy(p.id_pista, id_pista);
    strcpy(p.nome, nome);
    if (dificuldade)
      p.dificuldade = dificuldade;
    else
      p.dificuldade = 1;
    p.distancia = distancia;
    p.recorde = recorde;
    
    int rrn = qtd_registros_pistas;
    escrever_registro_pista(p, rrn);
    qtd_registros_pistas++;
    criar_pistas_idx();
    criar_nome_pista_idx();
    printf(SUCESSO);
  } else {
    printf(ERRO_PK_REPETIDA, nome);
  } 
}

void executar_corrida_menu(char *id_pista, char *ocorrencia, char *id_corredores, char *id_veiculos) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	corridas_index index;
  strcpy(index.ocorrencia, ocorrencia);
  strcpy(index.id_pista, id_pista);
  corridas_index *found = busca_binaria((void*)&index, corridas_idx, qtd_registros_corridas, sizeof(corridas_index), qsort_corridas_idx, false, 0);
  if (found == NULL || found->rrn < 0){
    pistas_index index_pista;
    strcpy(index_pista.id_pista, id_pista);
    pistas_index *found_pista = busca_binaria((void*)&index_pista, pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx, false, 0);
    if (found_pista == NULL || found_pista->rrn < 0){
      printf(ERRO_REGISTRO_NAO_ENCONTRADO);
      return;
    }
    for (int i = 0; i < 6; ++i){
      corredores_index index_corredor;
      strncpy(index_corredor.id_corredor, id_corredores + (i * TAM_ID_CORREDOR), TAM_ID_CORREDOR);
      corredores_index *found_corredor = busca_binaria((void*)&index_corredor, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, false, 0);
      if (found_corredor == NULL || found_corredor->rrn < 0){
        printf(ERRO_REGISTRO_NAO_ENCONTRADO);
        break;
      } else {
        Corredor c = recuperar_registro_corredor(found_corredor->rrn);
        char id_veiculo[TAM_ID_VEICULO];
        strncpy(id_veiculo, id_veiculos + (i * TAM_ID_VEICULOS), TAM_ID_VEICULO);
        if (strcmp(c.veiculos[0], id_veiculo) != 0 && strcmp(c.veiculos[1], id_veiculo) != 0 && strcmp(c.veiculos[2], id_veiculo) != 0){
          printf(ERRO_CORREDOR_VEICULO, c.nome, id_veiculo);
        }
      }
    }
    for (int i = 0; i < 6; ++i){
      veiculos_index index_veiculo;
      strncpy(index_veiculo.id_veiculo, id_veiculos + (i * TAM_ID_VEICULO), TAM_ID_VEICULO);
      veiculos_index *found_veiculo = busca_binaria((void*)&index_veiculo, veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx, false, 0);
      if (found_veiculo == NULL || found_veiculo->rrn < 0){
        printf(ERRO_REGISTRO_NAO_ENCONTRADO);
        break;
      }
    }
    Corrida c;
    strcpy(c.ocorrencia, ocorrencia);
    strcpy(c.id_pista, id_pista);
    strcpy(c.id_corredores, id_corredores);
    strcpy(c.id_veiculos, id_veiculos);
    Pista p = recuperar_registro_pista(found_pista->rrn);
    double valor = 6 * (TX_FIXA * p.dificuldade);
    Corredor c1, c2, c3;
    corredores_index index_corredor1, index_corredor2, index_corredor3;
    strncpy(index_corredor1.id_corredor, id_corredores + (0 * TAM_ID_CORREDOR), TAM_ID_CORREDOR);
    strncpy(index_corredor2.id_corredor, id_corredores + (1 * TAM_ID_CORREDOR), TAM_ID_CORREDOR);
    strncpy(index_corredor3.id_corredor, id_corredores + (2 * TAM_ID_CORREDOR), TAM_ID_CORREDOR);
    corredores_index *found_corredor1 = busca_binaria((void*)&index_corredor1, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, false, 0);
    corredores_index *found_corredor2 = busca_binaria((void*)&index_corredor2, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, false, 0);
    corredores_index *found_corredor3 = busca_binaria((void*)&index_corredor3, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, false, 0);
    c1 = recuperar_registro_corredor(found_corredor1->rrn);
    c2 = recuperar_registro_corredor(found_corredor2->rrn);
    c3 = recuperar_registro_corredor(found_corredor3->rrn);
    c1.saldo += valor * 0.4;
    c2.saldo += valor * 0.3;
    c3.saldo += valor * 0.2;
    escrever_registro_corredor(c1, found_corredor1->rrn);
    escrever_registro_corredor(c2, found_corredor2->rrn);
    escrever_registro_corredor(c3, found_corredor3->rrn);
    escrever_registro_corrida(c, qtd_registros_corridas);
    qtd_registros_corridas++;
    criar_pistas_idx();
    criar_corredores_idx();
    printf(SUCESSO);
  } else {
    printf(ERRO_PK_REPETIDA, ocorrencia);
  }  
}

/* Busca */
void buscar_corredor_id_menu(char *id_corredor) {
	corredores_index index;
	strcpy(index.id_corredor, id_corredor);
    corredores_index *found = busca_binaria((void*)&index, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, true, 0);
	if (found == NULL || found->rrn < 0)
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	else
		exibir_corredor(found->rrn);
}

void buscar_pista_id_menu(char *id_pista) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	pistas_index index;
  strcpy(index.id_pista, id_pista);
  pistas_index *found = busca_binaria((void*)&index, pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx, true, 0);
  if (found == NULL || found->rrn < 0)
    printf(ERRO_REGISTRO_NAO_ENCONTRADO);
  else
    exibir_pista(found->rrn);
}

void buscar_pista_nome_menu(char *nome_pista) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	nome_pista_index index;
  strcpy(index.nome, nome_pista);
  nome_pista_index *found = busca_binaria((void*)&index, nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx, true, 0);
  if (found == NULL || found->id_pista < 0)
    printf(ERRO_REGISTRO_NAO_ENCONTRADO);
  else {
    pistas_index index_pista;
    strcpy(index_pista.id_pista, found->id_pista);
    pistas_index *found_pista = busca_binaria((void*)&index_pista, pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx, true, 0);
    exibir_pista(found_pista->rrn);
  }
}

/* Listagem */
void listar_corredores_id_menu() {
	if (qtd_registros_corredores == 0)
		printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
	else
		for (unsigned int i = 0; i < qtd_registros_corredores; i++)
			exibir_corredor(corredores_idx[i].rrn);
}

void listar_corredores_modelo_menu(char *modelo){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  int result;
  if (!inverted_list_secondary_search(&result, false, modelo, &corredor_veiculos_idx)){
    printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
  } else {
    corredor_veiculos_primario_index index;
    for (index = corredor_veiculos_idx.corredor_veiculos_primario_idx[result]; index.proximo_indice != -1; index = corredor_veiculos_idx.corredor_veiculos_primario_idx[index.proximo_indice]) {
      corredores_index *found = busca_binaria((void*)&index, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, true, 0);
      exibir_corredor(found->rrn);
    }
  }
}

void listar_veiculos_compra_menu(char *id_corredor) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	corredores_index index;
  strcpy(index.id_corredor, id_corredor);
  corredores_index *found = busca_binaria((void*)&index, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, true, 0);
  Corredor c = recuperar_registro_corredor(found->rrn);
  int flag = 0;
  for (unsigned int i = 0; i < qtd_registros_veiculos; i++){
    if(preco_veiculo_idx[i].preco < c.saldo){
      flag = 1;
      veiculos_index index_veiculo;
      strcpy(index_veiculo.id_veiculo, preco_veiculo_idx[i].id_veiculo);
      veiculos_index *found_veiculo = busca_binaria((void*)&index_veiculo, veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx, true, 0);
      exibir_veiculo(found_veiculo->rrn);
    }
  }
  if (!flag)
    printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
}

void listar_corridas_periodo_menu(char *data_inicio, char *data_fim) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	corridas_index index;
  strcpy(index.ocorrencia, data_inicio);
  corridas_index *found = busca_binaria_com_reps((void*)&index, corridas_idx, qtd_registros_corridas, sizeof(corridas_index), qsort_corridas_idx, true, -1, 1);
  int flag = 0;
  if (found == NULL){
    printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
  } else {
    while(found + (sizeof(found)) != NULL){
      if(found->ocorrencia <= data_fim && found->ocorrencia >= data_inicio){
        flag = 1;
        exibir_corrida(found->rrn);
      }
    }
  }
  if (!flag)
    printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
}

/* Liberar espaço */
void liberar_espaco_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  char temp[TAM_ARQUIVO_CORREDORES + 1];
  temp[0] = '\0';

  for (unsigned int i = 0; i < qtd_registros_corredores; ++i){
    if (strncmp(&ARQUIVO_CORREDORES[i * TAM_REGISTRO_CORREDOR], "*|", 2) != 0){
      strncat(temp, &ARQUIVO_CORREDORES[i * TAM_REGISTRO_CORREDOR], TAM_REGISTRO_CORREDOR);
    } else
      continue;
  }

  strcpy(ARQUIVO_CORREDORES, temp);
  criar_corredores_idx();
  printf(SUCESSO);
}

/* Imprimir arquivos de dados */
void imprimir_arquivo_corredores_menu() {
	if (qtd_registros_corredores == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_CORREDORES);
}

void imprimir_arquivo_veiculos_menu() {
	if (qtd_registros_veiculos == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_VEICULOS);
}

void imprimir_arquivo_pistas_menu() {
	if (qtd_registros_pistas == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_PISTAS);
}

void imprimir_arquivo_corridas_menu() {
	if (qtd_registros_corridas == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_CORRIDAS);
}

/* Imprimir índices primários */
void imprimir_corredores_idx_menu() {
	if (corredores_idx == NULL || qtd_registros_corredores == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		for (unsigned i = 0; i < qtd_registros_corredores; ++i)
			printf("%s, %d\n", strupr(corredores_idx[i].id_corredor), corredores_idx[i].rrn);
}

void imprimir_veiculos_idx_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	if (veiculos_idx == NULL || qtd_registros_veiculos == 0)
    printf(ERRO_ARQUIVO_VAZIO);
  else
    for (unsigned int i = 0; i < qtd_registros_veiculos; i++)
      if (veiculos_idx[i].rrn != -1)
        printf("%s, %d\n", veiculos_idx[i].id_veiculo, veiculos_idx[i].rrn);
}

void imprimir_pistas_idx_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  if (pistas_idx == NULL || qtd_registros_pistas == 0)
    printf(ERRO_ARQUIVO_VAZIO);
  else
    for (unsigned int i = 0; i < qtd_registros_pistas; i++)
      if (pistas_idx[i].rrn != -1)
        printf("%s, %d\n", pistas_idx[i].id_pista, pistas_idx[i].rrn);
}

void imprimir_corridas_idx_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  if (corridas_idx == NULL || qtd_registros_corridas == 0)
    printf(ERRO_ARQUIVO_VAZIO);
  else
    for (unsigned int i = 0; i < qtd_registros_corridas; i++)
      if (corridas_idx[i].rrn != -1)
        printf("%s, %s %d\n", corridas_idx[i].ocorrencia, corridas_idx[i].id_pista, corridas_idx[i].rrn);  
}

/* Imprimir índices secundários */
void imprimir_nome_pista_idx_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  if (nome_pista_idx == NULL || qtd_registros_pistas == 0)
    printf(ERRO_ARQUIVO_VAZIO);
  else
    for (unsigned int i = 0; i < qtd_registros_pistas; i++)
      if (strcmp(nome_pista_idx[i].id_pista, "\0") != 0)
        printf("%s, %s\n", strupr(nome_pista_idx[i].nome), nome_pista_idx[i].id_pista);
}

void imprimir_preco_veiculo_idx_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	if (preco_veiculo_idx == NULL || qtd_registros_veiculos == 0)
    printf(ERRO_ARQUIVO_VAZIO);
  else
    for (unsigned i = 0; i < qtd_registros_veiculos; i++)
      if(strcmp(preco_veiculo_idx[i].id_veiculo, "-1") != 0)
        printf("%.2f, %s\n", preco_veiculo_idx[i].preco, preco_veiculo_idx[i].id_veiculo);
}

void imprimir_corredor_veiculos_secundario_idx_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	if (corredor_veiculos_idx.corredor_veiculos_secundario_idx == NULL || corredor_veiculos_idx.qtd_registros_secundario == 0)
    printf(ERRO_ARQUIVO_VAZIO);
  else
    for(unsigned int i = 0; i < corredor_veiculos_idx.qtd_registros_secundario; i++)
    printf("%s, %d\n", strupr(corredor_veiculos_idx.corredor_veiculos_secundario_idx[i].chave_secundaria), corredor_veiculos_idx.corredor_veiculos_secundario_idx[i].primeiro_indice);
}

void imprimir_corredor_veiculos_primario_idx_menu(){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	if (corredor_veiculos_idx.corredor_veiculos_primario_idx == NULL || corredor_veiculos_idx.qtd_registros_primario == 0)
    printf(ERRO_ARQUIVO_VAZIO);
  else
    for (unsigned int i = 0; i < corredor_veiculos_idx.qtd_registros_primario; i++)
      printf("%s, %d\n", corredor_veiculos_idx.corredor_veiculos_primario_idx[i].chave_primaria, corredor_veiculos_idx.corredor_veiculos_primario_idx[i].proximo_indice);
}

/* Liberar memória e encerrar programa */
void liberar_memoria_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	free(corredores_idx);
  free(veiculos_idx);
  free(pistas_idx);
  free(corridas_idx);
  free(nome_pista_idx);
  free(preco_veiculo_idx);
  free(corredor_veiculos_idx.corredor_veiculos_primario_idx);
  free(corredor_veiculos_idx.corredor_veiculos_secundario_idx);
}

void inverted_list_insert(char *chave_secundaria, char *chave_primaria, inverted_list *t) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  int result;
  if (inverted_list_secondary_search(&result, false, chave_secundaria, t)){
    int indice_final;
    inverted_list_primary_search(NULL, false, result, &indice_final, t);
    t->corredor_veiculos_primario_idx[indice_final].proximo_indice = t->qtd_registros_primario;
    strcpy(t->corredor_veiculos_primario_idx[t->qtd_registros_primario].chave_primaria, chave_primaria);
    t->corredor_veiculos_primario_idx[t->qtd_registros_primario].proximo_indice = -1;
    t->qtd_registros_primario++;
  } else {
    strcpy(t->corredor_veiculos_secundario_idx[t->qtd_registros_secundario].chave_secundaria, chave_secundaria);
    t->corredor_veiculos_secundario_idx[t->qtd_registros_secundario].primeiro_indice = t->qtd_registros_primario;
    t->corredor_veiculos_primario_idx[t->qtd_registros_primario].proximo_indice = -1;
    strcpy(t->corredor_veiculos_primario_idx[t->qtd_registros_primario].chave_primaria, chave_primaria);
    t->qtd_registros_secundario++;
    t->qtd_registros_primario++;
    qsort(t->corredor_veiculos_secundario_idx, t->qtd_registros_secundario, sizeof(corredor_veiculos_secundario_index), t->compar);
  }
}

bool inverted_list_secondary_search(int *result, bool exibir_caminho, char *chave_secundaria, inverted_list *t) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  result = busca_binaria(chave_secundaria, t, t->qtd_registros_secundario, sizeof(corredor_veiculos_secundario_index), t->compar, exibir_caminho, 0);
  return result != NULL;
}

int inverted_list_primary_search(char result[][TAM_ID_CORREDOR], bool exibir_caminho, int indice, int *indice_final, inverted_list *t) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	int qtd = 0;
  corredor_veiculos_primario_index a;
  if (exibir_caminho)
    printf("%d ", indice);
  for (a = t->corredor_veiculos_primario_idx[indice]; a.proximo_indice != -1; a = t->corredor_veiculos_primario_idx[a.proximo_indice]){
    if (result != NULL)
      strcat(result[qtd], a.chave_primaria);
    if (exibir_caminho)
      printf("%d ", a.proximo_indice);
    if (indice_final != NULL)
      if (t->corredor_veiculos_primario_idx[a.proximo_indice].proximo_indice == -1)
        indice_final = &a.proximo_indice;
    qtd++;
  }
  return qtd;
}


void* busca_binaria_com_reps(const void *key, const void *base0, size_t nmemb, size_t size, int (*compar)(const void *, const void *), bool exibir_caminho, int posicao_caso_repetido, int retorno_se_nao_encontrado) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
  size_t __l, __u, __idx;
  const void *__p;
  int __comparison;

  if(exibir_caminho)
    printf(REGS_PERCORRIDOS);

  __l = 0;
  __u = nmemb;
  while (__l < __u)
    {
      __idx = (__l + __u) / 2;

      if (exibir_caminho)
        printf(" %zu", __idx);
      
      __p = (void *) (((const char *) base0) + (__idx * size));
      __comparison = (*compar) (key, __p);
      if (__comparison < 0)
  __u = __idx;
      else if (__comparison > 0)
  __l = __idx + 1;
      else {
        if (exibir_caminho)
          printf("\n");
  return (void *) __p;
      }
    }

  if(retorno_se_nao_encontrado == -1){
    if (__l > 0){
      if (exibir_caminho)
        printf("\n");
      return (void *)(base0 + (__l - 1) * size);
    }
  } else if (retorno_se_nao_encontrado == 1){
    if (__l < nmemb){
      if (exibir_caminho)
        printf("\n");
      return (void *)(base0 + (__l * size));
    }
  }

  if (exibir_caminho)
    printf("\n");
  return NULL;
}

void* busca_binaria(const void *key, const void *base0, size_t nmemb, size_t size, int (*compar)(const void *, const void *), bool exibir_caminho, int retorno_se_nao_encontrado) {
	return busca_binaria_com_reps(key, base0, nmemb, size, compar, exibir_caminho, 0, retorno_se_nao_encontrado);
}

char *strpadright(char *str, char pad, unsigned size){
	for (unsigned i = strlen(str); i < size; ++i)
		str[i] = pad;
	str[size] = '\0';
	return str;
}
char *strupr(char *str){
	for (char *p = str; *p; ++p)
		*p = toupper(*p);
	return str;
}
char *strlower(char *str){
	for (char *p = str; *p; ++p)
		*p = tolower(*p);
	return str;
}
