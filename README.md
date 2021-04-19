[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[forks-shield]: https://img.shields.io/github/forks/allancotto/PiVersus
[forks-url]: https://github.com/allancotto/PiVersus/network/members
[stars-shield]: https://img.shields.io/github/stars/allancotto/PiVersus
[stars-url]: https://github.com/allancotto/PiVersus/stargazers
[issues-shield]: https://img.shields.io/github/issues/allancotto/PiVersus
[issues-url]: https://github.com/allancotto/PiVersus/issues
[license-shield]: https://img.shields.io/github/license/allancotto/PiVersus
[license-url]: https://github.com/allancotto/PiVersus/blob/main/LICENSE



# PiVersus

![PiVersus](https://user-images.githubusercontent.com/35377323/115171986-31849380-a0bc-11eb-97fe-7317b7379ac3.gif)


# Overview

PiVersus is a `real-time game system` that allows `users` to play games `utilising real-time sensors`.

PiVersus uses real-time sensors as controllers to allow users to play multiple games. 
The system runs on a Raspberry Pi 4B. Scoring for each game is done through the real-time
processing of incoming data from sensors.

Website : https://allancotto.github.io/PiVersus/

Connect with us on social media for regular updates! Check out our YouTube channel for a demo of the current release!

[<img src=https://edent.github.io/SuperTinyIcons/images/svg/instagram.svg width=80>](https://www.instagram.com/pi_versus/)
[<img src=https://edent.github.io/SuperTinyIcons/images/svg/youtube.svg width=80>](https://www.youtube.com/channel/UCxI0JWJ07GGeQGmsw30Y7qQ)
[<img src=https://edent.github.io/SuperTinyIcons/images/svg/facebook.svg width=80>](https://www.facebook.com/piversusgame)

## Team Members:
* Allan Cotto 2589702H
* Ibrahim Javed 2265799J
* Paul Lampropoulos 2245874L
* Akhilesh Vishnu Hari 25967326H

## Packages/Libraries Used:

SFML — Simple and Fast Multimedia Library
* [SFML 2.5.1](https://github.com/allancotto/PiVersus/wiki/Game-Descriptions)

Catch2 Unit Testing Framework for C++
* [Catch2](https://github.com/catchorg/Catch2)

Wiring Pi GPIO Interface library for the Raspberry Pi
* [WiringPi](http://wiringpi.com/)


## RealTime Responsiveness

You can read about the RealTime Responsiveness of the game in the [Wiki](https://github.com/allancotto/PiVersus/wiki/RealTime-Responsiveness). We use multiple threads throughout PiVersus, we have threads for each input which are launched and terminated depending on state and also sleep according to required latencies. The graphics also run on a dedicated thread so the game always runs seamlessly.

# Prototype Hardware
* [Raspberry Pi 4 Model B 4GB RAM](https://thepihut.com/products/raspberry-pi-4-model-b)
* [Push buttons](https://www.ebay.co.uk/itm/154400487760)
* [2x Accelerometer/Gyroscope/Magnetometer sensors](https://thepihut.com/products/adafruit-precision-nxp-9-dof-breakout-board-ada3463?variant=12364068519998)
* [1x 2-axis joystick](https://www.parallax.com/product/2-axis-joystick/)
* [Mini External USB Stereo Speaker](https://thepihut.com/products/mini-external-usb-stereo-speaker?variant=31955934801)
* [HDMI to Micro-HDMI Cable](https://thepihut.com/products/micro-hdmi-to-standard-hdmi-a-cable?variant=31597425033278) 
* [Power Supply (5.1V 3A)](https://thepihut.com/products/raspberry-pi-psu-uk?variant=20064004505662)


Links below lead to wiring schematics for the hardware in the Wiki, we have also developed output tests
for each piece of hardware; so you can test each individual piece of hardware is working as expected after wiring. 

* [Hardware Schematics](https://github.com/allancotto/PiVersus/wiki/Wiring-Diagrams)
* [Running Output Tests](https://github.com/allancotto/PiVersus/wiki/Running-Hardware-Output-Tests)



## Running PiVersus

To make and run PiVersus, follow these steps:


1. Make a new directory for the project
```
 mkdir PiVersus
 cd PiVersus
```


2. Clone the repository 
```
 git clone https://github.com/allancotto/PiVersus.git
```


3. Install SFML 
```
 sudo apt-get install libsfml-dev
```

4. Navigate into the 'Main' folder and run the makefile
```
 cd Main
 make
```

5. Navigate to the executable and run PiVersus

```
cd ..
cd bin
./main
```


# Games
Game descriptions can be found in the Wiki.

* [Game Descriptions](https://github.com/allancotto/PiVersus/wiki/Game-Descriptions)
* [Game Layout Designs](https://github.com/allancotto/PiVersus/wiki/Game-Layout-Designs)
* [Game Logos](https://github.com/allancotto/PiVersus/wiki/Game-Logos)







<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[forks-shield]: https://img.shields.io/github/forks/allancotto/PiVersus
[forks-url]: https://github.com/allancotto/PiVersus/network/members
[stars-shield]: https://img.shields.io/github/stars/allancotto/PiVersus
[stars-url]: https://github.com/allancotto/PiVersus/stargazers
[issues-shield]: https://img.shields.io/github/issues/allancotto/PiVersus
[issues-url]: https://github.com/allancotto/PiVersus/issues
[license-shield]: https://img.shields.io/github/license/allancotto/PiVersus
[license-url]: https://github.com/allancotto/PiVersus/blob/main/LICENSE

