#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class PublisherNode : public rclcpp::Node
{
public:
    PublisherNode() : Node("publisher_node")
    {
        // 创建发布者
        publisher_ = this->create_publisher<std_msgs::msg::String>("my_topic", 10);
        
        // 创建计时器，每秒发布一次
        timer_ = this->create_wall_timer(
            1000ms, [this]() {
                auto message = std_msgs::msg::String();
                message.data = "你好，我是发布者！";
                publisher_->publish(message);
                RCLCPP_INFO(this->get_logger(), "发布消息: '%s'", message.data.c_str());
            });
        
        RCLCPP_INFO(this->get_logger(), "发布者节点已启动");
    }

private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PublisherNode>());
    rclcpp::shutdown();
    return 0;
}