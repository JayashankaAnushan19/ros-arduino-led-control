#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int32
import sys, select, termios, tty

nodeName = 'messagePublisher'
topicName = 'information'

# Save the existing terminal settings
settings = termios.tcgetattr(sys.stdin)

def getKey():
    tty.setraw(sys.stdin.fileno())  # Set terminal to raw mode
    key = None
    try:
        if select.select([sys.stdin], [], [], 0.1)[0]:
            key = sys.stdin.read(1)  # Read one character
            if key == '\x1b':  # Check for arrow key sequence
                key += sys.stdin.read(2)  # Read additional two characters for arrow keys
    except Exception as e:
        print(f"Error reading key: {e}")
    finally:
        # Restore terminal settings
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key


def main():
    rospy.init_node(nodeName, anonymous=True)
    publisher1 = rospy.Publisher(topicName, Int32, queue_size=5)

    ratePublisher = rospy.Rate(1)

    user_input_value = 0

    # Main loop: keep publishing until ROS is shutdown
    while not rospy.is_shutdown():
        key = getKey()
        if key:
            if key == "1":
                user_input_value = 1
            elif key == "2":
                user_input_value = 2
            elif key == "q":
                break
            else:
                user_input_value = 0

        rospy.loginfo(f"Publishing message: {user_input_value} | key: {key}")
        publisher1.publish(user_input_value)  # Publish the message
        # ratePublisher.sleep()  # Maintain 1Hz rate
        user_input_value = 0

if __name__ == '__main__':
    main()