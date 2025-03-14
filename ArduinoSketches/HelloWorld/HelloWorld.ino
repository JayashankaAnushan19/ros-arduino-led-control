#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;
std_msgs::String str_msg;
ros::Publisher chatter_object("chatter_node", &str_msg); // Renamed object & topic

char hello[20] = "Hello Jayashanka!";
char buffer[50]; // Buffer to hold concatenated string

void setup()
{
  nh.initNode();
  nh.advertise(chatter_object); // Use renamed publisher object
}

int no = 1;

void loop()
{
  sprintf(buffer, "%s %d", hello, no);  // Correct way to concatenate
  str_msg.data = buffer; 
  chatter_object.publish(&str_msg); // Use renamed publisher object
  nh.spinOnce();
  delay(500);
  no = no + 1; // Increment counter
}
