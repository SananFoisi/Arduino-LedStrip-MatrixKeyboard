#include <Arduino.h>
#include <Keypad.h>            // Biblioteca para controle do teclado de matrizes.
#include <Adafruit_NeoPixel.h> // Biblioteca para controle da fita LED
// Necessário para Trinket Adafruit de 16 MHz
#ifdef __AVR__
#include <avr/power.h>
#endif

#define DATA_PIN 2  // Pino de E/S digital conectado aos NeoPixels.
#define NUM_LEDS 75 // Número de LEDs na fita
#define botReset 4  //Porta de entrada do botao Reset

const byte ROWS = 4; // Quatro linhas por...
const byte COLS = 4; // Quatro colunas.
// const int botReset = 4;

int _UM = 0, _DOIS = 0, _TRES = 0;
int _QUATRO = 0, _CINCO = 0, _SEIS = 0;
// int _SETE = 0, _OITO = 0, _NOVE = 0;
int _A = 0, _B = 0, _C = 0, _D = 0;

// Define o Keypad (mapa do circuito do teclado).
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[ROWS] = {12, 11, 10, 9}; // Pinos que estão ligados as linhas.
byte colPins[COLS] = {8, 7, 6, 5};    // Pinos que estão ligados as colunas.

//***PROTOTIPAÇÃO DE FUNÇÕES***
void rainbowCycle(int SpeedDelay);
byte *Wheel(byte WheelPos); /*PERTENCE A RAINBOW*/
void RGBLoop();
void FadeInOut(byte red, byte green, byte blue);
void RunningLights(byte red, byte green, byte blue, int WaveDelay);
void colorWipe(byte red, byte green, byte blue, int SpeedDelay);
// ***NOT REPLACE HERE***
void showStrip();
void setPixel(int Pixel, byte red, byte green, byte blue);
void setAll(byte red, byte green, byte blue);
// FUNCTION RESET ARDUINO
void (*funcReset)() = 0;

// Cria um "objeto" Keypad (Teclado)
Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
// Cria um "objeto" Adafruit_NeoPixel (Fita LED)
Adafruit_NeoPixel strip(NUM_LEDS, DATA_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  // Estas linhas são especificamente para suportar a Adafruit Trinket 5V 16 MHz.
  // Qualquer outra placa, você pode remover esta parte (mas nenhum dano deixando-a)
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // FIM do código específico do Trinket.
  strip.begin();                   // Inicialize o objeto de tira NeoPixel (NECESSÁRIO)
  strip.show();                    // DESLIGUE todos os pixels o mais rápido possível
  strip.setBrightness(200);        //Brilho da tira
  pinMode(botReset, INPUT_PULLUP); // Entrada do botao RESET
}

void loop()
{
  char key = kpd.getKey(); //Capturar o que foi digitado
  if (key)                 // Checa se um botão foi pressionado.
  {
    switch (key)
    {
    // EFEITOS
    case '1':
      while (_UM < 2048)
      {
        rainbowCycle(30);
        _UM++;
      }
      break;
    case '2':
      while (_DOIS < 2048)
      {
        RGBLoop();
        _DOIS++;
      }
      break;
    case '3':
      while (_TRES < 2048)
      {
        FadeInOut(0x00, 0x00, 0xff); // blue
        FadeInOut(0x00, 0xff, 0xff); // ciano
        FadeInOut(0x00, 0xff, 0x00); // green
        FadeInOut(0xff, 0xff, 0x00); // yellow
        FadeInOut(0xff, 0x00, 0x00); // red
        FadeInOut(0xff, 0x14, 0x93); // pink
        _TRES++;
      }
      break;
    case '4':
      while (_QUATRO < 2048)
      {
        RunningLights(0xff, 0x00, 0x00, 50);
        _QUATRO++;
      }
      break;
    case '5':
      while (_CINCO < 2048)
      {
        RunningLights(0x00, 0xff, 0x00, 50);
        _CINCO++;
      }
      break;
    case '6':
      while (_SEIS < 2048)
      {
        RunningLights(0x00, 0x00, 0xff, 50);
        _SEIS++;
      }
      break;
    case '7':
      /*
      while (_SETE < 2048)
      {
        _SETE++;
      }
      */
      break;
    case '8':
      /*
      while (_OITO < 2048)
      {
        _SETE++;
      }
      */
      break;
    case '9':
      /*
      while (_NOVE < 2048)
      {
        _NOVE++;
      }
      */
      break;
    case 'A':
      while (_A < 2048)
      {
        colorWipe(0xff, 0x00, 0x00, 50);
        _A++;
      }
      break;
    case 'B':
      while (_B < 2048)
      {
        colorWipe(0x00, 0xff, 0x00, 50);
        _B++;
      }
      break;
    case 'C':
      while (_C < 2048)
      {
        colorWipe(0x00, 0x00, 0xff, 50);
        _C++;
      }
      break;
    case 'D':
      while (_D < 2048)
      {
        colorWipe(0xff, 0xff, 0xff, 50);
        _D++;
      }
      break;
    case '*':
      break;
    case '#':
      break;
    case '0':
      break;
    default:
      Serial.println(key);
      break;
    }
  }
}

void rainbowCycle(int SpeedDelay)
{
  byte *c;
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++)
  { // 5 ciclos de todas as cores na roda
    for (i = 0; i < NUM_LEDS; i++)
    {
      c = Wheel(((i * 256 / NUM_LEDS) + j) & 255);
      setPixel(i, *c, *(c + 1), *(c + 2));
      if (digitalRead(botReset) == 0)
      {
        funcReset(); //Reset
      }
    }
    showStrip();
    delay(SpeedDelay);
  }
}

byte *Wheel(byte WheelPos) /*PERTENCE A RAINBOW*/
{
  static byte c[3];

  if (WheelPos < 85)
  {
    c[0] = WheelPos * 3;
    c[1] = 255 - WheelPos * 3;
    c[2] = 0;
  }
  else if (WheelPos < 170)
  {
    WheelPos -= 85;
    c[0] = 255 - WheelPos * 3;
    c[1] = 0;
    c[2] = WheelPos * 3;
  }
  else
  {
    WheelPos -= 170;
    c[0] = 0;
    c[1] = WheelPos * 3;
    c[2] = 255 - WheelPos * 3;
  }

  return c;
}

void RGBLoop()
{
  for (int j = 0; j < 3; j++)
  {
    // Fade IN
    for (int k = 0; k < 256; k++)
    {
      switch (j)
      {
      case 0:
        setAll(k, 0, 0);
        break;
      case 1:
        setAll(0, k, 0);
        break;
      case 2:
        setAll(0, 0, k);
        break;
      }
      if (digitalRead(botReset) == 0)
      {
        funcReset(); //Reset
      }
      showStrip();
      delay(3);
    }
    // Fade OUT
    for (int k = 255; k >= 0; k--)
    {
      switch (j)
      {
      case 0:
        setAll(k, 0, 0);
        break;
      case 1:
        setAll(0, k, 0);
        break;
      case 2:
        setAll(0, 0, k);
        break;
      }
      if (digitalRead(botReset) == 0)
      {
        funcReset(); //Reset
      }
      showStrip();
      delay(3);
    }
  }
}

void FadeInOut(byte red, byte green, byte blue)
{
  float r, g, b;

  for (int k = 0; k < 256; k = k + 1)
  {
    r = (k / 256.0) * red;
    g = (k / 256.0) * green;
    b = (k / 256.0) * blue;
    setAll(r, g, b);
    if (digitalRead(botReset) == 0)
    {
      funcReset(); //Reset
    }
    showStrip();
  }

  for (int k = 255; k >= 0; k = k - 2)
  {
    r = (k / 256.0) * red;
    g = (k / 256.0) * green;
    b = (k / 256.0) * blue;
    setAll(r, g, b);
    if (digitalRead(botReset) == 0)
    {
      funcReset(); //Reset
    }
    showStrip();
  }
}

void RunningLights(byte red, byte green, byte blue, int WaveDelay)
{
  int Position = 0;

  for (int i = 0; i < NUM_LEDS * 2; i++)
  {
    Position++; // = 0; //Position + Rate;
    //= 0; //Posição + Taxa;
    for (int i = 0; i < NUM_LEDS; i++)
    {
      //  onda seno, 3 ondas offset fazem um arco-íris!
      //  float level = sin(i+Position) * 127 + 128;
      //  setPixel(i,level,0,0);
      //  float level = sin(i+Position) * 127 + 128;
      setPixel(i, ((sin(i + Position) * 127 + 128) / 255) * red,
               ((sin(i + Position) * 127 + 128) / 255) * green,
               ((sin(i + Position) * 127 + 128) / 255) * blue);
      if (digitalRead(botReset) == 0)
      {
        funcReset(); //Reset
      }
    }

    showStrip();
    delay(WaveDelay);
  }
}

void colorWipe(byte red, byte green, byte blue, int SpeedDelay)
{
  for (uint16_t i = 0; i < NUM_LEDS; i++)
  {
    setPixel(i, red, green, blue);
    if (digitalRead(botReset) == 0)
    {
      funcReset(); //Reset
    }
    showStrip();
    delay(SpeedDelay);
  }
}

// ***NOT REPLACE HERE DOWN***
void showStrip()
{
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.show();
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  FastLED.show();
#endif
}
void setPixel(int Pixel, byte red, byte green, byte blue)
{
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.setPixelColor(Pixel, strip.Color(red, green, blue));
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  leds[Pixel].r = red;
  leds[Pixel].g = green;
  leds[Pixel].b = blue;
#endif
}
void setAll(byte red, byte green, byte blue)
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    setPixel(i, red, green, blue);
  }
  showStrip();
}
