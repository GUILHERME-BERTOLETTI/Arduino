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
    
 if (digitalRead(botao1) == LOW ) {
    while (digitalRead(botao1) == LOW){}
    if (cont == 5) cont = -1;
  cont++;
  delay(200);
  lcd.clear();
 }

  if (digitalRead(botao2) == LOW) {
    while (digitalRead(botao2) == LOW){}
    if (cont == 0) cont = 6;
  cont--;
  delay(200);
  lcd.clear();
 }


  
}
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
    lcd.print("Cod             ");
    lcd.setCursor(5,1); 
    lcd.print(codigo1[cont]);
 }
 if (cont3 == 1){
    lcd.setCursor(0,1);
    lcd.print("bits            ");
    lcd.setCursor(6,1); 
    lcd.print(bits1[cont]);
 }
  if (cont3 == 2){
    lcd.setCursor(0,1);
    lcd.print("length          ");
    lcd.setCursor(8,1); 
    lcd.print(length1[cont]);
 }
  if (cont3 == 3){
    lcd.setCursor(0,1);
    lcd.print("protocolo       ");
    lcd.setCursor(11,1); 
    lcd.print(protocolo1[cont]);
 }
 
 if (digitalRead(botao1) == LOW ) {
    while (digitalRead(botao1) == LOW){}
    if (cont3 == 3) cont3 = -1;
  cont3++;
  delay(200);
 }

 if (digitalRead(botao2) == LOW) {
    while (digitalRead(botao2) == LOW){}
    if (cont3 == 0) cont3 = 4;
  cont3--;
  delay(200);
 }
 if (digitalRead(botao3) == LOW) {
  bool edit = 1;
  soma = 1;
  delay(1000);
  lcd.setCursor(12,0);
  lcd.print("EDIT");
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
    lcd.setCursor(0,1);
    lcd.print("Cod             ");
    lcd.setCursor(5,1); 
    lcd.print(codigo1[cont]);

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

    lcd.setCursor(0,1);
    lcd.print("bits            ");
    lcd.setCursor(6,1); 
    lcd.print(bits1[cont]);
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
    lcd.setCursor(0,1);
    lcd.print("length          ");
    lcd.setCursor(8,1); 
    lcd.print(length1[cont]);
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
    lcd.setCursor(0,1);
    lcd.print("protocolo       ");
    lcd.setCursor(11,1); 
    lcd.print(protocolo1[cont]);
 }
 if (digitalRead(botao3) == LOW ) {
      while (digitalRead(botao3) == LOW){}
      soma = soma*10;
      if (soma == 1000000000)soma = 1;
      delay(200);
 }
 if (digitalRead(botao4) == LOW )edit = 0; 
 
      }
 delay(1000);
 }
 if (digitalRead(botao4) == LOW )Ccompleto = 0;
  }
  
  delay(1000);
  lcd.clear();
}
