// This file is generated by omniidl (C++ backend) - omniORB_4_1. Do not edit.

#include "ObjectRecognition.hh"

OMNI_USING_NAMESPACE(omni)

static const char* _0RL_dyn_library_version = omniORB_4_1_dyn;

static ::CORBA::TypeCode::_Tracker _0RL_tcTrack(__FILE__);

static CORBA::PR_structMember _0RL_structmember_ObjectRecognition_mObjectParam[] = {
  {"name", CORBA::TypeCode::PR_string_tc(0, &_0RL_tcTrack)},
  {"width", CORBA::TypeCode::PR_long_tc()},
  {"height", CORBA::TypeCode::PR_long_tc()},
  {"x", CORBA::TypeCode::PR_long_tc()},
  {"y", CORBA::TypeCode::PR_long_tc()}
};

#ifdef _0RL_tc_ObjectRecognition_mObjectParam
#  undef _0RL_tc_ObjectRecognition_mObjectParam
#endif
static CORBA::TypeCode_ptr _0RL_tc_ObjectRecognition_mObjectParam = CORBA::TypeCode::PR_struct_tc("IDL:ObjectRecognition/ObjectParam:1.0", "ObjectParam", _0RL_structmember_ObjectRecognition_mObjectParam, 5, &_0RL_tcTrack);

#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace ObjectRecognition { 
  const ::CORBA::TypeCode_ptr _tc_ObjectParam = _0RL_tc_ObjectRecognition_mObjectParam;
} 
#else
const ::CORBA::TypeCode_ptr ObjectRecognition::_tc_ObjectParam = _0RL_tc_ObjectRecognition_mObjectParam;
#endif


static CORBA::PR_structMember _0RL_structmember_RTC_mTime[] = {
  {"sec", CORBA::TypeCode::PR_ulong_tc()},
  {"nsec", CORBA::TypeCode::PR_ulong_tc()}
};

#ifdef _0RL_tc_RTC_mTime
#  undef _0RL_tc_RTC_mTime
#endif
static CORBA::TypeCode_ptr _0RL_tc_RTC_mTime = CORBA::TypeCode::PR_struct_tc("IDL:RTC/Time:1.0", "Time", _0RL_structmember_RTC_mTime, 2, &_0RL_tcTrack);


static CORBA::PR_structMember _0RL_structmember_ObjectRecognition_mTimedObjectParam[] = {
  {"tm", _0RL_tc_RTC_mTime},
  {"data", _0RL_tc_ObjectRecognition_mObjectParam}
};

#ifdef _0RL_tc_ObjectRecognition_mTimedObjectParam
#  undef _0RL_tc_ObjectRecognition_mTimedObjectParam
#endif
static CORBA::TypeCode_ptr _0RL_tc_ObjectRecognition_mTimedObjectParam = CORBA::TypeCode::PR_struct_tc("IDL:ObjectRecognition/TimedObjectParam:1.0", "TimedObjectParam", _0RL_structmember_ObjectRecognition_mTimedObjectParam, 2, &_0RL_tcTrack);



#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace ObjectRecognition { 
  const ::CORBA::TypeCode_ptr _tc_TimedObjectParam = _0RL_tc_ObjectRecognition_mTimedObjectParam;
} 
#else
const ::CORBA::TypeCode_ptr ObjectRecognition::_tc_TimedObjectParam = _0RL_tc_ObjectRecognition_mTimedObjectParam;
#endif




static CORBA::PR_structMember _0RL_structmember_ObjectRecognition_mTimedObjectParamSeq[] = {
  {"tm", _0RL_tc_RTC_mTime},
  {"data", CORBA::TypeCode::PR_sequence_tc(0, _0RL_tc_ObjectRecognition_mObjectParam, &_0RL_tcTrack)}
};

#ifdef _0RL_tc_ObjectRecognition_mTimedObjectParamSeq
#  undef _0RL_tc_ObjectRecognition_mTimedObjectParamSeq
#endif
static CORBA::TypeCode_ptr _0RL_tc_ObjectRecognition_mTimedObjectParamSeq = CORBA::TypeCode::PR_struct_tc("IDL:ObjectRecognition/TimedObjectParamSeq:1.0", "TimedObjectParamSeq", _0RL_structmember_ObjectRecognition_mTimedObjectParamSeq, 2, &_0RL_tcTrack);



#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace ObjectRecognition { 
  const ::CORBA::TypeCode_ptr _tc_TimedObjectParamSeq = _0RL_tc_ObjectRecognition_mTimedObjectParamSeq;
} 
#else
const ::CORBA::TypeCode_ptr ObjectRecognition::_tc_TimedObjectParamSeq = _0RL_tc_ObjectRecognition_mTimedObjectParamSeq;
#endif


static void _0RL_ObjectRecognition_mObjectParam_marshal_fn(cdrStream& _s, void* _v)
{
  ObjectRecognition::ObjectParam* _p = (ObjectRecognition::ObjectParam*)_v;
  *_p >>= _s;
}
static void _0RL_ObjectRecognition_mObjectParam_unmarshal_fn(cdrStream& _s, void*& _v)
{
  ObjectRecognition::ObjectParam* _p = new ObjectRecognition::ObjectParam;
  *_p <<= _s;
  _v = _p;
}
static void _0RL_ObjectRecognition_mObjectParam_destructor_fn(void* _v)
{
  ObjectRecognition::ObjectParam* _p = (ObjectRecognition::ObjectParam*)_v;
  delete _p;
}

void operator<<=(::CORBA::Any& _a, const ObjectRecognition::ObjectParam& _s)
{
  ObjectRecognition::ObjectParam* _p = new ObjectRecognition::ObjectParam(_s);
  _a.PR_insert(_0RL_tc_ObjectRecognition_mObjectParam,
               _0RL_ObjectRecognition_mObjectParam_marshal_fn,
               _0RL_ObjectRecognition_mObjectParam_destructor_fn,
               _p);
}
void operator<<=(::CORBA::Any& _a, ObjectRecognition::ObjectParam* _sp)
{
  _a.PR_insert(_0RL_tc_ObjectRecognition_mObjectParam,
               _0RL_ObjectRecognition_mObjectParam_marshal_fn,
               _0RL_ObjectRecognition_mObjectParam_destructor_fn,
               _sp);
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, ObjectRecognition::ObjectParam*& _sp)
{
  return _a >>= (const ObjectRecognition::ObjectParam*&) _sp;
}
::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, const ObjectRecognition::ObjectParam*& _sp)
{
  void* _v;
  if (_a.PR_extract(_0RL_tc_ObjectRecognition_mObjectParam,
                    _0RL_ObjectRecognition_mObjectParam_unmarshal_fn,
                    _0RL_ObjectRecognition_mObjectParam_marshal_fn,
                    _0RL_ObjectRecognition_mObjectParam_destructor_fn,
                    _v)) {
    _sp = (const ObjectRecognition::ObjectParam*)_v;
    return 1;
  }
  return 0;
}

static void _0RL_ObjectRecognition_mTimedObjectParam_marshal_fn(cdrStream& _s, void* _v)
{
  ObjectRecognition::TimedObjectParam* _p = (ObjectRecognition::TimedObjectParam*)_v;
  *_p >>= _s;
}
static void _0RL_ObjectRecognition_mTimedObjectParam_unmarshal_fn(cdrStream& _s, void*& _v)
{
  ObjectRecognition::TimedObjectParam* _p = new ObjectRecognition::TimedObjectParam;
  *_p <<= _s;
  _v = _p;
}
static void _0RL_ObjectRecognition_mTimedObjectParam_destructor_fn(void* _v)
{
  ObjectRecognition::TimedObjectParam* _p = (ObjectRecognition::TimedObjectParam*)_v;
  delete _p;
}

void operator<<=(::CORBA::Any& _a, const ObjectRecognition::TimedObjectParam& _s)
{
  ObjectRecognition::TimedObjectParam* _p = new ObjectRecognition::TimedObjectParam(_s);
  _a.PR_insert(_0RL_tc_ObjectRecognition_mTimedObjectParam,
               _0RL_ObjectRecognition_mTimedObjectParam_marshal_fn,
               _0RL_ObjectRecognition_mTimedObjectParam_destructor_fn,
               _p);
}
void operator<<=(::CORBA::Any& _a, ObjectRecognition::TimedObjectParam* _sp)
{
  _a.PR_insert(_0RL_tc_ObjectRecognition_mTimedObjectParam,
               _0RL_ObjectRecognition_mTimedObjectParam_marshal_fn,
               _0RL_ObjectRecognition_mTimedObjectParam_destructor_fn,
               _sp);
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, ObjectRecognition::TimedObjectParam*& _sp)
{
  return _a >>= (const ObjectRecognition::TimedObjectParam*&) _sp;
}
::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, const ObjectRecognition::TimedObjectParam*& _sp)
{
  void* _v;
  if (_a.PR_extract(_0RL_tc_ObjectRecognition_mTimedObjectParam,
                    _0RL_ObjectRecognition_mTimedObjectParam_unmarshal_fn,
                    _0RL_ObjectRecognition_mTimedObjectParam_marshal_fn,
                    _0RL_ObjectRecognition_mTimedObjectParam_destructor_fn,
                    _v)) {
    _sp = (const ObjectRecognition::TimedObjectParam*)_v;
    return 1;
  }
  return 0;
}

static void _0RL_ObjectRecognition_mTimedObjectParamSeq_marshal_fn(cdrStream& _s, void* _v)
{
  ObjectRecognition::TimedObjectParamSeq* _p = (ObjectRecognition::TimedObjectParamSeq*)_v;
  *_p >>= _s;
}
static void _0RL_ObjectRecognition_mTimedObjectParamSeq_unmarshal_fn(cdrStream& _s, void*& _v)
{
  ObjectRecognition::TimedObjectParamSeq* _p = new ObjectRecognition::TimedObjectParamSeq;
  *_p <<= _s;
  _v = _p;
}
static void _0RL_ObjectRecognition_mTimedObjectParamSeq_destructor_fn(void* _v)
{
  ObjectRecognition::TimedObjectParamSeq* _p = (ObjectRecognition::TimedObjectParamSeq*)_v;
  delete _p;
}

void operator<<=(::CORBA::Any& _a, const ObjectRecognition::TimedObjectParamSeq& _s)
{
  ObjectRecognition::TimedObjectParamSeq* _p = new ObjectRecognition::TimedObjectParamSeq(_s);
  _a.PR_insert(_0RL_tc_ObjectRecognition_mTimedObjectParamSeq,
               _0RL_ObjectRecognition_mTimedObjectParamSeq_marshal_fn,
               _0RL_ObjectRecognition_mTimedObjectParamSeq_destructor_fn,
               _p);
}
void operator<<=(::CORBA::Any& _a, ObjectRecognition::TimedObjectParamSeq* _sp)
{
  _a.PR_insert(_0RL_tc_ObjectRecognition_mTimedObjectParamSeq,
               _0RL_ObjectRecognition_mTimedObjectParamSeq_marshal_fn,
               _0RL_ObjectRecognition_mTimedObjectParamSeq_destructor_fn,
               _sp);
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, ObjectRecognition::TimedObjectParamSeq*& _sp)
{
  return _a >>= (const ObjectRecognition::TimedObjectParamSeq*&) _sp;
}
::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, const ObjectRecognition::TimedObjectParamSeq*& _sp)
{
  void* _v;
  if (_a.PR_extract(_0RL_tc_ObjectRecognition_mTimedObjectParamSeq,
                    _0RL_ObjectRecognition_mTimedObjectParamSeq_unmarshal_fn,
                    _0RL_ObjectRecognition_mTimedObjectParamSeq_marshal_fn,
                    _0RL_ObjectRecognition_mTimedObjectParamSeq_destructor_fn,
                    _v)) {
    _sp = (const ObjectRecognition::TimedObjectParamSeq*)_v;
    return 1;
  }
  return 0;
}

