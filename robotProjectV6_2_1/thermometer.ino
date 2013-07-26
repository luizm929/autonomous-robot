float chkTemp(){
   float Celsius, Farenheit;
   int reading = analogRead(tempSensor);
   /***************************************************************************************************************************
  We do a little math and convert the the reading of the temp sensor into a voltage, which we will turn into a temperature below
  *****************************************************************************************************************************/
   //float voltage = reading*(5000.0/1024.0);
   float voltage = reading * aref_voltage;
   voltage /= 1024.0;
 //  /*We convert the voltage into Celsius and then to Farenheit.
//    It would be better to conver voltage into Faren directly so we do not waste cycles*/  
  //Cels= (voltage-500)/10; //This is more intuitive but rather use one line
  //Faren = Cels*1.8 + 32;
  //Serial.print(voltage); Serial.println(" volts");
 
  // now print out the temperature
  Celsius = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((volatge - 500mV) times 100)
 // Serial.print(Celsius); Serial.println(" degrees C");
 
  // now convert to Fahrenheight
  Farenheit = (Celsius * 9.0 / 5.0) + 32.0;
  //Serial.print(Farenheit); 
  //Serial.println(" degrees F");
//  //Serial.print("Farenheit: "); //DEBUG
//  //Serial.println(Faren);
return Farenheit; 
//delay(100);  
 }

