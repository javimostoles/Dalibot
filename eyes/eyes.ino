// Program to exercise the MD_MAX72XX library
//
// Uses the graphics functions to animate a pair of eyes on 2 matrix modules.
// Eyes are coordinated to work together.
// Eyes are created to fill all available modules.
//
//
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "MD_EyePair.h"
#include <LEDMatrixDriver.hpp>

// Define the number of devices we have in the chain and the hardware interface
#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 4

// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define CLK_PIN   13  // or SCK
#define DATA_PIN  11  // or MOSI
#define CS_PIN    9  // or SS

const uint8_t LEDMATRIX_CS_PIN = 4;
// Number of 8x8 segments you are connecting
const int LEDMATRIX_SEGMENTS = 1;
const int LEDMATRIX_WIDTH    = LEDMATRIX_SEGMENTS * 8;

// The LEDMatrixDriver class instance



// SPI hardware interface
//MD_MAX72XX M = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// Arbitrary pins
MD_MAX72XX M = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

// Define the eyes!
#define MAX_EYE_PAIR 4

MD_EyePair E[MAX_EYE_PAIR];

// Miscellaneous defines
#define  DELAYTIME  400  // in milliseconds

void setup()
{
 
  
  M.begin();

  // initialize the eye view
  for (uint8_t i=0; i<MAX_EYE_PAIR; i++)
    E[i].begin(i*4+1, &M, DELAYTIME);
}

void loop()
{
  for (uint8_t i=0; i<MAX_EYE_PAIR; i++)
    E[i].animate();
}
