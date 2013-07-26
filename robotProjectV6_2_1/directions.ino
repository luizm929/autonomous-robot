void Fwd(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
 // motor1.setSpeed(255);
  //motor2.setSpeed(255);
  delay(10);
  //int distance = chkDistance();//distanceLeft has the new value of chkDistance
  //return distanceLeft;
}

void Back(){
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  //motor1.setSpeed(255);
  //motor2.setSpeed(255);
  delay(10);
  int distance = chkDistance();//distanceLeft has the new value of chkDistance
}

void Halt(){
motor1.run(RELEASE);
  motor2.run(RELEASE);
  //motor1.setSpeed(255);
  //motor2.setSpeed(255);
  delay(10);
  int distance = chkDistance();//distanceLeft has the new value of chkDistance
}

int TurnLeft(){
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  delay(10);
  int distanceLeft = chkDistance();//distanceLeft has the new value of chkDistance
  return distanceLeft;
}

int TurnRight(){
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  delay(10);
  int distanceRight = chkDistance(); //distanceRight has the new value of chkDistance
  return distanceRight;

}
