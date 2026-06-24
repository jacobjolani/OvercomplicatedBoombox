# OvercomplicatedBoombox

Turning a 2015 Raspberry Pi 3, a gutted CD player, and a gutted cassette deck into a boombox 

## What it does: 
Inside the cardboard box the Pi switches between a cassette deck and a CD player and plays the selected source out through its 3.5mm headphone jack. Both decks keep their original circuit boards (preamp/decoder included), so the Pi only has to handle source switching and output, not raw signal decoding. 

## The reason its inside a cardboard box:
I have a summer job at a Menasha facility where I have access to a cnc machine that cuts corrugated paper (Basically heavy duty cardboard). The housing is going to be a designed in CAD and lot more slim fitted and secure than what it may sound like. 

## Where it's at: 
Pi is set up and I can write/run C on it over SSH. Currently learning GPIO control with libgpiod (LED blinking, almost there). Haven't gotten the actual cassette deck or CD player yet — that's next. Audio routing, switching logic, and the cardboard build haven't been started :(


## Hardware:
Raspberry Pi 3 Model B (2015, v1.2),
Cassette deck (TBD — thrifted),
CD player (TBD — thrifted),
non soldering breadboard, jumper wires, LED (for GPIO learning phase)
Corrugated cardboard enclosure,
Planned:(USB audio interface or ADC, LCD module, IMU)


## Why this project:
This project has two main purposes. The first is that I used to have a 2001 tacoma that had a cassette and CD player that got sold immediately after leaving for college which means that I now have a collection of cds and Cassetes that I can't use. I'm also aiming for computer hardware engineering roles (with interest in bioelectronics), and wanted a project that forces me to actually work with electronics hands-on instead of just writing software so I thought this would actually be the best of both worlds. 

## A few things this is meant to build:
reading through low-level docs and library source instead of relying on tutorials (I basically learned libgpiod like this by just going straight to the raw header file), debugging at the circuit level instead of just in code, tracing signals on real hardware, and eventually handling real-time audio and source-switching logic in C.
