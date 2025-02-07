# EdgeML-Arduino

## Pre-requistes
This project targets the Arduino Arduino Nano 33 BLE Sense and Nicla Sense ME. Before your start, please download the required support libraries in your Arduino IDE. Also, please make sure you have the latest Arduino IDE version installed before your start.

## How to install
1. Open the Arduino library manager
<img src="https://user-images.githubusercontent.com/11386075/143419661-5aa339dd-e5c2-4891-a28e-72831c764fa2.png" alt="alt text" width="500">

2. Install the edge-ml library using the integrated libary manager in the Arduino-IDE by searching for "EdgeML-Arduino".
<img src="https://user-images.githubusercontent.com/11386075/143421304-d4ab20ff-c1e8-48bf-a3cd-6134e3c5b25e.png" alt="alt text" width="500">

3. Once you are asked if you would like to install the required dependencies, select "Install all". (Note: if you already have the required dependencies installed at some point in the past this dialog will not show).
<img src="https://user-images.githubusercontent.com/11386075/143424434-37db4466-d471-4cae-9255-2247005d761e.png" alt="alt text" width="500">




4. Select your board from the boards manager (Arduino Nano 33 BLE or Nicla Sense ME)
<img src="https://user-images.githubusercontent.com/11386075/143422287-a209679a-7235-4249-9318-d7d7ad92a4c4.png" alt="alt text" width="500">

5. Connect your Arduino to your PC via Micro USB cable and select the port your Arduino is connected to (in this example the Nicla Sense ME, if you have a Nano 33 BLE Sense, then select the port it shows up on)
<img src="https://user-images.githubusercontent.com/11386075/143423313-cb7e4a89-c305-4ad8-9213-96d3bedc845d.png" alt="alt text" width="500">

6. Open the edge-ml firmware app by selecting it from the list of examples.
<img src="https://user-images.githubusercontent.com/11386075/143424987-a3ec925c-97e2-4a3b-bdf5-9425324a5603.png" alt="alt text" width="500">

7. Flash it onto your Arduino board by hitting the upload button (this may take a while).
<img src="https://user-images.githubusercontent.com/11386075/143425338-2db4c4f1-b4d1-455f-850a-fac7556417ef.png" alt="alt text" width="200">

8. You can now connect to your Arduino from edge-ml.

## Github actions firmware compilation
Currently, the firmware for the Nicla Sense ME, the Nano 33 BLE and the Seeed Xiao nRF52840 Sense is compiled using GitHub actions and are provided as build artifacts. Artifacts can be downloaded through the following links:

| Board                     | Firmware                                                                       |
|---------------------------|--------------------------------------------------------------------------------|
| Nicla Sense ME            | https://nightly.link/edge-ml/EdgeML-Arduino/workflows/build/main/nicla.bin.zip |
| Nano 33 BLE               | https://nightly.link/edge-ml/EdgeML-Arduino/workflows/build/main/nano.bin.zip  |
| Seeed Xiao nRF52840 Sense | https://nightly.link/edge-ml/EdgeML-Arduino/workflows/build/main/xiao.bin.zip  |

## Attribution
This repository contains code from https://github.com/arduino-libraries/Arduino_BHY2
