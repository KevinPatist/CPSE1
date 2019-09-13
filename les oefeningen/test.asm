.global sum

sum:
    push { lr }
    mov r1, #0
    mov r2, #1
loop:
    cmp r0, r2
    blt done
    add r1, r1, r2
    add r2, r2, #1
    b loop
done:
    mov r0, r1
    pop { pc }

