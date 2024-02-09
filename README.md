# Stopwatch
![image](https://github.com/Mazen-Omar/Stopwatch/assets/112568201/67e27d7a-6696-4225-97e9-de65d64bf05c)


#### Purpose
The application.c file contains the implementation of the application layer functionalities for controlling a timer system. It initializes various hardware components such as buttons, 7-segment display, and control pins, and then runs a timer loop based on button inputs.

#### Button and Hardware Initialization:
The file initializes multiple buttons (start, stop, pause, speed_up, reset) with their respective configurations such as port, pin, direction, logic, and initial state.
It also initializes control pins (control_1 to control_6) and a 7-segment display (seg).

#### Main Loop
The main loop continuously checks for the state of the start button. Once pressed, it triggers the timer functionality.
Inside the timer loop, it updates the timer values (hours, minutes, seconds) and displays them on the 7-segment display.
It handles additional functionalities like speed adjustment (speed_up button), pausing the timer (pause button), stopping the timer (stop button), and resetting the timer (reset button).

#### Timer Operation
I handled the timer operation using a loop. The timer increments seconds and updates minutes and hours accordingly. It also handles rollover conditions for hours.

#### Button Inputs Handling
Button inputs are continuously monitored in the loop. Different button presses trigger various actions such as starting, pausing, stopping, and resetting the timer.

#### Summary
The application.c file provides the implementation for a timer system, utilizing hardware components like buttons and a 7-segment display. It manages timer operations and button inputs to control the timer's behavior effectively.
