#!/usr/bin/env python
# -*- coding: utf-8 -*-
# -*- Python -*-

"""
 @file Deep_LearningRTC.py
 @brief ModuleDescription
 @date $Date$


"""
import sys
import time
sys.path.append(".")

# Import RTM module
import RTC
import OpenRTM_aist

import Img
import ObjectRecognition

from fast_rcnn.config import cfg
from fast_rcnn.test import im_detect
from fast_rcnn.nms_wrapper import nms
from utils.timer import Timer
import caffe, os, sys, cv2
import scipy.io as sio
import numpy as np

# Import Service implementation class
# <rtc-template block="service_impl">

# </rtc-template>

# Import Service stub modules
# <rtc-template block="consumer_import">
# </rtc-template>


# This module's spesification
# <rtc-template block="module_spec">
CLASSES_KARUTA = ('__background__', # always index 0
                 'a', 'i', 'u', 'e', 'o',
		 'ka', 'ki', 'ku', 'ke', 'ko',
	   	 'sa', 'si', 'su', 'se', 'so',
 		 'ta', 'ti', 'tu', 'te', 'to',
		 'na', 'ni', 'nu', 'ne', 'no',
		 'ha', 'hi', 'hu', 'he', 'ho',
		 'ma', 'mi', 'mu', 'me', 'mo',
		 'ya', 'yu', 'yo',
		 'ra', 'ri', 'ru', 're', 'ro',
                 'wa', 'ba', 'bu', 'ze')

NETS = {'vgg16': ('VGG16',
          'VGG16_faster_rcnn_final.caffemodel'),
        'zf': ('ZF',
          'ZF_faster_rcnn_final.caffemodel')}


deep_learningrtc_spec = ["implementation_id", "Deep_LearningRTC", 
		 "type_name",         "Deep_LearningRTC", 
		 "description",       "ModuleDescription", 
		 "version",           "1.0.0", 
		 "vendor",            "Kengo Ishida", 
		 "category",          "Category", 
		 "activity_type",     "STATIC", 
		 "max_instance",      "1", 
		 "language",          "Python", 
		 "lang_type",         "SCRIPT",
		 "conf.default.dataset", "karuta",
		 "conf.default.mode", "gpu",
		 "conf.default.net", "vgg16",
		 "conf.default.recognitionRate", "0.8",

		 "conf.__widget__.dataset", "text",
		 "conf.__widget__.mode", "text",
		 "conf.__widget__.net", "text",
		 "conf.__widget__.recognitionRate", "text",

         "conf.__type__.dataset", "string",
         "conf.__type__.mode", "string",
         "conf.__type__.net", "string",
         "conf.__type__.recognitionRate", "double",

		 ""]
# </rtc-template>
class ObjectParam:
        def __init__(self, name, width, height, x, y):
                self.name = name
                self.width = width
                self.height = height
                self.x = x
                self.y = y

def detect(net, im, speech, CLASSES, rate):
	# Detect all object classes and regress object bounds
	timer = Timer()
	timer.tic()
	scores, boxes = im_detect(net, im)
	timer.toc()
	print('Detection took {:.3f}s for '
			'{:d} object proposals').format(timer.total_time, boxes.shape[0])

	# Visualize detections for each class
	CONF_THRESH = rate
	NMS_THRESH = 0.3
	thresh = CONF_THRESH
        objParam = []
        objParam[:]
        
        searchResult = 0
        for cls_ind, cls in enumerate(CLASSES[1:]):
		cls_ind += 1 #because we skipped background
		cls_boxes = boxes[:, 4*cls_ind:4*(cls_ind + 1)]
		cls_scores = scores[:,cls_ind]
		dets = np.hstack((cls_boxes,
						cls_scores[:, np.newaxis])).astype(np.float32)
		keep = nms(dets,NMS_THRESH)
		dets = dets[keep, :]
		inds = np.where(dets[:,-1] >= thresh)[0]
		
		if cls == speech:
			for i in inds:
				bbox = dets[i, :4]
				score = dets[i, -1]
				im = cv2.rectangle(im, (bbox[0], bbox[1]),(bbox[2], bbox[3]),
								 (0,0,255), 2)
				im = cv2.putText(im, ('{:s} {:.3f}'.format(cls,score)),
								(int(bbox[0]), int(bbox[1]-2)),
								cv2.FONT_HERSHEY_SIMPLEX,
								0.8, (0,0,0), 2)
			        print 'A'
                        	addObjParam = ObjectParam(cls, long(bbox[2]-bbox[0]), long(bbox[3]-bbox[1]), long(bbox[0]), long(bbox[1]))
                        	objParam.append(addObjParam)
				searchResult = 1
				print 'B'

#	cv2.imwrite('result.jpg', im)
        return searchResult

##
# @class Deep_LearningRTC
# @brief ModuleDescription
# 
# 
class Deep_LearningRTC(OpenRTM_aist.DataFlowComponentBase):
	
	##
	# @brief constructor
	# @param manager Maneger Object
	# 
	def __init__(self, manager):
		OpenRTM_aist.DataFlowComponentBase.__init__(self, manager)

		inImage_arg = [None] * ((len(Img._d_TimedCameraImage) - 4) / 2)
		self._d_inImage = Img.TimedCameraImage(*inImage_arg)
		"""
		"""
		self._inImageIn = OpenRTM_aist.InPort("inImage", self._d_inImage)
		self._d_inString = OpenRTM_aist.instantiateDataType(RTC.TimedString)
		"""
		"""
		self._inStringIn = OpenRTM_aist.InPort("inString", self._d_inString)
		outImage_arg = [None] * ((len(Img._d_TimedCameraImage) - 4) / 2)
		self._d_outImage = Img.TimedCameraImage(RTC.Time(0,0),Img.CameraImage(RTC.Time(0,0),Img.ImageData(0,0,0,[]),Img.CameraIntrinsicParameter([],[]),[]),0)
		"""
		"""
		self._outImageOut = OpenRTM_aist.OutPort("outImage", self._d_outImage)
		self._d_outObjectParam = OpenRTM_aist.instantiateDataType(ObjectRecognition.TimedObjectParamSeq)
		"""
		"""
		self._outObjectParamOut = OpenRTM_aist.OutPort("outObjectParam", self._d_outObjectParam)
		self._d_outFlag = OpenRTM_aist.instantiateDataType(RTC.TimedLong)
		"""
		"""
		self._outFlagOut = OpenRTM_aist.OutPort("outFlag", self._d_outFlag)


		


		# initialize of configuration-data.
		# <rtc-template block="init_conf_param">
		"""
		
		 - Name:  dataset
		 - DefaultValue: karuta
		"""
		self._dataset = ['karuta']
		"""
		
		 - Name:  mode
		 - DefaultValue: gpu
		"""
		self._mode = ['gpu']
		"""
		
		 - Name:  net
		 - DefaultValue: vgg16
		"""
		self._net = ['vgg16']
		"""
		
		 - Name:  recognitionRate
		 - DefaultValue: 0.8
		"""
		self._recognitionRate = [0.8]
		
		# </rtc-template>


		 
	##
	#
	# The initialize action (on CREATED->ALIVE transition)
	# formaer rtc_init_entry() 
	# 
	# @return RTC::ReturnCode_t
	# 
	#
	def onInitialize(self):
		# Bind variables and configuration variable
		self.bindParameter("dataset", self._dataset, "karuta")
		self.bindParameter("mode", self._mode, "gpu")
		self.bindParameter("net", self._net, "vgg16")
		self.bindParameter("recognitionRate", self._recognitionRate, "0.8")
		
		# Set InPort buffers
		self.addInPort("inImage",self._inImageIn)
		self.addInPort("inString",self._inStringIn)
		
		# Set OutPort buffers
		self.addOutPort("outImage",self._outImageOut)
		self.addOutPort("outObjectParam",self._outObjectParamOut)
		self.addOutPort("outFlag",self._outFlagOut)
		
		# Set service provider to Ports
		
		# Set service consumers to Ports
		
		# Set CORBA Service Ports
		
		return RTC.RTC_OK
	
	#	##
	#	# 
	#	# The finalize action (on ALIVE->END transition)
	#	# formaer rtc_exiting_entry()
	#	# 
	#	# @return RTC::ReturnCode_t
	#
	#	# 
	#def onFinalize(self):
	#
	#	return RTC.RTC_OK
	
	#	##
	#	#
	#	# The startup action when ExecutionContext startup
	#	# former rtc_starting_entry()
	#	# 
	#	# @param ec_id target ExecutionContext Id
	#	#
	#	# @return RTC::ReturnCode_t
	#	#
	#	#
	#def onStartup(self, ec_id):
	#
	#	return RTC.RTC_OK
	
	#	##
	#	#
	#	# The shutdown action when ExecutionContext stop
	#	# former rtc_stopping_entry()
	#	#
	#	# @param ec_id target ExecutionContext Id
	#	#
	#	# @return RTC::ReturnCode_t
	#	#
	#	#
	#def onShutdown(self, ec_id):
	#
	#	return RTC.RTC_OK
	
		##
		#
		# The activated action (Active state entry action)
		# former rtc_active_entry()
		#
		# @param ec_id target ExecutionContext Id
		# 
		# @return RTC::ReturnCode_t
		#
		#
	def onActivated(self, ec_id):
		cfg.TEST.HAS_RPN = True

		m_net = self._net[0]
		m_dataset = self._dataset[0]
		if m_dataset == 'voc':
			self._CLASSES = CLASSES_VOC
			prototxt = os.path.join(cfg.MODELS_DIR, NETS[m_net][0],
				'faster_rcnn_alt_opt', 'faster_rcnn_test.pt')
			caffemodel = os.path.join(cfg.DATA_DIR, 'faster_rcnn_models',
				NETS[m_net][1])
		elif m_dataset == 'coco':
			self._CLASSES = CLASSES_COCO
			prototxt = os.path.join(cfg.MODELS_DIR,'../coco', NETS[m_net][0],
				'faster_rcnn_end2end', 'test.prototxt')
			caffemodel = os.path.join(cfg.DATA_DIR, 'faster_rcnn_models',
				'coco_vgg16_faster_rcnn_final.caffemodel')		
		elif m_dataset == 'karuta':
			self._CLASSES = CLASSES_KARUTA
			prototxt = os.path.join(cfg.MODELS_DIR,'../karuta', NETS[m_net][0],
				'faster_rcnn_end2end', 'test.prototxt')
			caffemodel = os.path.join(cfg.DATA_DIR, 'faster_rcnn_models',
				'karuta.caffemodel')
		if not os.path.isfile(caffemodel):
			raise IOError(('{:s} not found.\nDid you run ./data/script/'
							'fetch_faster_rcnn_models.sh?').format(caffemodel))

		m_mode = self._mode[0]
		if m_mode == 'cpu':
			caffe.set_mode_cpu()
		else:
			caffe.set_mode_gpu()
			caffe.set_device(0)
			cfg.GPU_ID = 0

		global net
		net = caffe.Net(prototxt, caffemodel, caffe.TEST)

		print '\n\nLoaded network {:s}'.format(caffemodel)
		
		# Warmup on a dummy image
		im =128 *  np.ones((640, 480, 3), dtype=np.int8)
		for i in xrange(2):
			_, _= im_detect(net,im)
	
		return RTC.RTC_OK
	
	#	##
	#	#
	#	# The deactivated action (Active state exit action)
	#	# former rtc_active_exit()
	#	#
	#	# @param ec_id target ExecutionContext Id
	#	#
	#	# @return RTC::ReturnCode_t
	#	#
	#	#
	#def onDeactivated(self, ec_id):
	#
	#	return RTC.RTC_OK
	
		##
		#
		# The execution action that is invoked periodically
		# former rtc_active_do()
		#
		# @param ec_id target ExecutionContext Id
		#
		# @return RTC::ReturnCode_t
		#
		#
	def onExecute(self, ec_id):
                if self._inImageIn.isNew():
			start = time.time()

			# Image input
			indata = self._inImageIn.read()
			width = indata.data.image.width 
			height = indata.data.image.height
			channels = 3
			rawdata = indata.data.image.raw_data
			size = (width, height, channels)
			img = np.fromstring(indata.data.image.raw_data, dtype=np.ubyte)
			img = img.reshape(height, width, channels)
			img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

			# String input
			indata2 = self._inStringIn.read()
   			readData = indata2.data
			print 'Search Card : {}'.format(readData)

			print 'detect .. '
                	# Object recognition from image
			global net
			self._d_outFlag.data = detect(net, img, readData, self._CLASSES, self._recognitionRate[0])

       			elapsed_time =  time.time() - start
       			print ("elapsed_time:{0}".format(elapsed_time) + "[sec]")
			print ('Search Realut : {}'.format(self._d_outFlag.data))

			# Output image and Output ObjectParam	
			print '-----------------------'
		
			self._d_outObjectParam.tm = indata.tm
	                #self._d_outObjectParam.data = objParam
			self._d_outImage.data = indata.data
			self._d_outImage.data.image.raw_data = img.tostring()			

			self._outImageOut.write()	
	                #self._outObjectParamOut.write()	
			self._outFlagOut.write()
			
		return RTC.RTC_OK
	
	#	##
	#	#
	#	# The aborting action when main logic error occurred.
	#	# former rtc_aborting_entry()
	#	#
	#	# @param ec_id target ExecutionContext Id
	#	#
	#	# @return RTC::ReturnCode_t
	#	#
	#	#
	#def onAborting(self, ec_id):
	#
	#	return RTC.RTC_OK
	
	#	##
	#	#
	#	# The error action in ERROR state
	#	# former rtc_error_do()
	#	#
	#	# @param ec_id target ExecutionContext Id
	#	#
	#	# @return RTC::ReturnCode_t
	#	#
	#	#
	#def onError(self, ec_id):
	#
	#	return RTC.RTC_OK
	
	#	##
	#	#
	#	# The reset action that is invoked resetting
	#	# This is same but different the former rtc_init_entry()
	#	#
	#	# @param ec_id target ExecutionContext Id
	#	#
	#	# @return RTC::ReturnCode_t
	#	#
	#	#
	#def onReset(self, ec_id):
	#
	#	return RTC.RTC_OK
	
	#	##
	#	#
	#	# The state update action that is invoked after onExecute() action
	#	# no corresponding operation exists in OpenRTm-aist-0.2.0
	#	#
	#	# @param ec_id target ExecutionContext Id
	#	#
	#	# @return RTC::ReturnCode_t
	#	#

	#	#
	#def onStateUpdate(self, ec_id):
	#
	#	return RTC.RTC_OK
	
	#	##
	#	#
	#	# The action that is invoked when execution context's rate is changed
	#	# no corresponding operation exists in OpenRTm-aist-0.2.0
	#	#
	#	# @param ec_id target ExecutionContext Id
	#	#
	#	# @return RTC::ReturnCode_t
	#	#
	#	#
	#def onRateChanged(self, ec_id):
	#
	#	return RTC.RTC_OK
	



def Deep_LearningRTCInit(manager):
    profile = OpenRTM_aist.Properties(defaults_str=deep_learningrtc_spec)
    manager.registerFactory(profile,
                            Deep_LearningRTC,
                            OpenRTM_aist.Delete)

def MyModuleInit(manager):
    Deep_LearningRTCInit(manager)

    # Create a component
    comp = manager.createComponent("Deep_LearningRTC")

def main():
	mgr = OpenRTM_aist.Manager.init(sys.argv)
	mgr.setModuleInitProc(MyModuleInit)
	mgr.activateManager()
	mgr.runManager()

if __name__ == "__main__":
	main()

