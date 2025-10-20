#include"rclcpp/rclcpp.hpp"
#include"std_msgs/msg/string.hpp"
#include<chrono>

using namespace std::chrono_literals;

class PublisherNode : public rclcpp::Node{
    private:
    size_t count_;//定义一个无符号的整数类型
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;//里面那个是命名空间的嵌套，此时作为模板参数
    void timer_callback(){
        auto message = std_msgs::msg::String();
        message.data = "Hello ROS2! 计数: " + std::to_string(count_++);
        publisher_->publish(message);//本质：std::shared_ptr<std_msgs::msg::String>
        RCLCPP_INFO(this->get_logger(), "发布: '%s'", message.data.c_str());//这里就是一个简单的日志器，getlogger就是类似获取当前点位置的函数
    }
    public:
    PublisherNode():Node("publisher_node"),count_(0){
        publisher_=this->create_publisher<std_msgs::msg::String>("topic",10);
        timer_=this->create_wall_timer(1000ms,std::bind(&PublisherNode::timer_callback,this));//（触发间隔，回调函数）
        RCLCPP_INFO(this->get_logger(),"发布者节点已启动");
    }
};

int main(int argc,char** argv){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<PublisherNode>());
    rclcpp::shutdown();
    return 0;
}
