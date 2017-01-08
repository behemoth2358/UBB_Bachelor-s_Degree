%include "msdn_defs.inc"

[bits 32]

struc Student
.lastName resb 20
.firstName resb 20
.age resd 1
.height resd 1
.eye_color resb 15
.size
endstruc

%define NULL 0
%define MAX_STUDENTS 99
section .text 

extern  _printf
extern _exit
extern __open_osfhandle
extern __fdopen
extern CreateFileA
extern _fopen
extern _fscanf
extern _strtok
extern _strcpy
extern _scanf
extern _atoi
extern _fclose

global  _main 

_main: 
		push NULL
		push FILE_ATTRIBUTE_NORMAL
		push OPEN_EXISTING
		push NULL
		push 0
		push GENERIC_READ ; open the file in read mode
		push filename
		call CreateFileA
		cmp EAX,INVALID_HANDLE_VALUE
		je .ferror
		mov [hFile],EAX
		push 0 ; _O_RDONLY
		push dword [hFile]
		call __open_osfhandle
		add ESP,4*2
		cmp EAX,-1
		je .ferror
		mov [cHandle],EAX
		push readmode
		push dword [cHandle]
		call __fdopen
		add ESP,4*2
		mov [filePointer],EAX
		push nrStudents
		push ints
		push dword [filePointer]
		call _fscanf
		mov ECX,[nrStudents]
		mov EDI,0
		.readData:
			push ECX
			push buffer ; read line
			push strings
			push dword [filePointer]
			call _fscanf
			add ESP,12
			push delim ; parse the line with strtok
			push buffer
			call _strtok
			add ESP,8
			mov EBX,0
			.tok:
				mov [token],EAX
				inc EBX
				cmp byte [token],NULL
				je .continue
				cmp EBX,1
				je .addLastName
				cmp EBX,2
				je .addFirstName
				cmp EBX,3
				je .addAge
				cmp EBX,4
				je .addHeight
				cmp EBX,5
				je .addEyeColor
			
				.addLastName:
					; save the EDI register
					push EDI
					mov EAX,token
					lea EDI,students[EDI + Student.lastName]
					mov esi,[token]
					cld
					.copy:
						lodsb
						stosb
						test AL,AL
						jnz .copy
					
					; restore EDI
					pop EDI
					jmp .nextTok
				.addFirstName:
					push EDI
					mov EAX,token
					lea EDI,students[EDI + Student.firstName]
					mov esi,[token]
					cld
					.copy_name:
						lodsb
						stosb
						test AL,AL
						jnz .copy_name
					pop EDI
					jmp .nextTok
				.addAge:
					push dword [token]
					call _atoi
					mov students[EDI + Student.age],EAX
					add ESP,4
					jmp .nextTok
				.addHeight:
					push dword [token]
					call _atoi
					mov students[EDI + Student.height],EAX
					add ESP,4
					jmp .nextTok
				.addEyeColor:
					push EDI
					mov EAX,token
					lea EDI,students[EDI + Student.eye_color]
					mov esi,[token]
					
					.copy_color:
						lodsb
						stosb
						test AL,AL
						jnz .copy_color
					pop EDI
					jmp .nextTok
				
				.nextTok:
					push delim
					push NULL
					call _strtok ; EAX will contain the token
					add ESP,8
					jmp .tok
			.continue:
				pop ECX ; restore ECX
				add EDI,Student.size
				dec ECX
				cmp ECX,0
				jne .readData

		.readCmd:
			push command ;read student index
			push ints
			call _scanf
			add ESP,4*2
			
			cmp dword [command],0 ; if 0 then exit
			je .finish
			
			mov EAX,[nrStudents]
			cmp dword [command],EAX ; compare index with nr of students
			jg invalidID 
			
			mov BX,Student.size
			mov AX,[command]
			dec AX
			mul BX ; result in DX:AX
			
			push DX
			push AX
			pop EAX
			add EAX,students

			add EAX,Student.eye_color
			push EAX
			
			sub EAX,Student.eye_color
			add EAX,Student.height
			push dword [EAX]
			
			sub EAX,Student.height
			add EAX,Student.age
			push dword [EAX]
			
			sub EAX,Student.age
			add EAX,Student.firstName
			push EAX
			
			sub EAX,Student.firstName
			add EAX,Student.lastName
			push EAX	
			push studFormat
			call _printf
			add ESP,4
			jmp .readCmd

			invalidID:
				push dword [command]
				push indexError
				call _printf
				add ESP,8
				jmp .readCmd
		jmp .finish

		.ferror:
			push fileError
			call _printf
			add ESP,4
		.finish:
		push filePointer ; close file
		call _fclose
		add ESP,4
		
        push    0
        call    _exit
        ret 

section .data
	students times MAX_STUDENTS*Student.size db 0
	buffer times 100 db 0
	token times 25 db 0
	filename db "students.txt",0
	readmode db "r",0
	ints db "%d",0
	strings db "%s",0
	studFormat db "%s %s %d %d %s",0Ah,0
	command dd 0
	nrStudents dd 0
	cHandle dd 0
	hFile dd 0
	filePointer dd 0
	fileError db "File error",0
	indexError db "Maximum index value: %d.",0Ah,0
	delim db ",",0
