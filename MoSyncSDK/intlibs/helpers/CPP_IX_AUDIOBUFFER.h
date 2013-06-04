#ifndef IX_AUDIOBUFFER_DEFS_H
#define IX_AUDIOBUFFER_DEFS_H

/** \brief A hash of the abstract representation of the API described in this file.
 * Identifiers, declarations and definitions are included in the calculation of the hash,
 * but documentation is not.
 */
#define MAIDL_HASH ((int)0x28c5d5c8)

#ifndef DONT_WANT_IX_AUDIOBUFFER_TYPEDEFS
#endif
/// MAEvent::state is \> 0 when the audio stream is waiting for more data,
/// or \< 0 on error.
#define EVENT_TYPE_AUDIOBUFFER_FILL 18
#define AUDIO_FMT_S8 1
#define AUDIO_FMT_S16 2
#define AUDIO_FMT_U8 3
#define AUDIO_FMT_U16 4
/**
* \brief Information about an audio buffer, including format, sample rate, channels, and size.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAAudioBufferInfo {
	int fmt;
	int sampleRate;
	int numChannels;
	int bufferSize;
	MAAddress buffer;
} MAAudioBufferInfo;
#ifdef _MSC_VER
#pragma pack(pop)
#endif
typedef struct MAAudioBufferInfoNative {
	int fmt;
	int sampleRate;
	int numChannels;
	int bufferSize;
	MAAddress buffer;
} MAAudioBufferInfoNative;

#define maExtensionFunctionInvoke_IX_AUDIOBUFFER_caselist \

#define maExtensionFunctionInvoke_IX_AUDIOBUFFER_syscall_caselist \

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
#define maIOCtl_IX_AUDIOBUFFER_caselist \
maIOCtl_maAudioBufferInit_case(maAudioBufferInit) \
maIOCtl_maAudioBufferReady_case(maAudioBufferReady) \
maIOCtl_maAudioBufferClose_case(maAudioBufferClose) \

#define maIOCtl_IX_AUDIOBUFFER_syscall_caselist \
maIOCtl_syscall_case(maAudioBufferInit) \
maIOCtl_syscall_case(maAudioBufferReady) \
maIOCtl_syscall_case(maAudioBufferClose) \

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
#define maIOCtl_maAudioBufferInit 84
#define maIOCtl_maAudioBufferInit_case(func) \
case 84: \
{ \
const MAAudioBufferInfo* _info = GVMR(a, MAAudioBufferInfo); \
return func(_info); \
} \

#define maIOCtl_maAudioBufferReady 85
#define maIOCtl_maAudioBufferReady_case(func) \
case 85: \
{ \
return func(); \
} \

#define maIOCtl_maAudioBufferClose 86
#define maIOCtl_maAudioBufferClose_case(func) \
case 86: \
{ \
return func(); \
} \


#endif	//IX_AUDIOBUFFER_DEFS_H
