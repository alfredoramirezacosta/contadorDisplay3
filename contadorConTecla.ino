int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int p = 9;
int tiempo = 500;
char letra;
int num;
bool iniciado = false;

void cero(){
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
}

void uno(){
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
}

void dos(){
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(e,HIGH);
digitalWrite(d,HIGH);
digitalWrite(g,HIGH);
}

void tres(){
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(g,HIGH);
}

void cuatro(){
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}

void cinco(){
digitalWrite(a,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}

void seis(){
digitalWrite(a,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}

void siete(){
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
}

void ocho(){
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}

void nueve(){
  digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}

void letraA(){
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}

void letraB(){
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}

void letraC(){
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(g,HIGH);
}

void letraD(){
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(g,HIGH);
}

void letraE(){
digitalWrite(a,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}

void letraF(){
digitalWrite(a,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}

void apagarTodo(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(p,LOW);
}

void contador(int num){
  apagarTodo();
  switch (num){
    case 0:
      //0
      cero();
      delay(tiempo);
      break;      
    case 1:
      //1
      uno();
      delay(tiempo);
      break;
    case 2:
      //2
      dos();
      delay(tiempo);
      break;
    case 3:
      //3
      tres();
      delay(tiempo);
      break;
    case 4:
      //4
      cuatro();
      delay(tiempo);
      break;
    case 5:
      //5
      cinco();
      delay(tiempo);
      break;
    case 6:
      //6
      seis();
      delay(tiempo);
      break;
    case 7:
      //7
      siete();
      delay(tiempo);
      break;
    case 8:
      //8
      ocho();
      delay(tiempo);
      break;
    case 9:
      //9
      nueve();
      delay(tiempo);
      break;
    case 10:
      //10
      letraA();
      delay(tiempo);
      break;
    case 11:
      //11
      letraB();
      delay(tiempo);
      break;
    case 12:
      //12
      letraC();
      delay(tiempo);
      break;
    case 13:
      //13
      letraD();
      delay(tiempo);
      break;
    case 14:
      //14
      letraE();
      delay(tiempo);
      break;
    case 15:
      //15
      letraF();
      delay(tiempo);
    break;
  }

}

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode (a, OUTPUT);
pinMode (b, OUTPUT);
pinMode (c, OUTPUT);
pinMode (d, OUTPUT);
pinMode (e, OUTPUT);
pinMode (f, OUTPUT);
pinMode (g, OUTPUT);
pinMode (p, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    if (Serial.available() > 0) {
    // read the incoming byte:
    letra = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(letra, DEC);

  }
    if (iniciado == true){
      if (num >15){
        num = 0;
      }
      contador(num); 
      num += 1;
      Serial.println(num);    
    }
    if (letra == 'a' && iniciado == false){
      Serial.println("Enciendo contador");
      iniciado = true;
      contador(num);
      num +=1;      
    }
    if (letra == 'A'){
      Serial.println("Detengo contador");
      iniciado = false;
    }
}