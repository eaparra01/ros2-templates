#!/usr/bin/env python3
import rclpy
from rclpy.node import Node


class NodeClass(Node):  # CHANGE THE CLASS NAME   # This class inherits functionalities from the ros2 node from rclpy

    def __init__(self):                 # Constructor
        super().__init__("py_test")     # Node name
        self.cnt = 1
        self.get_logger().info("Hello, this is the ros2 py template!")
        self.create_timer(1.0, self.timer_callback)       # Timer that calls the timer_callback every 1.0 seg

    def timer_callback(self):
        self.get_logger().info("Hello, the timer_callback is called " + str(self.cnt) +"!")
        self.cnt += 1

def main(args=None):
    rclpy.init(args=args)               # Initialize ros2 communication
    node = NodeClass()                  # CHANGE THE CLASS NAME
    rclpy.spin(node)                    # Keep the node alive until Ctrl+c
    rclpy.shutdown()                    # End ros2 communication

if __name__ == "__main__":
    main()