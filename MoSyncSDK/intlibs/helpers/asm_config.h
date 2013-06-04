#define SYSCALLS(m, arg1, arg, argD)\
	m(1, int, maCheckInterfaceVersion, arg1(hash), argD(in, int, hash))\
	m(2, noreturn, maExit, arg1(result), argD(in, int, result))\
	m(3, noreturn, maPanic, arg1(result)arg(message), argD(in, int, result) argD(in, MAString, message))\
	m(4, MAAddress, memset, arg1(dst)arg(val)arg(size), argD(out, MAAddress, dst) argD(in, int, val) argD(in, ulong, size))\
	m(5, MAAddress, memcpy, arg1(dst)arg(src)arg(size), argD(out, MAAddress, dst) argD(in, MAAddress, src) argD(in, ulong, size))\
	m(6, int, strcmp, arg1(str1)arg(str2), argD(in, MAString, str1) argD(in, MAString, str2))\
	m(7, MAString, strcpy, arg1(dst)arg(src), argD(out, NCString, dst) argD(in, NCString, src))\
	m(8, double, __adddf3, arg1(a)arg(b), argD(in, double, a) argD(in, double, b))\
	m(9, double, __subdf3, arg1(a)arg(b), argD(in, double, a) argD(in, double, b))\
	m(10, double, __muldf3, arg1(a)arg(b), argD(in, double, a) argD(in, double, b))\
	m(11, double, __divdf3, arg1(a)arg(b), argD(in, double, a) argD(in, double, b))\
	m(12, double, __negdf2, arg1(a), argD(in, double, a))\
	m(13, int, __fixdfsi, arg1(a), argD(in, double, a))\
	m(14, uint, __fixunsdfsi, arg1(a), argD(in, double, a))\
	m(15, double, __floatsidf, arg1(a), argD(in, int, a))\
	m(16, double, __extendsfdf2, arg1(a), argD(in, float, a))\
	m(17, int, dcmp, arg1(a)arg(b), argD(in, double, a) argD(in, double, b))\
	m(18, float, __addsf3, arg1(a)arg(b), argD(in, float, a) argD(in, float, b))\
	m(19, float, __subsf3, arg1(a)arg(b), argD(in, float, a) argD(in, float, b))\
	m(20, float, __mulsf3, arg1(a)arg(b), argD(in, float, a) argD(in, float, b))\
	m(21, float, __divsf3, arg1(a)arg(b), argD(in, float, a) argD(in, float, b))\
	m(22, float, __negsf2, arg1(a), argD(in, float, a))\
	m(23, int, __fixsfsi, arg1(a), argD(in, float, a))\
	m(24, uint, __fixunssfsi, arg1(a), argD(in, float, a))\
	m(25, float, __floatsisf, arg1(a), argD(in, int, a))\
	m(26, float, __truncdfsf2, arg1(a), argD(in, double, a))\
	m(27, int, fcmp, arg1(a)arg(b), argD(in, float, a) argD(in, float, b))\
	m(28, double, sin, arg1(x), argD(in, double, x))\
	m(29, double, cos, arg1(x), argD(in, double, x))\
	m(30, double, tan, arg1(x), argD(in, double, x))\
	m(31, double, sqrt, arg1(x), argD(in, double, x))\
	m(32, int, maSetColor, arg1(rgb), argD(in, int, rgb))\
	m(33, void, maSetClipRect, arg1(left)arg(top)arg(width)arg(height), argD(in, int, left) argD(in, int, top) argD(in, int, width) argD(in, int, height))\
	m(34, void, maGetClipRect, arg1(out), argD(out, MARect, out))\
	m(35, void, maPlot, arg1(posX)arg(posY), argD(in, int, posX) argD(in, int, posY))\
	m(36, void, maLine, arg1(startX)arg(startY)arg(endX)arg(endY), argD(in, int, startX) argD(in, int, startY) argD(in, int, endX) argD(in, int, endY))\
	m(37, void, maFillRect, arg1(left)arg(top)arg(width)arg(height), argD(in, int, left) argD(in, int, top) argD(in, int, width) argD(in, int, height))\
	m(38, void, maFillTriangleStrip, arg1(points)arg(count), argD(in, MAPoint2d, points) argD(in, int, count))\
	m(39, void, maFillTriangleFan, arg1(points)arg(count), argD(in, MAPoint2d, points) argD(in, int, count))\
	m(40, MAExtent, maGetTextSize, arg1(str), argD(in, MAString, str))\
	m(41, MAExtent, maGetTextSizeW, arg1(str), argD(in, MAWString, str))\
	m(42, void, maDrawText, arg1(left)arg(top)arg(str), argD(in, int, left) argD(in, int, top) argD(in, MAString, str))\
	m(43, void, maDrawTextW, arg1(left)arg(top)arg(str), argD(in, int, left) argD(in, int, top) argD(in, MAWString, str))\
	m(44, void, maUpdateScreen, ,)\
	m(45, void, maResetBacklight, ,)\
	m(46, MAExtent, maGetScrSize, ,)\
	m(47, void, maDrawImage, arg1(image)arg(left)arg(top), argD(in, MAHandle, image) argD(in, int, left) argD(in, int, top))\
	m(48, void, maDrawRGB, arg1(dstPoint)arg(src)arg(srcRect)arg(scanlength), argD(in, MAPoint2d, dstPoint) argD(in, MAAddress, src) argD(in, MARect, srcRect) argD(in, int, scanlength))\
	m(49, void, maDrawImageRegion, arg1(image)arg(srcRect)arg(dstPoint)arg(transformMode), argD(in, MAHandle, image) argD(in, MARect, srcRect) argD(in, MAPoint2d, dstPoint) argD(in, int, transformMode))\
	m(50, MAExtent, maGetImageSize, arg1(image), argD(in, MAHandle, image))\
	m(51, void, maGetImageData, arg1(image)arg(dst)arg(srcRect)arg(scanlength), argD(in, MAHandle, image) argD(out, MAAddress, dst) argD(in, MARect, srcRect) argD(in, int, scanlength))\
	m(52, MAHandle, maSetDrawTarget, arg1(image), argD(in, MAHandle, image))\
	m(53, int, maFindLabel, arg1(name), argD(in, MAString, name))\
	m(54, int, maCreateImageFromData, arg1(placeholder)arg(data)arg(offset)arg(size), argD(in, MAHandle, placeholder) argD(in, MAHandle, data) argD(in, int, offset) argD(in, int, size))\
	m(55, int, maCreateImageRaw, arg1(placeholder)arg(src)arg(size)arg(alpha), argD(in, MAHandle, placeholder) argD(in, MAAddress, src) argD(in, MAExtent, size) argD(in, int, alpha))\
	m(56, int, maCreateDrawableImage, arg1(placeholder)arg(width)arg(height), argD(in, MAHandle, placeholder) argD(in, int, width) argD(in, int, height))\
	m(57, int, maCreateData, arg1(placeholder)arg(size), argD(in, MAHandle, placeholder) argD(in, int, size))\
	m(58, MAHandle, maCreatePlaceholder, ,)\
	m(59, void, maDestroyPlaceholder, arg1(handle), argD(in, MAHandle, handle))\
	m(60, void, maDestroyObject, arg1(handle), argD(in, MAHandle, handle))\
	m(61, int, maGetDataSize, arg1(data), argD(in, MAHandle, data))\
	m(62, void, maReadData, arg1(data)arg(dst)arg(offset)arg(size), argD(in, MAHandle, data) argD(out, MAAddress, dst) argD(in, int, offset) argD(in, int, size))\
	m(63, void, maWriteData, arg1(data)arg(src)arg(offset)arg(size), argD(in, MAHandle, data) argD(in, MAAddress, src) argD(in, int, offset) argD(in, int, size))\
	m(64, void, maCopyData, arg1(params), argD(in, MACopyData, params))\
	m(65, MAHandle, maOpenStore, arg1(name)arg(flags), argD(in, MAString, name) argD(in, int, flags))\
	m(66, int, maWriteStore, arg1(store)arg(data), argD(in, MAHandle, store) argD(in, MAHandle, data))\
	m(67, int, maReadStore, arg1(store)arg(placeholder), argD(in, MAHandle, store) argD(in, MAHandle, placeholder))\
	m(68, void, maCloseStore, arg1(store)arg(_delete), argD(in, MAHandle, store) argD(in, int, _delete))\
	m(69, MAHandle, maConnect, arg1(url), argD(in, MAString, url))\
	m(70, void, maConnClose, arg1(conn), argD(in, MAHandle, conn))\
	m(71, void, maConnRead, arg1(conn)arg(dst)arg(size), argD(in, MAHandle, conn) argD(out, MAAddress, dst) argD(in, int, size))\
	m(72, void, maConnWrite, arg1(conn)arg(src)arg(size), argD(in, MAHandle, conn) argD(in, MAAddress, src) argD(in, int, size))\
	m(73, void, maConnReadToData, arg1(conn)arg(data)arg(offset)arg(size), argD(in, MAHandle, conn) argD(in, MAHandle, data) argD(in, int, offset) argD(in, int, size))\
	m(74, void, maConnWriteFromData, arg1(conn)arg(data)arg(offset)arg(size), argD(in, MAHandle, conn) argD(in, MAHandle, data) argD(in, int, offset) argD(in, int, size))\
	m(75, void, maConnReadFrom, arg1(conn)arg(dst)arg(size)arg(src), argD(in, MAHandle, conn) argD(out, MAAddress, dst) argD(in, int, size) argD(out, MAConnAddr, src))\
	m(76, void, maConnWriteTo, arg1(conn)arg(src)arg(size)arg(dst), argD(in, MAHandle, conn) argD(in, MAAddress, src) argD(in, int, size) argD(in, MAConnAddr, dst))\
	m(77, int, maConnGetAddr, arg1(conn)arg(addr), argD(in, MAHandle, conn) argD(out, MAConnAddr, addr))\
	m(78, MAHandle, maHttpCreate, arg1(url)arg(method), argD(in, MAString, url) argD(in, int, method))\
	m(79, void, maHttpSetRequestHeader, arg1(conn)arg(key)arg(value), argD(in, MAHandle, conn) argD(in, MAString, key) argD(in, MAString, value))\
	m(80, int, maHttpGetResponseHeader, arg1(conn)arg(key)arg(buffer)arg(bufSize), argD(in, MAHandle, conn) argD(in, MAString, key) argD(out, MAString, buffer) argD(in, int, bufSize))\
	m(81, void, maHttpFinish, arg1(conn), argD(in, MAHandle, conn))\
	m(82, int, maLoadResources, arg1(data), argD(in, MAHandle, data))\
	m(83, int, maLoadResource, arg1(handle)arg(placeholder)arg(flag), argD(in, MAHandle, handle) argD(in, MAHandle, placeholder) argD(in, int, flag))\
	m(84, int, maCountResources, ,)\
	m(85, void, maLoadProgram, arg1(data)arg(reload), argD(in, MAHandle, data) argD(in, int, reload))\
	m(86, int, maGetKeys, ,)\
	m(87, int, maGetEvent, arg1(event), argD(out, MAEvent, event))\
	m(88, void, maWait, arg1(timeout), argD(in, int, timeout))\
	m(89, int, maTime, ,)\
	m(90, int, maLocalTime, ,)\
	m(91, int, maGetMilliSecondCount, ,)\
	m(92, int, maFreeObjectMemory, ,)\
	m(93, int, maTotalObjectMemory, ,)\
	m(94, int, maVibrate, arg1(ms), argD(in, int, ms))\
	m(95, int, maSoundPlay, arg1(sound_res)arg(offset)arg(size), argD(in, MAHandle, sound_res) argD(in, int, offset) argD(in, int, size))\
	m(96, void, maSoundStop, ,)\
	m(97, int, maSoundIsPlaying, ,)\
	m(98, int, maSoundGetVolume, ,)\
	m(99, void, maSoundSetVolume, arg1(vol), argD(in, int, vol))\
	m(100, longlong, maExtensionFunctionInvoke, arg1(function)arg(a)arg(b)arg(c), argD(in, int, function) argD(in, int, a) argD(in, int, b) argD(in, int, c))\
	m(101, longlong, maIOCtl, arg1(function)arg(a)arg(b)arg(c), argD(in, int, function) argD(in, int, a) argD(in, int, b) argD(in, int, c))\

