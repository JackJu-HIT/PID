# 本程序是包括位置式的PID和增量式PID的C++实现。
# 涉及的原理是两种：
# 位置式PID
u(t)=kp*error(t)+ki(sum(error))+kd*(error(t)-error(t-1))
# 增量式PID
u(t)-u(t-1)=kp*(error(t)-error(t-1))+ki*(error(t))+kd*(error(t)-2*error(t-1)+error(t-2))
# 本例子采取的是被控对象传函G(S)=1/(2S+1)  具体实现的算法参见源码。
# 最终显示出所绘制的阶跃响应曲线，注意：横坐标不是时间，是迭代次数。
# 如果你想了解更多关于两种pid算法的更多信息参见我的CSDN博客：https://blog.csdn.net/qq_40464599/article/details/106439213
# 你需要的环境：
 linux ubuntu
# 你需要安装依赖：
# Gnuplot
sudo apt-get install gnuplot
# python and matplotlib
sudo apt-get install python-matplotlib
sudo apt-get install python2.7-dev
# 运行，需要你自己进行cmake编译
在代码的当前路径下打开终端：
(1)mkdir build
(2)cmake ..
(3)make
