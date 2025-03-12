# <u>Second Try</u>

This part I am going to create a pubisher and subcriber in ROS and communicate with Arduino board. This time it will be two way communication.

![ROS Arduino Communication](img/ros_arduino_communicaion.png)

>Scenario:
>Once the ROS publish a message to 'information' topic. Then Arduino will subscribe information from that topic, make it twise and publish the result to 'info_back' topic.

1. First created a package inside the folder using below command;

```catkin_create_pkg ros-arduino-led-control std_msgs rospy roscpp```

- Have been added some depedencies like std_msgs, rospy and roscpp.

2. Then created the `publisherArduino.py` and `subscriberArduino.py` for ROS commication.

3. Change the file persimmison as executables using;

```chmod +x publisherArduino.py```
```chmod +x subscriberArduino.py```

4. Created Arduino file _IntegerMultipleByArduino_.

5. Upload the file to Arduino.

![Second Try Arduino Code Uploading](img/SecondTry_ArduinoCodeUploading.png)

6. Run the publisher file

![Second Try Publisher](img/secondTry_Publisher.png)

7. Run the subcriber file

![Second Try Subscriber](img/secondTrySubscriber.png)

8. RQT Graph

![Second Try RQT Graph](img/secondTryRqt.png)


8. Communication is successfull !!!.