#define LED_PIN 4
#define BT_LEFT 7
#define BT_RIGHT 8
#define BT_BEAM 6

#define MIN_INTERVAL 1000

int STOP = false;
int LED_STATE = 0;
int INTERVAL = 500;
int OLD = millis();
int BT_LEFT_LASTPRESS = millis();
int BT_RIGHT_LASTPRESS = millis();
int BT_UP_LASTPRESS = millis();

void setup () {
    pinMode(BT_LEFT, INPUT);
    pinMode(BT_RIGHT, INPUT);
    pinMode(BT_BEAM, INPUT);
    Serial.begin(9600);
    //Keyboard.begin();
}

void loop () {
  //Serial.println(digitalRead(BUT2_PIN));
 if(STOP == false){ 
    
    int btup = digitalRead(BT_BEAM); // Read button state
    if(btup == HIGH){
      int btup_now = millis();
      if(btup_now - MIN_INTERVAL >= BT_UP_LASTPRESS){
        Serial.println("button BEAM pressed.");
        BT_UP_LASTPRESS = millis();
        //Keyboard.press(KEY_UP_ARROW);
      }
    }
    int btleft = digitalRead(BT_LEFT); // Read button state
    if(btleft == HIGH){
      int btleft_now = millis();
      if(btleft_now - MIN_INTERVAL >= BT_LEFT_LASTPRESS){
        Serial.println("button LEFT pressed.");
        BT_LEFT_LASTPRESS = millis();
        //Keyboard.press(KEY_LEFT_ARROW);
      }
    }
    
    int btright = digitalRead(BT_RIGHT); // Read button state
    if(btright == HIGH){
      int btright_now = millis();
      if(btright_now - MIN_INTERVAL >= BT_RIGHT_LASTPRESS){
        Serial.println("button RIGHT pressed.");
        BT_RIGHT_LASTPRESS = millis();
        //Keyboard.press(KEY_RIGHT_ARROW);
      }
    }
 }
}
