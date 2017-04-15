section.data
nr1 dd 3
nr2 dd 61
res dd ?
section.text
global _main
_main:
mov eax,[nr1]
mov ecx,[nr2]
add eax,ecx
mov [rez],eax
ret
