# 本程序是包括位置式的PID和增量式PID的C++实现。
# 涉及的原理是两种：
# 位置式PID
u(t)=kp*error(t)+ki(sum(error))+kd*(error(t)-error(t-1))
# 增量式PID
u(t)-u(t-1)=kp*(error(t)-error(t-1))+ki*(error(t))+kd*(error(t)-2*error(t-1)+error(t-2))
# 你需要的环境：
 linux ubuntu
# 你需要安装依赖：
# Gnuplot
sudo apt-get install gnuplot
# python and matplotlib
sudo apt-get install python-matplotlib
sudo apt-get install python2.7-dev
