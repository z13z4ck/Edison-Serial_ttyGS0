/*
 * Serial echo for verifying communication with a PC based program
 * On Edison this can talk to a process on the host
 * if you setup socat to create some devices.
 */

//Edison, setup ring buffer and TTYUARTClass
RingBuffer rx_buffer_S1;
TTYUARTClass mySerial(&rx_buffer_S1, 3, false); 

void setup() {
  //for Edison specify the host TTY to connect to
  mySerial.init_tty("/home/root/tty0");
  //now the mySerial instance can be treated just like any Serial instance
  mySerial.begin(115200);
}

void loop()
{
  mySerial.write("A");
  // if(mySerial.available()) {
  //   char in = mySerial.read();
  //   if(in == 'A') {
  //     mySerial.write("$");
  //   } else {
  //     mySerial.write("!");
  //   }
  // }
  delay(500);
}
