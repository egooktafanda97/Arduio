String inputString = "";
boolean stringComplete = false;
int sensorLDR = A1;
int sensorLDR2 = A0;
String Sensor = "";
int swt1 = 0;
int swt2 = 0;

int S1nilaiLdr1 = 90;
int S1nilaiLdr2 = 900;

int S2nilaiLdr1 = 110;
int S2nilaiLdr2 = 900;

int nilaiLdr1 = 0;
int nilaiLdr2 = 0;
boolean setNilai = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  inputString.reserve(200);
}

void loop() {
  String data="";
  int nilaiSensor;
  int nilaiSensor2;
  nilaiSensor = analogRead(sensorLDR);
  nilaiSensor2 = analogRead(sensorLDR2);


//  Serial.print("Serial1 = ");
//  Serial.print(nilaiSensor2);
//  Serial.print("nilai ubah = ");
//  Serial.print(nilaiLdr2);
//  Serial.print("\n");
//  delay(1000);
  
 
//          Serial.print("Serial1 = ");
//  Serial.print(nilaiSensor);
//  Serial.print("nilai ubah = ");
//  Serial.print(nilaiLdr1);
//  Serial.print("\n");
//  delay(1000);
  // put your main code here, to run repeatedly:
  if(inputString != ""){
     if(setNilai == false){
          nilaiLdr1 = nilaiSensor + 50;
          nilaiLdr2 = nilaiSensor2 + 100;
          setNilai = true;
        }

    if(stringComplete == true && inputString == "true"){
      // ------------------------------------------------------
      if(nilaiSensor > nilaiLdr1 && !nilaiSensor < nilaiLdr1 && swt1 == 0 && swt2 == 0){
      
        nilaiLdr2 = nilaiSensor2 + 100;
        
        data = "Kanan";
        Serial.print(data);
        Serial.print("\n");
        swt1 = 1;
        digitalWrite(7, HIGH);
        data = "";
      }else if(nilaiSensor2 > nilaiLdr2 && !nilaiSensor2 < nilaiLdr2 && swt2 == 0 && swt1 == 0){
        nilaiLdr1 = nilaiSensor + 100;
        data = "Kiri";
        Serial.print(data);
        Serial.print("\n");
        swt2 = 1;
        digitalWrite(7, HIGH);
        data = "";
      }

      
      if(nilaiSensor2 > nilaiLdr2 && !nilaiSensor2 < nilaiLdr2 && swt1 == 1){
        if(data == ""){
          data = "Kiri";
           Serial.print(data);
           Serial.print("\n");
           digitalWrite(7, LOW);
           inputString = "";
           data = "";
           swt1 = 0;
           stringComplete = false;
        }  
      }
      
      
      
      if(nilaiSensor > nilaiLdr1 && !nilaiSensor < nilaiLdr1&& swt2 == 1){
        
        if(data == ""){
           data = "Kanan";
           Serial.print(data);
           Serial.print("\n");
           digitalWrite(7, LOW);
           inputString = "";
           data = "";
           swt2 = 0;
           stringComplete = false;
        }  
      }


     }
   }
}


void serialEvent(){
  while(Serial.available()){
    char inChar = (char)Serial.read();
      inputString += inChar;
        if(inChar == '\n'){
          inputString = "true";
          stringComplete = true;
        }
  }
}


