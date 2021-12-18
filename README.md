# Scale-unwinder-3dp
A ESP32 driven Scale, Adjustable spoolwidth, esp touch for tare, offset 1, offset 2

For my recuring plates i need to know the remaining Filamet on spool. 
As my wife was yellin a ton for taking away her kitchen scale every day, this here became my solution.

![render](https://raw.githubusercontent.com/Stephan3/Scale-unwinder-3dp/master/pics/render_1.PNG)

You can hardcode two offsets(empty spoolweights) and select them by touching the screws below the display.

### Components used:
Bearings 608RS - [Amazon](https://www.amazon.de/gp/product/B00WXDAUQG/)

A ESP32 mcu - [Aliexpress](https://de.aliexpress.com/item/32839344778)

20KG HX711 Loadcell - [Amazon](https://www.amazon.de/ILS-Module-Aluminum-Weighing-Arduino/dp/B0768CN3T9/ref=sr_1_5?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=27R3F3R5OFVRF&keywords=load+cell+20kg&qid=1578851787&sprefix=load+ce%2Caps%2C161&sr=8-5)

128x64 OLED LCD - [Amazon](https://www.amazon.de/AZDelivery-Display-Arduino-Raspberry-gratis/dp/B074N9VLZX/ref=sr_1_5?__mk_de_DE=ÅMÅŽÕÑ&keywords=OLED+arduino&qid=1578851947&sr=8-5)

Wires

M3 screws DIN 912 (M3x12mm)

M3 screws DIN 912 (M3x16mm)

M5 screws DIN 912 (M5x20mm)

M4 screws DIN 912 (M4x20mm)

Heatinserts m3 thread  (M3 x 5mm x 4mm)

usbcable

### printsetings
Print in ABS - 
0.2 Layerheigth - 
4.5 Walls - 
50% infill - 
no Supports

### Putting things togeter
See the pictures in pics folder.

Insert the heatinserts with a soldering iron. Use washers between loadcell and scalecase.

Test the touch wires before closing the case, there is a serial feedback. The wires can be pushed into the screw holes of the displayfeet and then just screw in the display holder. You might want to change touchpins T0-T9 (line 72)


