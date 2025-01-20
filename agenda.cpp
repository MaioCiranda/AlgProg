#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//teste// consegue ver?//
//lembrar de ajeitar o layout no fim do exc!!!!!!!!!//
struct paciente
{
  long long cpf;
  char nome[50];
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
  int dia;
  int mes;
  int ano;
};
struct hora
{
  int minutos;
  int horas;
};


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
  bool cpf_valido(long long cpf);
  
  paciente paciente_novo;
  int cpf;
  printf("CPF: ");
  scanf("%i", &cpf);
  if (cpf_valido(cpf) == false)
  {
    printf("CPF inválido.");
    return {-1, -1, -1};
  }
  else
    paciente_novo.cpf = cpf;

  char nome[50];
  printf("Nome: ");
  fgets(nome, 50, stdin);
  if (strlen(nome) < 4)
  {
    printf("CPF inválido");
    return {-1, -1, -1};
  }
  else
    for (int i = 0; i < 50; i++)
    {
      paciente_novo.nome[i] = nome[i];
      if (nome[i] == '\0')
        break;
    }
    
}

void excluir_paciente()
{
  // A FAZER
}

void listar_pacientes_por_cpf()
{
  // A FAZER
}

void listar_pacientes_por_nome()
{
  // A FAZER
}

int data()

void agendar_consulta()
{
 for (int i = 0; i < 50; i ++)
{
    if (cpf == lista_pacientes[i].cpf)
      printf("true");
    else
      printf("false");
}
}
int data_valida()
{
  data data_correta;
  do
  {
  printf("DATA\n Dia Mes Ano");
  scanf("%d %d %d". &data_correta.dia, &data_correta.mes, &data_correta.ano);
  if (data_correta.dia < 1 || data_correta.dia >= 32 && data_correta.mes < 1 || data_correta.mes >= 13 && data_correta.ano < 2025)
    printf("ERRO");
    continue;
  } while (data_cocorretarreta.dia < 1 || data_correta.dia >= 32 && data_correta.mes < 1 || data_correta.mes >= 13 && data_correta.ano < 2025)
  return int data_cor;
  
}
 
int hora_valida()
{
  do
  {
  printf("Hora\n Horas Minutos");
  scanf("%d %d". &hora.horas, &hora.minuto);
  if (hora.horas < 8 || hora.horas > 19 && hora.minuto < 1 || hora.minuto >= 60 )
    printf("ERRO");
    continue;
  } while (hora.horas < 8 || hora.horas > 19 && hora.minuto < 1 || hora.minuto >= 60 )
  return int hora;
}


void cancelar_agendamento()
{
  // A FAZER
}

void listar_agenda()
{
  // A FAZER
}

//Funções auxiliares

bool cpf_valido(long long cpf)
{
    int primeiro_dv, segundo_dv, soma, resto, j, k;
    long long numero_cpf;
    int mult[10] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

    // Se cpf n�o est� no intervalo v�lido ou se tem todos os d�gitos iguais
    // ent�o � inv�lido
    if (cpf < 11111111111L || cpf > 99999999999L || cpf % 11111111111L == 0)
        return false;

    // Pega o primeiro DV e o segundo DV do cpf
    primeiro_dv = cpf % 100 / 10,
    segundo_dv  = cpf % 10;

    // Calcula primeiro DV
    numero_cpf = cpf / 100; // N�mero do cpf sem os DVs
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

    // Compara o primeiro DV calculado com o informado
    // Se � inv�lido, ent�o nem precisa calcular o segundo
    if (j != primeiro_dv)
        return false;

    // Calcula segundo DV
    numero_cpf = cpf / 10;  // N�mero do cpf sem segundo DV
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

    // Compara o segundo DV calculado com o informado
    if (k != segundo_dv)
        return false;

    return true;
}

int main()
{
    char resp;
    long long cpf;

    do {
        printf("CPF: ");
        scanf("%lld", &cpf);
        getchar();

        if (cpf_valido(cpf))
            puts("Valido");
        else
            puts("Invalido");

        printf("Continua (S/N)? ");
        resp = getchar();
    } while (resp == 's' || resp == 'S');
}

int main()
{
  paciente lista_pacientes[50];
  consulta lista_consultas[100];
  
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
          paciente temp = cadastro_paciente();
          printf("%i", temp.cpf);
          break;
        }
        case 2:
          excluir_paciente();
          break;
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
