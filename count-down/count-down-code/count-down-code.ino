// Global Variable
int PIN_A = 2;
int PIN_B = 3;
int PIN_C = 4;
int PIN_D = 5;
int PIN_E = 6;
int PIN_F = 7;
int PIN_G = 8;

int POW1 = 13; // right
int POW2 = 12; // left

int i = 0;
int j = 0;
int n = 0;
int limit = 0;

int arduinoPins[7] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G};
int segmentValues[10][7] = {
  {1,1,0,1,1,1,1}, //9
  {1,1,1,1,1,1,1}, //8
  {0,0,0,0,1,1,1}, //7
  {1,1,1,1,1,0,1}, //6
  {1,1,0,1,1,0,1}, //5
  {1,1,0,0,1,1,0}, //4
  {1,0,0,1,1,1,1}, //3
  {1,0,1,1,0,1,1}, //2
  {0,0,0,0,1,1,0}, //1
  {0,1,1,1,1,1,1} //0
};


void setup() {
 // pin setup
 pinMode(PIN_A, OUTPUT);
 pinMode(PIN_B, OUTPUT);
 pinMode(PIN_C, OUTPUT);
 pinMode(PIN_D, OUTPUT);
 pinMode(PIN_E, OUTPUT);
 pinMode(PIN_F, OUTPUT);
 pinMode(PIN_G, OUTPUT);
 
 pinMode(POW1, OUTPUT);
 pinMode(POW2, OUTPUT);
}

void loop() {
  
 for(; limit <= 9;){
   for(i = 0; i < 10; i++){
    digitalWrite(POW1, 0);
    digitalWrite(POW2, 1); // left

    //display one digit 
    for(j = 0; j < 7; j++){
      digitalWrite(arduinoPins[j], segmentValues[n][j]);
    }
    delay(50);

    //display one digit 
    digitalWrite(POW1, 1); //right
    digitalWrite(POW2, 0);
    for(j = 0; j < 7; j++) {
      digitalWrite(arduinoPins[j], segmentValues[i][j]);
    }
    delay(50);
    
    if(i==9){
      n++;
      limit++; //for stop the counting after 10 second.
      if(n > 9){
        n=0;
     }
    }
   }

   
  } //end limit loop


  // after finish stop timmer and  continue display 0
    digitalWrite(POW1, 0);
    digitalWrite(POW2, 1); // left
    //display 0 
    for(j = 0; j < 7; j++){
      digitalWrite(arduinoPins[j], segmentValues[9][j]);
    }
}


// Group-C
