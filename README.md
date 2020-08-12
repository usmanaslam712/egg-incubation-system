# egg-incubation-system
This project is primarily an Egg Incubation System that artificially takes over the concept of a hen hatching an egg. The project hatches eggs at a respective optimum temperature.

# Components required
1. DHT11 or DHT22 temperature sensor
2. Filament bulb (used as a heating source)
3. AC fan
4. 2 channel relay module
5. AC wires
6. Arduino UNO
7. Connecting wires

# Working
The DHT11 acts as a source of input and senses the temperature and humidity. You can easily select the temperature you want as a limit. If the temperature is higher than the limit than the ac fan will turn on as a cooling source. If let's suppose the environment of the system is a bit cold for the eggs than the the filament bulb turns on and it serves as a heating source. Based on the environment of the incubator either the fan or bulb will turn on.

# Arduino Connections
Here an Ardunio UNO was used further details can be found in code. Pin connections are as follows:
1. Pin 10 (arduino) -> IN1 Relay pin (for bulb)
2. Pin 11 (arduino) -> IN2 Relay pin (for ac fan)
3. Pin 2 (arduino) -> Data pin of temperature sensor
4. 5V pin (arduino) -> VCC Relay pin (for powering the relay)
5. 3.3V pin (arduino) -> VCC temperature sensor pin (for powering the sensor)
6. GND pin (arduino) -> GND pin of temperature sensor
7. GND pin (arduino) -> GND pin of relay

# Suggestions
If you do not have any proper container as a incubator then a shoe box or milk carton may suffice. Make holes and insert the temperature sensor, bulb and fan.
A PC size fan may suffice but please make sure it's AC.

# Disclaimer
1. Any temperature sensor maybe used but here DHT11 three pin version was used. Please consult the internet to understand how tmperature sensors work.
2. How code works has been explained in the comments in the code.
3. Here a single AC source was used but you can use two to seperately control the devices via AC.

# Precautions
1. Please be careful when using AC devices and working with AC voltage.
2. Do cover up all naked AC wires with electrical tape.
3. DO NOT use non operational plugs.
