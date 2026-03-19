#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

using namespace std::chrono_literals;

class PublisherClassNode : public rclcpp::Node
{
    public:
        PublisherClassNode() : Node("cpp_publisher"), name_("Robot Example")          // Node name
        { 
            publisher_ = this->create_publisher<example_interfaces::msg::String>("data_news", 10);       // Initialize in the constructor
            timer_ = this->create_wall_timer(0.5s,std::bind(&PublisherClassNode::publishNews, this));
            RCLCPP_INFO(this->get_logger(),"The cpp_publisher node has been started!");

        }
    private:
        void publishNews()                                      // Method to publish                  
        {
            auto msg = example_interfaces::msg::String();       // String object
            msg.data = std::string("Hello world, this is a ") + name_ + std::string("from ros2 cpp example");
            publisher_->publish(msg);
        }        

        std::string name_;
        rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;      // Create a publisher
        rclcpp::TimerBase::SharedPtr timer_;
};


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);                                   // Initialize ros2 communication
    
    auto node = std::make_shared<PublisherClassNode>();         // It is created a node using smart pointer of NodeClass
    rclcpp::spin(node);                                         // Keep the node alive until Ctrl+c

    rclcpp::shutdown();
    return 0;
}