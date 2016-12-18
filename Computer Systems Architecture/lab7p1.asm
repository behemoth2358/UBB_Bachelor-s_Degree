assume CS:code,DS:data
data segment

a db "1347"
la equ $-a
b db "235"
lb equ $-b
c db la+lb dup(?)

data ends

code segment
start:
mov AX,data
mov DS,AX

mov BX,0
mov SI,0
mov DI,0

merge:
mov AL,a[SI]
mov CL,b[DI]

cmp AL,CL
jb merge1 ; if AL < CL
jmp merge2 ; else

back:
cmp SI,la
jae continue

cmp DI,lb
jae continue

jmp merge

continue:

cmp SI,la
jb finish1

cmp DI,lb
jb finish2

jmp finish

finish1:
mov AL,a[SI]
mov c[BX],AL
add BX,1
add SI,1
cmp SI,la
jb finish1
jmp finish

finish2:
mov AL,b[DI]
mov c[BX],AL
add BX,1
add DI,1
cmp DI,lb
jb finish2
jmp finish

merge1:
mov c[BX],AL
add BX,1
add SI,1
jmp back

merge2:
mov c[BX],CL
add BX,1
add DI,1
jmp back

finish:
mov AX,4C00h
int 21h
code ends
end start
