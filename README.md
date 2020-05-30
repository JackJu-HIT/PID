# 本程序是包括位置式的PID和增量式PID的C++实现。
# 涉及的原理是两种：
# 位置式PID
u(t)=kp*error(t)+ki(sum(error))+kd*(error(t)-error(t-1))
# 增量式PID
u(t)-u(t-1)=kp*(error(t)-error(t-1))+ki*(error(t))+kd*(error(t)-2*error(t-1)+error(t-2))
# 本例子采取的是闭环传函G(S)=1/(2S+1)  具体实现的算法参见源码。
# 最终显示出所绘制的阶跃响应曲线，注意：横坐标不是时间，是迭代次数。
# 你需要的环境：
 linux ubuntu
# 你需要安装依赖：
# Gnuplot
sudo apt-get install gnuplot
# python and matplotlib
sudo apt-get install python-matplotlib
sudo apt-get install python2.7-dev
