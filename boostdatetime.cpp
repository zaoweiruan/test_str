#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>
#include <sstream>
using namespace boost::gregorian;
using namespace boost::posix_time;
using namespace std;
int main()
{
   date d(2010, 1, 30);
  std::cout << d.year() << std::endl;
  std::cout << d.month() << std::endl;
  std::cout << d.day() << std::endl;
  std::cout << d.day_of_week() << std::endl;
  std::cout << d.end_of_month() << std::endl;

  d = day_clock::universal_day();
  std::cout << d.year() << std::endl;
  std::cout << d.month() << std::endl;
  std::cout << d.day() << std::endl;
  ptime t=second_clock::local_time();
  std::cout << to_iso_string(t) << std::endl;
  //t=second_clock::local_day();
  time_duration t1=t.time_of_day();
  stringstream stream;
  stream<<std::hex<<stoll(to_iso_string(t.date())+to_iso_string(t1)) ;
  std::cout<<stream.str();
  std::cout << std::hex<<stoll(to_iso_string(t.date())+to_iso_string(t1)) << std::endl;


} /*
 * boost_date_time.cpp
 *
 *  Created on: 2024年10月14日
 *      Author: dsm
 */




