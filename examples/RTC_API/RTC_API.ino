/*
  Example to demonstrate the Arduino Core API for RealTimeClock

  This example code is in the public domain
*/

#include <RTCZero.h>

/* Create an RTCZero object */
RTCZero zeroRtc;

void setup() {
  Serial.begin(9600);
  zeroRtc.begin(); // initialize RTC
}

void loop() {
  // Bound the RTCZero to the main RTC base class
  RealTimeClock &rtc = zeroRtc;

  // ------------------------------------------------
  // From here we will only use the RealTimeClock API
  // ------------------------------------------------

  rtc.setTime(Timestamp(1619622702));

  for (;;) {
    printCurrentHour(rtc);
    delay(1000);
  }
}

void printCurrentHour(RealTimeClock &rtc) {
  auto t = rtc.getTime();
  char *days[] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                  "Thursday", "Friday", "Saturday"};
  Serial.print(t.getUnixTimestamp());
  Serial.print(" -> ");
  Serial.print(days[t.weekDay()]);
  Serial.print(" ");
  print2digits(t.day());
  Serial.print("/");
  print2digits(t.month());
  Serial.print("/");
  print2digits(t.year());
  Serial.print(" ");
  print2digits(t.hour());
  Serial.print(":");
  print2digits(t.minute());
  Serial.print(":");
  print2digits(t.second());
  Serial.println();
}

void print2digits(int number) {
  if (number < 10) {
    Serial.print("0"); // print a 0 before if the number is < than 10
  }
  Serial.print(number);
}