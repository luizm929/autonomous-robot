void lcdMod(){
   /**************************************************************
   set the cursor to column 0, line 1
   (note: line 1 is the second row, since counting begins with 0): 
   ***************************************************************/
   int distance = chkDistance();
  lcd.setBacklight(LCD_BLUE);
  lcd.setCursor(0,1);
  lcd.print("Dist:");
  lcd.print(distance);
  lcd.print(" cm");
  //I am tryign to print left, right, front distances 
  //but this update will be done in the future.
  lcd.print("  ");
  lcd.setCursor(8,1);
  lcd.print(chkDistance());
  lcd.print("cm");
  //End 
  int currTemp = chkTemp();
  lcd.setCursor(0, 0); //Where in the LCD we want cursor to be.
  // print the number of seconds since reset:
  lcd.print("Temp:");
  lcd.print(currTemp);
  lcd.print("F");
  delay(10); 
}
