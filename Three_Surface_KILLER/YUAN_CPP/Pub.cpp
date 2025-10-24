#include "rclcpp/rclcpp.hpp"//添加节点，实现通讯
#include "std_msgs/msg/string.hpp"//节点通讯的具体数据类型

using namespace std::chrono_literals;

class PublisherNode : public rclcpp::Node//继承Node,创建节点
{
public:
    PublisherNode() : Node("publisher_node"，rclcpp::NodeOptions().namespace_("robot_1"))//构造函数：必须含有节点名称
//补充：这里的命名空间作用就是给发布的话题添加标识（相同类型的数据需要区分用途需要不同的话题名称但是我希望保持命名一致方便处理和转移）
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("my_topic", 10);//补充：调用成员函数创建发布者 
//格式：this->create_publisher<传输数据类型>("节点名称",)
        
        timer_ = this->create_wall_timer(//依托该智能指针（成员本身）创建计时器，指针维护这个计时器
            1000ms, [this]() {//定时执行lambda函数（[this]检索上文的对象用于下面的日志器）
                auto message = std_msgs::msg::String();//这里体现了代码可读
                message.data = "你好，我是发布者！";
//=======================================================================================================================================================
//❌ 如果支持直接构造，会非常冗长：
//auto detection = ArmorDetection(header, position, 0.95, "hero");
//
// ✅ 分开设置更清晰：
//auto detection = ArmorDetection();
//detection.header = current_header;
//detection.position = detected_position;
//detection.confidence = 0.95;
//detection.armor_type = "hero";
//
//=======================================================================================================================================================
                publisher_->publish(message);//发布到话题
                RCLCPP_INFO(this->get_logger(), "发布消息: '%s'", message.data.c_str());
            });
        
        RCLCPP_INFO(this->get_logger(), "发布者节点已启动");//日志器（获取当前标识输出标识和提示）（标识：节点名称，时间戳）
    }

private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;//节点的成员，维护的是发布者（发布者直接依托于该指针所以生命周期由智能指针决定）,有点语法糖的意思前面的是该指针的指向的数据类型，本身c++的语法应该是：指针<参数模板> 指针名
    rclcpp::TimerBase::SharedPtr timer_;//节点成员
};

int main(int argc, char * argv[])//argv这里就是对应的初始化参数可以是某个文件
{
    rclcpp::init(argc, argv);//使用参数初始化，移除参数中ros2部分
    rclcpp::spin(std::make_shared<PublisherNode>());//节点保持运行，
    rclcpp::shutdown();//关闭ros2的上下文
    return 0;}
