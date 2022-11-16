const int A = 28;
const int B = 27;
const int C = 26;
const int D = 25;                   // Inicialización de variables para siete segmentos y motor
const int E = 24;
const int F = 23;
const int G = 22;

int IN1 = 9;
int IN2 = 10;
int ENA = 7;
int ultimo;
int sensor = A1;

int n1 = 9;
int n2 = 8;


void cero(){                      //funciones para el display de numeros en el siete segmentos
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void uno(){
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void dos(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}

void tres(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}

void cuatro(){
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void cinco(){
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void seis(){
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void siete(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void ocho(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void nueve(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}


 
void setup (){
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);                         //declaracion del modo de los pines para el  motor, sensor y siete segmentos
pinMode(ENA, OUTPUT);

Serial.begin (9600);


  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);                      
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);
  pinMode(sensor, INPUT);

}

void loop(){
  int value = analogRead(sensor);
  float volts = (value * 5) / 1023.0;
  float celsius = volts * 100;                                      //cálculo de la temperatura actual
  int digito1 = celsius / 10;
  int digito2 = celsius % 10;
 
  if (celsius > 28 and ultimo != 1){                                //subida de la cortina si la cortina está abajo y 
    digitalWrite(ENA, HIGH);                                        //la temperatura supera 28
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    delay(3000);
    digitalWrite(IN1, LOW);
    digitalWrite(ENA, LOW);
    ultimo = 1;
  }

  else if (celsius < 26 and ultimo != 2) {
    digitalWrite(ENA, HIGH);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);                                       //bajada de la cortina si la cortina está arriba y 
    delay(3000);                                                   //la temperatura es inferior a 26
    digitalWrite(IN2, LOW);
    digitalWrite(ENA, LOW);
    ultimo = 2;
  }

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);                                         //apagado del motor
  //Serial.println(celsius);

  digitalWrite(n1, HIGH);
  digitalWrite(n2, LOW);                                          //encendido del primer digito del siete segmentos
  if (digito1 == 0){
    cero();
  }
  if (digito1 == 1){
    uno();
  }
  if (digito1 == 2){
    dos();
  }
  if (digito1 == 3){
    tres();
  }
  if (digito1 == 4){
    cuatro();
  }
  if (digito1 == 5){
    cinco();
  }
  if (digito1 == 6){
    seis();
  }
  if (digito1 == 7){
    siete();
  }
  if (digito1 == 8){
    ocho();
  }
  if (digito1 == 9){
    nueve();
  
  }
    delay(50);
    digitalWrite(n1, LOW);
    digitalWrite(n2, HIGH);                           //encendido del segundo dígito del siete segmentos

  if (digito2 == 0){
    cero();
  }
  if (digito2 == 1){
    uno();
  }
  if (digito2 == 2){
    dos();
  }
  if (digito2 == 3){
    tres();
  }
  if (digito2 == 4){
    cuatro();
  }
  if (digito2 == 5){
    cinco();
  }
  if (digito2 == 6){
    seis();
  }
  if (digito2 == 7){
    siete();
  }
  if (digito2 == 8){
    ocho();
  }
  if (digito2 == 9){
    nueve();
  }
  delay(60);
}



