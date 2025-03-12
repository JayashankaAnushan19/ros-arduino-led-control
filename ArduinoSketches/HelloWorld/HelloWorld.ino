/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;
std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[20] = "Hello Jayashanka!";
char buffer[50]; // Buffer to hold concatenated string

void setup()
{
  nh.initNode();
  nh.advertise(chatter);
}

int no = 1;

void loop()
{
  sprintf(buffer, "%s %d", hello, no);  // Correct way to concatenate
  str_msg.data = buffer; 
  chatter.publish(&str_msg);
  nh.spinOnce();
  delay(500);
  no = no + 1; // Missing semicolon fixed
}
