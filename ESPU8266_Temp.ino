//This code uses the TMP36 to get tempature 
//sources used: 
//https://tttapa.github.io/ESP8266/Chap04%20-%20Microcontroller.html
//https://learn.adafruit.com/tmp36-temperature-sensor
//
int sensorPin = 0; //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade with a
                        //500 mV offset to allow for negative temperatures
 

void setup()
{// starts the serial connection on the computer 
  // this can be on any port number it is not important
  Serial.begin(9600);  
}

 //runs over and over again
void loop()
{
 //getting the voltage reading from the temperature sensor
 int reading = analogRead(sensorPin);
   
 //gets the volatge
 //the volatge of the circuit is 3.3 v i the analog reads it it will ether be 1 0r 0
//1023 = 1v 0 =0v 
 float volatge = (3.3*reading)/1023.0;

 // the conversion is volatge to C
 //https://learn.adafruit.com/tmp36-temperature-sensor
 float tempatureC = (volatge-500)/10;
 //Prints the tempature in C
 Serial.print(tempatureC); Serial.println(" degrees C");
 //converts the tempature from C to F
 float tempatureF = (tempatureC*9.0/5.0)+32.0;
 //prints out the tempature
 Serial.print(tempatureF);Serial.println("degress in f");
 //delays the loop by 1 second
 delay(1000);
 
 
}
