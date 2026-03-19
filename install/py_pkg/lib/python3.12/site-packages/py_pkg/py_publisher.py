#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String


class PublisherClassNode(Node):                                                 # This class inherits functionalities from the ros2 node from rclpy

    def __init__(self):                                                         # Constructor
        self.cnt = 1
        super().__init__("py_publisher")                                        # Node name is the same for the file name
        self.publishers_ = self.create_publisher(String, "data_news", 10)       # Create a publisher with the interface and topic name
        self.timer_ = self.create_timer(0.5, self.publish_news)                 # Timer that calls the timer_callback every 0.5 seg
        self.get_logger().info("The py_publisher node has been started!")
        

    def publish_news(self):
        msg = String()
        msg.data = "Hi, this is a py_publisher news "+ str(self.cnt)+" times !!!" 
        self.publishers_.publish(msg)
        self.cnt +=1


def main(args=None):
    rclpy.init(args=args)               # Initialize ros2 communication
    node = PublisherClassNode()
    rclpy.spin(node)                    # Keep the node alive until Ctrl+c
    rclpy.shutdown()                    # End ros2 communication

if __name__ == "__main__":
    main()