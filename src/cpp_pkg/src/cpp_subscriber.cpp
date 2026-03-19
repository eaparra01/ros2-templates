#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"


class SubscriberClassNode : public rclcpp::Node
{
    public:
        SubscriberClassNode() : Node("cpp_subscriber")              // Node name
        {
            subscriber_ = this->create_subscription<example_interfaces::msg::String>(
                "data_news",10, std::bind(&SubscriberClassNode::callback_data_news, this, std::placeholders::_1));
                RCLCPP_INFO(this->get_logger(), "The cpp_subscription has been started!");
        }
        
    private:
        void callback_data_news(const example_interfaces::msg::String::SharedPtr msg)
        {
            RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str());
        }
        rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber_;       // Create a publisher
};


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);                                       // Initialize ros2 communication
    
    auto node = std::make_shared<SubscriberClassNode>();            // It is created a node using smart pointer of NodeClass
    rclcpp::spin(node);                                             // Keep the node alive until Ctrl+c

    rclcpp::shutdown();
    return 0;
}