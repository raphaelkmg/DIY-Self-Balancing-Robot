# DIY Self Balancing Robot (Arduino)

## Overview

This open‑source project is a **self‑balancing robot** built around the Arduino Nano 33 BLE.  It combines a 3D‑printed chassis, two geared drive motors, a 6‑axis inertial sensor and a motor driver to keep itself upright.  The robot provides a fun way to explore control theory and embedded programming while producing a compact and rugged device suitable for experimentation.

## Motivation

Balancing robots are an excellent introduction to proportional–integral–derivative (PID) control and sensor fusion.  Traditional two‑wheel designs can be expensive or require specialized parts, so this project uses commonly available components and a custom chassis you can print at home.  The goal is to provide a starting point for hobbyists and students to experiment with balancing algorithms and expand the design.

## How to Use

1. **Print the parts** – Download the STL files from this repository and print them in PLA or PETG.  The chassis pieces are designed to print without supports.
2. **Assemble the hardware** – Mount the DC gear motors in the base, attach the wheels and install the motor driver.  Solder or connect the MPU‑6050 sensor and Arduino Nano 33 BLE to the driver board.  Use the provided battery holder and two 18650 cells to power the robot.  Secure everything using M3 screws and nuts.
3. **Upload the firmware** – In the `firmware` folder you’ll find a basic Arduino sketch that reads the IMU and drives the motors.  Open the sketch in the Arduino IDE, select “Arduino Nano 33 BLE” as the board, install the required libraries (Wire and LSM6DS3) and upload.
4. **Calibrate and test** – Place the robot upright on a flat surface.  Adjust the PID gains in the sketch until the robot balances stably.  Keep the robot away from edges and obstacles while tuning.

## File Organization

- **images/** – Project diagrams and renders.  The conceptual render below gives a high‑level view of the robot.  Replace it with a render of your actual CAD model once it’s complete.
- **firmware/** – Arduino sketch implementing the balancing algorithm.
- **BOM.csv** – Bill of materials with purchase links.
- **model.step** – A STEP file representing the assembled robot.  Use a CAD program (Fusion 360, FreeCAD, etc.) to view or modify the model.

<!-- TODO: Add a render or photo of the completed self-balancing robot here -->

## Bill of Materials

| Item                           | Quantity | Purchase Link |
|--------------------------------|---------:|--------------|
| Arduino Nano 33 BLE           | 1        | https://store.arduino.cc/products/arduino-nano-33-ble |
| L298N dual H‑bridge driver    | 1        | https://www.amazon.com/dp/B07QMYLTDL |
| 37 mm DC gear motor with wheel| 2        | https://www.amazon.com/dp/B01N4JNWH3 |
| MPU‑6050 IMU module           | 1        | https://www.amazon.com/dp/B07RF93YFQ |
| 18650 Li‑ion battery          | 2        | https://www.amazon.com/dp/B07RGSTVL2 |
| 2‑cell 18650 battery holder   | 1        | https://www.amazon.com/dp/B07Q2Y3Z51 |
| M3 screws and nuts (assort.)  | 1 set    | https://www.amazon.com/dp/B06XFS56S1 |
| Wires and connectors          | as req. | — |

## License

This project is released under the MIT License.  See the `LICENSE` file for details.
