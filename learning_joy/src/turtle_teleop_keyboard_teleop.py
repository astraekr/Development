#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Joy

from keyboard import key_down

import sys, select, termios, tty


# Author: Andrew Dai
# Adaptation: Alastair Straker

# This ROS Node converts Joystick inputs from the joy node
# into commands for turtlesim

# Receives joystick messages (subscribed to Joy topic)
# then converts the joysick inputs into Twist commands
# axis 1 aka left stick vertical controls linear speed
# axis 0 aka left stick horizonal controls angular speed

moveBindings = {
		'u':(180),
		'd':(0)
}

def getKey():
    tty.setraw(sys.stdin.fileno())
    select.select([sys.stdin], [], [], 0)
    key = sys.stdin.read(1)
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key
   

if __name__=="__main__":
    	settings = termios.tcgetattr(sys.stdin)
	
	pub = rospy.Publisher('cmd_vel', Twist, queue_size = 1)
	rospy.init_node('teleop_twist_keyboard')

	#speed = rospy.get_param("~speed", 0.5)
	#turn = rospy.get_param("~turn", 1.0)
	x = 0
	#y = 0
	#z = 0
	#th = 0
	status = 0

	try:
		print msg
		#print vels(speed,turn)
		while(1):
			key = getKey()
			if key in moveBindings.keys():
				x = moveBindings[key][0]
			elif key in speedBindings.keys():
				speed = speed * speedBindings[key][0]
				turn = turn * speedBindings[key][1]

				print vels(speed,turn)
				if (status == 14):
					print msg
				status = (status + 1) % 15
			else:
				x = 0
				if (key == '\x03'):
					break

			twist = Twist()
			twist.linear.x = x*speed; twist.linear.y = y*speed; twist.linear.z = z*speed;
			twist.angular.x = 0; twist.angular.y = 0; twist.angular.z = th*turn
			pub.publish(twist)

	except:
		print e

	finally:
		twist = Twist()
		twist.linear.x = 0; twist.linear.y = 0; twist.linear.z = 0
		twist.angular.x = 0; twist.angular.y = 0; twist.angular.z = 0
		pub.publish(twist)

termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
