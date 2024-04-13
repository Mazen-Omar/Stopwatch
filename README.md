# Stopwatch

![image](https://github.com/Mazen-Omar/Stopwatch/assets/112568201/67e27d7a-6696-4225-97e9-de65d64bf05c)


### Button and Hardware Initialization
The file initializes multiple buttons (start, stop, pause, speed_up, reset) with their respective configurations such as port, pin, direction, logic, and initial state.
It also initializes control pins (control_1 to control_6) and a 7-segment display (seg).

### Main Loop
The main loop continuously checks for the state of the start button. Once pressed, it triggers the timer functionality.
Inside the timer loop, it updates the timer values (hours, minutes, seconds) and displays them on the 7-segment display.
It handles additional functionalities like speed adjustment (speed_up button), pausing the timer (pause button), stopping the timer (stop button), and resetting the timer (reset button)

### Timer Operation
I tried to simulate timer operation. I handled the timer operation using a for loop. The timer increments seconds and updates minutes and hours accordingly. It also handles rollover conditions for hours.

🔑 Key Features of the Stopwatch Project:

🔘 Start Button: Initiates the stopwatch to begin counting time.

🔘 Close Button: Stops the stopwatch and closes the application.

🔘 Reset Button: Resets the stopwatch to zero, allowing for a fresh start.

🔘 Speed Up Button: Increases the timer speed.

🔘 Pause Button: Temporarily halts the stopwatch while maintaining the current time.

🔘 8-Digit 7-Segment Display: Provides a visually stunning representation of the elapsed time, making it easy to read.

