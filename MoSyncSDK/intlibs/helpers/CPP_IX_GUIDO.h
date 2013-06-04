#ifndef IX_GUIDO_DEFS_H
#define IX_GUIDO_DEFS_H

/** \brief A hash of the abstract representation of the API described in this file.
 * Identifiers, declarations and definitions are included in the calculation of the hash,
 * but documentation is not.
 */
#define MAIDL_HASH ((int)0x28c5d5c8)

#ifndef DONT_WANT_IX_GUIDO_TYPEDEFS
#endif
/// Has MAEvent::ked::key be the identifier for the TTS session, as returned by maStartSpeaking().
#define EVENT_TYPE_TTS 6
#define maExtensionFunctionInvoke_IX_GUIDO_caselist \

#define maExtensionFunctionInvoke_IX_GUIDO_syscall_caselist \

#undef ARG_NO_4
#define ARG_NO_4 SYSCALL_THIS->GetValidatedStackValue(0 VSV_ARGPTR_USE)
#undef ARG_NO_5
#define ARG_NO_5 SYSCALL_THIS->GetValidatedStackValue(4 VSV_ARGPTR_USE)
#undef ARG_NO_6
#define ARG_NO_6 SYSCALL_THIS->GetValidatedStackValue(8 VSV_ARGPTR_USE)
#undef ARG_NO_7
#define ARG_NO_7 SYSCALL_THIS->GetValidatedStackValue(12 VSV_ARGPTR_USE)
#undef ARG_NO_8
#define ARG_NO_8 SYSCALL_THIS->GetValidatedStackValue(16 VSV_ARGPTR_USE)
#undef ARG_NO_9
#define ARG_NO_9 SYSCALL_THIS->GetValidatedStackValue(20 VSV_ARGPTR_USE)
#undef ARG_NO_10
#define ARG_NO_10 SYSCALL_THIS->GetValidatedStackValue(24 VSV_ARGPTR_USE)
#define maIOCtl_IX_GUIDO_caselist \
maIOCtl_maStartSpeaking_case(maStartSpeaking) \
maIOCtl_maStopSpeaking_case(maStopSpeaking) \
maIOCtl_maIsSpeaking_case(maIsSpeaking) \
maIOCtl_maSetSpeechVolume_case(maSetSpeechVolume) \
maIOCtl_maSetSpeechSpeed_case(maSetSpeechSpeed) \
maIOCtl_maSetSpeechPitch_case(maSetSpeechPitch) \
maIOCtl_sinh_case(sinh) \
maIOCtl_cosh_case(cosh) \
maIOCtl_atanh_case(atanh) \

#define maIOCtl_IX_GUIDO_syscall_caselist \
maIOCtl_syscall_case(maStartSpeaking) \
maIOCtl_syscall_case(maStopSpeaking) \
maIOCtl_syscall_case(maIsSpeaking) \
maIOCtl_syscall_case(maSetSpeechVolume) \
maIOCtl_syscall_case(maSetSpeechSpeed) \
maIOCtl_syscall_case(maSetSpeechPitch) \
maIOCtl_syscall_case(sinh) \
maIOCtl_syscall_case(cosh) \
maIOCtl_syscall_case(atanh) \

#undef ARG_NO_4
#define ARG_NO_4 SYSCALL_THIS->GetValidatedStackValue(0 VSV_ARGPTR_USE)
#undef ARG_NO_5
#define ARG_NO_5 SYSCALL_THIS->GetValidatedStackValue(4 VSV_ARGPTR_USE)
#undef ARG_NO_6
#define ARG_NO_6 SYSCALL_THIS->GetValidatedStackValue(8 VSV_ARGPTR_USE)
#undef ARG_NO_7
#define ARG_NO_7 SYSCALL_THIS->GetValidatedStackValue(12 VSV_ARGPTR_USE)
#undef ARG_NO_8
#define ARG_NO_8 SYSCALL_THIS->GetValidatedStackValue(16 VSV_ARGPTR_USE)
#undef ARG_NO_9
#define ARG_NO_9 SYSCALL_THIS->GetValidatedStackValue(20 VSV_ARGPTR_USE)
#undef ARG_NO_10
#define ARG_NO_10 SYSCALL_THIS->GetValidatedStackValue(24 VSV_ARGPTR_USE)
#define maIOCtl_maStartSpeaking 17
#define maIOCtl_maStartSpeaking_case(func) \
case 17: \
{ \
const char* _text = GVS(a); \
return func(_text); \
} \

#define maIOCtl_maStopSpeaking 18
#define maIOCtl_maStopSpeaking_case(func) \
case 18: \
{ \
return func(); \
} \

#define maIOCtl_maIsSpeaking 19
#define maIOCtl_maIsSpeaking_case(func) \
case 19: \
{ \
return func(); \
} \

#define maIOCtl_maSetSpeechVolume 20
#define maIOCtl_maSetSpeechVolume_case(func) \
case 20: \
{ \
int _volume = a; \
return func(_volume); \
} \

#define maIOCtl_maSetSpeechSpeed 21
#define maIOCtl_maSetSpeechSpeed_case(func) \
case 21: \
{ \
int _speed = a; \
return func(_speed); \
} \

#define maIOCtl_maSetSpeechPitch 22
#define maIOCtl_maSetSpeechPitch_case(func) \
case 22: \
{ \
int _pitch = a; \
return func(_pitch); \
} \

#define maIOCtl_sinh 23
#define maIOCtl_sinh_case(func) \
case 23: \
{ \
MA_DV _x_dv; \
_x_dv.MA_DV_HI = a; \
_x_dv.MA_DV_LO = b; \
double _x = _x_dv.d; \
MA_DV result; \
result.d = func(_x); \
return result.ll; \
} \

#define maIOCtl_cosh 24
#define maIOCtl_cosh_case(func) \
case 24: \
{ \
MA_DV _x_dv; \
_x_dv.MA_DV_HI = a; \
_x_dv.MA_DV_LO = b; \
double _x = _x_dv.d; \
MA_DV result; \
result.d = func(_x); \
return result.ll; \
} \

#define maIOCtl_atanh 25
#define maIOCtl_atanh_case(func) \
case 25: \
{ \
MA_DV _x_dv; \
_x_dv.MA_DV_HI = a; \
_x_dv.MA_DV_LO = b; \
double _x = _x_dv.d; \
MA_DV result; \
result.d = func(_x); \
return result.ll; \
} \


#endif	//IX_GUIDO_DEFS_H
