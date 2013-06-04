case 1:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::maCheckInterfaceVersion), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())maCheckInterfaceVersion), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 2:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::maExit), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())maExit), (int)gSyscall);
#endif
	break;
}
case 3:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	assm.ADD(AA::R2, loadRegister(REG_i1, AA::R2, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::maPanic), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	assm.ADD(AA::R1, loadRegister(REG_i1, AA::R1, false) , MEMORY_ADDR);
	emitFuncCall((int)&((void (*)())maPanic), (int)gSyscall);
#endif
	break;
}
case 4:
{
#ifdef SYMBIAN
	assm.ADD(AA::R1, loadRegister(REG_i0, AA::R1, false) , MEMORY_ADDR);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::memset), (int)gSyscall);
#else
	assm.ADD(AA::R0, loadRegister(REG_i0, AA::R0, false) , MEMORY_ADDR);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	emitFuncCall((int)&((void (*)())memset), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 5:
{
#ifdef SYMBIAN
	assm.ADD(AA::R1, loadRegister(REG_i0, AA::R1, false) , MEMORY_ADDR);
	assm.ADD(AA::R2, loadRegister(REG_i1, AA::R2, false) , MEMORY_ADDR);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::memcpy), (int)gSyscall);
#else
	assm.ADD(AA::R0, loadRegister(REG_i0, AA::R0, false) , MEMORY_ADDR);
	assm.ADD(AA::R1, loadRegister(REG_i1, AA::R1, false) , MEMORY_ADDR);
	loadRegister(REG_i2, AA::R2, true);
	emitFuncCall((int)&((void (*)())memcpy), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 6:
{
#ifdef SYMBIAN
	assm.ADD(AA::R1, loadRegister(REG_i0, AA::R1, false) , MEMORY_ADDR);
	assm.ADD(AA::R2, loadRegister(REG_i1, AA::R2, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::strcmp), (int)gSyscall);
#else
	assm.ADD(AA::R0, loadRegister(REG_i0, AA::R0, false) , MEMORY_ADDR);
	assm.ADD(AA::R1, loadRegister(REG_i1, AA::R1, false) , MEMORY_ADDR);
	emitFuncCall((int)&((void (*)())strcmp), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 7:
{
#ifdef SYMBIAN
	assm.ADD(AA::R1, loadRegister(REG_i0, AA::R1, false) , MEMORY_ADDR);
	assm.ADD(AA::R2, loadRegister(REG_i1, AA::R2, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::strcpy), (int)gSyscall);
#else
	assm.ADD(AA::R0, loadRegister(REG_i0, AA::R0, false) , MEMORY_ADDR);
	assm.ADD(AA::R1, loadRegister(REG_i1, AA::R1, false) , MEMORY_ADDR);
	emitFuncCall((int)&((void (*)())strcpy), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 8:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::__adddf3), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())__adddf3), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	saveRegister(REG_r15, AA::R1);
	break;
}
case 9:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::__subdf3), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())__subdf3), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	saveRegister(REG_r15, AA::R1);
	break;
}
case 10:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::__muldf3), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())__muldf3), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	saveRegister(REG_r15, AA::R1);
	break;
}
case 11:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::__divdf3), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())__divdf3), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	saveRegister(REG_r15, AA::R1);
	break;
}
case 12:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::__negdf2), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())__negdf2), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	saveRegister(REG_r15, AA::R1);
	break;
}
case 13:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::__fixdfsi), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())__fixdfsi), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 14:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::__fixunsdfsi), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())__fixunsdfsi), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 15:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::__floatsidf), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())__floatsidf), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	saveRegister(REG_r15, AA::R1);
	break;
}
case 16:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::__extendsfdf2), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())__extendsfdf2), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	saveRegister(REG_r15, AA::R1);
	break;
}
case 17:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::dcmp), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())dcmp), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 18:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::__addsf3), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())__addsf3), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 19:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::__subsf3), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())__subsf3), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 20:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::__mulsf3), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())__mulsf3), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 21:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::__divsf3), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())__divsf3), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 22:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::__negsf2), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())__negsf2), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 23:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::__fixsfsi), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())__fixsfsi), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 24:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::__fixunssfsi), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())__fixunssfsi), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 25:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::__floatsisf), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())__floatsisf), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 26:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::__truncdfsf2), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())__truncdfsf2), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 27:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::fcmp), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())fcmp), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 28:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::sin), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())sin), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	saveRegister(REG_r15, AA::R1);
	break;
}
case 29:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::cos), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())cos), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	saveRegister(REG_r15, AA::R1);
	break;
}
case 30:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::tan), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())tan), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	saveRegister(REG_r15, AA::R1);
	break;
}
case 31:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::sqrt), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())sqrt), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	saveRegister(REG_r15, AA::R1);
	break;
}
case 32:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::maSetColor), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())maSetColor), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 33:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maSetClipRect), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())maSetClipRect), (int)gSyscall);
#endif
	break;
}
case 34:
{
#ifdef SYMBIAN
	assm.ADD(AA::R1, loadRegister(REG_i0, AA::R1, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::maGetClipRect), (int)gSyscall);
#else
	assm.ADD(AA::R0, loadRegister(REG_i0, AA::R0, false) , MEMORY_ADDR);
	emitFuncCall((int)&((void (*)())maGetClipRect), (int)gSyscall);
#endif
	break;
}
case 35:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::maPlot), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())maPlot), (int)gSyscall);
#endif
	break;
}
case 36:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maLine), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())maLine), (int)gSyscall);
#endif
	break;
}
case 37:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maFillRect), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())maFillRect), (int)gSyscall);
#endif
	break;
}
case 38:
{
#ifdef SYMBIAN
	assm.ADD(AA::R1, loadRegister(REG_i0, AA::R1, false) , MEMORY_ADDR);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::maFillTriangleStrip), (int)gSyscall);
#else
	assm.ADD(AA::R0, loadRegister(REG_i0, AA::R0, false) , MEMORY_ADDR);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())maFillTriangleStrip), (int)gSyscall);
#endif
	break;
}
case 39:
{
#ifdef SYMBIAN
	assm.ADD(AA::R1, loadRegister(REG_i0, AA::R1, false) , MEMORY_ADDR);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::maFillTriangleFan), (int)gSyscall);
#else
	assm.ADD(AA::R0, loadRegister(REG_i0, AA::R0, false) , MEMORY_ADDR);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())maFillTriangleFan), (int)gSyscall);
#endif
	break;
}
case 40:
{
#ifdef SYMBIAN
	assm.ADD(AA::R1, loadRegister(REG_i0, AA::R1, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::maGetTextSize), (int)gSyscall);
#else
	assm.ADD(AA::R0, loadRegister(REG_i0, AA::R0, false) , MEMORY_ADDR);
	emitFuncCall((int)&((void (*)())maGetTextSize), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 41:
{
#ifdef SYMBIAN
	assm.ADD(AA::R1, loadRegister(REG_i0, AA::R1, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::maGetTextSizeW), (int)gSyscall);
#else
	assm.ADD(AA::R0, loadRegister(REG_i0, AA::R0, false) , MEMORY_ADDR);
	emitFuncCall((int)&((void (*)())maGetTextSizeW), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 42:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	assm.ADD(AA::R3, loadRegister(REG_i2, AA::R3, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::maDrawText), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	assm.ADD(AA::R2, loadRegister(REG_i2, AA::R2, false) , MEMORY_ADDR);
	emitFuncCall((int)&((void (*)())maDrawText), (int)gSyscall);
#endif
	break;
}
case 43:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	assm.ADD(AA::R3, loadRegister(REG_i2, AA::R3, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::maDrawTextW), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	assm.ADD(AA::R2, loadRegister(REG_i2, AA::R2, false) , MEMORY_ADDR);
	emitFuncCall((int)&((void (*)())maDrawTextW), (int)gSyscall);
#endif
	break;
}
case 44:
{
#ifdef SYMBIAN
	emitFuncCall(FUNC_CAST(Syscall::maUpdateScreen), (int)gSyscall);
#else
	emitFuncCall((int)&((void (*)())maUpdateScreen), (int)gSyscall);
#endif
	break;
}
case 45:
{
#ifdef SYMBIAN
	emitFuncCall(FUNC_CAST(Syscall::maResetBacklight), (int)gSyscall);
#else
	emitFuncCall((int)&((void (*)())maResetBacklight), (int)gSyscall);
#endif
	break;
}
case 46:
{
#ifdef SYMBIAN
	emitFuncCall(FUNC_CAST(Syscall::maGetScrSize), (int)gSyscall);
#else
	emitFuncCall((int)&((void (*)())maGetScrSize), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 47:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maDrawImage), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	emitFuncCall((int)&((void (*)())maDrawImage), (int)gSyscall);
#endif
	break;
}
case 48:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.ADD(AA::R0, loadRegister(REG_i3, AA::R0), MEMORY_ADDR);
	assm.STR(AA::R0, 0, AA::SP);
	assm.ADD(AA::R1, loadRegister(REG_i0, AA::R1, false) , MEMORY_ADDR);
	assm.ADD(AA::R2, loadRegister(REG_i1, AA::R2, false) , MEMORY_ADDR);
	assm.ADD(AA::R3, loadRegister(REG_i2, AA::R3, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::maDrawRGB), (int)gSyscall);
#else
	assm.ADD(AA::R0, loadRegister(REG_i0, AA::R0, false) , MEMORY_ADDR);
	assm.ADD(AA::R1, loadRegister(REG_i1, AA::R1, false) , MEMORY_ADDR);
	assm.ADD(AA::R2, loadRegister(REG_i2, AA::R2, false) , MEMORY_ADDR);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())maDrawRGB), (int)gSyscall);
#endif
	break;
}
case 49:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	assm.ADD(AA::R2, loadRegister(REG_i1, AA::R2, false) , MEMORY_ADDR);
	assm.ADD(AA::R3, loadRegister(REG_i2, AA::R3, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::maDrawImageRegion), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	assm.ADD(AA::R1, loadRegister(REG_i1, AA::R1, false) , MEMORY_ADDR);
	assm.ADD(AA::R2, loadRegister(REG_i2, AA::R2, false) , MEMORY_ADDR);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())maDrawImageRegion), (int)gSyscall);
#endif
	break;
}
case 50:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::maGetImageSize), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())maGetImageSize), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 51:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	assm.ADD(AA::R2, loadRegister(REG_i1, AA::R2, false) , MEMORY_ADDR);
	assm.ADD(AA::R3, loadRegister(REG_i2, AA::R3, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::maGetImageData), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	assm.ADD(AA::R1, loadRegister(REG_i1, AA::R1, false) , MEMORY_ADDR);
	assm.ADD(AA::R2, loadRegister(REG_i2, AA::R2, false) , MEMORY_ADDR);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())maGetImageData), (int)gSyscall);
#endif
	break;
}
case 52:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::maSetDrawTarget), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())maSetDrawTarget), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 53:
{
#ifdef SYMBIAN
	assm.ADD(AA::R1, loadRegister(REG_i0, AA::R1, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::maFindLabel), (int)gSyscall);
#else
	assm.ADD(AA::R0, loadRegister(REG_i0, AA::R0, false) , MEMORY_ADDR);
	emitFuncCall((int)&((void (*)())maFindLabel), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 54:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maCreateImageFromData), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())maCreateImageFromData), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 55:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	assm.ADD(AA::R2, loadRegister(REG_i1, AA::R2, false) , MEMORY_ADDR);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maCreateImageRaw), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	assm.ADD(AA::R1, loadRegister(REG_i1, AA::R1, false) , MEMORY_ADDR);
	loadRegister(REG_i2, AA::R2, true);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())maCreateImageRaw), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 56:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maCreateDrawableImage), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	emitFuncCall((int)&((void (*)())maCreateDrawableImage), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 57:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::maCreateData), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())maCreateData), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 58:
{
#ifdef SYMBIAN
	emitFuncCall(FUNC_CAST(Syscall::maCreatePlaceholder), (int)gSyscall);
#else
	emitFuncCall((int)&((void (*)())maCreatePlaceholder), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 59:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::maDestroyPlaceholder), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())maDestroyPlaceholder), (int)gSyscall);
#endif
	break;
}
case 60:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::maDestroyObject), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())maDestroyObject), (int)gSyscall);
#endif
	break;
}
case 61:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::maGetDataSize), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())maGetDataSize), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 62:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	assm.ADD(AA::R2, loadRegister(REG_i1, AA::R2, false) , MEMORY_ADDR);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maReadData), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	assm.ADD(AA::R1, loadRegister(REG_i1, AA::R1, false) , MEMORY_ADDR);
	loadRegister(REG_i2, AA::R2, true);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())maReadData), (int)gSyscall);
#endif
	break;
}
case 63:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	assm.ADD(AA::R2, loadRegister(REG_i1, AA::R2, false) , MEMORY_ADDR);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maWriteData), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	assm.ADD(AA::R1, loadRegister(REG_i1, AA::R1, false) , MEMORY_ADDR);
	loadRegister(REG_i2, AA::R2, true);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())maWriteData), (int)gSyscall);
#endif
	break;
}
case 64:
{
#ifdef SYMBIAN
	assm.ADD(AA::R1, loadRegister(REG_i0, AA::R1, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::maCopyData), (int)gSyscall);
#else
	assm.ADD(AA::R0, loadRegister(REG_i0, AA::R0, false) , MEMORY_ADDR);
	emitFuncCall((int)&((void (*)())maCopyData), (int)gSyscall);
#endif
	break;
}
case 65:
{
#ifdef SYMBIAN
	assm.ADD(AA::R1, loadRegister(REG_i0, AA::R1, false) , MEMORY_ADDR);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::maOpenStore), (int)gSyscall);
#else
	assm.ADD(AA::R0, loadRegister(REG_i0, AA::R0, false) , MEMORY_ADDR);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())maOpenStore), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 66:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::maWriteStore), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())maWriteStore), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 67:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::maReadStore), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())maReadStore), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 68:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::maCloseStore), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())maCloseStore), (int)gSyscall);
#endif
	break;
}
case 69:
{
#ifdef SYMBIAN
	assm.ADD(AA::R1, loadRegister(REG_i0, AA::R1, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::maConnect), (int)gSyscall);
#else
	assm.ADD(AA::R0, loadRegister(REG_i0, AA::R0, false) , MEMORY_ADDR);
	emitFuncCall((int)&((void (*)())maConnect), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 70:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::maConnClose), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())maConnClose), (int)gSyscall);
#endif
	break;
}
case 71:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	assm.ADD(AA::R2, loadRegister(REG_i1, AA::R2, false) , MEMORY_ADDR);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maConnRead), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	assm.ADD(AA::R1, loadRegister(REG_i1, AA::R1, false) , MEMORY_ADDR);
	loadRegister(REG_i2, AA::R2, true);
	emitFuncCall((int)&((void (*)())maConnRead), (int)gSyscall);
#endif
	break;
}
case 72:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	assm.ADD(AA::R2, loadRegister(REG_i1, AA::R2, false) , MEMORY_ADDR);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maConnWrite), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	assm.ADD(AA::R1, loadRegister(REG_i1, AA::R1, false) , MEMORY_ADDR);
	loadRegister(REG_i2, AA::R2, true);
	emitFuncCall((int)&((void (*)())maConnWrite), (int)gSyscall);
#endif
	break;
}
case 73:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maConnReadToData), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())maConnReadToData), (int)gSyscall);
#endif
	break;
}
case 74:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maConnWriteFromData), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())maConnWriteFromData), (int)gSyscall);
#endif
	break;
}
case 75:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	assm.ADD(AA::R2, loadRegister(REG_i1, AA::R2, false) , MEMORY_ADDR);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maConnReadFrom), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	assm.ADD(AA::R1, loadRegister(REG_i1, AA::R1, false) , MEMORY_ADDR);
	loadRegister(REG_i2, AA::R2, true);
	assm.ADD(AA::R3, loadRegister(REG_i3, AA::R3, false) , MEMORY_ADDR);
	emitFuncCall((int)&((void (*)())maConnReadFrom), (int)gSyscall);
#endif
	break;
}
case 76:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	assm.ADD(AA::R2, loadRegister(REG_i1, AA::R2, false) , MEMORY_ADDR);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maConnWriteTo), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	assm.ADD(AA::R1, loadRegister(REG_i1, AA::R1, false) , MEMORY_ADDR);
	loadRegister(REG_i2, AA::R2, true);
	assm.ADD(AA::R3, loadRegister(REG_i3, AA::R3, false) , MEMORY_ADDR);
	emitFuncCall((int)&((void (*)())maConnWriteTo), (int)gSyscall);
#endif
	break;
}
case 77:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	assm.ADD(AA::R2, loadRegister(REG_i1, AA::R2, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::maConnGetAddr), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	assm.ADD(AA::R1, loadRegister(REG_i1, AA::R1, false) , MEMORY_ADDR);
	emitFuncCall((int)&((void (*)())maConnGetAddr), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 78:
{
#ifdef SYMBIAN
	assm.ADD(AA::R1, loadRegister(REG_i0, AA::R1, false) , MEMORY_ADDR);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::maHttpCreate), (int)gSyscall);
#else
	assm.ADD(AA::R0, loadRegister(REG_i0, AA::R0, false) , MEMORY_ADDR);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())maHttpCreate), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 79:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	assm.ADD(AA::R2, loadRegister(REG_i1, AA::R2, false) , MEMORY_ADDR);
	assm.ADD(AA::R3, loadRegister(REG_i2, AA::R3, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::maHttpSetRequestHeader), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	assm.ADD(AA::R1, loadRegister(REG_i1, AA::R1, false) , MEMORY_ADDR);
	assm.ADD(AA::R2, loadRegister(REG_i2, AA::R2, false) , MEMORY_ADDR);
	emitFuncCall((int)&((void (*)())maHttpSetRequestHeader), (int)gSyscall);
#endif
	break;
}
case 80:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	assm.ADD(AA::R2, loadRegister(REG_i1, AA::R2, false) , MEMORY_ADDR);
	assm.ADD(AA::R3, loadRegister(REG_i2, AA::R3, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::maHttpGetResponseHeader), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	assm.ADD(AA::R1, loadRegister(REG_i1, AA::R1, false) , MEMORY_ADDR);
	assm.ADD(AA::R2, loadRegister(REG_i2, AA::R2, false) , MEMORY_ADDR);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())maHttpGetResponseHeader), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 81:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::maHttpFinish), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())maHttpFinish), (int)gSyscall);
#endif
	break;
}
case 82:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::maLoadResources), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())maLoadResources), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 83:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maLoadResource), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	emitFuncCall((int)&((void (*)())maLoadResource), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 84:
{
#ifdef SYMBIAN
	emitFuncCall(FUNC_CAST(Syscall::maCountResources), (int)gSyscall);
#else
	emitFuncCall((int)&((void (*)())maCountResources), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 85:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	emitFuncCall(FUNC_CAST(Syscall::maLoadProgram), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	emitFuncCall((int)&((void (*)())maLoadProgram), (int)gSyscall);
#endif
	break;
}
case 86:
{
#ifdef SYMBIAN
	emitFuncCall(FUNC_CAST(Syscall::maGetKeys), (int)gSyscall);
#else
	emitFuncCall((int)&((void (*)())maGetKeys), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 87:
{
#ifdef SYMBIAN
	assm.ADD(AA::R1, loadRegister(REG_i0, AA::R1, false) , MEMORY_ADDR);
	emitFuncCall(FUNC_CAST(Syscall::maGetEvent), (int)gSyscall);
#else
	assm.ADD(AA::R0, loadRegister(REG_i0, AA::R0, false) , MEMORY_ADDR);
	emitFuncCall((int)&((void (*)())maGetEvent), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 88:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::maWait), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())maWait), (int)gSyscall);
#endif
	break;
}
case 89:
{
#ifdef SYMBIAN
	emitFuncCall(FUNC_CAST(Syscall::maTime), (int)gSyscall);
#else
	emitFuncCall((int)&((void (*)())maTime), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 90:
{
#ifdef SYMBIAN
	emitFuncCall(FUNC_CAST(Syscall::maLocalTime), (int)gSyscall);
#else
	emitFuncCall((int)&((void (*)())maLocalTime), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 91:
{
#ifdef SYMBIAN
	emitFuncCall(FUNC_CAST(Syscall::maGetMilliSecondCount), (int)gSyscall);
#else
	emitFuncCall((int)&((void (*)())maGetMilliSecondCount), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 92:
{
#ifdef SYMBIAN
	emitFuncCall(FUNC_CAST(Syscall::maFreeObjectMemory), (int)gSyscall);
#else
	emitFuncCall((int)&((void (*)())maFreeObjectMemory), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 93:
{
#ifdef SYMBIAN
	emitFuncCall(FUNC_CAST(Syscall::maTotalObjectMemory), (int)gSyscall);
#else
	emitFuncCall((int)&((void (*)())maTotalObjectMemory), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 94:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::maVibrate), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())maVibrate), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 95:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maSoundPlay), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	emitFuncCall((int)&((void (*)())maSoundPlay), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 96:
{
#ifdef SYMBIAN
	emitFuncCall(FUNC_CAST(Syscall::maSoundStop), (int)gSyscall);
#else
	emitFuncCall((int)&((void (*)())maSoundStop), (int)gSyscall);
#endif
	break;
}
case 97:
{
#ifdef SYMBIAN
	emitFuncCall(FUNC_CAST(Syscall::maSoundIsPlaying), (int)gSyscall);
#else
	emitFuncCall((int)&((void (*)())maSoundIsPlaying), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 98:
{
#ifdef SYMBIAN
	emitFuncCall(FUNC_CAST(Syscall::maSoundGetVolume), (int)gSyscall);
#else
	emitFuncCall((int)&((void (*)())maSoundGetVolume), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 99:
{
#ifdef SYMBIAN
	loadRegister(REG_i0, AA::R1, true);
	emitFuncCall(FUNC_CAST(Syscall::maSoundSetVolume), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	emitFuncCall((int)&((void (*)())maSoundSetVolume), (int)gSyscall);
#endif
	break;
}
case 100:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maExtensionFunctionInvoke), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())maExtensionFunctionInvoke), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
case 101:
{
#ifdef SYMBIAN
	assm.SUB_imm8(AA::SP, AA::SP, 4);
	assm.STR(loadRegister(REG_i3, AA::R0), 0, AA::SP);
	loadRegister(REG_i0, AA::R1, true);
	loadRegister(REG_i1, AA::R2, true);
	loadRegister(REG_i2, AA::R3, true);
	emitFuncCall(FUNC_CAST(Syscall::maIOCtl), (int)gSyscall);
#else
	loadRegister(REG_i0, AA::R0, true);
	loadRegister(REG_i1, AA::R1, true);
	loadRegister(REG_i2, AA::R2, true);
	loadRegister(REG_i3, AA::R3, true);
	emitFuncCall((int)&((void (*)())maIOCtl), (int)gSyscall);
#endif
	saveRegister(REG_r14, AA::R0);
	break;
}
