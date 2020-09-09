# Arduino + MatrixKeyboard + FitaLed

<br> FitaLed-ArduinoMatrixKeyboard

<br> //Para a troca de efeitos é necessario o presionamento do Push Button
<br> //To switch effects, pressing the Push Button is required

<br> (1) -    rainbowCycle(30) 
<br> (2) -    RGBLoop() 
<br> (3) -    FadeInOut(0x00, 0x00, 0xff) //blue 
<br> - - -    FadeInOut(0x00, 0xff, 0xff) //cian 
<br> - - -    FadeInOut(0x00, 0xff, 0x00) //green 
<br> - - -    FadeInOut(0xff, 0xff, 0x00) //yellow 
<br> - - -    FadeInOut(0xff, 0x00, 0x00) //red 
<br> - - -    FadeInOut(0xff, 0x14, 0x14) //pink
<br> (A) -    colorWipe(0xff, 0x00, 0x00, 50) //red

<br> (4) -    RunningLights(0xff, 0x00, 0x00, 50) //red 
<br> (5) -    RunningLights(0x00, 0xff, 0x00, 50) //green 
<br> (6) -    RunningLights(0x00, 0x00, 0xff, 50) //blue
<br> (B) -    colorWipe(0x00, 0xff, 0x00, 50) //green

<br> (7) -   -
<br> (8) -   - 
<br> (9) -   -
<br> (C) -   colorWipe(0x00, 0x00, 0xff, 50) //blue

<br> (*) -   -
<br> (#) -   -
<br> (0) -   -
<br> (D) -   colorWipe(0xff, 0xff, 0xff, 50) //white 
