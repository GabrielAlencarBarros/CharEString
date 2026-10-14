#include <Arduino.h>
#include <string.h> //? strlen, strcpy, strcat, strcmp, strchr
#include <stdlib.h> //? atoi

void textoChar();
void textoString();

void setup()
{
  Serial.begin(9600);
  Serial.println();
}

void loop() {}

void textoChar()
{
  //? Texto literal
  //? Use const char* quando o texto não será alterado
  const char cidade[] = "Sao Paulo";
  Serial.println(cidade);

  //? Descobrindo o tamanho do texto
  //? strlen conta quantos caracteres antes do '/0'
  int tamanhoTextoCidade = strlen(cidade);
  Serial.print("Comprimento do texto: ");
  Serial.println(tamanhoTextoCidade);

  //? Descobrindo o tamanho ocupado
  //? O sizeof() retornará um byte a mais que o comprimento por causa do '/0'
  int tamanhoVariavelCidade = sizeof(cidade);
  Serial.print("Espaço utlizado");
  Serial.println(tamanhoVariavelCidade);

  char vetorTexto[6] = {'B', 'r', 'u', 'n', 'o', '\0'};
  Serial.println(vetorTexto);

  //? Comparador texto
  const char *cidade1 = "Sao Caetano";
  const char *cidade2 = "Sao Caetano";

  if (strcmp(cidade1, cidade2) == 0)
    Serial.println("Os textos são iguais");
  else
    Serial.println("Os textos são diferentes");

  //? strcmp analisa a ordem lexica das palavras, se a primeira palavra vem antes que a segunda o valor retornado será menos que zero, se a primeira vem após a segunda o retorno será maior que zero

  //!================================
  //!   TEXTO EDITAVEL COM char[]
  //!================================

  char nomeAluno[20] = "Alencar";
  Serial.println(nomeAluno);

  //? Alterando caracteres individualmente
  nomeAluno[2] = 'o';
  Serial.println(nomeAluno);

  //? Copiando outro texto para dentro do vetor
  //! Cuidado: o vetor precisa ter espaço sufiente

  strcpy(nomeAluno, "Guilherme");
  Serial.println(nomeAluno);

  //? Concatenando de texto ao final
  char frase[40] = "Ola ";
  strcat(frase, "Mundo!");
  Serial.println(frase);

  //? Procurando um caractere no texto
  //? Frase "Ola Mundo!"
  char *posicaoLetra = strchr(frase, 'M');

  if (posicaoLetra != NULL)
  {
    Serial.println("Letra encontrada");
    Serial.println(posicaoLetra);
  }
  else
  {
    Serial.println("Letra não encontrada");
  }

  //? Convertendo texto numérico para inteiro
  char idadeTexto[] = "45"; // 52, 53, \0
  int idade = atoi(idadeTexto);
  Serial.println(idade);
}

void textoString()
{

  //? =============================================
  //? USANDO String
  //? =============================================

  String nome = "Gabriel";
  String curso = "Logica de Programacao";
  String mensagem = "Ola";

  //? Concatenando String
  mensagem = mensagem + "," + nome + "! Bem vindo ao curso de " + curso + ".";
  Serial.println(mensagem);

  //? Tamanho da String
  int tamanhoMensagem = mensagem.length();
  Serial.print("Tamanho da String em letra: ");
  Serial.println(tamanhoMensagem);

  //? Acessando um caractere em uma posição especificada
  char primeiraLetra = mensagem.charAt(0);
  Serial.print("Primeira letra: ");
  Serial.println(primeiraLetra);

  //? Também é possível acessar com colchetes
  char segundaLetra = mensagem[1];
  Serial.println(segundaLetra);

  //? Procurando um texto dentro da String
  int posicaoTextoProcurado = mensagem.indexOf("curso");
  Serial.println(posicaoTextoProcurado);

  //? Extraindo um texto dentro da String
  int InicioNomeCurso = posicaoTextoProcurado + 9;                          // posicao da palavra curso + 9 caracteres
  Serial.println(mensagem.substring(InicioNomeCurso, tamanhoMensagem - 1)); //* -1 tira o ponto final

  //? Substituindo um texto dentro da String
  mensagem.replace("Ola,", "Oi, tudo bom? ");
  Serial.println(mensagem);

  //? Convertendo para maiúsculas
  mensagem.toUpperCase();
  Serial.println(mensagem);

  //? Convetendo tudo para minúsculo
  mensagem.toLowerCase();
  Serial.println(mensagem);

  //? Convertendo texto numérico para inteiro
  String textoNumerico = "123";
  int numero = textoNumerico.toInt();
  Serial.println(numero * 2);

  //? Verificando se a String está vazia
  String textoVazio = "";
  if(textoVazio.length() == 0) Serial.println("O texto está vazio");

  //? Convertendo String para const char*
  //? Isto é útil quando alguma biblioteca espera texto estilo C
  const char* textoComoChar = mensagem.c_str();
  Serial.println(textoComoChar);

  //? Convertendo texto numérico para inteiro
  char idadeTexto[] = "45"; // 52, 53, \0
  int idade = atoi(idadeTexto);
  Serial.println(idade);

  //? Montando Texto
  char buffer[100];
  char* local = "Sala de Aula";
  float temperatura = 26.4;
  int umidade = 58;

  //? '\n' mudança de linha
  //? '\r' retorno ao começo da linha
  snprintf(buffer, sizeof(buffer), "%s | Temp.: %f | Umid.: %d %% \n\r", buffer, temperatura, umidade);

  Serial.print(buffer);
  Serial.printf("O tamanho do Buffer é %lu \n\r", sizeof(buffer));

  //? snprintf monta um texto dentro de um vetor de char 
  //? Sintaxe: snprintf(variavelOndeSeraMontadoOTexto, TamanhoMaximoDoTexto, TextoComFormatação, ItensDeFormado)
  //? Isso é muito útil quando depois você quer:
  //? - salvar o texto em uma variável
  //? - mandar para o display
  //? - Imprimir na serial
  //? enviar por MQTT (IoT)
  //?
  //? ESPECIFICADORES
  //?
  //?   %d ou %i    -int
  //?   %u          -unsigned int
  //?   %ld         -long
  //?   %lu         -unsigned long
  //?   %f          -float
  //?   %e          -notação científica
  //?   %g          -float, formato mais curto
  //?   %c          -char
  //?   %s          -char* (string)
  //?   %x ou %X    -hexadecimal minúsculo/maiúsculo
  //?   %o          -octal
  //?   %p          -ponteiro
  //?   %%          -o próprio %
  //?
  //?   Flag, largura e precisão
  //?
  //?   %5d     -imprime com largura miníma de 5 alinhado a direita [     3], [   100], [1000000000]
  //?   %-4d    -imprime com largura miníma de 5 alinhado a esquerda [3    ], [100  ], [123456]
  //?   %03d    -completa com zeros a esquerda, [003]
  //?   %+d     -sempre mostra o sinal [+3] [-3]
  //?   %.2f    -2 casas decimais num float
  //?   %4.2f   -largura miníma 4 a direita com 2 casas decimais
  //?   %02X    -exadecimal com 2 digítos [0F], [3A]
  //?   %#x     -imprime o prefixo 0x [0x2a], [0xF]
  //?   %.3s    -somente os 3 primeiros caracteres da string
  //?   %*d     -largura passada como argumento ex.:
  //?   int largura = 3;
  //?   int numero = 9;
  //?   snprintf(buffer, sizeof(buffer), "numero %*d", precisao, numero)
  //?   Serial.print(buffer) -> [  9]
   


  Serial.println("SENAI");

  //? Sala de Aula | Temp.: 26.4 | Umid.: 58%
}

