/**
 * Authors:Jack Ju
 * HIT
 * PID controller*
 * 增量式pid算法。
 * 开环传递函数：G(S)=1/(2s+1)
 * 20200526
 * */
#include "matplotlibcpp.h"
#include <iostream>
#include <vector>
using std::vector;
namespace plt = matplotlibcpp;//可视化
/****目标跟踪初始条件设置***/
double x_ref=10;//[]={10,10,10,10,10,10,10,10,10,10};//跟踪的阶跃信号10组信号


vector<double> y_output; 
vector<double> y_orgin_output; 
double y_org=0;

//PID
class PID
{
public:
    double error;
    double u_output=0;
    void PID_function(double kp,double ki,double kd); //增量式pid算法
    PID();
    ~PID();
private:
    vector<double> pre_error;
    double pre_u=0;
    int i=1;
    int j;
   
   
};
 void PID::PID_function(double kp,double ki,double kd)
{ 
  
    if(i==1)
   {
        pre_error.push_back(0);
        pre_error.push_back(0);
       
        std::cout<<pre_error[0]<<std::endl;
        std::cout<<pre_error[1]<<std::endl;
        std::cout<<pre_error.size()<<std::endl;
    } 
   std::cout<<"error:"<<error<<std::endl;
   pre_error.push_back(error);
   j=pre_error.size();
   std::cout<<pre_error.size()<<std::endl;
   u_output+=kp*(pre_error[j-1]-pre_error[j-2])+ki*pre_error[j-1]+kd*(pre_error[j-1]-2*pre_error[j-2]+pre_error[j-3]);
   i=i+1;
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
  double u=0;//控制指令的初始值
  double y=0;//实际输出值为零。
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
  std::cout<<u<<" ";
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