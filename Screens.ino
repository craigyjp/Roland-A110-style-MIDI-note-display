/*
   Module for the OLED screens

   this module is about controlling the OLED screens via a TCA9548A

*/



void setupScreens() {

  display1.begin(SSD1306_SWITCHCAPVCC);
  display1.clearDisplay();
  display1.display();
  display2.begin(SSD1306_SWITCHCAPVCC);
  display2.clearDisplay();
  display2.display();
  display3.begin(SSD1306_SWITCHCAPVCC);
  display3.clearDisplay();
  display3.display();
  display4.begin(SSD1306_SWITCHCAPVCC);
  display4.clearDisplay();
  display4.display();
  display5.begin(SSD1306_SWITCHCAPVCC);
  display5.clearDisplay();
  display5.display();
  display6.begin(SSD1306_SWITCHCAPVCC);
  display6.clearDisplay();
  display6.display();
  display7.begin(SSD1306_SWITCHCAPVCC);
  display7.clearDisplay();
  display7.display();
  display8.begin(SSD1306_SWITCHCAPVCC);
  display8.clearDisplay();
  display8.display();
  display9.begin(SSD1306_SWITCHCAPVCC);
  display9.clearDisplay();
  display9.display();
  display10.begin(SSD1306_SWITCHCAPVCC);
  display10.clearDisplay();
  display10.display();
}


void splashScreens() {

  delay(100);

  display1.drawRect(5, 32, 11, 28, SSD1306_WHITE);
  display1.drawRect(23, 32, 11, 28, SSD1306_WHITE);
  display1.drawRect(41, 32, 11, 28, SSD1306_WHITE);
  display1.drawRect(59, 32, 11, 28, SSD1306_WHITE);
  display1.drawRect(77, 32, 11, 28, SSD1306_WHITE);
  display1.drawRect(95, 32, 11, 28, SSD1306_WHITE);
  display1.drawRect(112, 32, 11, 28, SSD1306_WHITE);

  display1.drawRect(14, 0, 11, 28, SSD1306_WHITE);
  display1.drawRect(33, 0, 11, 28, SSD1306_WHITE);
  display1.drawRect(67, 0, 11, 28, SSD1306_WHITE);
  display1.drawRect(85, 0, 11, 28, SSD1306_WHITE);
  display1.drawRect(105, 0, 11, 28, SSD1306_WHITE);

  display1.drawLine(0, 63, 127, 63, SSD1306_WHITE);
  display1.drawLine(0, 0, 0, 63, SSD1306_WHITE);
  display1.drawLine(127, 0, 127, 63, SSD1306_WHITE);
  display1.drawLine(55, 0, 55, 63, SSD1306_WHITE);

  display1.drawLine(19, 30, 19, 63, SSD1306_WHITE);
  display1.drawLine(37, 30, 37, 63, SSD1306_WHITE);
  display1.drawLine(73, 30, 73, 63, SSD1306_WHITE);
  display1.drawLine(91, 30, 91, 63, SSD1306_WHITE);
  display1.drawLine(109, 30, 109, 63, SSD1306_WHITE);
  display1.display();

  display2.drawRect(5, 32, 11, 28, SSD1306_WHITE);
  display2.drawRect(23, 32, 11, 28, SSD1306_WHITE);
  display2.drawRect(41, 32, 11, 28, SSD1306_WHITE);
  display2.drawRect(59, 32, 11, 28, SSD1306_WHITE);
  display2.drawRect(77, 32, 11, 28, SSD1306_WHITE);
  display2.drawRect(95, 32, 11, 28, SSD1306_WHITE);
  display2.drawRect(112, 32, 11, 28, SSD1306_WHITE);

  display2.drawRect(14, 0, 11, 28, SSD1306_WHITE);
  display2.drawRect(33, 0, 11, 28, SSD1306_WHITE);
  display2.drawRect(67, 0, 11, 28, SSD1306_WHITE);
  display2.drawRect(85, 0, 11, 28, SSD1306_WHITE);
  display2.drawRect(105, 0, 11, 28, SSD1306_WHITE);

  display2.drawLine(0, 63, 127, 63, SSD1306_WHITE);
  display2.drawLine(0, 0, 0, 63, SSD1306_WHITE);
  display2.drawLine(127, 0, 127, 63, SSD1306_WHITE);
  display2.drawLine(55, 0, 55, 63, SSD1306_WHITE);

  display2.drawLine(19, 30, 19, 63, SSD1306_WHITE);
  display2.drawLine(37, 30, 37, 63, SSD1306_WHITE);
  display2.drawLine(73, 30, 73, 63, SSD1306_WHITE);
  display2.drawLine(91, 30, 91, 63, SSD1306_WHITE);
  display2.drawLine(109, 30, 109, 63, SSD1306_WHITE);
  display2.display();

  display3.drawRect(5, 32, 11, 28, SSD1306_WHITE);
  display3.drawRect(23, 32, 11, 28, SSD1306_WHITE);
  display3.drawRect(41, 32, 11, 28, SSD1306_WHITE);
  display3.drawRect(59, 32, 11, 28, SSD1306_WHITE);
  display3.drawRect(77, 32, 11, 28, SSD1306_WHITE);
  display3.drawRect(95, 32, 11, 28, SSD1306_WHITE);
  display3.drawRect(112, 32, 11, 28, SSD1306_WHITE);

  display3.drawRect(14, 0, 11, 28, SSD1306_WHITE);
  display3.drawRect(33, 0, 11, 28, SSD1306_WHITE);
  display3.drawRect(67, 0, 11, 28, SSD1306_WHITE);
  display3.drawRect(85, 0, 11, 28, SSD1306_WHITE);
  display3.drawRect(105, 0, 11, 28, SSD1306_WHITE);

  display3.drawLine(0, 63, 127, 63, SSD1306_WHITE);
  display3.drawLine(0, 0, 0, 63, SSD1306_WHITE);
  display3.drawLine(127, 0, 127, 63, SSD1306_WHITE);
  display3.drawLine(55, 0, 55, 63, SSD1306_WHITE);

  display3.drawLine(19, 30, 19, 63, SSD1306_WHITE);
  display3.drawLine(37, 30, 37, 63, SSD1306_WHITE);
  display3.drawLine(73, 30, 73, 63, SSD1306_WHITE);
  display3.drawLine(91, 30, 91, 63, SSD1306_WHITE);
  display3.drawLine(109, 30, 109, 63, SSD1306_WHITE);
  display3.display();

  display4.drawRect(5, 32, 11, 28, SSD1306_WHITE);
  display4.drawRect(23, 32, 11, 28, SSD1306_WHITE);
  display4.drawRect(41, 32, 11, 28, SSD1306_WHITE);
  display4.drawRect(59, 32, 11, 28, SSD1306_WHITE);
  display4.drawRect(77, 32, 11, 28, SSD1306_WHITE);
  display4.drawRect(95, 32, 11, 28, SSD1306_WHITE);
  display4.drawRect(112, 32, 11, 28, SSD1306_WHITE);

  display4.drawRect(14, 0, 11, 28, SSD1306_WHITE);
  display4.drawRect(33, 0, 11, 28, SSD1306_WHITE);
  display4.drawRect(67, 0, 11, 28, SSD1306_WHITE);
  display4.drawRect(85, 0, 11, 28, SSD1306_WHITE);
  display4.drawRect(105, 0, 11, 28, SSD1306_WHITE);

  display4.drawLine(0, 63, 127, 63, SSD1306_WHITE);
  display4.drawLine(0, 0, 0, 63, SSD1306_WHITE);
  display4.drawLine(127, 0, 127, 63, SSD1306_WHITE);
  display4.drawLine(55, 0, 55, 63, SSD1306_WHITE);

  display4.drawLine(19, 30, 19, 63, SSD1306_WHITE);
  display4.drawLine(37, 30, 37, 63, SSD1306_WHITE);
  display4.drawLine(73, 30, 73, 63, SSD1306_WHITE);
  display4.drawLine(91, 30, 91, 63, SSD1306_WHITE);
  display4.drawLine(109, 30, 109, 63, SSD1306_WHITE);
  display4.display();

  display5.drawRect(5, 32, 11, 28, SSD1306_WHITE);
  display5.drawRect(23, 32, 11, 28, SSD1306_WHITE);
  display5.drawRect(41, 32, 11, 28, SSD1306_WHITE);
  display5.drawRect(59, 32, 11, 28, SSD1306_WHITE);
  display5.drawRect(77, 32, 11, 28, SSD1306_WHITE);
  display5.drawRect(95, 32, 11, 28, SSD1306_WHITE);
  display5.drawRect(112, 32, 11, 28, SSD1306_WHITE);

  display5.drawRect(14, 0, 11, 28, SSD1306_WHITE);
  display5.drawRect(33, 0, 11, 28, SSD1306_WHITE);
  display5.drawRect(67, 0, 11, 28, SSD1306_WHITE);
  display5.drawRect(85, 0, 11, 28, SSD1306_WHITE);
  display5.drawRect(105, 0, 11, 28, SSD1306_WHITE);

  display5.drawLine(0, 63, 127, 63, SSD1306_WHITE);
  display5.drawLine(0, 0, 0, 63, SSD1306_WHITE);
  display5.drawLine(127, 0, 127, 63, SSD1306_WHITE);
  display5.drawLine(55, 0, 55, 63, SSD1306_WHITE);

  display5.drawLine(19, 30, 19, 63, SSD1306_WHITE);
  display5.drawLine(37, 30, 37, 63, SSD1306_WHITE);
  display5.drawLine(73, 30, 73, 63, SSD1306_WHITE);
  display5.drawLine(91, 30, 91, 63, SSD1306_WHITE);
  display5.drawLine(109, 30, 109, 63, SSD1306_WHITE);
  display5.display();

  display6.drawRect(5, 32, 11, 28, SSD1306_WHITE);
  display6.drawRect(23, 32, 11, 28, SSD1306_WHITE);
  display6.drawRect(41, 32, 11, 28, SSD1306_WHITE);
  display6.drawRect(59, 32, 11, 28, SSD1306_WHITE);
  display6.drawRect(77, 32, 11, 28, SSD1306_WHITE);
  display6.drawRect(95, 32, 11, 28, SSD1306_WHITE);
  display6.drawRect(112, 32, 11, 28, SSD1306_WHITE);

  display6.drawRect(14, 0, 11, 28, SSD1306_WHITE);
  display6.drawRect(33, 0, 11, 28, SSD1306_WHITE);
  display6.drawRect(67, 0, 11, 28, SSD1306_WHITE);
  display6.drawRect(85, 0, 11, 28, SSD1306_WHITE);
  display6.drawRect(105, 0, 11, 28, SSD1306_WHITE);

  display6.drawLine(0, 63, 127, 63, SSD1306_WHITE);
  display6.drawLine(0, 0, 0, 63, SSD1306_WHITE);
  display6.drawLine(127, 0, 127, 63, SSD1306_WHITE);
  display6.drawLine(55, 0, 55, 63, SSD1306_WHITE);

  display6.drawLine(19, 30, 19, 63, SSD1306_WHITE);
  display6.drawLine(37, 30, 37, 63, SSD1306_WHITE);
  display6.drawLine(73, 30, 73, 63, SSD1306_WHITE);
  display6.drawLine(91, 30, 91, 63, SSD1306_WHITE);
  display6.drawLine(109, 30, 109, 63, SSD1306_WHITE);
  display6.display();

  display7.drawRect(5, 32, 11, 28, SSD1306_WHITE);
  display7.drawRect(23, 32, 11, 28, SSD1306_WHITE);
  display7.drawRect(41, 32, 11, 28, SSD1306_WHITE);
  display7.drawRect(59, 32, 11, 28, SSD1306_WHITE);
  display7.drawRect(77, 32, 11, 28, SSD1306_WHITE);
  display7.drawRect(95, 32, 11, 28, SSD1306_WHITE);
  display7.drawRect(112, 32, 11, 28, SSD1306_WHITE);

  display7.drawRect(14, 0, 11, 28, SSD1306_WHITE);
  display7.drawRect(33, 0, 11, 28, SSD1306_WHITE);
  display7.drawRect(67, 0, 11, 28, SSD1306_WHITE);
  display7.drawRect(85, 0, 11, 28, SSD1306_WHITE);
  display7.drawRect(105, 0, 11, 28, SSD1306_WHITE);

  display7.drawLine(0, 63, 127, 63, SSD1306_WHITE);
  display7.drawLine(0, 0, 0, 63, SSD1306_WHITE);
  display7.drawLine(127, 0, 127, 63, SSD1306_WHITE);
  display7.drawLine(55, 0, 55, 63, SSD1306_WHITE);

  display7.drawLine(19, 30, 19, 63, SSD1306_WHITE);
  display7.drawLine(37, 30, 37, 63, SSD1306_WHITE);
  display7.drawLine(73, 30, 73, 63, SSD1306_WHITE);
  display7.drawLine(91, 30, 91, 63, SSD1306_WHITE);
  display7.drawLine(109, 30, 109, 63, SSD1306_WHITE);
  display7.display();

  display8.drawRect(5, 32, 11, 28, SSD1306_WHITE);
  display8.drawRect(23, 32, 11, 28, SSD1306_WHITE);
  display8.drawRect(41, 32, 11, 28, SSD1306_WHITE);
  display8.drawRect(59, 32, 11, 28, SSD1306_WHITE);
  display8.drawRect(77, 32, 11, 28, SSD1306_WHITE);
  display8.drawRect(95, 32, 11, 28, SSD1306_WHITE);
  display8.drawRect(112, 32, 11, 28, SSD1306_WHITE);

  display8.drawRect(14, 0, 11, 28, SSD1306_WHITE);
  display8.drawRect(33, 0, 11, 28, SSD1306_WHITE);
  display8.drawRect(67, 0, 11, 28, SSD1306_WHITE);
  display8.drawRect(85, 0, 11, 28, SSD1306_WHITE);
  display8.drawRect(105, 0, 11, 28, SSD1306_WHITE);

  display8.drawLine(0, 63, 127, 63, SSD1306_WHITE);
  display8.drawLine(0, 0, 0, 63, SSD1306_WHITE);
  display8.drawLine(127, 0, 127, 63, SSD1306_WHITE);
  display8.drawLine(55, 0, 55, 63, SSD1306_WHITE);

  display8.drawLine(19, 30, 19, 63, SSD1306_WHITE);
  display8.drawLine(37, 30, 37, 63, SSD1306_WHITE);
  display8.drawLine(73, 30, 73, 63, SSD1306_WHITE);
  display8.drawLine(91, 30, 91, 63, SSD1306_WHITE);
  display8.drawLine(109, 30, 109, 63, SSD1306_WHITE);
  display8.display();

  display9.drawRect(5, 32, 11, 28, SSD1306_WHITE);
  display9.drawRect(23, 32, 11, 28, SSD1306_WHITE);
  display9.drawRect(41, 32, 11, 28, SSD1306_WHITE);
  display9.drawRect(59, 32, 11, 28, SSD1306_WHITE);
  display9.drawRect(77, 32, 11, 28, SSD1306_WHITE);
  display9.drawRect(95, 32, 11, 28, SSD1306_WHITE);
  display9.drawRect(112, 32, 11, 28, SSD1306_WHITE);

  display9.drawRect(14, 0, 11, 28, SSD1306_WHITE);
  display9.drawRect(33, 0, 11, 28, SSD1306_WHITE);
  display9.drawRect(67, 0, 11, 28, SSD1306_WHITE);
  display9.drawRect(85, 0, 11, 28, SSD1306_WHITE);
  display9.drawRect(105, 0, 11, 28, SSD1306_WHITE);

  display9.drawLine(0, 63, 127, 63, SSD1306_WHITE);
  display9.drawLine(0, 0, 0, 63, SSD1306_WHITE);
  display9.drawLine(127, 0, 127, 63, SSD1306_WHITE);
  display9.drawLine(55, 0, 55, 63, SSD1306_WHITE);

  display9.drawLine(19, 30, 19, 63, SSD1306_WHITE);
  display9.drawLine(37, 30, 37, 63, SSD1306_WHITE);
  display9.drawLine(73, 30, 73, 63, SSD1306_WHITE);
  display9.drawLine(91, 30, 91, 63, SSD1306_WHITE);
  display9.drawLine(109, 30, 109, 63, SSD1306_WHITE);
  display9.display();

  display10.drawRect(5, 32, 11, 28, SSD1306_WHITE);
  display10.drawRect(23, 32, 11, 28, SSD1306_WHITE);
  display10.drawRect(41, 32, 11, 28, SSD1306_WHITE);
  display10.drawRect(59, 32, 11, 28, SSD1306_WHITE);
  display10.drawRect(77, 32, 11, 28, SSD1306_WHITE);
  display10.drawRect(95, 32, 11, 28, SSD1306_WHITE);
  display10.drawRect(112, 32, 11, 28, SSD1306_WHITE);

  display10.drawRect(14, 0, 11, 28, SSD1306_WHITE);
  display10.drawRect(33, 0, 11, 28, SSD1306_WHITE);
  display10.drawRect(67, 0, 11, 28, SSD1306_WHITE);
  display10.drawRect(85, 0, 11, 28, SSD1306_WHITE);
  display10.drawRect(105, 0, 11, 28, SSD1306_WHITE);

  display10.drawLine(0, 63, 127, 63, SSD1306_WHITE);
  display10.drawLine(0, 0, 0, 63, SSD1306_WHITE);
  display10.drawLine(127, 0, 127, 63, SSD1306_WHITE);
  display10.drawLine(55, 0, 55, 63, SSD1306_WHITE);

  display10.drawLine(19, 30, 19, 63, SSD1306_WHITE);
  display10.drawLine(37, 30, 37, 63, SSD1306_WHITE);
  display10.drawLine(73, 30, 73, 63, SSD1306_WHITE);
  display10.drawLine(91, 30, 91, 63, SSD1306_WHITE);
  display10.drawLine(109, 30, 109, 63, SSD1306_WHITE);
  display10.display();
}

void initScreens() {
  //Nothing to do: initialization of screens is nothing at the moment
}

void clearScreen(uint8_t screen) {
  display1.clearDisplay();
  display1.display();
  display2.clearDisplay();
  display2.display();
  display3.clearDisplay();
  display3.display();
  display4.clearDisplay();
  display4.display();
  display5.clearDisplay();
  display5.display();
  display6.clearDisplay();
  display6.display();
  display7.clearDisplay();
  display7.display();
  display8.clearDisplay();
  display8.display();
  display9.clearDisplay();
  display9.display();
  display10.clearDisplay();
  display10.display();
}


void display_note(int note, uint8_t screen)
{
  switch (screen)
  {
    case 0:
      switch (note)
      {
        case 0:
          display1.fillRect(6, 33, 9, 26, SSD1306_WHITE);
          display1.display();
          break;
        case 1:
          display1.fillRect(15, 1, 9, 26, SSD1306_WHITE);
          display1.display();
          break;
        case 2:
          display1.fillRect(24, 33, 9, 26, SSD1306_WHITE);
          display1.display();
          break;
        case 3:
          display1.fillRect(34, 1, 9, 26, SSD1306_WHITE);
          display1.display();
          break;
        case 4:
          display1.fillRect(42, 33, 9, 26, SSD1306_WHITE);
          display1.display();
        case 5:
          display1.fillRect(60, 33, 9, 26, SSD1306_WHITE);
          display1.display();
          break;
        case 6:
          display1.fillRect(68, 1, 9, 26, SSD1306_WHITE);
          display1.display();
          break;
        case 7:
          display1.fillRect(78, 33, 9, 26, SSD1306_WHITE);
          display1.display();
          break;
        case 8:
          display1.fillRect(86, 1, 9, 26, SSD1306_WHITE);
          display1.display();
          break;
        case 9:
          display1.fillRect(96, 33, 9, 26, SSD1306_WHITE);
          display1.display();
          break;
        case 10:
          display1.fillRect(106, 1, 9, 26, SSD1306_WHITE);
          display1.display();
          break;
        case 11:
          display1.fillRect(113, 33, 9, 26, SSD1306_WHITE);
          display1.display();
          break;
      }
      break;

    case 1:
      switch (note)
      {
        case 0:
          display2.fillRect(6, 33, 9, 26, SSD1306_WHITE);
          display2.display();;
          break;
        case 1:
          display2.fillRect(15, 1, 9, 26, SSD1306_WHITE);
          display2.display();
          break;
        case 2:
          display2.fillRect(24, 33, 9, 26, SSD1306_WHITE);
          display2.display();
          break;
        case 3:
          display2.fillRect(34, 1, 9, 26, SSD1306_WHITE);
          display2.display();
          break;
        case 4:
          display2.fillRect(42, 33, 9, 26, SSD1306_WHITE);
          display2.display();
          break;
        case 5:
          display2.fillRect(60, 33, 9, 26, SSD1306_WHITE);
          display2.display();
          break;
        case 6:
          display2.fillRect(68, 1, 9, 26, SSD1306_WHITE);
          display2.display();
          break;
        case 7:
          display2.fillRect(78, 33, 9, 26, SSD1306_WHITE);
          display2.display();
          break;
        case 8:
          display2.fillRect(86, 1, 9, 26, SSD1306_WHITE);
          display2.display();
          break;
        case 9:
          display2.fillRect(96, 33, 9, 26, SSD1306_WHITE);
          display2.display();
          break;
        case 10:
          display2.fillRect(106, 1, 9, 26, SSD1306_WHITE);
          display2.display();
          break;
        case 11:
          display2.fillRect(113, 33, 9, 26, SSD1306_WHITE);
          display2.display();
          break;
      }
      break;
    case 2:
      switch (note)
      {
        case 0:
          display3.fillRect(6, 33, 9, 26, SSD1306_WHITE);
          display3.display();
          break;
        case 1:
          display3.fillRect(15, 1, 9, 26, SSD1306_WHITE);
          display3.display();
          break;
        case 2:
          display3.fillRect(24, 33, 9, 26, SSD1306_WHITE);
          display3.display();
          break;
        case 3:
          display3.fillRect(34, 1, 9, 26, SSD1306_WHITE);
          display3.display();
          break;
        case 4:
          display3.fillRect(42, 33, 9, 26, SSD1306_WHITE);
          display3.display();
          break;
        case 5:
          display3.fillRect(60, 33, 9, 26, SSD1306_WHITE);
          display3.display();
          break;
        case 6:
          display3.fillRect(68, 1, 9, 26, SSD1306_WHITE);
          display3.display();
          break;
        case 7:
          display3.fillRect(78, 33, 9, 26, SSD1306_WHITE);
          display3.display();
          break;
        case 8:
          display3.fillRect(86, 1, 9, 26, SSD1306_WHITE);
          display3.display();
          break;
        case 9:
          display3.fillRect(96, 33, 9, 26, SSD1306_WHITE);
          display3.display();
          break;
        case 10:
          display3.fillRect(106, 1, 9, 26, SSD1306_WHITE);
          display3.display();
          break;
        case 11:
          display3.fillRect(113, 33, 9, 26, SSD1306_WHITE);
          display3.display();
          break;
      }
      break;

    case 3:
      switch (note)
      {
        case 0:
          display4.fillRect(6, 33, 9, 26, SSD1306_WHITE);
          display4.display();
          break;
        case 1:
          display4.fillRect(15, 1, 9, 26, SSD1306_WHITE);
          display4.display();
          break;
        case 2:
          display4.fillRect(24, 33, 9, 26, SSD1306_WHITE);
          display4.display();
          break;
        case 3:
          display4.fillRect(34, 1, 9, 26, SSD1306_WHITE);
          display4.display();
          break;
        case 4:
          display4.fillRect(42, 33, 9, 26, SSD1306_WHITE);
          display4.display();
          break;
        case 5:
          display4.fillRect(60, 33, 9, 26, SSD1306_WHITE);
          display4.display();
          break;
        case 6:
          display4.fillRect(68, 1, 9, 26, SSD1306_WHITE);
          display4.display();
          break;
        case 7:
          display4.fillRect(78, 33, 9, 26, SSD1306_WHITE);
          display4.display();
          break;
        case 8:
          display4.fillRect(86, 1, 9, 26, SSD1306_WHITE);
          display4.display();
          break;
        case 9:
          display4.fillRect(96, 33, 9, 26, SSD1306_WHITE);
          display4.display();
          break;
        case 10:
          display4.fillRect(106, 1, 9, 26, SSD1306_WHITE);
          display4.display();
          break;
        case 11:
          display4.fillRect(113, 33, 9, 26, SSD1306_WHITE);
          display4.display();
          break;
      }
      break;

    case 4:
      switch (note)
      {
        case 0:
          display5.fillRect(6, 33, 9, 26, SSD1306_WHITE);
          display5.display();
          break;
        case 1:
          display5.fillRect(15, 1, 9, 26, SSD1306_WHITE);
          display5.display();
          break;
        case 2:
          display5.fillRect(24, 33, 9, 26, SSD1306_WHITE);
          display5.display();
          break;
        case 3:
          display5.fillRect(34, 1, 9, 26, SSD1306_WHITE);
          display5.display();
          break;
        case 4:
          display5.fillRect(42, 33, 9, 26, SSD1306_WHITE);
          display5.display();
          break;
        case 5:
          display5.fillRect(60, 33, 9, 26, SSD1306_WHITE);
          display5.display();
          break;
        case 6:
          display5.fillRect(68, 1, 9, 26, SSD1306_WHITE);
          display5.display();
          break;
        case 7:
          display5.fillRect(78, 33, 9, 26, SSD1306_WHITE);
          display5.display();
          break;
        case 8:
          display5.fillRect(86, 1, 9, 26, SSD1306_WHITE);
          display5.display();
          break;
        case 9:
          display5.fillRect(96, 33, 9, 26, SSD1306_WHITE);
          display5.display();
          break;
        case 10:
          display5.fillRect(106, 1, 9, 26, SSD1306_WHITE);
          display5.display();
          break;
        case 11:
          display5.fillRect(113, 33, 9, 26, SSD1306_WHITE);
          display5.display();
          break;
      }
      break;

    case 5:
      switch (note)
      {
        case 0:
          display6.fillRect(6, 33, 9, 26, SSD1306_WHITE);
          display6.display();
          break;
        case 1:
          display6.fillRect(15, 1, 9, 26, SSD1306_WHITE);
          display6.display();
          break;
        case 2:
          display6.fillRect(24, 33, 9, 26, SSD1306_WHITE);
          display6.display();
          break;
        case 3:
          display6.fillRect(34, 1, 9, 26, SSD1306_WHITE);
          display6.display();
          break;
        case 4:
          display6.fillRect(42, 33, 9, 26, SSD1306_WHITE);
          display6.display();
          break;
        case 5:
          display6.fillRect(60, 33, 9, 26, SSD1306_WHITE);
          display6.display();
          break;
        case 6:
          display6.fillRect(68, 1, 9, 26, SSD1306_WHITE);
          display6.display();
          break;
        case 7:
          display6.fillRect(78, 33, 9, 26, SSD1306_WHITE);
          display6.display();
          break;
        case 8:
          display6.fillRect(86, 1, 9, 26, SSD1306_WHITE);
          display6.display();
          break;
        case 9:
          display6.fillRect(96, 33, 9, 26, SSD1306_WHITE);
          display6.display();
          break;
        case 10:
          display6.fillRect(106, 1, 9, 26, SSD1306_WHITE);
          display6.display();
          break;
        case 11:
          display6.fillRect(113, 33, 9, 26, SSD1306_WHITE);
          display6.display();
          break;
      }
      break;

    case 6:
      switch (note)
      {
        case 0:
          display7.fillRect(6, 33, 9, 26, SSD1306_WHITE);
          display7.display();
          break;
        case 1:
          display7.fillRect(15, 1, 9, 26, SSD1306_WHITE);
          display7.display();
          break;
        case 2:
          display7.fillRect(24, 33, 9, 26, SSD1306_WHITE);
          display7.display();
          break;
        case 3:
          display7.fillRect(34, 1, 9, 26, SSD1306_WHITE);
          display7.display();
          break;
        case 4:
          display7.fillRect(42, 33, 9, 26, SSD1306_WHITE);
          display7.display();
          break;
        case 5:
          display7.fillRect(60, 33, 9, 26, SSD1306_WHITE);
          display7.display();
          break;
        case 6:
          display7.fillRect(68, 1, 9, 26, SSD1306_WHITE);
          display7.display();
          break;
        case 7:
          display7.fillRect(78, 33, 9, 26, SSD1306_WHITE);
          display7.display();
          break;
        case 8:
          display7.fillRect(86, 1, 9, 26, SSD1306_WHITE);
          display7.display();
          break;
        case 9:
          display7.fillRect(96, 33, 9, 26, SSD1306_WHITE);
          display7.display();
          break;
        case 10:
          display7.fillRect(106, 1, 9, 26, SSD1306_WHITE);
          display7.display();
          break;
        case 11:
          display7.fillRect(113, 33, 9, 26, SSD1306_WHITE);
          display7.display();
          break;
      }
      break;

    case 7:
      switch (note)
      {
        case 0:
          display8.fillRect(6, 33, 9, 26, SSD1306_WHITE);
          display8.display();
          break;
        case 1:
          display8.fillRect(15, 1, 9, 26, SSD1306_WHITE);
          display8.display();
          break;
        case 2:
          display8.fillRect(24, 33, 9, 26, SSD1306_WHITE);
          display8.display();
          break;
        case 3:
          display8.fillRect(34, 1, 9, 26, SSD1306_WHITE);
          display8.display();
          break;
        case 4:
          display8.fillRect(42, 33, 9, 26, SSD1306_WHITE);
          display8.display();
          break;
        case 5:
          display8.fillRect(60, 33, 9, 26, SSD1306_WHITE);
          display8.display();
          break;
        case 6:
          display8.fillRect(68, 1, 9, 26, SSD1306_WHITE);
          display8.display();
          break;
        case 7:
          display8.fillRect(78, 33, 9, 26, SSD1306_WHITE);
          display8.display();
          break;
        case 8:
          display8.fillRect(86, 1, 9, 26, SSD1306_WHITE);
          display8.display();
          break;
        case 9:
          display8.fillRect(96, 33, 9, 26, SSD1306_WHITE);
          display8.display();
          break;
        case 10:
          display8.fillRect(106, 1, 9, 26, SSD1306_WHITE);
          display8.display();
          break;
        case 11:
          display8.fillRect(113, 33, 9, 26, SSD1306_WHITE);
          display8.display();
          break;
      }
      break;

          case 8:
      switch (note)
      {
        case 0:
          display9.fillRect(6, 33, 9, 26, SSD1306_WHITE);
          display9.display();
          break;
        case 1:
          display9.fillRect(15, 1, 9, 26, SSD1306_WHITE);
          display9.display();
          break;
        case 2:
          display9.fillRect(24, 33, 9, 26, SSD1306_WHITE);
          display9.display();
          break;
        case 3:
          display9.fillRect(34, 1, 9, 26, SSD1306_WHITE);
          display9.display();
          break;
        case 4:
          display9.fillRect(42, 33, 9, 26, SSD1306_WHITE);
          display9.display();
          break;
        case 5:
          display9.fillRect(60, 33, 9, 26, SSD1306_WHITE);
          display9.display();
          break;
        case 6:
          display9.fillRect(68, 1, 9, 26, SSD1306_WHITE);
          display9.display();
          break;
        case 7:
          display9.fillRect(78, 33, 9, 26, SSD1306_WHITE);
          display9.display();
          break;
        case 8:
          display9.fillRect(86, 1, 9, 26, SSD1306_WHITE);
          display9.display();
          break;
        case 9:
          display9.fillRect(96, 33, 9, 26, SSD1306_WHITE);
          display9.display();
          break;
        case 10:
          display9.fillRect(106, 1, 9, 26, SSD1306_WHITE);
          display9.display();
          break;
        case 11:
          display9.fillRect(113, 33, 9, 26, SSD1306_WHITE);
          display9.display();
          break;
      }
      break;

    case 9:
      switch (note)
      {
        case 0:
          display10.fillRect(6, 33, 9, 26, SSD1306_WHITE);
          display10.display();
          break;
        case 1:
          display10.fillRect(15, 1, 9, 26, SSD1306_WHITE);
          display10.display();
          break;
        case 2:
          display10.fillRect(24, 33, 9, 26, SSD1306_WHITE);
          display10.display();
          break;
        case 3:
          display10.fillRect(34, 1, 9, 26, SSD1306_WHITE);
          display10.display();
          break;
        case 4:
          display10.fillRect(42, 33, 9, 26, SSD1306_WHITE);
          display10.display();
          break;
        case 5:
          display10.fillRect(60, 33, 9, 26, SSD1306_WHITE);
          display10.display();
          break;
        case 6:
          display10.fillRect(68, 1, 9, 26, SSD1306_WHITE);
          display10.display();
          break;
        case 7:
          display10.fillRect(78, 33, 9, 26, SSD1306_WHITE);
          display10.display();
          break;
        case 8:
          display10.fillRect(86, 1, 9, 26, SSD1306_WHITE);
          display10.display();
          break;
        case 9:
          display10.fillRect(96, 33, 9, 26, SSD1306_WHITE);
          display10.display();
          break;
        case 10:
          display10.fillRect(106, 1, 9, 26, SSD1306_WHITE);
          display10.display();
          break;
        case 11:
          display10.fillRect(113, 33, 9, 26, SSD1306_WHITE);
          display10.display();
          break;
      }
      break;
  }
}

void remove_note(int noteoff, uint8_t screen)
{
  switch (screen)
  {
    case 0:
      switch (noteoff)
      {
        case 0:
          display1.fillRect(6, 33, 9, 26, SSD1306_INVERSE);
          display1.display();
          break;
        case 1:
          display1.fillRect(15, 1, 9, 26, SSD1306_INVERSE);
          display1.display();
          break;
        case 2:
          display1.fillRect(24, 33, 9, 26, SSD1306_INVERSE);
          display1.display();
          break;
        case 3:
          display1.fillRect(34, 1, 9, 26, SSD1306_INVERSE);
          display1.display();
          break;
        case 4:
          display1.fillRect(42, 33, 9, 26, SSD1306_INVERSE);
          display1.display();
          break;
        case 5:
          display1.fillRect(60, 33, 9, 26, SSD1306_INVERSE);
          display1.display();
          break;
        case 6:
          display1.fillRect(68, 1, 9, 26, SSD1306_INVERSE);
          display1.display();
          break;
        case 7:
          display1.fillRect(78, 33, 9, 26, SSD1306_INVERSE);
          display1.display();
          break;
        case 8:
          display1.fillRect(86, 1, 9, 26, SSD1306_INVERSE);
          display1.display();
          break;
        case 9:
          display1.fillRect(96, 33, 9, 26, SSD1306_INVERSE);
          display1.display();
          break;
        case 10:
          display1.fillRect(106, 1, 9, 26, SSD1306_INVERSE);
          display1.display();
          break;
        case 11:
          display1.fillRect(113, 33, 9, 26, SSD1306_INVERSE);
          display1.display();
          break;
      }
      break;

    case 1:
      switch (noteoff)
      {
        case 0:
          display2.fillRect(6, 33, 9, 26, SSD1306_INVERSE);
          display2.display();
          break;
        case 1:
          display2.fillRect(15, 1, 9, 26, SSD1306_INVERSE);
          display2.display();
          break;
        case 2:
          display2.fillRect(24, 33, 9, 26, SSD1306_INVERSE);
          display2.display();
          break;
        case 3:
          display2.fillRect(34, 1, 9, 26, SSD1306_INVERSE);
          display2.display();
          break;
        case 4:
          display2.fillRect(42, 33, 9, 26, SSD1306_INVERSE);
          display2.display();
          break;
        case 5:
          display2.fillRect(60, 33, 9, 26, SSD1306_INVERSE);
          display2.display();
          break;
        case 6:
          display2.fillRect(68, 1, 9, 26, SSD1306_INVERSE);
          display2.display();
          break;
        case 7:
          display2.fillRect(78, 33, 9, 26, SSD1306_INVERSE);
          display2.display();
          break;
        case 8:
          display2.fillRect(86, 1, 9, 26, SSD1306_INVERSE);
          display2.display();
          break;
        case 9:
          display2.fillRect(96, 33, 9, 26, SSD1306_INVERSE);
          display2.display();
          break;
        case 10:
          display2.fillRect(106, 1, 9, 26, SSD1306_INVERSE);
          display2.display();
          break;
        case 11:
          display2.fillRect(113, 33, 9, 26, SSD1306_INVERSE);
          display2.display();
          break;
      }
      break;
    case 2:
      switch (noteoff)
      {
        case 0:
          display3.fillRect(6, 33, 9, 26, SSD1306_INVERSE);
          display3.display();
          break;
        case 1:
          display3.fillRect(15, 1, 9, 26, SSD1306_INVERSE);
          display3.display();
          break;
        case 2:
          display3.fillRect(24, 33, 9, 26, SSD1306_INVERSE);
          display3.display();
          break;
        case 3:
          display3.fillRect(34, 1, 9, 26, SSD1306_INVERSE);
          display3.display();
          break;
        case 4:
          display3.fillRect(42, 33, 9, 26, SSD1306_INVERSE);
          display3.display();
          break;
        case 5:
          display3.fillRect(60, 33, 9, 26, SSD1306_INVERSE);
          display3.display();
          break;
        case 6:
          display3.fillRect(68, 1, 9, 26, SSD1306_INVERSE);
          display3.display();
          break;
        case 7:
          display3.fillRect(78, 33, 9, 26, SSD1306_INVERSE);
          display3.display();
          break;
        case 8:
          display3.fillRect(86, 1, 9, 26, SSD1306_INVERSE);
          display3.display();
          break;
        case 9:
          display3.fillRect(96, 33, 9, 26, SSD1306_INVERSE);
          display3.display();
          break;
        case 10:
          display3.fillRect(106, 1, 9, 26, SSD1306_INVERSE);
          display3.display();
          break;
        case 11:
          display3.fillRect(113, 33, 9, 26, SSD1306_INVERSE);
          display3.display();
          break;
      }
      break;

    case 3:
      switch (noteoff)
      {
        case 0:
          display4.fillRect(6, 33, 9, 26, SSD1306_INVERSE);
          display4.display();
          break;
        case 1:
          display4.fillRect(15, 1, 9, 26, SSD1306_INVERSE);
          display4.display();
          break;
        case 2:
          display4.fillRect(24, 33, 9, 26, SSD1306_INVERSE);
          display4.display();
          break;
        case 3:
          display4.fillRect(34, 1, 9, 26, SSD1306_INVERSE);
          display4.display();
          break;
        case 4:
          display4.fillRect(42, 33, 9, 26, SSD1306_INVERSE);
          display4.display();
          break;
        case 5:
          display4.fillRect(60, 33, 9, 26, SSD1306_INVERSE);
          display4.display();
          break;
        case 6:
          display4.fillRect(68, 1, 9, 26, SSD1306_INVERSE);
          display4.display();
          break;
        case 7:
          display4.fillRect(78, 33, 9, 26, SSD1306_INVERSE);
          display4.display();
          break;
        case 8:
          display4.fillRect(86, 1, 9, 26, SSD1306_INVERSE);
          display4.display();
          break;
        case 9:
          display4.fillRect(96, 33, 9, 26, SSD1306_INVERSE);
          display4.display();
          break;
        case 10:
          display4.fillRect(106, 1, 9, 26, SSD1306_INVERSE);
          display4.display();
          break;
        case 11:
          display4.fillRect(113, 33, 9, 26, SSD1306_INVERSE);
          display4.display();
          break;
      }
      break;

    case 4:
      switch (noteoff)
      {
        case 0:
          display5.fillRect(6, 33, 9, 26, SSD1306_INVERSE);
          display5.display();
          break;
        case 1:
          display5.fillRect(15, 1, 9, 26, SSD1306_INVERSE);
          display5.display();
          break;
        case 2:
          display5.fillRect(24, 33, 9, 26, SSD1306_INVERSE);
          display5.display();
          break;
        case 3:
          display5.fillRect(34, 1, 9, 26, SSD1306_INVERSE);
          display5.display();
          break;
        case 4:
          display5.fillRect(42, 33, 9, 26, SSD1306_INVERSE);
          display5.display();
          break;
        case 5:
          display5.fillRect(60, 33, 9, 26, SSD1306_INVERSE);
          display5.display();
          break;
        case 6:
          display5.fillRect(68, 1, 9, 26, SSD1306_INVERSE);
          display5.display();
          break;
        case 7:
          display5.fillRect(78, 33, 9, 26, SSD1306_INVERSE);
          display5.display();
          break;
        case 8:
          display5.fillRect(86, 1, 9, 26, SSD1306_INVERSE);
          display5.display();
          break;
        case 9:
          display5.fillRect(96, 33, 9, 26, SSD1306_INVERSE);
          display5.display();
          break;
        case 10:
          display5.fillRect(106, 1, 9, 26, SSD1306_INVERSE);
          display5.display();
          break;
        case 11:
          display5.fillRect(113, 33, 9, 26, SSD1306_INVERSE);
          display5.display();
          break;
      }
      break;

    case 5:
      switch (noteoff)
      {
        case 0:
          display6.fillRect(6, 33, 9, 26, SSD1306_INVERSE);
          display6.display();
          break;
        case 1:
          display6.fillRect(15, 1, 9, 26, SSD1306_INVERSE);
          display6.display();
          break;
        case 2:
          display6.fillRect(24, 33, 9, 26, SSD1306_INVERSE);
          display6.display();
          break;
        case 3:
          display6.fillRect(34, 1, 9, 26, SSD1306_INVERSE);
          display6.display();
          break;
        case 4:
          display6.fillRect(42, 33, 9, 26, SSD1306_INVERSE);
          display6.display();
          break;
        case 5:
          display6.fillRect(60, 33, 9, 26, SSD1306_INVERSE);
          display6.display();
          break;
        case 6:
          display6.fillRect(68, 1, 9, 26, SSD1306_INVERSE);
          display6.display();
          break;
        case 7:
          display6.fillRect(78, 33, 9, 26, SSD1306_INVERSE);
          display6.display();
          break;
        case 8:
          display6.fillRect(86, 1, 9, 26, SSD1306_INVERSE);
          display6.display();
          break;
        case 9:
          display6.fillRect(96, 33, 9, 26, SSD1306_INVERSE);
          display6.display();
          break;
        case 10:
          display6.fillRect(106, 1, 9, 26, SSD1306_INVERSE);
          display6.display();
          break;
        case 11:
          display6.fillRect(113, 33, 9, 26, SSD1306_INVERSE);
          display6.display();
          break;
      }
      break;

    case 6:
      switch (noteoff)
      {
        case 0:
          display7.fillRect(6, 33, 9, 26, SSD1306_INVERSE);
          display7.display();
          break;
        case 1:
          display7.fillRect(15, 1, 9, 26, SSD1306_INVERSE);
          display7.display();
          break;
        case 2:
          display7.fillRect(24, 33, 9, 26, SSD1306_INVERSE);
          display7.display();
          break;
        case 3:
          display7.fillRect(34, 1, 9, 26, SSD1306_INVERSE);
          display7.display();
          break;
        case 4:
          display7.fillRect(42, 33, 9, 26, SSD1306_INVERSE);
          display7.display();
          break;
        case 5:
          display7.fillRect(60, 33, 9, 26, SSD1306_INVERSE);
          display7.display();
          break;
        case 6:
          display7.fillRect(68, 1, 9, 26, SSD1306_INVERSE);
          display7.display();
          break;
        case 7:
          display7.fillRect(78, 33, 9, 26, SSD1306_INVERSE);
          display7.display();
          break;
        case 8:
          display7.fillRect(86, 1, 9, 26, SSD1306_INVERSE);
          display7.display();
          break;
        case 9:
          display7.fillRect(96, 33, 9, 26, SSD1306_INVERSE);
          display7.display();
          break;
        case 10:
          display7.fillRect(106, 1, 9, 26, SSD1306_INVERSE);
          display7.display();
          break;
        case 11:
          display7.fillRect(113, 33, 9, 26, SSD1306_INVERSE);
          display7.display();
          break;
      }
      break;

    case 7:
      switch (noteoff)
      {
        case 0:
          display8.fillRect(6, 33, 9, 26, SSD1306_INVERSE);
          display8.display();
          break;
        case 1:
          display8.fillRect(15, 1, 9, 26, SSD1306_INVERSE);
          display8.display();
          break;
        case 2:
          display8.fillRect(24, 33, 9, 26, SSD1306_INVERSE);
          display8.display();
          break;
        case 3:
          display8.fillRect(34, 1, 9, 26, SSD1306_INVERSE);
          display8.display();
          break;
        case 4:
          display8.fillRect(42, 33, 9, 26, SSD1306_INVERSE);
          display8.display();
          break;
        case 5:
          display8.fillRect(60, 33, 9, 26, SSD1306_INVERSE);
          display8.display();
          break;
        case 6:
          display8.fillRect(68, 1, 9, 26, SSD1306_INVERSE);
          display8.display();
          break;
        case 7:
          display8.fillRect(78, 33, 9, 26, SSD1306_INVERSE);
          display8.display();
          break;
        case 8:
          display8.fillRect(86, 1, 9, 26, SSD1306_INVERSE);
          display8.display();
          break;
        case 9:
          display8.fillRect(96, 33, 9, 26, SSD1306_INVERSE);
          display8.display();
          break;
        case 10:
          display8.fillRect(106, 1, 9, 26, SSD1306_INVERSE);
          display8.display();
          break;
        case 11:
          display8.fillRect(113, 33, 9, 26, SSD1306_INVERSE);
          display8.display();
          break;
      }
      break;

          case 8:
      switch (noteoff)
      {
        case 0:
          display9.fillRect(6, 33, 9, 26, SSD1306_INVERSE);
          display9.display();
          break;
        case 1:
          display9.fillRect(15, 1, 9, 26, SSD1306_INVERSE);
          display9.display();
          break;
        case 2:
          display9.fillRect(24, 33, 9, 26, SSD1306_INVERSE);
          display9.display();
          break;
        case 3:
          display9.fillRect(34, 1, 9, 26, SSD1306_INVERSE);
          display9.display();
          break;
        case 4:
          display9.fillRect(42, 33, 9, 26, SSD1306_INVERSE);
          display9.display();
          break;
        case 5:
          display9.fillRect(60, 33, 9, 26, SSD1306_INVERSE);
          display9.display();
          break;
        case 6:
          display9.fillRect(68, 1, 9, 26, SSD1306_INVERSE);
          display9.display();
          break;
        case 7:
          display9.fillRect(78, 33, 9, 26, SSD1306_INVERSE);
          display9.display();
          break;
        case 8:
          display9.fillRect(86, 1, 9, 26, SSD1306_INVERSE);
          display9.display();
          break;
        case 9:
          display9.fillRect(96, 33, 9, 26, SSD1306_INVERSE);
          display9.display();
          break;
        case 10:
          display9.fillRect(106, 1, 9, 26, SSD1306_INVERSE);
          display9.display();
          break;
        case 11:
          display9.fillRect(113, 33, 9, 26, SSD1306_INVERSE);
          display9.display();
          break;
      }
      break;

    case 9:
      switch (noteoff)
      {
        case 0:
          display10.fillRect(6, 33, 9, 26, SSD1306_INVERSE);
          display10.display();
          break;
        case 1:
          display10.fillRect(15, 1, 9, 26, SSD1306_INVERSE);
          display10.display();
          break;
        case 2:
          display10.fillRect(24, 33, 9, 26, SSD1306_INVERSE);
          display10.display();
          break;
        case 3:
          display10.fillRect(34, 1, 9, 26, SSD1306_INVERSE);
          display10.display();
          break;
        case 4:
          display10.fillRect(42, 33, 9, 26, SSD1306_INVERSE);
          display10.display();
          break;
        case 5:
          display10.fillRect(60, 33, 9, 26, SSD1306_INVERSE);
          display10.display();
          break;
        case 6:
          display10.fillRect(68, 1, 9, 26, SSD1306_INVERSE);
          display10.display();
          break;
        case 7:
          display10.fillRect(78, 33, 9, 26, SSD1306_INVERSE);
          display10.display();
          break;
        case 8:
          display10.fillRect(86, 1, 9, 26, SSD1306_INVERSE);
          display10.display();
          break;
        case 9:
          display10.fillRect(96, 33, 9, 26, SSD1306_INVERSE);
          display10.display();
          break;
        case 10:
          display10.fillRect(106, 1, 9, 26, SSD1306_INVERSE);
          display10.display();
          break;
        case 11:
          display10.fillRect(113, 33, 9, 26, SSD1306_INVERSE);
          display10.display();
          break;
      }
      break;
  }
}
