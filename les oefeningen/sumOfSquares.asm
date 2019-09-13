.global sumOfPows

sumOfPows:
    push { r4, lr }
    mov r3, #0
    mov r2, #1
    mov r4, r0
loopje:
    cmp r2,r4
    bgt klaar
    mov r0, r2
    mov r1, r2
    bl powerFunc
    add r3, r0
    add r2, #1
    b lusje
klaar:
    mov r0, r1
    pop { r4, pc }

powerFunc:
    push { r2, r3, lr }
    mov r2, #1
    mov r3, r0
loop:
    cmp r1, r2
    bgt done
    mul r3, r3, r0
    add r2, #1
    b loop
done:
    mov r0, r3
    pop { r2, r3, pc }


