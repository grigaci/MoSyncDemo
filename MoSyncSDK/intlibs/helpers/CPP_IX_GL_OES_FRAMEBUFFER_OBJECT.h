#ifndef IX_GL_OES_FRAMEBUFFER_OBJECT_DEFS_H
#define IX_GL_OES_FRAMEBUFFER_OBJECT_DEFS_H

/** \brief A hash of the abstract representation of the API described in this file.
 * Identifiers, declarations and definitions are included in the calculation of the hash,
 * but documentation is not.
 */
#define MAIDL_HASH ((int)0x28c5d5c8)

#ifndef DONT_WANT_IX_GL_OES_FRAMEBUFFER_OBJECT_TYPEDEFS
#endif
#define maExtensionFunctionInvoke_IX_GL_OES_FRAMEBUFFER_OBJECT_caselist \

#define maExtensionFunctionInvoke_IX_GL_OES_FRAMEBUFFER_OBJECT_syscall_caselist \

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
#define maIOCtl_IX_GL_OES_FRAMEBUFFER_OBJECT_caselist \
maIOCtl_glIsRenderbufferOES_case(glIsRenderbufferOES) \
maIOCtl_glBindRenderbufferOES_case(glBindRenderbufferOES) \
maIOCtl_glDeleteRenderbuffersOES_case(glDeleteRenderbuffersOES) \
maIOCtl_glGenRenderbuffersOES_case(glGenRenderbuffersOES) \
maIOCtl_glRenderbufferStorageOES_case(glRenderbufferStorageOES) \
maIOCtl_glGetRenderbufferParameterivOES_case(glGetRenderbufferParameterivOES) \
maIOCtl_glIsFramebufferOES_case(glIsFramebufferOES) \
maIOCtl_glBindFramebufferOES_case(glBindFramebufferOES) \
maIOCtl_glDeleteFramebuffersOES_case(glDeleteFramebuffersOES) \
maIOCtl_glGenFramebuffersOES_case(glGenFramebuffersOES) \
maIOCtl_glCheckFramebufferStatusOES_case(glCheckFramebufferStatusOES) \
maIOCtl_glFramebufferRenderbufferOES_case(glFramebufferRenderbufferOES) \
maIOCtl_glFramebufferTexture2DOES_case(glFramebufferTexture2DOES) \
maIOCtl_glGetFramebufferAttachmentParameterivOES_case(glGetFramebufferAttachmentParameterivOES) \
maIOCtl_glGenerateMipmapOES_case(glGenerateMipmapOES) \

#define maIOCtl_IX_GL_OES_FRAMEBUFFER_OBJECT_syscall_caselist \
maIOCtl_syscall_case(glIsRenderbufferOES) \
maIOCtl_syscall_case(glBindRenderbufferOES) \
maIOCtl_syscall_case(glDeleteRenderbuffersOES) \
maIOCtl_syscall_case(glGenRenderbuffersOES) \
maIOCtl_syscall_case(glRenderbufferStorageOES) \
maIOCtl_syscall_case(glGetRenderbufferParameterivOES) \
maIOCtl_syscall_case(glIsFramebufferOES) \
maIOCtl_syscall_case(glBindFramebufferOES) \
maIOCtl_syscall_case(glDeleteFramebuffersOES) \
maIOCtl_syscall_case(glGenFramebuffersOES) \
maIOCtl_syscall_case(glCheckFramebufferStatusOES) \
maIOCtl_syscall_case(glFramebufferRenderbufferOES) \
maIOCtl_syscall_case(glFramebufferTexture2DOES) \
maIOCtl_syscall_case(glGetFramebufferAttachmentParameterivOES) \
maIOCtl_syscall_case(glGenerateMipmapOES) \

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
#define maIOCtl_glIsRenderbufferOES 409
#define maIOCtl_glIsRenderbufferOES_case(func) \
case 409: \
{ \
GLuint _renderbuffer = (GLuint)a; \
return func(_renderbuffer); \
} \

#define maIOCtl_glBindRenderbufferOES 410
#define maIOCtl_glBindRenderbufferOES_case(func) \
case 410: \
{ \
GLenum _target = (GLenum)a; \
GLuint _renderbuffer = (GLuint)b; \
func(_target, _renderbuffer); \
return 0; \
} \

#define maIOCtl_glDeleteRenderbuffersOES 411
#define maIOCtl_glDeleteRenderbuffersOES_case(func) \
case 411: \
{ \
GLsizei _n = (GLsizei)a; \
const GLuint* _renderbuffers = GVMR(b, GLuint); \
func(_n, _renderbuffers); \
return 0; \
} \

#define maIOCtl_glGenRenderbuffersOES 412
#define maIOCtl_glGenRenderbuffersOES_case(func) \
case 412: \
{ \
GLsizei _n = (GLsizei)a; \
GLuint* _renderbuffers = GVMR(b, GLuint); \
func(_n, _renderbuffers); \
return 0; \
} \

#define maIOCtl_glRenderbufferStorageOES 413
#define maIOCtl_glRenderbufferStorageOES_case(func) \
case 413: \
{ \
GLenum _target = (GLenum)a; \
GLenum _internalformat = (GLenum)b; \
GLsizei _width = (GLsizei)c; \
GLsizei _height = (GLsizei)ARG_NO_4; \
func(_target, _internalformat, _width, _height); \
return 0; \
} \

#define maIOCtl_glGetRenderbufferParameterivOES 414
#define maIOCtl_glGetRenderbufferParameterivOES_case(func) \
case 414: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLint* _params = GVMR(c, GLint); \
func(_target, _pname, _params); \
return 0; \
} \

#define maIOCtl_glIsFramebufferOES 415
#define maIOCtl_glIsFramebufferOES_case(func) \
case 415: \
{ \
GLuint _framebuffer = (GLuint)a; \
return func(_framebuffer); \
} \

#define maIOCtl_glBindFramebufferOES 416
#define maIOCtl_glBindFramebufferOES_case(func) \
case 416: \
{ \
GLenum _target = (GLenum)a; \
GLuint _framebuffer = (GLuint)b; \
func(_target, _framebuffer); \
return 0; \
} \

#define maIOCtl_glDeleteFramebuffersOES 417
#define maIOCtl_glDeleteFramebuffersOES_case(func) \
case 417: \
{ \
GLsizei _n = (GLsizei)a; \
const GLuint* _framebuffers = GVMR(b, GLuint); \
func(_n, _framebuffers); \
return 0; \
} \

#define maIOCtl_glGenFramebuffersOES 418
#define maIOCtl_glGenFramebuffersOES_case(func) \
case 418: \
{ \
GLsizei _n = (GLsizei)a; \
GLuint* _framebuffers = GVMR(b, GLuint); \
func(_n, _framebuffers); \
return 0; \
} \

#define maIOCtl_glCheckFramebufferStatusOES 419
#define maIOCtl_glCheckFramebufferStatusOES_case(func) \
case 419: \
{ \
GLenum _target = (GLenum)a; \
return func(_target); \
} \

#define maIOCtl_glFramebufferRenderbufferOES 420
#define maIOCtl_glFramebufferRenderbufferOES_case(func) \
case 420: \
{ \
GLenum _target = (GLenum)a; \
GLenum _attachment = (GLenum)b; \
GLenum _renderbuffertarget = (GLenum)c; \
GLuint _renderbuffer = (GLuint)ARG_NO_4; \
func(_target, _attachment, _renderbuffertarget, _renderbuffer); \
return 0; \
} \

#define maIOCtl_glFramebufferTexture2DOES 421
#define maIOCtl_glFramebufferTexture2DOES_case(func) \
case 421: \
{ \
GLenum _target = (GLenum)a; \
GLenum _attachment = (GLenum)b; \
GLenum _textarget = (GLenum)c; \
GLuint _texture = (GLuint)ARG_NO_4; \
GLint _level = (GLint)ARG_NO_5; \
func(_target, _attachment, _textarget, _texture, _level); \
return 0; \
} \

#define maIOCtl_glGetFramebufferAttachmentParameterivOES 422
#define maIOCtl_glGetFramebufferAttachmentParameterivOES_case(func) \
case 422: \
{ \
GLenum _target = (GLenum)a; \
GLenum _attachment = (GLenum)b; \
GLenum _pname = (GLenum)c; \
GLint* _params = GVMR(ARG_NO_4, GLint); \
func(_target, _attachment, _pname, _params); \
return 0; \
} \

#define maIOCtl_glGenerateMipmapOES 423
#define maIOCtl_glGenerateMipmapOES_case(func) \
case 423: \
{ \
GLenum _target = (GLenum)a; \
func(_target); \
return 0; \
} \


#endif	//IX_GL_OES_FRAMEBUFFER_OBJECT_DEFS_H
