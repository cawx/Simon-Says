// Game variables
bool gameStart = false;
bool playerTurn = false;
bool gameOver = true;
int doneRounds = 0; // how many rounds has player done
int rounds = 5; // how long will the game be
int leds[] = {10, 11, 12, 13}; // array of LEDs

void setup() {
  // LEDs
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  // game buttons
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  // start button
  pinMode(6, INPUT);
  // piezo
  //pinMode(7, OUTPUT);
  startAnimation();
}

void loop() {
  // waiting for game start
  while(gameStart == false) {
    int startBtn = digitalRead(6);
    if(startBtn == HIGH) {
      gameStart = true;
      gameOver = false;
    }
  }
  // game start
  int cMoves[5]; 
  for(int i = 0; i < rounds; i++) {
    delay(1000);
    // computers turn
    int randomMove = random(0, 4);
    cMoves[i] = leds[randomMove];
    // computer shows its turns
    for(int j = 0; j < i + 1; j++) {
      lowAll();
      digitalWrite(cMoves[j], HIGH);
      delay(300);
      digitalWrite(cMoves[j], LOW);
      delay(300);
    }
    // players turn
    playerTurn = true;
    doneRounds = 0;
    // while loop to get players input
    while(playerTurn == true) {
        if(digitalRead(5) == HIGH) {
          if(cMoves[doneRounds] == 13) {
            move(13);
            doneRounds++;
          } else {
            gameOver = true;
          }
        } else if(digitalRead(4) == HIGH) {
          if(cMoves[doneRounds] == 12) {
            move(12);
            doneRounds++;
          } else {
            gameOver = true;
          }
        } else if(digitalRead(3) == HIGH) {
          if(cMoves[doneRounds] == 11) {
            move(11);
            doneRounds++;
          } else {
            gameOver = true;
          }
        } else if(digitalRead(2) == HIGH) {
          if(cMoves[doneRounds] == 10) {
            move(10);
            doneRounds++;
          } else {
            gameOver = true;
          }
        }
        if(gameOver == true) {
          lowAll();
          gameStart = false;
          playerTurn = false;
          gameOverAnimation();
          delay(1000);
          i = rounds;
        }
        if(i+1 == doneRounds) {
          playerTurn = false;
        }
      }
    
  }
  // Rounds over, game ends
  gameStart = false;
  startAnimation();
}

// flashes the LED of which button was pressed
void move(int led){
  lowAll();
  digitalWrite(led, HIGH);
  delay(300);
  digitalWrite(led, LOW);
}
// turns off all LEDs
void lowAll() {
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}

// self-explanatory
void startAnimation() {
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  delay(100);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}
// self-explanatory
void gameOverAnimation() {
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  delay(300);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(300);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  delay(300);
  digitalWrite(13, LOW);
  delay(100);
  digitalWrite(12, LOW);
  delay(100);
  digitalWrite(11, LOW);
  delay(100);
  digitalWrite(10, LOW);
  
}
