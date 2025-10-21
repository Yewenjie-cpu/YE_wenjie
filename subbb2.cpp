#include"rclcpp/rclcpp.hpp"
#include"std_msgs/msg/string.hpp"

class SubscriberNode:public rclcpp::Node
{
private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

    void topic_callback(const std_msgs::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(),"订阅到'%s'",msg->data.c_str());
    }

public:
    SubscriberNode():Node("subscriber_node")
    {
        subscription_=this->create_subscription<std_msgs::msg::String>(
            "topic",10,std::bind(&SubscriberNode::topic_callback,this,std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(),"订阅者节点已启动，等待消息。。。");
    }
};
int main(int argc, char** argv)
{
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<SubscriberNode>());
    rclcpp::shutdown();
}