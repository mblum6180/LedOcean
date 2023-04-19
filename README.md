LED Ocean

LED Ocean is a dynamic lighting project that simulates the look and feel of ocean waves and water, providing a visually appealing and calming effect. The project is designed to work with an ESP32 microcontroller and individually addressable WS2812B LED strips. It also features a day/night sensor that adjusts the lighting based on ambient light conditions.
Features

    Realistic ocean wave simulation using FastLED library
    Day/Night sensor for adaptive lighting
    Customizable animation parameters (e.g., wave speed, color palette)
    Energy-efficient design, suitable for outdoor use

Hardware Requirements

    ESP32 microcontroller
    WS2812B individually addressable LED strip
    LDR (Light Dependent Resistor) for day/night sensing
    10K Ohm resistor
    Breadboard or custom PCB
    Jumper wires and connectors
    Power supply for LED strip

Software Requirements

    Arduino IDE
    FastLED library

Getting Started

    Install the Arduino IDE: Download and install the Arduino IDE from the official website: https://www.arduino.cc/en/software

    Install the FastLED library: In the Arduino IDE, go to Sketch > Include Library > Manage Libraries.... Search for "FastLED" and install the latest version.

    Connect the hardware components:
        Connect the LED strip's data line to a valid GPIO pin on the ESP32 (e.g., GPIO5).
        Connect the LED strip's ground and power lines to the power supply's ground and voltage output, respectively.
        Set up the LDR voltage divider: Connect one end of the LDR to 3.3V, the other end to an analog input pin (e.g., GPIO34), and also to one end of the 10K Ohm resistor. Connect the other end of the resistor to the ground.

    Load the LED Ocean sketch: Open the Arduino IDE, and copy the LED Ocean sketch code into a new project.

    Configure the sketch: Update the #define statements in the sketch to match your hardware configuration (e.g., data pin, number of LEDs, LDR pin).

    Upload the sketch: Connect your ESP32 to your computer via USB, select the correct board and port in the Arduino IDE, and click Upload.

    Enjoy the LED Ocean! Once the sketch is uploaded, the LED strip will display the ocean animation, adjusting its brightness and colors based on the ambient light conditions.

Customization

You can customize various parameters of the LED Ocean sketch to achieve different visual effects or adjust the behavior of the day/night sensor. Some customizable parameters include:

    Wave speed
    Color palette
    Day/night sensitivity

Contributing

We welcome contributions to improve the LED Ocean project. If you have any ideas or suggestions, please feel free to open an issue or submit a pull request.

This library is released under the GNU General Public License v3.0. See the LICENSE file for more information.
