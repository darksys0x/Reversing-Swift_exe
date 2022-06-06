#include <stdio.h>
#include <Windows.h>
#include <libloaderapi.h>
#pragma comment(lib, "kernel32.lib")




DWORD sub_41A0AB;
//revers 1:
//text:0041A0AB                               sub_41A0AB      proc near; CODE XREF : WinMain(x, x, x, x) : loc_41A251↓p
//.text : 0041A0AB 51                                            push    ecx
//.text : 0041A0AC 56                                            push    esi
//.text : 0041A0AD 57                                            push    edi
//.text : 0041A0AE 68 0C 12 40 00                                push    offset ModuleName; "kernel32.dll"
//.text:0041A0B3 FF 15 4C 10 40 00                               call    ds : GetModuleHandleW
//
//
//.text : 0041A0B9 68 28 12 40 00                                push    offset ProcName; "LocalAlloc"
//.text:0041A0BE 50                                              push    eax; hModule //?
//.text:0041A0BF A3 50 1D BB 02                                  mov     dword_2BB1D50, eax
//.text : 0041A0C4 FF 15 48 10 40 00                             call    ds : GetProcAddress
//
//.text : 0041A0CA FF 35 64 1D BB 02                             push    dwSize
//.text : 0041A0D0 33 FF xor edi, edi
//.text : 0041A0D2 57                                            push    edi
//.text : 0041A0D3 A3 48 1D BB 02                                mov     LocalAlloc, eax
//.text : 0041A0D8 FF D0                                         call    eax
//
//
//.text : 0041A0DA 8D 4C 24 08                                   lea     ecx, [esp + 8]
//.text:0041A0DE 51                                              push    ecx; lpflOldProtect
//.text:0041A0DF 6A 40                                           push    40h; '@'; flNewProtect
//.text:0041A0E1 FF 35 64 1D BB 02                               push    dwSize; dwSize
//.text:0041A0E7 A3 C8 29 B9 02                                  mov     pointerToHeap, eax
//.text : 0041A0EC 50                                            push    eax; lpAddress
//.text:0041A0ED FF 15 44 10 40 00                               call    ds : VirtualProtect
//______________
//function1: 


typedef DWORD(__stdcall* FuncType)(int, int); //function type
FuncType func = 0;
DWORD dwSize;


int main() {

	HMODULE hamad = GetModuleHandle(L"kernel32.dll");
	DWORD dword_2BB1D50 = (DWORD)hamad;
	func = (FuncType)GetProcAddress(hamad, "LocalAlloc");
	int* hamadHeap = (int*)func(0, dwSize);
	DWORD oldProtect;
	int hamadProtection = VirtualProtect(hamadHeap, dwSize, 0x40, &oldProtect);

}