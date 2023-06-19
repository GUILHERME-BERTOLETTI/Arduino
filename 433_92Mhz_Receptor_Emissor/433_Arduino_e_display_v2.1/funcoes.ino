//Funçao que faz a leitura do codigo, do tamanho do codigo, dos bits e do protocolo utilizado e salva nas variaveis value para serem utilizadas depois
void LEITURA(){ 
  
    if (mySwitch.available()) {
   
      value1 = mySwitch.getReceivedValue();
      value2 = mySwitch.getReceivedBitlength();
      value3 = mySwitch.getReceivedDelay();
      value4 = mySwitch.getReceivedProtocol();
     
      mySwitch.resetAvailable();
      }
}

// Funcao onde se encontra a navegaçao pelos codigos lidos
void MENU_1(){
  lcd.setCursor(4,0);
    lcd.print("Codigo");
    lcd.setCursor(11,0);
    lcd.print(cont + 1);
    lcd.setCursor(3,1); 
    lcd.print(codigo1[cont]);
    //delay(100);
// Se botao1 for pressionado vai para nivel baixo e entra neste if     
 if (digitalRead(botao1) == LOW ) {
// Esse while garante que se o botao ficar pressionado nada acontece, somente quando for solto pra nao gerar loop
    while (digitalRead(botao1) == LOW){}
    if (cont == 5) cont = -1;
  cont++;
  delay(200);
  lcd.clear();
 }
// Se botao2 for pressionado vai para nivel baixo e entra neste if
  if (digitalRead(botao2) == LOW) {
// Esse while garante que se o botao ficar pressionado nada acontece, somente quando for solto pra nao gerar loop
    while (digitalRead(botao2) == LOW){}
    if (cont == 0) cont = 6;
  cont--;
  delay(200);
  lcd.clear();
 }


  
}
// Funçao onde o codigo selecionado é transmitido se pressionado o botao3
void TRANSMITIR(){
 if (digitalRead(botao3) == LOW ) {
  lcd.clear();
    while (digitalRead(botao3) == LOW){
      lcd.setCursor(2,0);
      lcd.print("TRANSMITINDO");
      lcd.setCursor(4,1);
      lcd.print("Codigo");
      lcd.setCursor(11,1);
      lcd.print(cont + 1);

        mySwitch.setProtocol(protocolo1[cont]);
        mySwitch.setPulseLength(length1[cont]);
        mySwitch.send(codigo1[cont], bits1[cont]); //envia sinal
        
        delay (200);
      }
      lcd.clear();

 }
}
// Funçao de configuracao, nessa funçao, no display voce consegue verificar os detalhes dos codigos salvos e edita-los, codigo, bits, lenght e protocolo
// se pressionar o botao3 sera direcionado para a funçao MENU_2 onde sera possivel ver esses detalhes
// e o botao4 para sair 
void CONFIG(){
 if (digitalRead(botao4) == LOW ) {
  detalhes = 1;
  delay(1000);
  while (detalhes == 1){
    MENU_1();
    lcd.setCursor(14,0);
    lcd.print("CF");
    if (digitalRead(botao3) == LOW )MENU_2();
    
    if (digitalRead(botao4) == LOW )detalhes = 0;
  }
  delay(1000);
  lcd.clear();
 }
}
// Funçao onde é possivel verificar no display os detalhes do codigo lido
// neste menu ao pressionar o botao 3 em cima do detalhe que se esta vendo voce consegue edita-lo
// botao4 para sair
// menu de ediçao em desenvolvimento
void MENU_2(){
  bool Ccompleto = 1;
  int cont3 = 0;
  delay(1000);
  lcd.clear();
  while (Ccompleto == 1){
    
    lcd.setCursor(0,0);
    lcd.print("Codigo");
    lcd.setCursor(7,0);
    lcd.print(cont + 1);
    
 if (cont3 == 0){
    lcd.setCursor(0,1);
    lcd.print("Cod");
    lcd.setCursor(5,1); 
    lcd.print(codigo1[cont]);
 }
 if (cont3 == 1){
    lcd.setCursor(0,1);
    lcd.print("bits");
    lcd.setCursor(6,1); 
    lcd.print(bits1[cont]);
 }
  if (cont3 == 2){
    lcd.setCursor(0,1);
    lcd.print("length");
    lcd.setCursor(8,1); 
    lcd.print(length1[cont]);
 }
  if (cont3 == 3){
    lcd.setCursor(0,1);
    lcd.print("protocolo");
    lcd.setCursor(11,1); 
    lcd.print(protocolo1[cont]);
 }
 
 if (digitalRead(botao1) == LOW ) {
    while (digitalRead(botao1) == LOW){}
    if (cont3 == 3) cont3 = -1;
  cont3++;
  delay(200);
  lcd.setCursor(0,1);
  lcd.print("               ");
 }

 if (digitalRead(botao2) == LOW) {
    while (digitalRead(botao2) == LOW){}
    if (cont3 == 0) cont3 = 4;
  cont3--;
  delay(200);
  lcd.setCursor(0,1);
  lcd.print("               ");
 }
 if (digitalRead(botao3) == LOW) {
  bool edit = 1;
  soma = 1;
  soma2 = 1;
  delay(1000);
  lcd.setCursor(9,0);
  lcd.print("EDIT 1");
    while (edit == 1){
    
 if (cont3 == 0){
      if (digitalRead(botao1) == LOW ) {
      while (digitalRead(botao1) == LOW){}
      codigo1[cont] = codigo1[cont] + soma;
      delay(200); 
 }

       if (digitalRead(botao2) == LOW ) {
      while (digitalRead(botao2) == LOW){}
      codigo1[cont] = codigo1[cont] - soma;
      delay(200);  
 }
    CASAS(codigo1[cont],5);
    lcd.setCursor(0,1);
    lcd.print("Cod");
    lcd.setCursor(5,1); 
    lcd.print(codigo1[cont]);
    delay(150);
    lcd.setCursor(fixo-soma2,1);
    lcd.write(B11111111);
    delay(150);
   }
 if (cont3 == 1){
      if (digitalRead(botao1) == LOW ) {
      while (digitalRead(botao1) == LOW){}
      bits1[cont] = bits1[cont] + soma;
      delay(200); 
 }

       if (digitalRead(botao2) == LOW ) {
      while (digitalRead(botao2) == LOW){}
      bits1[cont] = bits1[cont] - soma;
      delay(200);  
 }

    CASAS(bits1[cont],6);
    lcd.setCursor(0,1);
    lcd.print("bits");
    lcd.setCursor(6,1); 
    lcd.print(bits1[cont]);
    delay(150);
    lcd.setCursor(fixo-soma2,1);
    lcd.write(B11111111);
    delay(150);
 }
  if (cont3 == 2){
      if (digitalRead(botao1) == LOW ) {
      while (digitalRead(botao1) == LOW){}
      length1[cont] = length1[cont] + soma;
      delay(200); 
 }

       if (digitalRead(botao2) == LOW ) {
      while (digitalRead(botao2) == LOW){}
      length1[cont] = length1[cont] - soma;
      delay(200);  
 }
    CASAS(length1[cont],8);
    lcd.setCursor(0,1);
    lcd.print("length");
    lcd.setCursor(8,1); 
    lcd.print(length1[cont]);
    delay(150);
    lcd.setCursor(fixo-soma2,1);
    lcd.write(B11111111);
    delay(150);
 }
  if (cont3 == 3){
      if (digitalRead(botao1) == LOW ) {
      while (digitalRead(botao1) == LOW){}
      protocolo1[cont] = protocolo1[cont] + soma;
      delay(200); 
 }

       if (digitalRead(botao2) == LOW ) {
      while (digitalRead(botao2) == LOW){}
      protocolo1[cont] = protocolo1[cont] - soma;
      delay(200);  
 }
    CASAS(protocolo1[cont],11);
    lcd.setCursor(0,1);
    lcd.print("protocolo");
    lcd.setCursor(11,1); 
    lcd.print(protocolo1[cont]);
    delay(150);
    lcd.setCursor(fixo-soma2,1);
    lcd.write(B11111111);
    delay(150);
 }
 if (digitalRead(botao3) == LOW ) {
      while (digitalRead(botao3) == LOW){}
      soma = soma*10;
      soma2 = soma2+1;
      if (soma == 1000000000){
        soma = 1;
        soma2 = 1;
      }
      lcd.setCursor(14,0);
      lcd.print(soma2);
      delay(200);
 }
 if (digitalRead(botao4) == LOW )edit = 0;
 
      }
 delay(1000);
 lcd.clear();
 }
 if (digitalRead(botao4) == LOW )Ccompleto = 0;
  }
  
  delay(1000);
  lcd.clear();
}
// Funçao criada para verificar quantas casas o valor de x tem pra enviar para o menu( em desenvolvimento mas funcional)
void CASAS(unsigned long x,int coluna){
    if (x< 10000000000){
      fixo = coluna + 10;
      if (x< 1000000000){
        fixo = coluna + 9;
        if (x< 100000000){
          fixo = coluna + 8;
          if (x< 10000000){
            fixo = coluna + 7;
            if (x< 1000000){
              fixo = coluna + 6;
              if (x< 100000){
                fixo = coluna + 5;
                if (x< 10000){
                  fixo = coluna + 4;
                  if (x< 1000){
                    fixo = coluna + 3;
                    if (x< 100){
                      fixo = coluna + 2;
                      if (x< 10){
                        fixo = coluna + 1;
                      }
                    }  
                  }
                }      
              } 
            }      
          }
        }      
      }
    }
   }
