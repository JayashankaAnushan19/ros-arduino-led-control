#include <ros.h>
#include <std_msgs/Int32.h>

ros::NodeHandle nh;
std_msgs::Int32 outputMessage;
ros::Publisher pub("info_back", &outputMessage); // Renamed object & topic

void callBackFunction(const std_msgs::Int32 &inputMessage){
  outputMessage.data=2*inputMessage.data;
  pub.publish(&outputMessage);
}

ros::Subscriber<std_msgs::Int32> sub("information", &callBackFunction);

void setup()
{
  nh.initNode();
  nh.advertise(pub);
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(1);
}
