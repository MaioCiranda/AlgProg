#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

const int LIMITE_PACIENTES = 50;
const int LIMITE_CARACTERES = 51;
const int IDADE_MINIMA = 13;
const int LIMITE_CONSULTAS = 100;

struct paciente
{
  long long cpf;
  char nome[LIMITE_CARACTERES];
  int nascimento;
};

struct consulta
{
  long long cpf;
  int data;
  int hora_inicial;
  int hora_final;
};

struct data
{
  int ano;
  int mes;
  int dia;
  int hora;
  int min;
  int seg;
};

//Funções auxiliares

bool cpf_valido(long long cpf)
{
  int primeiro_dv, segundo_dv, soma, resto, j, k;
  long long numero_cpf;
  int mult[10] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

  if (cpf < 11111111111L || cpf > 99999999999L || cpf % 11111111111L == 0)
    return false;

  primeiro_dv = cpf % 100 / 10,
  segundo_dv  = cpf % 10;

  numero_cpf = cpf / 100;
  soma = 0;
  for (int i = 0; i < 9; i++)
  {
    soma += (numero_cpf % 10) * mult[i];
    numero_cpf /= 10;
  }

  resto = soma % 11;

  if (resto == 0 || resto == 1)
    j = 0;
  else
    j = 11 - resto;

  if (j != primeiro_dv)
    return false;

  numero_cpf = cpf / 10;
  soma = 0;
  for (int i = 0; i < 10; i++)
  {
    soma += (numero_cpf % 10) * mult[i];
    numero_cpf /= 10;
  }

  resto = soma % 11;

  if (resto == 0 || resto == 1)
    k = 0;
  else
    k = 11 - resto;

  if (k != segundo_dv)
    return false;

  return true;
}

void data_hora_atual(int &dia, int &mes, int &ano,
int &hora, int &min, int &seg) 
{
  time_t t = time(NULL);
  struct tm lt = *localtime(&t);
  ano = lt.tm_year + 1900;
  mes = lt.tm_mon + 1;
  dia = lt.tm_mday;
  hora = lt.tm_hour;
  min = lt.tm_min;
  seg = lt.tm_sec;
}

data int_para_data (int data_int)
{
  data data_struct;
  data_struct.ano = data_int % 10000;
  data_struct.mes = (data_int % 1000000) / 10000;
  data_struct.dia = data_int / 1000000;
  return data_struct;
}

bool idade_minima (int nascimento, int idade_minima)
{
  void data_hora_atual(int &dia, int &mes, int &ano,
  int &hora, int &min, int &seg);
  data data_atual;
  data_hora_atual(data_atual.dia, data_atual.mes, data_atual.ano, data_atual.hora,
                  data_atual.min, data_atual.seg);

  data nascimento_formatado = int_para_data(nascimento);
  if ((data_atual.ano - nascimento_formatado.ano) * 365 +
      (data_atual.mes - nascimento_formatado.mes) * 30 +
       data_atual.dia - nascimento_formatado.dia < idade_minima * 365)
    return false;
  return true;
}

// Função que retorna a posição do CPF na lista ou -1 para cpfs não cadastrados
int posicao_paciente(paciente lista[LIMITE_PACIENTES], long long cpf)
{
  for (int i = 0; i < LIMITE_PACIENTES; i++)
  {
    if (lista[i].cpf == cpf)
      return i;
  }
  return -1;
}

//Funções Principais

int menu_principal()
{
  int n;
  printf("Menu Principal\n1-Cadastro de pacientes\n2-Agenda\n3-Fim\n");
  scanf(" %i", &n);
  return n;
}

int menu_cadastro()
{
  int n;
  printf("\nMenu do Cadastro de Pacientes\n"
         "1-Cadastrar novo paciente\n"
         "2-Excluir paciente\n"
         "3-Listar pacientes (ordenado por CPF)\n"
         "4-Listar pacientes (ordenado por nome)\n"
         "5-Voltar p/ menu principal\n");
  scanf("%i", &n);
  return n;
}

int menu_agenda()
{
  int n;
  printf("\nAgenda\n"
         "1-Agendar consulta\n"
         "2-Cancelar agendamento\n"
         "3-Listar agenda\n"
         "4-Voltar p/ menu principal\n");
  scanf("%i", &n);
  return n;
}

paciente cadastro_paciente()
{
  paciente paciente_novo;
  int paciente_valido = 0;

  // CPF
  long long cpf;
  while (cpf_valido(cpf) == false)
  {
    printf("CPF: ");
    scanf("%lld", &cpf);
    if (cpf_valido(cpf) == false)
      printf("CPF inválido.\n");
  }
  paciente_novo.cpf = cpf;

  // Nome
  char nome[LIMITE_CARACTERES];
  for (;;)
  {
    printf("Nome: ");
    while (getchar() != '\n');
    fgets(nome, LIMITE_CARACTERES, stdin);
    if (strlen(nome) < 4)
      printf("Nome inválido\n");
    else
      break;
  }
  int i = 0;
  while (nome[i] != '\0')
  {
    paciente_novo.nome[i] = toupper(nome[i]);
    i++;
  }
  
  // Data de Nascimento
  int data_nascimento = 99999999;
  while (idade_minima(data_nascimento, IDADE_MINIMA) == false)
  {
    printf("Data de nascimento: ");
    scanf(" %i", &data_nascimento);
    if (idade_minima(data_nascimento, IDADE_MINIMA) == false)
      printf("Apenas pacientes acima de %i anos\n", IDADE_MINIMA);
  }
  paciente_novo.nascimento = data_nascimento;
  return paciente_novo;
}

void listar_pacientes_por_cpf()
{
  // A FAZER
}

void listar_pacientes_por_nome()
{
  // A FAZER
}

void agendar_consulta()
{
  // A FAZER
}

void cancelar_agendamento()
{
  // A FAZER
}

void listar_agenda()
{
  // A FAZER
}

int main()
{
  paciente lista_pacientes[LIMITE_PACIENTES];
  for (int i = 0; i < LIMITE_PACIENTES; i++)
  {
    lista_pacientes[i].cpf = 0;
  }

  consulta lista_consultas[LIMITE_CONSULTAS];
  
  int requerimento;
  
  while (requerimento != 3)
  {
  requerimento = menu_principal();
  if (requerimento == 1)
   { 
    for (;;)
    {
      int requisito_cadastro = menu_cadastro();
      if (requisito_cadastro == 5)
        break;
      switch (requisito_cadastro)
      {
        case 1:
        {
          bool tem_invalido = false;
          paciente paciente_temp = cadastro_paciente();
          for (int i = 0; i < LIMITE_PACIENTES; i++)
          {
            if (paciente_temp.cpf == lista_pacientes[i].cpf)
            {
              printf("\nPaciente já cadastrado");
              tem_invalido = true;
              break;
            }
            if (lista_pacientes[i].cpf == 0)
            {
              lista_pacientes[i] = paciente_temp;
              printf("\nPaciente cadastrado com sucesso!\n");
              tem_invalido = true;
              break;
            }
          }
          if (tem_invalido == false)
            printf("\nLimite de pacientes atingido\n");
          break;
        } 
        
        case 2:
        {
          long long cpf_a_excluir;
          printf("CPF: ");
          scanf("%lld", &cpf_a_excluir);
          int n = posicao_paciente(lista_pacientes, cpf_a_excluir);
          if (n == -1)
            printf("\nPaciente não cadastrado");
          else
            lista_pacientes[n].cpf = 0;
          break;
        }

        case 3:
          listar_pacientes_por_cpf();
          break;
        case 4:
          listar_pacientes_por_nome();
          break;
        default:
          printf("Requerimento inválido.\n");
          break;
      }
    }
   }
  if (requerimento == 2)
    for(;;)
    {
      int requisito_agenda = menu_agenda();
      if (requisito_agenda == 4)
        break;
      switch (requisito_agenda)
      {
        case 1:
          agendar_consulta();
          break;
        case 2:
          cancelar_agendamento();
          break;
        case 3:
          listar_agenda();
          break;
        default:
          printf("Requerimento inválido\n");
          break;
      }
    }
  }
  
  return 0;
}
