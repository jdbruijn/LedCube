LedCube
=======

[![License MIT][badge-license]][license]

LedCube is a project of making an 8x8x8 RGB LED cube. This repository contains the drawings, design, overview of the hardware and last but not least the code to control this 8x8x8 RGB LED cube.

LedCube is written in C and uses various peripherals like SPI, UART.

![Alt text](/Docs/3D Model/LedCube 3D Model.bmp?raw=true "LedCube 3D Model")

###LedCube Visualisation
LedCube Visualisation is a Windows program that visualizes a 8x8x8 RGB LED cube and can be used to visualize a LED cube without risking of damaging the actual LED cube. In the future this program can possibly also be used to program the LedCube by visually programming sequences.<br />
A link to the repository of this program can be found [here](https://github.com/vidavidorra/LedCube-Visualisation/).

##[Documents](Docs)
####Hardware
Microcontroller: [Microchip PIC24FJ64GA004](http://www.microchip.com/wwwproducts/Devices.aspx?product=PIC24FJ64GA004)  
Used PCBs:
* LedCube v1.0
 * Microcontroller: [Microchip PIC24FJ64GA004](http://www.microchip.com/wwwproducts/Devices.aspx?product=PIC24FJ64GA004)
 * LDO Voltage regulator: [Taiwan Semiconductor TS1117BCW-3.3](http://nl.farnell.com/taiwan-semiconductor/ts1117bcw-3-3/ldo-voltage-reg-0-8a-12v-sot223/dp/7208359?ost=7208359)
 * USB to UART: [FTDI Chip FT231XS](http://www.ftdichip.com/Products/ICs/FT231X.html)
 * Bluetooth: [Microchip RN4020](http://www.microchip.com/wwwproducts/Devices.aspx?product=RN4020)
 * Shift Register: [ON Semiconductor MC74HC595A](http://www.onsemi.com/PowerSolutions/product.do?id=MC74HC595A)
 * Piezo Transducer: [Pro Signal ABT-436-RC](http://nl.farnell.com/pro-signal/abt-436-rc/piezo-transducer-pcb/dp/1300026?ost=1300026)

* PanelControl v1.0
 * LedDriver: [Texas Instruments TLC5925](http://www.ti.com/product/tlc5925)
 
#### Programming environment
IDE: [MPLAB X v3.10](http://www.microchip.com/pagehandler/en-us/family/mplabx/home.html?tab=t2)  
Compiler: [XC16 v1.25](http://www.microchip.com/pagehandler/en-us/devtools/mplabxc/home.html#tab-2)  

Licensing
---------
LedCube is free software, released under the [MIT license](http://opensource.org/licenses/MIT), as published by the Open Source Initiative.
Modification and redistribution are permitted according to the terms of the MIT license.
The license can be found in the `LICENSE` file.

[badge-license]: https://img.shields.io/badge/license-MIT-blue.svg
[license]: https://github.com/vidavidorra/LedCube/blob/master/LICENSE.md