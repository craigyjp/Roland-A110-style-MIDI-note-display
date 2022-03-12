#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MIDI.h>
#include <USBHost_t36.h>
#include <SPI.h>

#define DISPLAY_NORMAL 0
#define DISPLAY_OVERVIEW 1
#define DISPLAY_MENU 2

//Need to put the typedef here, for function's sake...
typedef struct {
  uint8_t unit; //the unit that is selected
  uint16_t param; //the parameter that is selected
} param_type;

int masterChan = 1;

int firstoctavenote = 0;
int secondoctavenote = 0;
int thirdoctavenote = 0;
int fourthoctavenote = 0;
int fifthoctavenote = 0;
int sixthoctavenote = 0;
int seventhoctavenote = 0;
int eigthoctavenote = 0;
//int 9octavenote = 0;
//int 10octavenote = 0;

int firstoctavenoteoff = 0;
int secondoctavenoteoff = 0;
int thirdoctavenoteoff = 0;
int fourthoctavenoteoff = 0;
int fifthoctavenoteoff = 0;
int sixthoctavenoteoff = 0;
int seventhoctavenoteoff = 0;
int eigthoctavenoteoff = 0;
//int 9octavenoteoff = 0;
//int 10octavenoteoff = 0;

typedef struct {
  uint8_t rate[6];  //dly, r1, r2, r3, r4, r5
  uint8_t level[6]; //l0, l1, l2, l3, l4, l5
} env_type;



//Default menu: OSC of unit 1, Volume
uint8_t greenSelect = 2;
uint8_t blueSelect = 0;
uint8_t operatorSelect = 0; //Selected operator, often the same as operator used, except for envelopes
uint8_t operatorUsed = 0; //Operator actually used
uint8_t toggleMode = 0; //Sets the toggle mode
uint8_t patchSelect = 0; //The active patch
bool patchChanged = false; //True if the patch is changed without saving it
bool dx7LegacyMode = false; //Don't go into legacy mode! (it's not allowed ;-))
String outputdisplay = "       ";
uint8_t displayMode = DISPLAY_OVERVIEW; //Sets the overview mode (extra information, is temporarilly set to DISPLAY_NORMAL whenever you hit a button)
unsigned long lastChange = 0; //Sets the time when you last hit a button

//Set to true when an interrupt arrives: don't do anything till the interrupt is processed (or bad things will happen due to concurrency!!!)
bool rotating = false;

//Mapping from logical screens to fysical OLEDs
const uint8_t SCRMAP[8] = {0, 1, 2, 3, 4, 5, 6, 7};
//// SCK, MOSI, CS, DC, RES
//U8GLIB_SSD1306_128X64 displayOne(13, 11, 5, 2, 3);
//U8GLIB_SSD1306_128X64 displayTwo(13, 11, 35, 38, 39);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET  32

#define OLED1_CS     2
#define OLED2_CS     3
#define OLED3_CS     4
#define OLED4_CS     5
#define OLED5_CS     6
#define OLED6_CS     7
#define OLED7_CS     8
#define OLED8_CS     9

#define OLED_DC1     23
#define OLED_DC2     25
#define OLED_DC3     26
#define OLED_DC4     27
#define OLED_DC5     28
#define OLED_DC6     29
#define OLED_DC7     30
#define OLED_DC8     31

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

//USB HOST MIDI Class Compliant
USBHost myusb;
USBHub hub1(myusb);
USBHub hub2(myusb);
MIDIDevice midi1(myusb);

//MIDI 5 Pin DIN
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

void setup() {

  //USB HOST MIDI Class Compliant
  delay(200); //Wait to turn on USB Host
  myusb.begin();
  //  midi1.setHandleControlChange(myControlChange);
  //  midi1.setHandleProgramChange(myProgramChange);
  midi1.setHandleNoteOff(myNoteOff);
  midi1.setHandleNoteOn(myNoteOn);
  Serial.println("USB HOST MIDI Class Compliant Listening");

  //USB Client MIDI
  //  usbMIDI.setHandleControlChange(myControlChange);
  //  usbMIDI.setHandleProgramChange(myProgramChange);
  usbMIDI.setHandleNoteOff(myNoteOff);
  usbMIDI.setHandleNoteOn(myNoteOn);
  Serial.println("USB Client MIDI Listening");

  //MIDI 5 Pin DIN
  MIDI.begin();
  //  MIDI.setHandleControlChange(myControlChange);
  //  MIDI.setHandleProgramChange(myProgramChange);
  MIDI.setHandleNoteOn(myNoteOn);
  MIDI.setHandleNoteOff(myNoteOff);
  Serial.println("MIDI In DIN Listening");

  // put your setup code here, to run once:
  Wire.begin();

  //Next, we splash the OLED screens
  setupScreens();
  splashScreens();
}

void myNoteOn(byte channel, byte note, byte velocity)
{
  //Check for out of range notes
  if (note < 0 || note > 127) return;
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
      eigthoctavenote = (note - 84);
      display_note(eigthoctavenote, 7);
      break;
  }

}

void myNoteOff(byte channel, byte noteoff, byte velocity)
{
  //Check for out of range notes
  if (noteoff < 0 || noteoff > 127) return;
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
      eigthoctavenoteoff = (noteoff - 84);
      remove_note(eigthoctavenoteoff, 7);
      break;
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  myusb.Task();
  midi1.read(masterChan);   //USB HOST MIDI Class Compliant
  MIDI.read(masterChan);//MIDI 5 Pin DIN
  usbMIDI.read(masterChan); //USB Client MIDI
}
