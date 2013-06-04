#ifndef IX_OPENGL_ES_MA_DEFS_H
#define IX_OPENGL_ES_MA_DEFS_H

/** \brief A hash of the abstract representation of the API described in this file.
 * Identifiers, declarations and definitions are included in the calculation of the hash,
 * but documentation is not.
 */
#define MAIDL_HASH ((int)0x28c5d5c8)

#ifndef DONT_WANT_IX_OPENGL_ES_MA_TYPEDEFS
#endif
/** @ingroup OpenGLES */
#define MA_GL_TEX_IMAGE_2D_OK 0
/** @ingroup OpenGLES */
#define MA_GL_TEX_IMAGE_2D_INVALID_IMAGE -2
/** @ingroup OpenGLES */
#define MA_GL_API_GL2 0
/** @ingroup OpenGLES */
#define MA_GL_API_GL1 1
/** @ingroup OpenGLES */
#define MA_GL_INIT_RES_OK 0
/** @ingroup OpenGLES */
#define MA_GL_INIT_RES_UNAVAILABLE_API -2
/** @ingroup OpenGLES */
#define MA_GL_INIT_RES_ERROR -3
#define maExtensionFunctionInvoke_IX_OPENGL_ES_MA_caselist \

#define maExtensionFunctionInvoke_IX_OPENGL_ES_MA_syscall_caselist \

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
#define maIOCtl_IX_OPENGL_ES_MA_caselist \
maIOCtl_maOpenGLInitFullscreen_case(maOpenGLInitFullscreen) \
maIOCtl_maOpenGLCloseFullscreen_case(maOpenGLCloseFullscreen) \
maIOCtl_maOpenGLTexImage2D_case(maOpenGLTexImage2D) \
maIOCtl_maOpenGLTexSubImage2D_case(maOpenGLTexSubImage2D) \

#define maIOCtl_IX_OPENGL_ES_MA_syscall_caselist \
maIOCtl_syscall_case(maOpenGLInitFullscreen) \
maIOCtl_syscall_case(maOpenGLCloseFullscreen) \
maIOCtl_syscall_case(maOpenGLTexImage2D) \
maIOCtl_syscall_case(maOpenGLTexSubImage2D) \

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
#define maIOCtl_maOpenGLInitFullscreen 176
#define maIOCtl_maOpenGLInitFullscreen_case(func) \
case 176: \
{ \
int _glApi = a; \
return func(_glApi); \
} \

#define maIOCtl_maOpenGLCloseFullscreen 177
#define maIOCtl_maOpenGLCloseFullscreen_case(func) \
case 177: \
{ \
return func(); \
} \

#define maIOCtl_maOpenGLTexImage2D 178
#define maIOCtl_maOpenGLTexImage2D_case(func) \
case 178: \
{ \
MAHandle _image = (MAHandle)a; \
return func(_image); \
} \

#define maIOCtl_maOpenGLTexSubImage2D 179
#define maIOCtl_maOpenGLTexSubImage2D_case(func) \
case 179: \
{ \
MAHandle _image = (MAHandle)a; \
return func(_image); \
} \


#endif	//IX_OPENGL_ES_MA_DEFS_H
