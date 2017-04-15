[bits 32]

section .text 

extern  _printf
extern _exit

global  _main

; result in edx
_strlen:
	push EBP
	mov EBP,ESP
	
	mov ESI,[EBP+8]
	mov EBX,0
	count:
		mov DL,byte [ESI]
		cmp DL,0
		je endd
		inc EBX
		inc ESI
		jmp count
	endd:
	pop EBP
	ret 4
; esi(haystack) and edi(needle) 
_strstr:
	push EBP
	mov EBP,ESP
	
	mov ESI,[EBP+8] ; haystack
	mov EDI,[EBP+12] ; needle
	
	mov EBX,ESI
	mov EAX,EDI
	
	search:
		mov ESI,EBX
		mov EDI,EAX
		
		mov DL,byte [ESI]
		cmp DL,0
		je not_found
	lp:
			mov DL,byte [ESI]
			mov DH,byte [EDI]
			cmp DL,DH
			jne continue
			inc ESI
			inc EDI
			mov DL,byte [EDI]
			cmp DL,0
			je found
			jmp lp
		continue:
			inc EBX
			jmp search
		not_found:
			mov EAX,0
			jmp to_end
		found:
			mov EAX,EBX
	to_end:
	pop EBP
	ret 2*4
_main:
		push needle
		push haystack
		call _strstr
		cmp EAX,0
		je not_solution
		
		push needle
		call _strlen
		
		push EBX
		sub EAX,haystack
		push EAX
		push format
		call _printf
		add ESP,8
		jmp ed
		not_solution:
			push notfound
			call _printf
			add ESP,4
		ed:
        push    0
        call    _exit
        ret 

section .data
notfound: db 'substring not found',0
format: db '[%d,%d]',0
haystack: db 'banana',0
needle: db 'ana',0