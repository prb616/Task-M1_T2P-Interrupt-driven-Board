//Name : prabhjot singh
//roll no. : 2210994884


// Define constant variable 'pir' for PIR sensor connected to pin 2
const int pir = 2;

// Variable to store the PIR sensor state
volatile int pirState = LOW;

void setup()
{
  // Set pin 2 as input for PIR sensor
  pinMode(pir, INPUT);

  // Set built-in LED pin as output
  pinMode(LED_BUILTIN, OUTPUT);

  // Set up the interrupt for pin 2 (pir)
  attachInterrupt(digitalPinToInterrupt(pir), motionDetected, CHANGE);

  // Set serial communication baud rate to 9600
  Serial.begin(9600);
}

void loop()
{
  // Print the PIR sensor state to the serial monitor
  	Serial.println(pirState == HIGH ? "HIGH" : "LOW");
  if(pirState)
  {
    
    // Toggle the built-in LED based on the PIR sensor state
 	 digitalWrite(LED_BUILTIN, pirState);
  }
    delay(500);
}

// Interrupt Service Routine (ISR) for motion detection
void motionDetected()
{
  // Read the state of the PIR sensor
  pirState = digitalRead(pir);

  
}
