 /*    Leitor, e emulador 433,92 com display 16x2
  
 *     AUTOR: GUILHERME BERTOLETTI
 *     Este codigo tem como finalidade ler codigos de controles RF 433,92, salvar os codigos lidos
 *     e ter opcao para selecionar e transmitir pelo emissor algum deles e poder adicionar um codigo manualmente
 *     Biblioteca utilizada para ler os codigos:  https://github.com/sui77/rc-switch/ */


#define botao1 6
#define botao2 7
#define botao3 A0
#define botao4 A1

#include <LiquidCrystal.h>
#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

unsigned long codigo1[6] = {00, 11, 22, 33, 44, 0};
unsigned long bits1[6] = {00, 11, 22, 33, 44, 0};
unsigned long length1[6] = {00, 11, 22, 33, 44, 0};
unsigned long protocolo1[6] = {00, 11, 22, 33, 44, 0};

unsigned long soma = 1;

unsigned long value1 = 0;
unsigned long value2 = 0;
unsigned long value3 = 0;
unsigned long value4 = 0;

int cont = 0;
int cont2 = 0;
bool detalhes = 0;

//rs = 13, e = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); //configurar os pinos do display dessa forma 

void setup() {
  pinMode(botao1,INPUT_PULLUP); //Botao de mais ou cima
  pinMode(botao2,INPUT_PULLUP); //Botao de menis ou baixo
  pinMode(botao3,INPUT_PULLUP); //Botao de transmitir ou confirmar 
  pinMode(botao4,INPUT_PULLUP); //Botao para entrar no modo config e voltar

  //Definindo entrada de sinal como pino 
  mySwitch.enableReceive(0); // 0 igual ao pino 2, 1= 3, so estes dois pinos podem ser usados no arduino uno, Seleçao do pino de recepçao do codigo TX
  
  // Definindo saida de sinal como pino
  mySwitch.enableTransmit(A2); // Seleçao do pino de transmissao do codigo TX

  lcd.begin(16, 2);
   
   lcd.clear();
   lcd.setCursor(3,0);
   lcd.print("By  GMBW");
   delay(500);
   lcd.setCursor(3,0); 
   lcd.print("433,92Mhz");
   lcd.setCursor(3,1); 
   lcd.print("DECODER");
   delay(500);
   lcd.clear();
  }
void loop(){

  //Funçao que faz a leitura do codigo e copia o codigo lido para variaveis para serem usados
  LEITURA();

  //value1 contem o codigo do recebido se for diferente dos codigos salvos e de 0 executa o switch e incrementa 1 em cont2
    if(value1 != codigo1[0] && value1 != codigo1[1] && value1 != codigo1[2] && value1 != codigo1[3] && value1 != codigo1[4] && value1 != 0)
    {
     cont2++;   // contador auxiliar, inicia em 0, se value1 for diferente de todos entra no if uma vez seta o switch para o case 1 e copia o codico lido para os arrays na posiçao 0, 
                // na segunda vez seta em 2 e assim continua ate case 6 onde direciona pro case 5 em loop, esse loop faz com que ao final so o codigo 5 
                // fique a reeceber novos codigos ate o arduino ser resetado

    switch (cont2) {

  case 1:
  
    codigo1[0] = value1;
    bits1[0] = value2;
    length1[0] = value3;
    protocolo1[0] = value4;
    break;
    
  case 2:

    codigo1[1] = value1;
    bits1[1] = value2;
    length1[1] = value3;
    protocolo1[1] = value4;    
    break;
    
  case 3:

    codigo1[2] = value1;
    bits1[2] = value2;
    length1[2] = value3;
    protocolo1[2] = value4;
    break;
  case 4:

    codigo1[3] = value1;
    bits1[3] = value2;
    length1[3] = value3;
    protocolo1[3] = value4;
    break;
    
  case 5:

    codigo1[4] = value1;
    bits1[4] = value2;
    length1[4] = value3;
    protocolo1[4] = value4;
    break;
    
  case 6:

    codigo1[4] = value1;
    bits1[4] = value2;
    length1[4] = value3;
    protocolo1[4] = value4;
    cont2 = 5;
    break;
      }
    }
   MENU_1();                            // Funcao menu 1 onde se encontra a navegaçao pelos codigos lidos 
   TRANSMITIR();                        // Funçao que seta os valores e faz a transmissao do codigo selecionado
   CONFIG();                            // Funçao de configuraçao
  }
