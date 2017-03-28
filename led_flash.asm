org 0000h
back:mov p0,#0
     mov p0,#0ffh
     acall delay
     mov p0,#0h
     acall delay
     sjmp back

delay:
back_0:mov r0,#256
again:       mov r1,#256
nop
nop
nop      
 djnz r1,back_0
       djnz r0,again      