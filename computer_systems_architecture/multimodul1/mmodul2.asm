

public _printString

code segment

_printString proc

IRP reg,<a,b,c,d>

push &reg&x

endm

mov AH,09h
int 21h

IRP reg,<d,c,b,a>

pop &reg&x

endm

ret

_printString endp

code ends
end



