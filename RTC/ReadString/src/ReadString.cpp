// -*- C++ -*-
/*!
 * @file  ReadString.cpp
 * @brief ReadString
 * @date $Date$
 *
 * $Id$
 */

#include "ReadString.h"
#include <iostream>
#include <string>

std::vector<std::string> strList;
int num = 0;

// Module specification
// <rtc-template block="module_spec">
static const char* readstring_spec[] =
  {
    "implementation_id", "ReadString",
    "type_name",         "ReadString",
    "description",       "ReadString",
    "version",           "1.0.0",
    "vendor",            "Ohashi",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
ReadString::ReadString(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_jtimeIn("jtime", m_jtime),
    m_outstringOut("outstring", m_outstring)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ReadString::~ReadString()
{
}



RTC::ReturnCode_t ReadString::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("jtime", m_jtimeIn);
  
  // Set OutPort buffer
  addOutPort("outstring", m_outstringOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ReadString::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ReadString::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ReadString::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ReadString::onActivated(RTC::UniqueId ec_id)
{
  strList.push_back("a");
  strList.push_back("si");
  strList.push_back("te");
  strList.push_back("o");
  strList.push_back("ku");
  strList.push_back("so");
  strList.push_back("ta");
  strList.push_back("e");
  strList.push_back("ka");
  strList.push_back("to");
  strList.push_back("ki");
  strList.push_back("i");
  strList.push_back("ke");
  strList.push_back("sa");
  strList.push_back("u");
  strList.push_back("ti");
  strList.push_back("ko");
  strList.push_back("su");
  strList.push_back("se");
  strList.push_back("tu");

/*
  std::string str = strList[num];
  m_outstring.data = str.c_str();    
  m_outstringOut.write();  // 適応させたデータをデータポートから出力する

  num++;
*/
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ReadString::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ReadString::onExecute(RTC::UniqueId ec_id)
{
  
  if(m_jtimeIn.isNew())
  {             
    //  何かしらのデータが来たら処理する
    m_jtimeIn.read();             //  何かしらのデータを読み込む
    long data = m_jtime.data;
    std::cout << "フラグ確認 : " << data << std::endl;

    if (data == 1)
    {
      std::string str = strList[num];
      m_outstring.data = str.c_str();    
      m_outstringOut.write();//  適応させたデータをデータポートから出力する
      num++;
    }
  }
   
  

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ReadString::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ReadString::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ReadString::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ReadString::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ReadString::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ReadStringInit(RTC::Manager* manager)
  {
    coil::Properties profile(readstring_spec);
    manager->registerFactory(profile,
                             RTC::Create<ReadString>,
                             RTC::Delete<ReadString>);
  }
  
};


