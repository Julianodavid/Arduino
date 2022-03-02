#include <Adafruit_Sensor.h> //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_BMP280.h> //INCLUSÃO DE BIBLIOTECA

Adafruit_BMP280 bmp; //OBJETO DO TIPO Adafruit_BMP280 (I2C)


int AltitudeIni ;
int AltitudeAut ;
int Resultado ; 
int Resultado2 ;
int Cont = 0 ;


void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
  if(!bmp.begin(0x76)){ //SE O SENSOR NÃO FOR INICIALIZADO NO ENDEREÇO I2C 0x76, FAZ
    Serial.println(F("Sensor BMP280 não foi identificado! Verifique as conexões.")); //IMPRIME O TEXTO NO MONITOR SERIAL
    while(1); //SEMPRE ENTRE NO LOOP

    Serial.println ("JDF AUTOMAÇÃO" 
                    "email jdfautomação@gmail.com" 
                    " Tel. (0359 88565109");
    Serial.println("-----------------------------------"); //IMPRIME UMA LINHA NO MONITOR SERIAL
     delay(500); //INTERVALO DE 2 SEGUNDOS

  }


AltitudeIni =  bmp.readAltitude(1013.25);


  
}

void loop(){


AltitudeAut = bmp.readAltitude(1013.25);

if  (AltitudeAut > AltitudeIni) { 
Cont++;
AltitudeIni = AltitudeAut; 
}

else if (AltitudeAut < AltitudeIni) { 
Cont--;
AltitudeIni = AltitudeAut; 
}

Resultado2 = (Cont * 1000) * 3.28084; 


    Serial.print(F("Temperatura: ")); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.print(bmp.readTemperature()); //IMPRIME NO MONITOR SERIAL A TEMPERATURA
    Serial.println(" *C (Grau Celsius)"); //IMPRIME O TEXTO NO MONITOR SERIAL
    
    Serial.print(F("Pressão: ")); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.print(bmp.readPressure()); //IMPRIME NO MONITOR SERIAL A PRESSÃO
    Serial.println(" Pa (Pascal)"); //IMPRIME O TEXTO NO MONITOR SERIAL

    Serial.print(F("Altitude aprox.: ")); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.print(bmp.readAltitude(1013.25),0); //IMPRIME NO MONITOR SERIAL A ALTITUDE APROXIMADA
    Serial.println(" m (Metros)"); //IMPRIME O TEXTO NO MONITOR SERIAL


    Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    Serial.print(F("Pressure = "));
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.print(F("Approx altitude = "));
    Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
    Serial.println(" m");
   
    Serial.print("Altura em Metros"); 
    Serial.println(Cont);

    Serial.print("Altura em Pés"); 
    Serial.println(Resultado2);
    
    Serial.println("-----------------------------------"); //IMPRIME UMA LINHA NO MONITOR SERIAL
    delay(2000); //INTERVALO DE 2 SEGUNDOS
}
