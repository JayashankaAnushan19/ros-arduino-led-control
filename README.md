# <u>ROS Arduino LED Control</u>

In this project i am going to communicate between simple ROS program with Arduino Uno board and light a LED. Below is the inialization and configuration steps.

## Install Arduino
For install arduino need to run below code.

```sudo apt install arduino```

This will install Arduino and below code can use to check the version

```arduino --version```

If got any error regarding 'dialout', install below library.

```sudo apt install libcanberra-gtk-module libcanberra-gtk3-module```

run arduino using below code or by search icon via application menu;

```arduino```

## Arduino programming
1. First need to install essential libraries;

```sudo apt install ros-noetic-rosserial```

```sudo apt install ros-noetic-rosserial-arduino```

```sudo apt install ros-noetic-rosserial-python```

2. Then created a folder to save arduino sketches and codes in home folder. _I creatd as "**ArduinoSketches**" in home folder._

3. Then opend Arduino IDE and change the library installation location for above folder.

4. Install ROS Communication library via Arduino IDE.



<continue..>

## Conslusion
## Future enhancement

