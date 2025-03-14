#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int32

nodeName = 'messagePublisher'
topicName = 'information'

# Initialize the ROS node
rospy.init_node(nodeName, anonymous=True)

# Create a publisher object
publisher1 = rospy.Publisher(topicName, Int32, queue_size=5)

# Set the publishing rate to 1Hz
ratePublisher = rospy.Rate(1)

# Initialize the message content
intMessage = 1

# Main loop: keep publishing until ROS is shutdown
while not rospy.is_shutdown():
    rospy.loginfo(f"Publishing message: {intMessage}")  # Correct loginfo syntax
    publisher1.publish(intMessage)  # Publish the message
    intMessage += 1  # Increment the message
    ratePublisher.sleep()  # Wait to maintain 1Hz rate
