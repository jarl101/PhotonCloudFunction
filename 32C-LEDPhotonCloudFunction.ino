
int redLED = D7;
int yellowLED = D6;
int greenLED = D5;


bool redOn = false;
bool yellowOn = false;
bool greenOn = false;


int ledToggle(String command);


void setup()
{

   pinMode(redLED, OUTPUT);
   pinMode(yellowLED, OUTPUT);
   pinMode(greenLED, OUTPUT);

   // We are also going to declare a Particle.function so that we can turn the LED on and off from the cloud.
   Particle.function("led",ledToggle);
   // This is saying that when we ask the cloud for the function "led", it will employ the function ledToggle() from this app.

   digitalWrite(redLED, LOW);
   digitalWrite(yellowLED, LOW);
   digitalWrite(greenLED, LOW);

}


void loop()
{
   // Nothing to do here
}


int ledToggle(String command) {


    if (command=="red") {
        if (redOn == false) {
            digitalWrite(redLED,HIGH);
            redOn = true;
            return 5;
        }
        else if (redOn == true) {
            digitalWrite(redLED,LOW);
            redOn = false;
            return 4;
        }
        
    }
    else if (command=="yellow") {
        if (yellowOn == false) {
            digitalWrite(yellowLED,HIGH);
            yellowOn = true;
            return 3;
        }
        else if (yellowOn == true) {
            digitalWrite(yellowLED,LOW);
            yellowOn = false;
            return 2;
        }
    }
    else if (command=="green") {
        if (greenOn == false) {
            digitalWrite(greenLED,HIGH);
            greenOn = true;
            return 1;
        }
        else if (greenOn == true) {
            digitalWrite(greenLED,LOW);
            greenOn = false;
            return 0;
        }
    }
    else {
        return -1;
    }

}