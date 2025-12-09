#include "rclcpp/rclcpp.hpp"

class NodeClass : public rclcpp::Node
{
    public:
        NodeClass() : Node("cpp_test"), counter_(1)     // Node name and initilize the counter
        {
            RCLCPP_INFO(this->get_logger(), "Hello, this is the ros2 cpp template!");
            timer_ = this->create_wall_timer(std::chrono::seconds(1), 
                                             std::bind(&NodeClass::timerCallback, this));   
        }
    private:
        void timerCallback()
        {
            RCLCPP_INFO(this->get_logger(),"Hello, the timerCallback is called %d", counter_);
            counter_++;
        }
        
        rclcpp::TimerBase::SharedPtr timer_;
        int counter_;
};


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);                           // Initialize ros2 communication
    
    auto node = std::make_shared<NodeClass>();          // It is created a node using smart pointer of NodeClass
    rclcpp::spin(node);                                 // Keep the node alive until Ctrl+c

    rclcpp::shutdown();
    return 0;
}