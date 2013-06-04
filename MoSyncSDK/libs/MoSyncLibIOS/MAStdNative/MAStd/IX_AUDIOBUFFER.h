#ifndef IX_AUDIOBUFFER_H
#define IX_AUDIOBUFFER_H

#ifdef __cplusplus
extern "C" {
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

IOCTLDEF int maAudioBufferInit(const MAAudioBufferInfo* info) {
	return (int) maIOCtl(84, (int)info, 0, 0);
}

IOCTLDEF int maAudioBufferReady(void) {
	return (int) maIOCtl(85, 0, 0, 0);
}

IOCTLDEF int maAudioBufferClose(void) {
	return (int) maIOCtl(86, 0, 0, 0);
}

#ifdef __cplusplus
}
#endif

#endif	//IX_AUDIOBUFFER_H
