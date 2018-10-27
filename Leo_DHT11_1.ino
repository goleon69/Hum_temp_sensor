#include <SimpleDHT.h> //library for the humidity and temperature sensor DHT
int pinDHT11 = 3; // need to define the digital pin to connect the single wire transmission, in this case DIG3

bool debug = false; // debug off
SimpleDHT11 dht11; //generate the object

//byte temperature = 0;
//byte humidity = 0;
int err = SimpleDHTErrSuccess;
String errore =""; //string for error check across the libraries

void setup() {
Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
while (!Serial) {
    ;               // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  
byte Temperature = ReadTemperature();
Serial.println (Temperature);

byte Humidity = ReadHumidity();
Serial.println (Humidity);

  if( errore!="") {
  //here the code of the error
  }

}
/*Leo_DHT11-1, 
DHT11 function ver 24-9-2018

Need the :                  
#include <SimpleDHT.h> //library for the humidity and temperature sensor DHT
int pinDHT11 = 3; // need to define the digital pin to connect the single wire transmission, in this case DIG3.
SimpleDHT11 dht11; //generate the object from the class SimpleDHT.
int err = SimpleDHTErrSuccess;  //needed for check
String errore =""; //string for error check across the libraries

Errors :
dht11-01 error is = ????????????

Debug:
bool debug = false; // debug off

if debug = true  will print on the serial print all the data and errors.???????????

 */


byte ReadTemperature(){

byte temp;  //for internal use
  
if ((err = dht11.read(pinDHT11, &temp, NULL, NULL)) != SimpleDHTErrSuccess) {
    errore = "dht11-01";
    if (debug) Serial.print("Read DHT11 failed, err="); 
    if (debug) Serial.println(err);
    return(0); // return to the loop if error accour
    }    
if (debug){ 
  Serial.print("Temp: ");
  Serial.print(temp);
}

delay(1400); // Humidity sensor need 1 sec min refresh

return(temp);
}

byte ReadHumidity(){

byte hum;  //for internal use
  
if ((err = dht11.read(pinDHT11, NULL, &hum, NULL)) != SimpleDHTErrSuccess) {
    errore = "dht11-01";
    if (debug) Serial.print("Read DHT11 failed, err="); 
    if (debug) Serial.println(err);
    return(0); // return to the loop if error accour
    }    
if (debug){ 
  Serial.print("Hum: ");
  Serial.print(hum); 
}

delay(1400); // Humidity sensor need 1 sec min refresh

return(hum);
}

