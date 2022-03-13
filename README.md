# Roland-A110-style-MIDI-note-display
A MIDI note analyzer in the style of the Roland A110 Midi device, accepts USB Host, USB MIDI and MIDI DIN inputs and displays the notes.

Displays notes from 0-120

Using a Teensy 3.6 and 10x 0.96" SPI SSD136 displays to make one long display.

LED display for channel and program change information

Added channel selection control 1-16, Omni Mode and Program Omni Mode (displays all program changes)

Added the hold function, led will light when a sustain message is seen in the MIDI stream
