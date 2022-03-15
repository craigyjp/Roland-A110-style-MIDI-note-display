#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MIDI.h>
#include <USBHost_t36.h>
#include <SPI.h>
#include <TM1637Display.h>
//#define ENCODER_OPTIMIZE_INTERRUPTS
//#include <Encoder.h>
#include <Bounce.h>
//#include <RoxMux.h>

// Module connection pins (Digital Pins)
#define CLK 34
#define DIO 33

TM1637Display display(CLK, DIO);

const uint8_t CHAN01[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                   // C
  SEG_C | SEG_E | SEG_F | SEG_G,                   // h
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // 0
  SEG_B | SEG_C                                    // 1
};

const uint8_t CHAN02[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                   // C
  SEG_C | SEG_E | SEG_F | SEG_G,                   // h
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // 0
  SEG_A | SEG_B | SEG_D | SEG_E | SEG_G            // 2
};

const uint8_t CHAN03[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                   // C
  SEG_C | SEG_E | SEG_F | SEG_G,                   // h
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // 0
  SEG_A | SEG_B | SEG_D | SEG_C | SEG_G            // 3
};

const uint8_t CHAN04[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                   // C
  SEG_C | SEG_E | SEG_F | SEG_G,                   // h
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // 0
  SEG_B | SEG_C | SEG_F | SEG_G                    // 4
};

const uint8_t CHAN05[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                   // C
  SEG_C | SEG_E | SEG_F | SEG_G,                   // h
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // 0
  SEG_A | SEG_C | SEG_D | SEG_F | SEG_G            // 5
};

const uint8_t CHAN06[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                   // C
  SEG_C | SEG_E | SEG_F | SEG_G,                   // h
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // 0
  SEG_C | SEG_D | SEG_E | SEG_F | SEG_G            // 6
};

const uint8_t CHAN07[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                   // C
  SEG_C | SEG_E | SEG_F | SEG_G,                   // h
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // 0
  SEG_A | SEG_B | SEG_C                            // 7
};

const uint8_t CHAN08[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                   // C
  SEG_C | SEG_E | SEG_F | SEG_G,                   // h
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // 0
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E  | SEG_F | SEG_G  // 8
};

const uint8_t CHAN09[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                   // C
  SEG_C | SEG_E | SEG_F | SEG_G,                   // h
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // 0
  SEG_A | SEG_B | SEG_C | SEG_F | SEG_G            // 9
};

const uint8_t CHAN10[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                   // C
  SEG_C | SEG_E | SEG_F | SEG_G,                   // h
  SEG_B | SEG_C,                                   // 1
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F    // 0
};

const uint8_t CHAN11[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                   // C
  SEG_C | SEG_E | SEG_F | SEG_G,                   // h
  SEG_B | SEG_C,                                   // 1
  SEG_B | SEG_C                                    // 1
};

const uint8_t CHAN12[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                   // C
  SEG_C | SEG_E | SEG_F | SEG_G,                   // h
  SEG_B | SEG_C,                                   // 1
  SEG_A | SEG_B | SEG_D | SEG_E | SEG_G            // 2
};

const uint8_t CHAN13[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                   // C
  SEG_C | SEG_E | SEG_F | SEG_G,                   // h
  SEG_B | SEG_C,                                   // 1
  SEG_A | SEG_B | SEG_D | SEG_C | SEG_G            // 3
};

const uint8_t CHAN14[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                   // C
  SEG_C | SEG_E | SEG_F | SEG_G,                   // h
  SEG_B | SEG_C,                                   // 1
  SEG_B | SEG_C | SEG_F | SEG_G                    // 4
};

const uint8_t CHAN15[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                   // C
  SEG_C | SEG_E | SEG_F | SEG_G,                   // h
  SEG_B | SEG_C,                                   // 1
  SEG_A | SEG_C | SEG_D | SEG_F | SEG_G            // 5
};

const uint8_t CHAN16[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                   // C
  SEG_C | SEG_E | SEG_F | SEG_G,                   // h
  SEG_B | SEG_C,                                   // 1
  SEG_C | SEG_D | SEG_E | SEG_F | SEG_G            // 6
};

const uint8_t OMNI[] = {
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // 0
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F,           // M
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_C                                            // i
};

const uint8_t PGM[] = {
  SEG_A | SEG_B | SEG_E | SEG_F | SEG_G,            // P
  SEG_E | SEG_G,                                    // r
  SEG_A | SEG_C | SEG_D | SEG_E | SEG_F,            // G
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F             // M
};

int mynotes[120];

int ProgramMode = 0;
int ProgramChangeReceived = 0;
int masterChan = 1;
int EncoderValue = 1;
int firstoctavenote = 0;
int secondoctavenote = 0;
int thirdoctavenote = 0;
int fourthoctavenote = 0;
int fifthoctavenote = 0;
int sixthoctavenote = 0;
int seventhoctavenote = 0;
int eigthoctavenote = 0;
int ninthoctavenote = 0;
int tenthoctavenote = 0;

int firstoctavenoteoff = 0;
int secondoctavenoteoff = 0;
int thirdoctavenoteoff = 0;
int fourthoctavenoteoff = 0;
int fifthoctavenoteoff = 0;
int sixthoctavenoteoff = 0;
int seventhoctavenoteoff = 0;
int eigthoctavenoteoff = 0;
int ninthoctavenoteoff = 0;
int tenthoctavenoteoff = 0;

String outputdisplay = "       ";

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET  10

#define OLED1_CS     2
#define OLED2_CS     3
#define OLED3_CS     4
#define OLED4_CS     5
#define OLED5_CS     6
#define OLED6_CS     7
#define OLED7_CS     8
#define OLED8_CS     9
#define OLED9_CS     38
#define OLED10_CS     37

#define OLED_DC1     25
#define OLED_DC2     26
#define OLED_DC3     27
#define OLED_DC4     28
#define OLED_DC5     29
#define OLED_DC6     30
#define OLED_DC7     31
#define OLED_DC8     32
#define OLED_DC9     36
#define OLED_DC10     35

#define SUSTAINLED     39

#define UP_SW 15
#define DOWN_SW 14
#define DEBOUNCE 30

//These are pushbuttons and require debouncing
Bounce upSwitch = Bounce(UP_SW, DEBOUNCE);
Bounce downSwitch = Bounce(DOWN_SW, DEBOUNCE);

Adafruit_SSD1306 display1(SCREEN_WIDTH, SCREEN_HEIGHT,
                          &SPI, OLED_DC1, OLED_RESET, OLED1_CS);

Adafruit_SSD1306 display2(SCREEN_WIDTH, SCREEN_HEIGHT,
                          &SPI, OLED_DC2, -1, OLED2_CS);

Adafruit_SSD1306 display3(SCREEN_WIDTH, SCREEN_HEIGHT,
                          &SPI, OLED_DC3, -1, OLED3_CS);

Adafruit_SSD1306 display4(SCREEN_WIDTH, SCREEN_HEIGHT,
                          &SPI, OLED_DC4, -1, OLED4_CS);

Adafruit_SSD1306 display5(SCREEN_WIDTH, SCREEN_HEIGHT,
                          &SPI, OLED_DC5, -1, OLED5_CS);

Adafruit_SSD1306 display6(SCREEN_WIDTH, SCREEN_HEIGHT,
                          &SPI, OLED_DC6, -1, OLED6_CS);

Adafruit_SSD1306 display7(SCREEN_WIDTH, SCREEN_HEIGHT,
                          &SPI, OLED_DC7, -1, OLED7_CS);

Adafruit_SSD1306 display8(SCREEN_WIDTH, SCREEN_HEIGHT,
                          &SPI, OLED_DC8, -1, OLED8_CS);

Adafruit_SSD1306 display9(SCREEN_WIDTH, SCREEN_HEIGHT,
                          &SPI, OLED_DC9, -1, OLED9_CS);

Adafruit_SSD1306 display10(SCREEN_WIDTH, SCREEN_HEIGHT,
                           &SPI, OLED_DC10, -1, OLED10_CS);


//USB HOST MIDI Class Compliant
USBHost myusb;
USBHub hub1(myusb);
USBHub hub2(myusb);
MIDIDevice midi1(myusb);

//MIDI 5 Pin DIN
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

void setup() {
  Serial.begin(57600);
  //USB HOST MIDI Class Compliant
  delay(200); //Wait to turn on USB Host
  myusb.begin();
  midi1.setHandleControlChange(myControlChange);
  midi1.setHandleProgramChange(myProgramChange);
  midi1.setHandleNoteOff(myNoteOff);
  midi1.setHandleNoteOn(myNoteOn);
  Serial.println("USB HOST MIDI Class Compliant Listening");

  //USB Client MIDI
  usbMIDI.setHandleControlChange(myControlChange);
  usbMIDI.setHandleProgramChange(myProgramChange);
  usbMIDI.setHandleNoteOff(myNoteOff);
  usbMIDI.setHandleNoteOn(myNoteOn);
  Serial.println("USB Client MIDI Listening");

  //MIDI 5 Pin DIN
  MIDI.begin();
  MIDI.setHandleControlChange(myControlChange);
  MIDI.setHandleProgramChange(myProgramChange);
  MIDI.setHandleNoteOn(myNoteOn);
  MIDI.setHandleNoteOff(myNoteOff);
  Serial.println("MIDI In DIN Listening");

  //Next, we splash the OLED screens
  setupScreens();
  splashScreens();
  display.setBrightness(0x0d);
  pinMode(SUSTAINLED, OUTPUT);
  digitalWrite(SUSTAINLED, LOW);
  for (int i = 0; i < 120; i++)
  {
    mynotes[i] = 0;
  }
  display.setSegments(CHAN01);
  pinMode(UP_SW, INPUT_PULLUP);
  pinMode(DOWN_SW, INPUT_PULLUP);
}

void loop() {
  MIDI.read(masterChan);    //MIDI 5 Pin DIN
  usbMIDI.read(masterChan); //USB Client MIDI
  myusb.Task();
  midi1.read(masterChan);   //USB HOST MIDI Class Compliant
  checkSwitches();
}

void checkSwitches()
{
  upSwitch.update();
  if (upSwitch.fallingEdge())
  {
    clear_notes();
    EncoderValue = (EncoderValue + 1);
    if (EncoderValue >= 19)
    {
      EncoderValue = 1;
    }
    read_pot(EncoderValue);
  }

  downSwitch.update();
  if (downSwitch.fallingEdge())
  {
    clear_notes();
    EncoderValue = (EncoderValue - 1);
    if (EncoderValue < 1)
    {
      EncoderValue = 18;
    }
    read_pot(EncoderValue);
  }
}

void myProgramChange(byte channel, byte program)
{
  if (ProgramMode == 1 )
  {
    display.showNumberDec((program + 1), false); // Expect: ___1
    ProgramChangeReceived = 1;
  }

}

void myControlChange(byte channel, byte control, byte value)
{
  if (control == 64 )
  {
    if (value >= 64)
    {
      digitalWrite(SUSTAINLED, HIGH);
    }
    else
    {
      digitalWrite(SUSTAINLED, LOW);
    }
  }
}

void clear_notes()
{
  for (int i = 0; i < 120; i++)
  {
    if (mynotes[i] == 1)
    {
      myNoteOff(0, i, 0);
      mynotes[i] = 0;
    }
  }
}

void read_pot(int EncoderValue)
{

  if (EncoderValue == 1)
  {
    masterChan = 1;
    display.setSegments(CHAN01);
    ProgramMode = 0;
    ProgramChangeReceived = 0;
  }
  else if (EncoderValue == 2)
  {
    masterChan = 2;
    display.setSegments(CHAN02);
    ProgramMode = 0;
    ProgramChangeReceived = 0;
  }
  else if (EncoderValue == 3)
  {
    masterChan = 3;
    display.setSegments(CHAN03);
    ProgramMode = 0;
    ProgramChangeReceived = 0;
  }
  else if (EncoderValue == 4)
  {
    masterChan = 4;
    display.setSegments(CHAN04);
    ProgramMode = 0;
    ProgramChangeReceived = 0;
  }
  else if (EncoderValue == 5)
  {
    masterChan = 5;
    display.setSegments(CHAN05);
    ProgramMode = 0;
    ProgramChangeReceived = 0;
  }
  else if (EncoderValue == 6)
  {
    masterChan = 6;
    display.setSegments(CHAN06);
    ProgramMode = 0;
    ProgramChangeReceived = 0;
  }
  else if (EncoderValue == 7)
  {
    masterChan = 7;
    display.setSegments(CHAN07);
    ProgramMode = 0;
    ProgramChangeReceived = 0;
  }
  else if (EncoderValue == 8)
  {
    masterChan = 8;
    display.setSegments(CHAN08);
    ProgramMode = 0;
    ProgramChangeReceived = 0;
  }
  else if (EncoderValue == 9)
  {
    masterChan = 9;
    display.setSegments(CHAN09);
    ProgramMode = 0;
    ProgramChangeReceived = 0;
  }
  else if (EncoderValue == 10)
  {
    masterChan = 10;
    display.setSegments(CHAN10);
    ProgramMode = 0;
    ProgramChangeReceived = 0;
  }
  else if (EncoderValue == 11)
  {
    masterChan = 11;
    display.setSegments(CHAN11);
    ProgramMode = 0;
    ProgramChangeReceived = 0;
  }
  else if (EncoderValue == 12)
  {
    masterChan = 12;
    display.setSegments(CHAN12);
    ProgramMode = 0;
    ProgramChangeReceived = 0;
  }
  else if (EncoderValue == 13)
  {
    masterChan = 13;
    display.setSegments(CHAN13);
    ProgramMode = 0;
    ProgramChangeReceived = 0;
  }
  else if (EncoderValue == 14)
  {
    masterChan = 14;
    display.setSegments(CHAN14);
    ProgramMode = 0;
    ProgramChangeReceived = 0;
  }
  else if (EncoderValue == 15)
  {
    masterChan = 15;
    display.setSegments(CHAN15);
    ProgramMode = 0;
    ProgramChangeReceived = 0;
  }
  else if (EncoderValue == 16)
  {
    masterChan = 16;
    display.setSegments(CHAN16);
    ProgramMode = 0;
    ProgramChangeReceived = 0;
  }
  else if (EncoderValue == 17)
  {
    masterChan = 0;
    display.setSegments(OMNI);
    ProgramMode = 0;
    ProgramChangeReceived = 0;
  }
  else if (EncoderValue == 18)
  {
    masterChan = 0;
    ProgramMode = 1;
    if (ProgramChangeReceived != 1)
    {
      display.setSegments(PGM);
    }
  }
}


void myNoteOn(byte channel, byte note, byte velocity)
{
  switch (note)
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
      mynotes[note] = 1;
      firstoctavenote = note;
      display_note(firstoctavenote, 0);
      break;

    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
      mynotes[note] = 1;
      secondoctavenote = (note - 12);
      display_note(secondoctavenote, 1);
      break;

    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
      mynotes[note] = 1;
      thirdoctavenote = (note - 24);
      display_note(thirdoctavenote, 2);
      break;

    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
      mynotes[note] = 1;
      fourthoctavenote = (note - 36);
      display_note(fourthoctavenote, 3);
      break;

    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
      mynotes[note] = 1;
      fifthoctavenote = (note - 48);
      display_note(fifthoctavenote, 4);
      break;

    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
      mynotes[note] = 1;
      sixthoctavenote = (note - 60);
      display_note(sixthoctavenote, 5);
      break;

    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
      mynotes[note] = 1;
      seventhoctavenote = (note - 72);
      display_note(seventhoctavenote, 6);
      break;

    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 94:
    case 95:
      mynotes[note] = 1;
      eigthoctavenote = (note - 84);
      display_note(eigthoctavenote, 7);
      break;

    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
      mynotes[note] = 1;
      ninthoctavenote = (note - 96);
      display_note(ninthoctavenote, 8);
      break;

    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
      mynotes[note] = 1;
      tenthoctavenote = (note - 108);
      display_note(tenthoctavenote, 9);
      break;
  }
}

void myNoteOff(byte channel, byte noteoff, byte velocity)
{
  switch (noteoff)
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
      mynotes[noteoff] = 0;
      firstoctavenoteoff = noteoff;
      remove_note(firstoctavenoteoff, 0);
      break;

    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
      mynotes[noteoff] = 0;
      secondoctavenoteoff = (noteoff - 12);
      remove_note(secondoctavenoteoff, 1);
      break;

    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
      mynotes[noteoff] = 0;
      thirdoctavenoteoff = (noteoff - 24);
      remove_note(thirdoctavenoteoff, 2);
      break;

    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
      mynotes[noteoff] = 0;
      fourthoctavenoteoff = (noteoff - 36);
      remove_note(fourthoctavenoteoff, 3);
      break;

    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
      mynotes[noteoff] = 0;
      fifthoctavenoteoff = (noteoff - 48);
      remove_note(fifthoctavenoteoff, 4);
      break;

    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
      mynotes[noteoff] = 0;
      sixthoctavenoteoff = (noteoff - 60);
      remove_note(sixthoctavenoteoff, 5);
      break;

    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
      mynotes[noteoff] = 0;
      seventhoctavenoteoff = (noteoff - 72);
      remove_note(seventhoctavenoteoff, 6);
      break;

    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 94:
    case 95:
      mynotes[noteoff] = 0;
      eigthoctavenoteoff = (noteoff - 84);
      remove_note(eigthoctavenoteoff, 7);
      break;

    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
      mynotes[noteoff] = 0;
      ninthoctavenoteoff = (noteoff - 96);
      remove_note(ninthoctavenoteoff, 8);
      break;

    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
      mynotes[noteoff] = 0;
      tenthoctavenoteoff = (noteoff - 108);
      remove_note(tenthoctavenoteoff, 9);
      break;
  }
}

void setupScreens() {

  display1.begin(SSD1306_SWITCHCAPVCC);
  display1.clearDisplay();
  display1.display();
  delay(50);
  display2.begin(SSD1306_SWITCHCAPVCC);
  display2.clearDisplay();
  display2.display();
  delay(50);
  display3.begin(SSD1306_SWITCHCAPVCC);
  display3.clearDisplay();
  display3.display();
  delay(50);
  display4.begin(SSD1306_SWITCHCAPVCC);
  display4.clearDisplay();
  display4.display();
  delay(50);
  display5.begin(SSD1306_SWITCHCAPVCC);
  display5.clearDisplay();
  display5.display();
  delay(50);
  display6.begin(SSD1306_SWITCHCAPVCC);
  display6.clearDisplay();
  display6.display();
  delay(50);
  display7.begin(SSD1306_SWITCHCAPVCC);
  display7.clearDisplay();
  display7.display();
  delay(50);
  display8.begin(SSD1306_SWITCHCAPVCC);
  display8.clearDisplay();
  display8.display();
  delay(50);
  display9.begin(SSD1306_SWITCHCAPVCC);
  display9.clearDisplay();
  display9.display();
  delay(50);
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
  //    Serial.print("NoteOff ");
  //  Serial.println(noteoff);
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
  //  Serial.print("NoteOff ");
  //  Serial.println(noteoff);
  switch (screen)
  {
    case 0:
      switch (noteoff)
      {
        case 0:
          display1.fillRect(6, 33, 9, 26, SSD1306_BLACK);
          display1.display();
          break;
        case 1:
          display1.fillRect(15, 1, 9, 26, SSD1306_BLACK);
          display1.display();
          break;
        case 2:
          display1.fillRect(24, 33, 9, 26, SSD1306_BLACK);
          display1.display();
          break;
        case 3:
          display1.fillRect(34, 1, 9, 26, SSD1306_BLACK);
          display1.display();
          break;
        case 4:
          display1.fillRect(42, 33, 9, 26, SSD1306_BLACK);
          display1.display();
          break;
        case 5:
          display1.fillRect(60, 33, 9, 26, SSD1306_BLACK);
          display1.display();
          break;
        case 6:
          display1.fillRect(68, 1, 9, 26, SSD1306_BLACK);
          display1.display();
          break;
        case 7:
          display1.fillRect(78, 33, 9, 26, SSD1306_BLACK);
          display1.display();
          break;
        case 8:
          display1.fillRect(86, 1, 9, 26, SSD1306_BLACK);
          display1.display();
          break;
        case 9:
          display1.fillRect(96, 33, 9, 26, SSD1306_BLACK);
          display1.display();
          break;
        case 10:
          display1.fillRect(106, 1, 9, 26, SSD1306_BLACK);
          display1.display();
          break;
        case 11:
          display1.fillRect(113, 33, 9, 26, SSD1306_BLACK);
          display1.display();
          break;
      }
      break;

    case 1:
      switch (noteoff)
      {
        case 0:
          display2.fillRect(6, 33, 9, 26, SSD1306_BLACK);
          display2.display();
          break;
        case 1:
          display2.fillRect(15, 1, 9, 26, SSD1306_BLACK);
          display2.display();
          break;
        case 2:
          display2.fillRect(24, 33, 9, 26, SSD1306_BLACK);
          display2.display();
          break;
        case 3:
          display2.fillRect(34, 1, 9, 26, SSD1306_BLACK);
          display2.display();
          break;
        case 4:
          display2.fillRect(42, 33, 9, 26, SSD1306_BLACK);
          display2.display();
          break;
        case 5:
          display2.fillRect(60, 33, 9, 26, SSD1306_BLACK);
          display2.display();
          break;
        case 6:
          display2.fillRect(68, 1, 9, 26, SSD1306_BLACK);
          display2.display();
          break;
        case 7:
          display2.fillRect(78, 33, 9, 26, SSD1306_BLACK);
          display2.display();
          break;
        case 8:
          display2.fillRect(86, 1, 9, 26, SSD1306_BLACK);
          display2.display();
          break;
        case 9:
          display2.fillRect(96, 33, 9, 26, SSD1306_BLACK);
          display2.display();
          break;
        case 10:
          display2.fillRect(106, 1, 9, 26, SSD1306_BLACK);
          display2.display();
          break;
        case 11:
          display2.fillRect(113, 33, 9, 26, SSD1306_BLACK);
          display2.display();
          break;
      }
      break;
    case 2:
      switch (noteoff)
      {
        case 0:
          display3.fillRect(6, 33, 9, 26, SSD1306_BLACK);
          display3.display();
          break;
        case 1:
          display3.fillRect(15, 1, 9, 26, SSD1306_BLACK);
          display3.display();
          break;
        case 2:
          display3.fillRect(24, 33, 9, 26, SSD1306_BLACK);
          display3.display();
          break;
        case 3:
          display3.fillRect(34, 1, 9, 26, SSD1306_BLACK);
          display3.display();
          break;
        case 4:
          display3.fillRect(42, 33, 9, 26, SSD1306_BLACK);
          display3.display();
          break;
        case 5:
          display3.fillRect(60, 33, 9, 26, SSD1306_BLACK);
          display3.display();
          break;
        case 6:
          display3.fillRect(68, 1, 9, 26, SSD1306_BLACK);
          display3.display();
          break;
        case 7:
          display3.fillRect(78, 33, 9, 26, SSD1306_BLACK);
          display3.display();
          break;
        case 8:
          display3.fillRect(86, 1, 9, 26, SSD1306_BLACK);
          display3.display();
          break;
        case 9:
          display3.fillRect(96, 33, 9, 26, SSD1306_BLACK);
          display3.display();
          break;
        case 10:
          display3.fillRect(106, 1, 9, 26, SSD1306_BLACK);
          display3.display();
          break;
        case 11:
          display3.fillRect(113, 33, 9, 26, SSD1306_BLACK);
          display3.display();
          break;
      }
      break;

    case 3:
      switch (noteoff)
      {
        case 0:
          display4.fillRect(6, 33, 9, 26, SSD1306_BLACK);
          display4.display();
          break;
        case 1:
          display4.fillRect(15, 1, 9, 26, SSD1306_BLACK);
          display4.display();
          break;
        case 2:
          display4.fillRect(24, 33, 9, 26, SSD1306_BLACK);
          display4.display();
          break;
        case 3:
          display4.fillRect(34, 1, 9, 26, SSD1306_BLACK);
          display4.display();
          break;
        case 4:
          display4.fillRect(42, 33, 9, 26, SSD1306_BLACK);
          display4.display();
          break;
        case 5:
          display4.fillRect(60, 33, 9, 26, SSD1306_BLACK);
          display4.display();
          break;
        case 6:
          display4.fillRect(68, 1, 9, 26, SSD1306_BLACK);
          display4.display();
          break;
        case 7:
          display4.fillRect(78, 33, 9, 26, SSD1306_BLACK);
          display4.display();
          break;
        case 8:
          display4.fillRect(86, 1, 9, 26, SSD1306_BLACK);
          display4.display();
          break;
        case 9:
          display4.fillRect(96, 33, 9, 26, SSD1306_BLACK);
          display4.display();
          break;
        case 10:
          display4.fillRect(106, 1, 9, 26, SSD1306_BLACK);
          display4.display();
          break;
        case 11:
          display4.fillRect(113, 33, 9, 26, SSD1306_BLACK);
          display4.display();
          break;
      }
      break;

    case 4:
      switch (noteoff)
      {
        case 0:
          display5.fillRect(6, 33, 9, 26, SSD1306_BLACK);
          display5.display();
          break;
        case 1:
          display5.fillRect(15, 1, 9, 26, SSD1306_BLACK);
          display5.display();
          break;
        case 2:
          display5.fillRect(24, 33, 9, 26, SSD1306_BLACK);
          display5.display();
          break;
        case 3:
          display5.fillRect(34, 1, 9, 26, SSD1306_BLACK);
          display5.display();
          break;
        case 4:
          display5.fillRect(42, 33, 9, 26, SSD1306_BLACK);
          display5.display();
          break;
        case 5:
          display5.fillRect(60, 33, 9, 26, SSD1306_BLACK);
          display5.display();
          break;
        case 6:
          display5.fillRect(68, 1, 9, 26, SSD1306_BLACK);
          display5.display();
          break;
        case 7:
          display5.fillRect(78, 33, 9, 26, SSD1306_BLACK);
          display5.display();
          break;
        case 8:
          display5.fillRect(86, 1, 9, 26, SSD1306_BLACK);
          display5.display();
          break;
        case 9:
          display5.fillRect(96, 33, 9, 26, SSD1306_BLACK);
          display5.display();
          break;
        case 10:
          display5.fillRect(106, 1, 9, 26, SSD1306_BLACK);
          display5.display();
          break;
        case 11:
          display5.fillRect(113, 33, 9, 26, SSD1306_BLACK);
          display5.display();
          break;
      }
      break;

    case 5:
      switch (noteoff)
      {
        case 0:
          display6.fillRect(6, 33, 9, 26, SSD1306_BLACK);
          display6.display();
          break;
        case 1:
          display6.fillRect(15, 1, 9, 26, SSD1306_BLACK);
          display6.display();
          break;
        case 2:
          display6.fillRect(24, 33, 9, 26, SSD1306_BLACK);
          display6.display();
          break;
        case 3:
          display6.fillRect(34, 1, 9, 26, SSD1306_BLACK);
          display6.display();
          break;
        case 4:
          display6.fillRect(42, 33, 9, 26, SSD1306_BLACK);
          display6.display();
          break;
        case 5:
          display6.fillRect(60, 33, 9, 26, SSD1306_BLACK);
          display6.display();
          break;
        case 6:
          display6.fillRect(68, 1, 9, 26, SSD1306_BLACK);
          display6.display();
          break;
        case 7:
          display6.fillRect(78, 33, 9, 26, SSD1306_BLACK);
          display6.display();
          break;
        case 8:
          display6.fillRect(86, 1, 9, 26, SSD1306_BLACK);
          display6.display();
          break;
        case 9:
          display6.fillRect(96, 33, 9, 26, SSD1306_BLACK);
          display6.display();
          break;
        case 10:
          display6.fillRect(106, 1, 9, 26, SSD1306_BLACK);
          display6.display();
          break;
        case 11:
          display6.fillRect(113, 33, 9, 26, SSD1306_BLACK);
          display6.display();
          break;
      }
      break;

    case 6:
      switch (noteoff)
      {
        case 0:
          display7.fillRect(6, 33, 9, 26, SSD1306_BLACK);
          display7.display();
          break;
        case 1:
          display7.fillRect(15, 1, 9, 26, SSD1306_BLACK);
          display7.display();
          break;
        case 2:
          display7.fillRect(24, 33, 9, 26, SSD1306_BLACK);
          display7.display();
          break;
        case 3:
          display7.fillRect(34, 1, 9, 26, SSD1306_BLACK);
          display7.display();
          break;
        case 4:
          display7.fillRect(42, 33, 9, 26, SSD1306_BLACK);
          display7.display();
          break;
        case 5:
          display7.fillRect(60, 33, 9, 26, SSD1306_BLACK);
          display7.display();
          break;
        case 6:
          display7.fillRect(68, 1, 9, 26, SSD1306_BLACK);
          display7.display();
          break;
        case 7:
          display7.fillRect(78, 33, 9, 26, SSD1306_BLACK);
          display7.display();
          break;
        case 8:
          display7.fillRect(86, 1, 9, 26, SSD1306_BLACK);
          display7.display();
          break;
        case 9:
          display7.fillRect(96, 33, 9, 26, SSD1306_BLACK);
          display7.display();
          break;
        case 10:
          display7.fillRect(106, 1, 9, 26, SSD1306_BLACK);
          display7.display();
          break;
        case 11:
          display7.fillRect(113, 33, 9, 26, SSD1306_BLACK);
          display7.display();
          break;
      }
      break;

    case 7:
      switch (noteoff)
      {
        case 0:
          display8.fillRect(6, 33, 9, 26, SSD1306_BLACK);
          display8.display();
          break;
        case 1:
          display8.fillRect(15, 1, 9, 26, SSD1306_BLACK);
          display8.display();
          break;
        case 2:
          display8.fillRect(24, 33, 9, 26, SSD1306_BLACK);
          display8.display();
          break;
        case 3:
          display8.fillRect(34, 1, 9, 26, SSD1306_BLACK);
          display8.display();
          break;
        case 4:
          display8.fillRect(42, 33, 9, 26, SSD1306_BLACK);
          display8.display();
          break;
        case 5:
          display8.fillRect(60, 33, 9, 26, SSD1306_BLACK);
          display8.display();
          break;
        case 6:
          display8.fillRect(68, 1, 9, 26, SSD1306_BLACK);
          display8.display();
          break;
        case 7:
          display8.fillRect(78, 33, 9, 26, SSD1306_BLACK);
          display8.display();
          break;
        case 8:
          display8.fillRect(86, 1, 9, 26, SSD1306_BLACK);
          display8.display();
          break;
        case 9:
          display8.fillRect(96, 33, 9, 26, SSD1306_BLACK);
          display8.display();
          break;
        case 10:
          display8.fillRect(106, 1, 9, 26, SSD1306_BLACK);
          display8.display();
          break;
        case 11:
          display8.fillRect(113, 33, 9, 26, SSD1306_BLACK);
          display8.display();
          break;
      }
      break;

    case 8:
      switch (noteoff)
      {
        case 0:
          display9.fillRect(6, 33, 9, 26, SSD1306_BLACK);
          display9.display();
          break;
        case 1:
          display9.fillRect(15, 1, 9, 26, SSD1306_BLACK);
          display9.display();
          break;
        case 2:
          display9.fillRect(24, 33, 9, 26, SSD1306_BLACK);
          display9.display();
          break;
        case 3:
          display9.fillRect(34, 1, 9, 26, SSD1306_BLACK);
          display9.display();
          break;
        case 4:
          display9.fillRect(42, 33, 9, 26, SSD1306_BLACK);
          display9.display();
          break;
        case 5:
          display9.fillRect(60, 33, 9, 26, SSD1306_BLACK);
          display9.display();
          break;
        case 6:
          display9.fillRect(68, 1, 9, 26, SSD1306_BLACK);
          display9.display();
          break;
        case 7:
          display9.fillRect(78, 33, 9, 26, SSD1306_BLACK);
          display9.display();
          break;
        case 8:
          display9.fillRect(86, 1, 9, 26, SSD1306_BLACK);
          display9.display();
          break;
        case 9:
          display9.fillRect(96, 33, 9, 26, SSD1306_BLACK);
          display9.display();
          break;
        case 10:
          display9.fillRect(106, 1, 9, 26, SSD1306_BLACK);
          display9.display();
          break;
        case 11:
          display9.fillRect(113, 33, 9, 26, SSD1306_BLACK);
          display9.display();
          break;
      }
      break;

    case 9:
      switch (noteoff)
      {
        case 0:
          display10.fillRect(6, 33, 9, 26, SSD1306_BLACK);
          display10.display();
          break;
        case 1:
          display10.fillRect(15, 1, 9, 26, SSD1306_BLACK);
          display10.display();
          break;
        case 2:
          display10.fillRect(24, 33, 9, 26, SSD1306_BLACK);
          display10.display();
          break;
        case 3:
          display10.fillRect(34, 1, 9, 26, SSD1306_BLACK);
          display10.display();
          break;
        case 4:
          display10.fillRect(42, 33, 9, 26, SSD1306_BLACK);
          display10.display();
          break;
        case 5:
          display10.fillRect(60, 33, 9, 26, SSD1306_BLACK);
          display10.display();
          break;
        case 6:
          display10.fillRect(68, 1, 9, 26, SSD1306_BLACK);
          display10.display();
          break;
        case 7:
          display10.fillRect(78, 33, 9, 26, SSD1306_BLACK);
          display10.display();
          break;
        case 8:
          display10.fillRect(86, 1, 9, 26, SSD1306_BLACK);
          display10.display();
          break;
        case 9:
          display10.fillRect(96, 33, 9, 26, SSD1306_BLACK);
          display10.display();
          break;
        case 10:
          display10.fillRect(106, 1, 9, 26, SSD1306_BLACK);
          display10.display();
          break;
        case 11:
          display10.fillRect(113, 33, 9, 26, SSD1306_BLACK);
          display10.display();
          break;
      }
      break;
  }
}
