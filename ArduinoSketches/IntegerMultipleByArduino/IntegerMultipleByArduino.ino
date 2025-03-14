#include <ros.h>
#include <std_msgs/Int32.h>

#define LED1 13 //Inbuilt LED
#define LED2 8 // BLue LED

ros::NodeHandle nh;
std_msgs::Int32 outputMessage;
ros::Publisher pub("info_back", &outputMessage); // Renamed object & topic

void callBackFunction(const std_msgs::Int32 &inputMessage){
  outputMessage.data=2*inputMessage.data;
  if (inputMessage.data == 1){
    digitalWrite(LED1, HIGH);  // Turn LED1 on
    delay(500);               // Wait for a second
    digitalWrite(LED2, LOW);   // Turn LED1 off
    delay(500);
    outputMessage.data = 1;
  }
  else if (inputMessage.data == 2){
    digitalWrite(LED2, HIGH);  // Turn LED1 on
    delay(500);               // Wait for a second
    digitalWrite(LED1, LOW);   // Turn LED1 off
    delay(500);  
    outputMessage.data = 2;
    }
  pub.publish(&outputMessage);
}

ros::Subscriber<std_msgs::Int32> sub("information", &callBackFunction);

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  nh.initNode();
  nh.advertise(pub);
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(1);
}
