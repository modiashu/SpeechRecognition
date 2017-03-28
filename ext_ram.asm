#pragma asm
     org 0000h
     mov dptr,#1234h
back:mov p1,#0h
     acall delay
     mov a,#0ffh
     movx @dptr,a
     mov a,#0h
     movx a,@dptr
     mov p1,a
     ;jnb p1.0,#0h    
acall delay     
sjmp back
delay:      mov r7, #01h
        l1: mov r1, #0ffh
        l2: mov r2, #0ffh
        l3: djnz r2, l3
            djnz r1, l2
            djnz r7, l1
            ret
      end

#pragma endasm