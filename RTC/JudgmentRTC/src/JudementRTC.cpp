// -*- C++ -*-
/*!
 * @file  JudementRTC.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "JudementRTC.h"

// Module specification
// <rtc-template block="module_spec">
static const char* judementrtc_spec[] =
  {
    "implementation_id", "JudementRTC",
    "type_name",         "JudementRTC",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "Kengo Ishida",
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
JudementRTC::JudementRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inFlagsIn("inFlags", m_inFlags),
    m_inImageIn("inImage", m_inImage),
    m_inObjectParamIn("inObjectParam", m_inObjectParam),
    m_outGetHumanOut("outGetHuman", m_outGetHuman),
    m_outGetRototOut("outGetRotot", m_outGetRotot)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
JudementRTC::~JudementRTC()
{
}



RTC::ReturnCode_t JudementRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("inFlags", m_inFlagsIn);
  addInPort("inImage", m_inImageIn);
  addInPort("inObjectParam", m_inObjectParamIn);
  
  // Set OutPort buffer
  addOutPort("outGetHuman", m_outGetHumanOut);
  addOutPort("outGetRotot", m_outGetRototOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t JudementRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t JudementRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t JudementRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t JudementRTC::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t JudementRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t JudementRTC::onExecute(RTC::UniqueId ec_id)
{
  static int getHuman = 0;
  static int getRobot = 0;
  
  if (m_inFlagsIn.isNew())
  {
    m_inFlagsIn.read();
    int FLAGS = m_inFlags.data;
    if (FLAGS == 1)
    	getRobot++;
    
    else if(FLAGS == 2)
	getHuman++;
  }
  std::cout << "------------------------" << std::endl;
  std::cout << "getRobot : " << getRobot << std::endl;
  std::cout << "getHuman : " << getHuman << std::endl;

  /*		Output start		*/
  m_outGetHuman.data = getHuman;
  m_outGetRotot.data = getRobot;
  m_outGetHumanOut.write();
  m_outGetRototOut.write();
  /*		Output end		*/ 
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t JudementRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t JudementRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t JudementRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t JudementRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t JudementRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void JudementRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(judementrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<JudementRTC>,
                             RTC::Delete<JudementRTC>);
  }
  
};


