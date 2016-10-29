#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <chrono>
#include <random>
#include <numeric>
#include <string>
#include <memory>
#include <functional>
#include <utility>
#include "random/Bernoulli.h"
#include "random/Beta.h"
#include "random/Binomial.h"
#include "random/BooleanDistrib.h"
#include "random/Categorical.h"
#include "random/Gaussian.h"
#include "random/Geometric.h"
#include "random/Poisson.h"
#include "random/UniformChoice.h"
#include "random/UniformInt.h"
#include "random/UniformReal.h"
#include "util/Hist.h"
#include "util/util.h"
#include "util/DynamicTable.h"

using namespace std;
using namespace swift::random;


int main();

namespace swift {

class BLOGProgram;

class BLOGProgram {
public:
  BLOGProgram();
  void init(int);
  void print();
  void debug();
  int _cur_loop;
  default_random_engine __random_device;
  char __value_Burglary;
  int __mark_Burglary;
  char __get_Burglary();
  BooleanDistrib BooleanDistrib3537224;
  double __likeli_Burglary();
  double __set_Burglary(char);
  char __value_Earthquake;
  int __mark_Earthquake;
  char __get_Earthquake();
  BooleanDistrib BooleanDistrib7851912;
  double __likeli_Earthquake();
  double __set_Earthquake(char);
  char __value_Alarm;
  int __mark_Alarm;
  char __get_Alarm();
  BooleanDistrib BooleanDistrib3537560;
  BooleanDistrib BooleanDistrib3537960;
  BooleanDistrib BooleanDistrib3538360;
  BooleanDistrib BooleanDistrib3538760;
  double __likeli_Alarm();
  double __set_Alarm(char);
  char __value_JohnCalls;
  int __mark_JohnCalls;
  char __get_JohnCalls();
  BooleanDistrib BooleanDistrib7854072;
  BooleanDistrib BooleanDistrib7854472;
  double __likeli_JohnCalls();
  double __set_JohnCalls(char);
  char __value_MaryCalls;
  int __mark_MaryCalls;
  char __get_MaryCalls();
  BooleanDistrib BooleanDistrib7854648;
  BooleanDistrib BooleanDistrib7855048;
  double __likeli_MaryCalls();
  double __set_MaryCalls(char);
  bool _set_evidence(double&);
  void sample(int);
  vector<double> _weight;
  inline void _evaluate_query(double);
  Hist<bool> _answer_0 = Hist<bool>(true);
};

BLOGProgram::BLOGProgram()
{}
void BLOGProgram::init(int n)
{
  BooleanDistrib3537224.init(0.00100000);
  BooleanDistrib7851912.init(0.00200000);
  BooleanDistrib3537560.init(0.95000000);
  BooleanDistrib3537960.init(0.94000000);
  BooleanDistrib3538360.init(0.29000000);
  BooleanDistrib3538760.init(0.00100000);
  BooleanDistrib7854072.init(0.90000000);
  BooleanDistrib7854472.init(0.05000000);
  BooleanDistrib7854648.init(0.70000000);
  BooleanDistrib7855048.init(0.01000000);
  _weight.resize(n);
}
void BLOGProgram::print()
{
  _answer_0.print("Burglary");
}
void BLOGProgram::debug()
{}
char BLOGProgram::__get_Burglary()
{
  char& __retvalue = __value_Burglary;
  int& __mark = __mark_Burglary;
  if (__mark==_cur_loop)
    return __retvalue;
  __retvalue=BooleanDistrib3537224.gen();
  __mark=_cur_loop;
  return __retvalue;
}
double BLOGProgram::__likeli_Burglary()
{
  char& __retvalue = __value_Burglary;
  double __local_weight = 0.000000;
  __local_weight=BooleanDistrib3537224.loglikeli(__retvalue);
  return __local_weight;
}
double BLOGProgram::__set_Burglary(char __retvalue_arg)
{
  __value_Burglary=__retvalue_arg;
  int& __mark = __mark_Burglary;
  __mark=_cur_loop;
  return __likeli_Burglary();
}
char BLOGProgram::__get_Earthquake()
{
  char& __retvalue = __value_Earthquake;
  int& __mark = __mark_Earthquake;
  if (__mark==_cur_loop)
    return __retvalue;
  __retvalue=BooleanDistrib7851912.gen();
  __mark=_cur_loop;
  return __retvalue;
}
double BLOGProgram::__likeli_Earthquake()
{
  char& __retvalue = __value_Earthquake;
  double __local_weight = 0.000000;
  __local_weight=BooleanDistrib7851912.loglikeli(__retvalue);
  return __local_weight;
}
double BLOGProgram::__set_Earthquake(char __retvalue_arg)
{
  __value_Earthquake=__retvalue_arg;
  int& __mark = __mark_Earthquake;
  __mark=_cur_loop;
  return __likeli_Earthquake();
}
char BLOGProgram::__get_Alarm()
{
  char& __retvalue = __value_Alarm;
  int& __mark = __mark_Alarm;
  if (__mark==_cur_loop)
    return __retvalue;
  if (__get_Burglary())
    if (__get_Earthquake())
      __retvalue=BooleanDistrib3537560.gen();
    else
      __retvalue=BooleanDistrib3537960.gen();
  else
    if (__get_Earthquake())
      __retvalue=BooleanDistrib3538360.gen();
    else
      __retvalue=BooleanDistrib3538760.gen();
  __mark=_cur_loop;
  return __retvalue;
}
double BLOGProgram::__likeli_Alarm()
{
  char& __retvalue = __value_Alarm;
  double __local_weight = 0.000000;
  if (__get_Burglary())
    if (__get_Earthquake())
      __local_weight=BooleanDistrib3537560.loglikeli(__retvalue);
    else
      __local_weight=BooleanDistrib3537960.loglikeli(__retvalue);
  else
    if (__get_Earthquake())
      __local_weight=BooleanDistrib3538360.loglikeli(__retvalue);
    else
      __local_weight=BooleanDistrib3538760.loglikeli(__retvalue);
  return __local_weight;
}
double BLOGProgram::__set_Alarm(char __retvalue_arg)
{
  __value_Alarm=__retvalue_arg;
  int& __mark = __mark_Alarm;
  __mark=_cur_loop;
  return __likeli_Alarm();
}
char BLOGProgram::__get_JohnCalls()
{
  char& __retvalue = __value_JohnCalls;
  int& __mark = __mark_JohnCalls;
  if (__mark==_cur_loop)
    return __retvalue;
  if (__get_Alarm())
    __retvalue=BooleanDistrib7854072.gen();
  else
    __retvalue=BooleanDistrib7854472.gen();
  __mark=_cur_loop;
  return __retvalue;
}
double BLOGProgram::__likeli_JohnCalls()
{
  char& __retvalue = __value_JohnCalls;
  double __local_weight = 0.000000;
  if (__get_Alarm())
    __local_weight=BooleanDistrib7854072.loglikeli(__retvalue);
  else
    __local_weight=BooleanDistrib7854472.loglikeli(__retvalue);
  return __local_weight;
}
double BLOGProgram::__set_JohnCalls(char __retvalue_arg)
{
  __value_JohnCalls=__retvalue_arg;
  int& __mark = __mark_JohnCalls;
  __mark=_cur_loop;
  return __likeli_JohnCalls();
}
char BLOGProgram::__get_MaryCalls()
{
  char& __retvalue = __value_MaryCalls;
  int& __mark = __mark_MaryCalls;
  if (__mark==_cur_loop)
    return __retvalue;
  if (__get_Alarm())
    __retvalue=BooleanDistrib7854648.gen();
  else
    __retvalue=BooleanDistrib7855048.gen();
  __mark=_cur_loop;
  return __retvalue;
}
double BLOGProgram::__likeli_MaryCalls()
{
  char& __retvalue = __value_MaryCalls;
  double __local_weight = 0.000000;
  if (__get_Alarm())
    __local_weight=BooleanDistrib7854648.loglikeli(__retvalue);
  else
    __local_weight=BooleanDistrib7855048.loglikeli(__retvalue);
  return __local_weight;
}
double BLOGProgram::__set_MaryCalls(char __retvalue_arg)
{
  __value_MaryCalls=__retvalue_arg;
  int& __mark = __mark_MaryCalls;
  __mark=_cur_loop;
  return __likeli_MaryCalls();
}
bool BLOGProgram::_set_evidence(double& __local_weight)
{
  __local_weight=0.000000;
  __local_weight+=__set_JohnCalls(1);
  __local_weight+=__set_MaryCalls(1);
  return true;
}
void BLOGProgram::sample(int n)
{
  double __local_weight;
  init(n);
  for (_cur_loop=1;_cur_loop<n;_cur_loop++)
  {
    if (_set_evidence(__local_weight))
      _evaluate_query(__local_weight);
    _weight[_cur_loop]=__local_weight;
  }

}
inline void BLOGProgram::_evaluate_query(double __local_weight)
{
  _answer_0.add(__get_Burglary(),__local_weight);
}

}
int main()
{
  std::chrono::time_point<std::chrono::system_clock> __start_time = std::chrono::system_clock::now();
  swift::BLOGProgram sampler;
  sampler.sample(1000000);
  sampler.print();
  std::chrono::duration<double> __elapsed_seconds = std::chrono::system_clock::now()-__start_time;
  printf("\nrunning time: %fs\n",__elapsed_seconds.count());
}
