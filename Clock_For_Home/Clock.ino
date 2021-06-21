void Clock() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; //-> save the last time

    GetDateTime(); //-> Retrieve time and date data from DS1307

    dmd.selectFont(Font_12x5);


    str_hr_24 = String(_hour24);
    str_hr_24.toCharArray(hr_24, 3);
    if (_hour24 < 10) {
      dmd.drawString(2, 2, "0", 1, GRAPHICS_NORMAL);
      dmd.drawString(8, 2, hr_24, 1, GRAPHICS_NORMAL);
    }
    else {
      dmd.drawString(2, 2, hr_24, 2, GRAPHICS_NORMAL);
    }


    if (_second % 2 == 0) {
      dmd.drawFilledBox(15, 4, 16, 5, GRAPHICS_OR);
      dmd.drawFilledBox(15, 10, 16, 11, GRAPHICS_OR);
    }
    else {
      dmd.drawFilledBox(15, 4, 16, 5, GRAPHICS_NOR);
      dmd.drawFilledBox(15, 10, 16, 11, GRAPHICS_NOR);
    }


    str_mn = String(_minute);
    str_mn.toCharArray(mn, 3);

    if (_minute < 10) {
      dmd.drawString(19, 2, "0", 1, GRAPHICS_NORMAL);
      dmd.drawString(25, 2, mn, 1, GRAPHICS_NORMAL);
    }
    else {
      dmd.drawString(19, 2, mn, 2, GRAPHICS_NORMAL);
    }
    dmd.drawFilledBox(0, 0, 31, 0, GRAPHICS_NORMAL);
    dmd.drawFilledBox(0, 0, 0, 16, GRAPHICS_NORMAL);
    dmd.drawFilledBox(0, 15, 31, 15, GRAPHICS_NORMAL);
    dmd.drawFilledBox(31, 0, 31, 15, GRAPHICS_NORMAL);

    if (_second == 10) { //-> Display the date when seconds equal to 11
      if (_hour24 == 10 && _minute <= 10 && hr24 < 12) {
        while (1) {
          drawText1("GOOD MORNING");
          dmd.clearScreen(true);
          delay(0);
          return;
        }
      }
      else if (_hour24 == 2 && _minute <= 10 && hr24 > 12) {
        while (1) {
          drawText1("GOOD AFTERNOON");
          dmd.clearScreen(true);
          delay(0);
          return;
        }
      }
      else if (_hour24 == 7 && _minute <= 10 && hr24 > 12) {
        while (1) {
          drawText1("GOOD EVENING");
          dmd.clearScreen(true);
          delay(0);
          return;
        }
      }
      else if (_hour24 == 10 && _minute <= 10 && hr24 > 12) {
        while (1) {
          drawText1("GOOD NIGHT");
          dmd.clearScreen(true);
          delay(0);
          return;
        }
      }
      else {
        scrolling_date();
      }
    }

  }
}
