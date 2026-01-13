## Detailed Working Principle
The Line Following Robot operates as a closed-loop feedback system that translates environmental data into mechanical movement. This simulation specifically addresses the challenges of testing sensor logic in a virtual environment.

### 1. Sensing & Simulation Logic (Input Layer)
The robot is designed to navigate by reading binary inputs from two sensors located at the front.

Actual Hardware: The physical implementation is intended to use Infrared (IR) sensors to detect the contrast between the line and the floor.

Simulation Constraints: In the Tinkercad simulator, PIR sensors are used to represent the sensor logic. However, PIR sensors only stay HIGH for a very short duration after detecting motion.

Manual Simulation Switches: To overcome the "pulse" nature of the PIR sensors during simulation, slide switches are wired in parallel with each sensor. This allows the user to manually "lock" a sensor state to HIGH. For example, to simulate sustained Forward Movement, the user can slide both switches to the HIGH position, ensuring both input pins receive a constant signal simultaneously.

### 2. Control & ActuationMicrocontroller: 
An Arduino UNO serves as the processing unit, reading inputs from Pins 2 and 3.Motor Driver: The L293D IC manages the high-current requirements of the DC motors using signals from pins 8, 9, 10, and 11.Visual Indicators: The design includes Green and Yellow LEDs with $1k\Omega$ resistors to provide real-time visual feedback on the logic execution.

### 3. Logic & Movement Table
The movement is determined by the combined state of the sensor/switch inputs:

| Left Input (Pin 2) | Right Input (Pin 3) | Robot Action | Left Motor | Right Motor |
| :--- | :--- | :--- | :--- | :--- |
| **HIGH** | **HIGH** | Forward | Forward | Forward |
| **LOW** | **HIGH** | Turn Left | Stop | Forward |
| **HIGH** | **LOW** | Turn Right | Forward | Stop |
| **LOW** | **LOW** | Stop | Stop | Stop |
