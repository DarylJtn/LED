bool ButtonPush() {
  Serial.println("ButtonPush");
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    Serial.println("Button");
    return true;

  } else {
    return false;
  }

}

bool buttonDelay(int ms){
  int startTime = millis();
  while(millis() < startTime+ms){
    if(ButtonPush() == true){
      return true;
      }
    }
    return false;
  }
