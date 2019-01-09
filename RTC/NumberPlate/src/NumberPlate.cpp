// -*- C++ -*-
/*!
 * @file  NumberPlate.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "NumberPlate.h"
#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

namespace std
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}



int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

// Module specification
// <rtc-template block="module_spec">
static const char* numberplate_spec[] =
  {
    "implementation_id", "NumberPlate",
    "type_name",         "NumberPlate",
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
NumberPlate::NumberPlate(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inGetHumanIn("inGetHuman", m_inGetHuman),
    m_inGetRobotIn("inGetRobot", m_inGetRobot),
    m_outImageOut("outImage", m_outImage),
    m_outFlagOut("outFlag", m_outFlag)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
NumberPlate::~NumberPlate()
{
}



RTC::ReturnCode_t NumberPlate::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("inGetHuman", m_inGetHumanIn);
  addInPort("inGetRobot", m_inGetRobotIn);
  
  // Set OutPort buffer
  addOutPort("outImage", m_outImageOut);
  addOutPort("outFlag", m_outFlagOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t NumberPlate::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t NumberPlate::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t NumberPlate::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t NumberPlate::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t NumberPlate::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t NumberPlate::onExecute(RTC::UniqueId ec_id)
{
  if (m_inGetHumanIn.isNew() && m_inGetRobotIn.isNew())
  {
      
      m_inGetHumanIn.read();
      m_inGetRobotIn.read();

      static int getHuman = 0;
      static int getRobot = 0;

      int width = 640;
      int height = 480;
      int channels = 3;
      
      getHuman = m_inGetHuman.data;
      getRobot = m_inGetRobot.data;
      
      std::cout << "人が取った枚数 : " << getHuman << std::endl;
      std::cout << "ロボットが取った枚数 : " << getRobot << std::endl;
      std::cout << "==================================" << std::endl;

      cv::Mat image(cv::Size(640, 480), CV_8UC3, cv::Scalar(255,255,255));

      cv::putText(image, "Human", cv::Point(50,200), cv::FONT_HERSHEY_SIMPLEX, 2.3, cv::Scalar(0,0,0), 4, CV_AA);
      cv::putText(image, std::to_string(getHuman), cv::Point(140,350), cv::FONT_HERSHEY_SIMPLEX, 3, cv::Scalar(0,0,0), 4, CV_AA);

      cv::putText(image, "Robot", cv::Point(350,200), cv::FONT_HERSHEY_SIMPLEX, 2.3, cv::Scalar(0,0,0), 4, CV_AA);
      cv::putText(image, std::to_string(getRobot), cv::Point(420,350), cv::FONT_HERSHEY_SIMPLEX, 3, cv::Scalar(0,0,0), 4, CV_AA);



      cv::namedWindow("image2", cv::WINDOW_AUTOSIZE);
      cv::imshow("image2", image);
      /*		Output start		*/
      m_outImage.data.image.width = width;
      m_outImage.data.image.height = height;
      m_outImage.data.image.raw_data.length(width * height * channels);
      m_outImage.data.image.format
		= (channels == 3) ? Img::CF_RGB :
		(channels == 1) ? Img::CF_GRAY : Img::CF_UNKNOWN;
      for (int i = 0; i<height; ++i){
		memcpy(&m_outImage.data.image.raw_data[i*width*channels],
			&image.data[i*image.step],
			sizeof(unsigned char)*width*channels);
      }

      m_outImageOut.write();
      /*		Output end		*/
     
     
     if (cv::waitKey(0) == 'n')
     {
	std::cout << "エンターキー押しました " << std::endl;
        m_outFlag.data = 1;
        m_outFlagOut.write();
     }

     m_outFlag.data = 0;
     std::cout <<  "確認 : " << m_outFlag.data << std::endl;
     m_outFlagOut.write();

  }
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t NumberPlate::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t NumberPlate::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t NumberPlate::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t NumberPlate::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t NumberPlate::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void NumberPlateInit(RTC::Manager* manager)
  {
    coil::Properties profile(numberplate_spec);
    manager->registerFactory(profile,
                             RTC::Create<NumberPlate>,
                             RTC::Delete<NumberPlate>);
  }
  
};


