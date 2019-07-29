int button = 8;
int led = 13; 
int motor = 12;
int status = false;
 
void setup(){ 
pinMode(led, OUTPUT); 
pinMode(button, INPUT_PULLUP); // set the internal pull up resistor, unpressed button is HIGH 
pinMode(motor, OUTPUT);
}
 
void loop(){ 
  digitalWrite(motor, HIGH);
}
