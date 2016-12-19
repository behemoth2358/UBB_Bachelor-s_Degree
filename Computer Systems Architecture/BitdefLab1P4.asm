section .data

format db '%d',0
seed dd 0
rand dd 0
const equ 257

section .text

extern _printf
extern _exit
extern __time32
extern _getchar

global _main

_main:
push 0
call __time32 ; EAX=current time
mov [seed],EAX
add ESP,4

random:
call _getchar ; std::cin>>eax;
cmp EAX,-1
je finish

mov EAX,[seed]
shr EAX,8 ; only least sign bits

mov [rand],AX

push dword [rand]
push format
call _printf
add ESP,8

mov AX,[rand]; AX=rand
mul AX; DX:AX=rand^2

mov [seed],AX
mov [seed+2],DX 
; seed = rand^2
mov EAX,[seed]
add EAX,const
mov [seed],EAX; seed = rand^2+const

jmp random

finish:
push 0
call _exit
ret