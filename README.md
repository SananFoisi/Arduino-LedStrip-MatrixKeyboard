# Arduino + MatrixKeyboard + FitaLed
![Arduino-FitaLed-MatrixKeyboard](https://user-images.githubusercontent.com/67809229/111480774-19160780-8711-11eb-8bfc-d2b3cab10734.png)

https://www.tinkercad.com/things/erhXX3efqQu

| PT-BR | 
| :---- | 
| Para a troca de efeitos é necessario o presionamento do Push Button | 
| Modelo de fita de led utilizado: WS2812b | 

|EN-US |
|:---- | 
|To switch effects, pressing the Push Button is required | 
|Led strip model used: WS2812b | 



| Botão | Efeito | 
| :---: | :----- | 
|||
| 1 | rainbowCycle(30) | 
| 2 | RGBLoop() | 
| 3 | FadeInOut(0x00, 0x00, 0xff) //blue <br/> FadeInOut(0x00, 0xff, 0xff) //cian <br/> FadeInOut(0x00, 0xff, 0x00) //green <br/> FadeInOut(0xff, 0xff, 0x00) //yellow <br/> FadeInOut(0xff, 0x00, 0x00) //red <br/> FadeInOut(0xff, 0x14, 0x14) //pink |
| A | colorWipe(0xff, 0x00, 0x00, 50) //red|
|||
| 4 | RunningLights(0xff, 0x00, 0x00, 50) `#ff0000` - ![#f03c15](https://placehold.it/15/f03c15/000000?text=+) `#f03c15`|
| 5 | RunningLights(0x00, 0xff, 0x00, 50) //green |
| 6 | RunningLights(0x00, 0x00, 0xff, 50) //blue|
| B | colorWipe(0x00, 0xff, 0x00, 50) //green|
|||
| 7 |-|
| 8 |-|
| 9 |-|
| C | colorWipe(0x00, 0x00, 0xff, 50) //blue|
|||
| * |-|
| 0 |-|
| # |-|
| D | colorWipe(0xff, 0xff, 0xff, 50) //white |
