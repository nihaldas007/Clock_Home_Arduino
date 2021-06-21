void scrolling_date() {
  dmd.clearScreen(true);
  delay(100);

 
  String Date = String(nameoftheday[_dtw]) + ", " + String(_day) + "-" + String(month_name[_month-1]) + "-" + String(_year);
  char dt[50];
  Date.toCharArray(dt,50);
  int i=32+10;
  int j=strlen(dt)+(strlen(dt)*8); //stay even change on when * value changes
  

  dmd.selectFont(Arial_Black_16);

  while(1) {
    unsigned long currentMillis_for_date = millis();
    if (currentMillis_for_date - previousMillis_for_date >= interval_for_date) {
      previousMillis_for_date = currentMillis_for_date; //-> save the last time 
      
      i--;
      dmd.drawString(i, 0, dt, strlen(dt), GRAPHICS_NORMAL);
      if (i<=~j) {
        dmd.clearScreen(true);
        delay(100);
        return;
      }
    }
    
  }
}
void drawText1( String dispString ) {
  dmd.clearScreen( true );
  dmd.selectFont(Arial_Black_16);
  char newString[256];
  int sLength = dispString.length();
  dispString.toCharArray( newString, sLength + 1 );
  dmd.drawMarquee( newString , sLength , ( 32 * DISPLAYS_ACROSS ) - 1 , 1);
  long start = millis();
  long timer = start;
  long timer2 = start;
  boolean ret = false;
  while ( !ret ) {
    if ( ( timer + timeScroll ) < millis() )
    {
      ret = dmd.stepMarquee( -1 , 0 );
      timer = millis();
    }
  }
}
