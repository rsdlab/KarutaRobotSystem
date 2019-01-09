// -*- C++ -*-
/*!
 * @file  karuta_arm_control.cpp
 * @brief karuta_arm_control
 * @date $Date$
 *
 * $Id$
 */

#include "karuta_arm_control.h"
#include <math.h>
//#include <string>
//#include <unistd.h>
#include <iostream>


// Module specification
// <rtc-template block="module_spec">
static const char* karuta_arm_control_spec[] =
  {
    "implementation_id", "karuta_arm_control",
    "type_name",         "karuta_arm_control",
    "description",       "karuta_arm_control",
    "version",           "1.0.0",
    "vendor",            "rsdlab",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.Speed", "20",

    // Widget
    "conf.__widget__.Speed", "text",
    // Constraints

    "conf.__type__.Speed", "int",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
karuta_arm_control::karuta_arm_control(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_BidNameIn("BidName", m_BidName),
    m_RecognitionSignalIn("RecognitionSignal", m_RecognitionSignal),
    m_EndSignalIn("EndSignal", m_EndSignal),
    m_SearchEndSignalOut("SearchEndSignal", m_SearchEndSignal),
    m_ManipulatorCommonInterface_CommonPort("ManipulatorCommonInterface_Common"),
    m_ManipulatorCommonInterface_MiddlePort("ManipulatorCommonInterface_Middle")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
karuta_arm_control::~karuta_arm_control()
{
}



RTC::ReturnCode_t karuta_arm_control::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("BidName", m_BidNameIn);
  addInPort("RecognitionSignal", m_RecognitionSignalIn);
  addInPort("EndSignal", m_EndSignalIn);
  
  // Set OutPort buffer
  addOutPort("SearchEndSignal", m_SearchEndSignalOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  m_ManipulatorCommonInterface_CommonPort.registerConsumer("ManipulatorCommonInterface_Common", "JARA_ARM::ManipulatorCommonInterface_Common", m_ManipulatorCommonInterface_Common);
  m_ManipulatorCommonInterface_MiddlePort.registerConsumer("ManipulatorCommonInterface_Middle", "JARA_ARM::ManipulatorCommonInterface_Middle", m_ManipulatorCommonInterface_Middle);
  
  // Set CORBA Service Ports
  addPort(m_ManipulatorCommonInterface_CommonPort);
  addPort(m_ManipulatorCommonInterface_MiddlePort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("Speed", m_Speed, "20");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t karuta_arm_control::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t karuta_arm_control::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t karuta_arm_control::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t karuta_arm_control::onActivated(RTC::UniqueId ec_id)
{
  //プロバイダより遅くActivateするため
  sleep(1);

  //関節速度の設定
  JARA_ARM::ULONG spdRation;
  spdRation = m_Speed;//%
  m_ManipulatorCommonInterface_Middle->setSpeedJoint(spdRation);

  /*リミット設定
  //ジョイントソフトリミットの初期化(AX-12A対応)
  JARA_ARM::LimitSeq softLimit;
  softLimit.length(5);
  softLimit[0].upper = 300;
  softLimit[0].lower = 0;
  softLimit[1].upper = 300;
  softLimit[1].lower = 0;
  softLimit[2].upper = 300;
  softLimit[2].lower = 0;
  softLimit[3].upper = 300;
  softLimit[3].lower = 0;
  m_ManipulatorCommonInterface_Common->setSoftLimitJoint(softLimit);

  //範囲ソフトリミットの初期化(CRANE+対応)
  JARA_ARM::LimitValue xLimit;
  JARA_ARM::LimitValue yLimit;
  JARA_ARM::LimitValue zLimit;
  xLimit.upper = 329;
  xLimit.lower = -300;
  yLimit.upper = 314.5;
  yLimit.lower = -314.5;
  zLimit.upper = 359.9;
  zLimit.lower = 0;
  m_ManipulatorCommonInterface_Middle->setSoftLimitCartesian(xLimit, yLimit, zLimit);
  */

  return RTC::RTC_OK;
}


RTC::ReturnCode_t karuta_arm_control::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t karuta_arm_control::onExecute(RTC::UniqueId ec_id)
{
  static int command = 0;
  static int a = 1;
  static int b, c = 1;
  static std::string bidName;
  static int endSignal = 0;
  static int recognitionSignal = 0;
  static int b_jointPoint[4];
  JARA_ARM::JointPos jointPoint;
  jointPoint.length(4);
  

  if(m_EndSignalIn.isNew())
  {
    m_EndSignalIn.read();
    endSignal = m_EndSignal.data;
  }
  if(m_RecognitionSignalIn.isNew())
  {
    m_RecognitionSignalIn.read();
    recognitionSignal = m_RecognitionSignal.data;
  }


  std::cout << "--------------------------------" << std::endl;
  switch(command)
  {
    case 0:
      m_rid=m_ManipulatorCommonInterface_Common->servoON();
      if(m_rid->id != 0)
      {
	//----Error------
  	std::cout<<"Servo ON ERROR"<<std::endl;
  	std::cout<<m_rid->comment<<std::endl<<std::endl;
      }
      b = a;
      command = 2;
      break;
   
      case 1:
        std::cout<< "検出できたか　: " << recognitionSignal << std::endl;
        if(recognitionSignal == 0)
	{
	  b = a;
          c = 1;
	  command = 2;
	}
        break;

      case 2:

	// 見つかった時（ロボットに得点）
        if(recognitionSignal == 1 || endSignal == 1)
	{
    	  command = 1;
	  jointPoint[0] = b_jointPoint[0];
	  jointPoint[1] = b_jointPoint[1];
          jointPoint[2] = b_jointPoint[2];
	  jointPoint[3] = b_jointPoint[3];
          m_rid=m_ManipulatorCommonInterface_Middle->movePTPJointAbs(jointPoint);
          sleep(2);
 
	  m_SearchEndSignal.data = 1;
	  m_SearchEndSignalOut.write();
	  std::cout<<"m_SearchEndSignal : "<< m_SearchEndSignal.data << std::endl;
    	  return RTC::RTC_OK;
    	}



        if(a == 1)
        {
    	  jointPoint[0] = -90;
    	  jointPoint[1] = 0;
    	  jointPoint[2] = 55;
    	  jointPoint[3] = -90;
	  
    	  b_jointPoint[0] = 90;
    	  b_jointPoint[1] = 0;
    	  b_jointPoint[2] = 90;
    	  b_jointPoint[3] = -90;
    	}
    	if(a == 2)
        {
    	  jointPoint[0] = -45;
    	  jointPoint[1] = 0;
    	  jointPoint[2] = 55;
    	  jointPoint[3] = -90;

    	  b_jointPoint[0] = -90;
    	  b_jointPoint[1] = 0;
    	  b_jointPoint[2] = 55;
    	  b_jointPoint[3] = -90;
    	}

    	if(a == 3)
        {
    	  jointPoint[0] = 0;
    	  jointPoint[1] = 0;
    	  jointPoint[2] = 55;
    	  jointPoint[3] = -90;

    	  b_jointPoint[0] = -45;
    	  b_jointPoint[1] = 0;
    	  b_jointPoint[2] = 55;
    	  b_jointPoint[3] = -90;
    	}

	if(a == 4)
        {
    	  jointPoint[0] = 45;
    	  jointPoint[1] = 0;
    	  jointPoint[2] = 55;
    	  jointPoint[3] = -90;

    	  b_jointPoint[0] = 0;
    	  b_jointPoint[1] = 0;
    	  b_jointPoint[2] = 55;
    	  b_jointPoint[3] = -90;
    	}

    	if(a == 5)
        {
    	  jointPoint[0] = 90;
    	  jointPoint[1] = 0;
    	  jointPoint[2] = 55;
    	  jointPoint[3] = -90;

    	  b_jointPoint[0] = 45;
    	  b_jointPoint[1] = 0;
    	  b_jointPoint[2] = 55;
    	  b_jointPoint[3] = -90;
    	}

        if(a == 6)
        {
    	  jointPoint[0] = 90;
    	  jointPoint[1] = 0;
    	  jointPoint[2] = 75;
    	  jointPoint[3] = -90;

    	  b_jointPoint[0] = 90;
    	  b_jointPoint[1] = 0;
    	  b_jointPoint[2] = 55;
    	  b_jointPoint[3] = -90;
    	}

    	if(a == 7)
        {
    	  jointPoint[0] = 45;
    	  jointPoint[1] = 0;
    	  jointPoint[2] = 75;
    	  jointPoint[3] = -90;

    	  b_jointPoint[0] = 90;
    	  b_jointPoint[1] = 0;
    	  b_jointPoint[2] = 75;
    	  b_jointPoint[3] = -90;
    	}

    	if(a == 8)
        {
    	  jointPoint[0] = 0;
    	  jointPoint[1] = 0;
    	  jointPoint[2] = 75;
    	  jointPoint[3] = -90;

    	  b_jointPoint[0] = 45;
    	  b_jointPoint[1] = 0;
    	  b_jointPoint[2] = 75;
    	  b_jointPoint[3] = -90;
    	}

    	if(a == 9)
        {
    	  jointPoint[0] = -45;
    	  jointPoint[1] = 0;
    	  jointPoint[2] = 75;
    	  jointPoint[3] = -90;

    	  b_jointPoint[0] = 0;
    	  b_jointPoint[1] = 0;
    	  b_jointPoint[2] = 75;
    	  b_jointPoint[3] = -90;
    	}

    	if(a == 10)
        {
    	  jointPoint[0] = -90;
    	  jointPoint[1] = 0;
    	  jointPoint[2] = 75;
    	  jointPoint[3] = -90;

    	  b_jointPoint[0] = -45;
    	  b_jointPoint[1] = 0;
    	  b_jointPoint[2] = 75;
    	  b_jointPoint[3] = -90;
    	}

        if(a == 11)
        {
    	  jointPoint[0] = -90;
    	  jointPoint[1] = 0;
    	  jointPoint[2] = 90;
    	  jointPoint[3] = -90;

    	  b_jointPoint[0] = -90;
    	  b_jointPoint[1] = 0;
    	  b_jointPoint[2] = 75;
    	  b_jointPoint[3] = -90;
    	}

    	if(a == 12)
        {
    	  jointPoint[0] = -45;
    	  jointPoint[1] = 0;
    	  jointPoint[2] = 90;
    	  jointPoint[3] = -90;

    	  b_jointPoint[0] = -90;
    	  b_jointPoint[1] = 0;
    	  b_jointPoint[2] = 90;
    	  b_jointPoint[3] = -90;
    	}

    	if(a == 13)
        {
    	  jointPoint[0] = 0;
    	  jointPoint[1] = 0;
    	  jointPoint[2] = 90;
    	  jointPoint[3] = -90;

    	  b_jointPoint[0] = -90;
    	  b_jointPoint[1] = 0;
    	  b_jointPoint[2] = 55;
    	  b_jointPoint[3] = -90;
    	}

    	if(a == 14)
        {
    	  jointPoint[0] = 45;
    	  jointPoint[1] = 0;
    	  jointPoint[2] = 90;
    	  jointPoint[3] = -90;

    	  b_jointPoint[0] = -90;
    	  b_jointPoint[1] = 0;
    	  b_jointPoint[2] = 55;
    	  b_jointPoint[3] = -90;
    	}

    	if(a == 15)
        {
    	  jointPoint[0] = 90;
    	  jointPoint[1] = 0;
    	  jointPoint[2] = 90;
    	  jointPoint[3] = -90;

    	  b_jointPoint[0] = -90;
    	  b_jointPoint[1] = 0;
    	  b_jointPoint[2] = 55;
    	  b_jointPoint[3] = -90;
          a = 1;
    	}       

   	m_rid=m_ManipulatorCommonInterface_Middle->movePTPJointAbs(jointPoint);
      	if(m_rid->id != 0)
	{
 	  //Error
	  std::cout<<"movePTPJointAbs ERROR"<<std::endl;
	  std::cout<<m_rid->comment<<std::endl<<std::endl;
     	}
        m_SearchEndSignal.data = 0;
	m_SearchEndSignalOut.write();
    	a++;

	// 見つからなかった時（人に得点）
        if (b == a)
        {
	  m_SearchEndSignal.data = 2;
	  m_SearchEndSignalOut.write();
	  sleep(2);
  	  std::cout<<"m_SearchEndSignal : "<< m_SearchEndSignal.data << std::endl;
        }
    	sleep(1);
 	
    	break;

      case 3:	
          command = 1;
	  break;
  }     
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t karuta_arm_control::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t karuta_arm_control::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t karuta_arm_control::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t karuta_arm_control::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t karuta_arm_control::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void karuta_arm_controlInit(RTC::Manager* manager)
  {
    coil::Properties profile(karuta_arm_control_spec);
    manager->registerFactory(profile,
                             RTC::Create<karuta_arm_control>,
                             RTC::Delete<karuta_arm_control>);
  }
  
};


