#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int32

nodeName = 'messageSubs'
topicName = 'info_back'

# Callback function to handle incoming messages
def callBackFunction(message):
    if (message.data == 1):
        print("Light Buil-it LED")
    elif (message.data == 2):
        print("Light Blue LED")
    else:
        print(f"From Arduino, we received: {message.data}") 

# Initialize the ROS node
rospy.init_node(nodeName, anonymous=True)

# Subscribe to the 'info_back' topic
rospy.Subscriber(topicName, Int32, callBackFunction)

ratePublisher = rospy.Rate(1)
ratePublisher.sleep()  # Maintain 1Hz rate
# Keep the node running
rospy.spin()
