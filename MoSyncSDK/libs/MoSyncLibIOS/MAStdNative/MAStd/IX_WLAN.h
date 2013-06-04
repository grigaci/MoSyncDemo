#ifndef IX_WLAN_H
#define IX_WLAN_H

#ifdef __cplusplus
extern "C" {
#endif

/// Uses MAEvent::state.
#define EVENT_TYPE_WLAN 7
/**@}*/
#define WLAN_ADDR_LEN 6
/**
* \brief A WLAN address.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAWlanAddr {
	byte a[WLAN_ADDR_LEN];
} MAWlanAddr;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief A WLAN access point.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAWlanAp {
	/// out
	MAWlanAddr address;

	/// in(ptr), out(content)
	char* name;

	/// in
	int nameBufSize;

	/// out. dBm?
	int signalStrength;
} MAWlanAp;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* Causes EVENT_TYPE_WLAN. Returns \<0 on failure.
* WLAN events' state are \>0 when the discovery is complete,
* 0 when it's still going on, \<0 on error.
*/
IOCTLDEF int maWlanStartDiscovery(void) {
	return (int) maIOCtl(36, 0, 0, 0);
}

/**
* Returns strlen(name) + 1 on success, 0 if no new AP is available, \<0 on failure.
*
* If \a dst.nameBufSize is less than the return value, the name is not copied.
*
* The IEEE 802.11 WLAN standard specifies that a name may be up to 32 characters long.
* Your buffer should therefore be at least 33 bytes long,
* in order to contain a maximum-length name and terminating zero.
*/
IOCTLDEF int maWlanGetNewAp(MAWlanAp* dst) {
	return (int) maIOCtl(37, (int)dst, 0, 0);
}

#ifdef __cplusplus
}
#endif

#endif	//IX_WLAN_H
