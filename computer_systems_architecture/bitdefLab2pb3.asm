%include "msdn_defs.inc"

[bits 32]

section .text 

extern  _printf
extern _exit
extern FindClose,FindFirstFile,FindNextFile

global  _main 

_main: 
		push abc
		push loc
		call FindFirstFile
		cmp EAX,INVALID_HANDLE_VALUE
		je .error
		mov [hFind],EAX
		.findFiles:
			test dword [abc + WIN32_FIND_DATA.dwFileAttributes],FILE_ATTRIBUTE_DIRECTORY
			jnz .printDir
			jmp .printFile
			.printDir:
				mov AL,byte [comma]
				cmp byte [abc + WIN32_FIND_DATA.cFileName],AL
				je .cont
				
				; print the directory
				mov EAX,abc
				add EAX,WIN32_FIND_DATA.cFileName
				push EAX
				push dirFormat
				call _printf
				add ESP,8
				jmp .cont	
			.printFile:
				push abc+ WIN32_FIND_DATA.cFileName
				push fileFormat
				call _printf
				add ESP,8
			.cont:
				push abc
				push dword [hFind]
				call FindNextFile

				cmp EAX,0 ; error?
				je .finish

				jmp .findFiles
	jmp .finish
	.error:
		push errorMessage
		call _printf
		add ESP,4
	.finish:
		push dword [hFind]
		call FindClose
		
		push    0
		call    _exit
		ret 

section .data

abc: 
istruc  WIN32_FIND_DATA 
at WIN32_FIND_DATA.dwFileAttributes,dd 0
at WIN32_FIND_DATA.ftCreationTime,db 0
at WIN32_FIND_DATA.ftLastAccessTime, db 0
at WIN32_FIND_DATA.ftLastWriteTime, db 0
at WIN32_FIND_DATA.nFileSizeHigh, dd 0
at WIN32_FIND_DATA.nFileSizeLow, dd 0
at WIN32_FIND_DATA.dwReserved0, dd 0
at WIN32_FIND_DATA.dwReserved1, dd 0
at WIN32_FIND_DATA.cFileName, db 0
at WIN32_FIND_DATA.cAlternateFileName,db 0
iend

struct_size dd $ - abc
hFind dd 0
loc db "C:\\Windows\\System32\\*",0
errorMessage db "File inexistent.",0
dirFormat db "D %s",0Ah,0
fileFormat db "- %s",0Ah,0
comma db ".",0
