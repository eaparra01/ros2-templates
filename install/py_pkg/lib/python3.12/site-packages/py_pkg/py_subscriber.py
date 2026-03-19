#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String


class SubscriberClassNode(Node):                                                # This class inherits functionalities from the ros2 node from rclpy

    def __init__(self):                                                         # Constructor
        super().__init__("py_subscriber") 
         
        self.subscriber_ = self.create_subscription(                            # Create a subscriber with the interface, topic name and callback   
            String, "data_news", self.callback_data_news, 10)
        self.get_logger().info("The py_subscriber has been started!")

    def callback_data_news(self, msg: String):                                  # The callback is named adding the topic name
        self.get_logger().info(msg.data)

    
def main(args=None):
    rclpy.init(args=args)               # Initialize ros2 communication
    node = SubscriberClassNode()
    rclpy.spin(node)                    # Keep the node alive until Ctrl+c
    rclpy.shutdown()                    # End ros2 communication

if __name__ == "__main__":
    main()