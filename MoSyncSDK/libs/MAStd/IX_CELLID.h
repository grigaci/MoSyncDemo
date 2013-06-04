#ifndef IX_CELLID_H
#define IX_CELLID_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* \brief Information about the current cell, including country,
* network and area code and the cell ID.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MACellInfo {
	/**
	* Mobile Country Code. Identifies the country whose cellular network the phone
	* is connected to.
	*/
	char mcc[4];

	/**
	* Mobile Network Code. Identifies the network operator
	* in the country specified by the MCC.
	*/
	char mnc[8];

	/**
	* Location Area Code. Identifies a geographic area within the cellular network
	* specified by the MCC and MNC.
	*/
	int lac;

	/**
	* Cell ID. Identifies the base station the phone is connected to,
	* within the cellular network specified by the MCC and MNC.
	* \note While a phone may be in range of several base stations at any time,
	* only one of those base stations controls the connection between the phone and
	* the network. That is the base station reported here.
	*/
	int cellId;
} MACellInfo;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* Retrieves the current cellular network information.
* If the phone is offline or otherwise has no signal, this function will fail.
* \param pInfo A pointer to a struct which will receive the information.
* \returns 0 if successful. \< 0 otherwise.
*/
IOCTLDEF int maGetCellInfo(MACellInfo* pInfo) {
	return (int) maIOCtl(67, (int)pInfo, 0, 0);
}

#ifdef __cplusplus
}
#endif

#endif	//IX_CELLID_H
