# PiVersus

![PiVersus Logo](https://user-images.githubusercontent.com/68835732/110843542-51948c00-82a0-11eb-8ce0-1597a9427c66.png)


# Overview


PiVersus is a game system that uses two "sticks" as controllers to play several
simple games. A raspberry pi will be kitted with a set of buttons that allow
players to choose between the games. A speaker will output sound files that
will explain the rules of the games, signal the start of a game and announce a
winner at the end. Scoring for each game is done by real-time processing of
the incoming data from the sensors in the controllers.


# Prototype Hardware
* Raspberry Pi 4 Model B 4GB RAM
* Push buttons
* 2x Accelerometer/Gyroscope/Magnetometer sensors
* 1x 2-axis joystick
* LCD Screen module
* Mini External USB Stereo Speaker
* HDMI to Micro-HDMI Cable
* Power Supply (5.1V 3A)

# Games
## Soda prank
On the signal, the two players must shake their controller as hard as possible
for 10 seconds. The player that shakes the hardest, wins.
An accelerometer in each controller sends data to the RasPi. The RasPi then
measures the magnitude of the data (as this is a triaxial accelerometer), and
adds it to an array. At the end of the game, an average is taken from the points
in the array and the player with the highest average wins the game.

## Statue game
On the signal, the players must hold their respective controllers as perfectly
still as possible. If someone shakes their controller to hard, they lose.
The same accelerometer data from before is used to determine whether the
controller is being shaken. A running differential between the magnitude of the
current data point and the previous one is being logged. If the difference
exceeds a certain threshold for a certain controller, the game ends and the
player has lost.

## Piggy bank
On the signal, players must rapidly shake the controller for 30 seconds. Every
second, if the controller has been shaken hard enough over the past second, a
coin sound plays, signifying the player has earned a point. The player with the
most points at the end wins the game.

The magnitude of motion of the controller is taken from the accelerometer data
and stored in an array that holds enough data points for one second of motion.
Once the array is filled with data, the average of the values is calculated. If the
average exceeds a certain requirement, the coin sound is played and a value
representing a player's score is increased by 1. At the end of the time limit, the
player with the most points wins the game.

## Team Members:
* Allan Cotto 2589702H
* Ibrahim Javed 2265799J
* Paul Lampropoulos 2245874L
* Akhilesh Vishnu Hari 25967326H


## Schematics:

![Schematic 1](https://user-images.githubusercontent.com/68835732/113633467-eeaad080-9664-11eb-8d0d-5ba3c6a82a3b.png)


*Figure 1: Schematic for Raspberry PI and Accelerometer*


![Schematic 2](https://user-images.githubusercontent.com/68835732/113633421-d5098900-9664-11eb-9b33-fa46016a83dd.png)

*Figure 2: Schematic for Raspberry Pi and ADC (Analogue-to-digital converter) / Joystick*

![Schematic 3](https://user-images.githubusercontent.com/68835732/113633499-fec2b000-9664-11eb-8e1d-4965438cf5d5.png)

*Figure 3: Schematic for Raspberry Pi and push button*

## Social Media

* [Facebook](https://www.facebook.com/piversusgame)
* [Instagram](https://www.instagram.com/pi_versus/)
* [YouTube](https://www.youtube.com/channel/UCxI0JWJ07GGeQGmsw30Y7qQ)
