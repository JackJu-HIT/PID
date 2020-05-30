/**
 * Authors:Jack Ju
 * HIT
 * PID controller*
 * 位置式pid算法。
 * 开环传递函数：G(S)=1/(2s+1)
 * */
#include "matplotlibcpp.h"
#include <iostream>
#include <vector>
using std::vector;
namespace plt = matplotlibcpp;//可视化
/****目标跟踪初始条件设置***/
double x_ref=10;//[]={10,10,10,10,10,10,10,10,10,10};//跟踪的阶跃信号10组信号
double y=0;//实际输出值为零。
double u=0;//控制指令的初始值
vector<double> y_output; 
vector<double> y_orgin_output; 
double y_org=0;

//PID
class PID
{
public:
    double error;
    double pre_error=0;
    double error_sum=0;
    double u_output;
    void PID_function(double kp,double ki,double kd); //位置式pid算法
    //void PID_
    PID();
    ~PID();
};
 void PID::PID_function(double kp,double ki,double kd)
{
   error_sum+=error;
   u_output=kp*error+ki*error_sum+kd*(error-pre_error);
   pre_error=error;
   std::cout<<"error:"<<error<<std::endl;
}
PID::PID()
{

}
PID::~PID()
{
}




//主程序
int main()
{
  PID pid;
  double err;
  /*开环控制**/
  for (size_t i = 0; i < 30; i++)
  {
    y_org=0.5*(1+2*y_org+x_ref);//模型
    y_orgin_output.push_back(y_org);
    
  }

  
/**闭环控制**/
  for (int  i = 0; i < 200; i++)
  {
  y=0.5*(y+u);//模型
  err=x_ref-y;
  pid.error=err;
  pid.PID_function(1,0.1,0);
  u=pid.u_output;
  y_output.push_back(y);
  }
 /*pid校正后（闭环）*/ 
 plt::subplot(2,2,1);
 plt::title("PID");
 plt::plot(y_output);
/*****pid矫正前（开环）****/
 plt::subplot(2,2,2);
 plt::title("orginal");
 plt::plot(y_orgin_output);
 plt::show();
 return 0;
}