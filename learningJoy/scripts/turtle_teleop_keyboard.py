#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Joy

from keyboard import key_down


# Author: Andrew Dai
# Adaptation: Alastair Straker

# This ROS Node converts Joystick inputs from the joy node
# into commands for turtlesim

# Receives joystick messages (subscribed to Joy topic)
# then converts the joysick inputs into Twist commands
# axis 1 aka left stick vertical controls linear speed
# axis 0 aka left stick horizonal controls angular speed

moveBindings = {
		'u':(1,0,0,1),
		'd':(0,0,-1,0)
}


def callback(data):
    key = key_down()
    keyValue = data 

    if(keyValue == value1)
	keyValue = 80
    elif
	keyValue = 0
    else
        keyValue = 0
    

    pub.publish(keyValue)
    

# Intializes everything
def start():
    # publishing to "turtle1/cmd_scoop" to control turtle1
    global pub
    pub = rospy.Publisher('turtle1/cmd_scoop', int, queue_size=10)
    # subscribed to keyboard keypresses on topic keydown
    rospy.Subscriber("keyboard", keydown, callback)
    # starts the node
    rospy.init_node('KeyboardToScoop')
    print('Done')
    rospy.spin()
    

if __name__ == '__main__':
    start()
