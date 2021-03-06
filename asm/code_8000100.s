.include "asm/macro.inc"
.syntax unified

_080000F4: .4byte gUnknown_03001EF0
_080000F8: .4byte gUnknown_020104D4
_080000FC: .4byte gUnknown_020104B4

	ARM_FUNC_START sub_8000100
sub_8000100: @ 0x08000100
	push {r4, r5, r6, r7}
	mov r7, #0x3e0
_08000108:
	ldr r0, _080000FC
	add r0, r0, r7, lsr #5
	ldrsb r5, [r0]
	tst r5, r5
	beq _080001C0
	ldr r4, _080000F8
	lsr r0, r7, #1
	add r0, r0, r0, lsl #1
	add r0, r0, #0x30
	add r4, r4, r0
	mov r6, #0x1e
_08000134:
	sub r4, r4, #3
	ldrb r0, [r4]
	add r0, r0, r5
	strb r0, [r4]
	subs r0, r0, #0x20
	bpl _08000150
	mov r0, #0
_08000150:
	cmp r0, #0x20
	blo _0800015C
	mov r0, #0x1f
_0800015C:
	ldrb r1, [r4, #1]
	add r1, r1, r5
	strb r1, [r4, #1]
	subs r1, r1, #0x20
	bpl _08000174
	mov r1, #0
_08000174:
	cmp r1, #0x20
	blo _08000180
	mov r1, #0x1f
_08000180:
	ldrb r2, [r4, #2]
	add r2, r2, r5
	strb r2, [r4, #2]
	subs r2, r2, #0x20
	bpl _08000198
	mov r2, #0
_08000198:
	cmp r2, #0x20
	blo _080001A4
	mov r2, #0x1f
_080001A4:
	add r0, r0, r1, lsl #5
	add r0, r0, r2, lsl #10
	ldr r1, _080000F4
	add r1, r1, r6
	strh r0, [r1, r7]
	subs r6, r6, #2
	bpl _08000134
_080001C0:
	subs r7, r7, #0x20
	bpl _08000108
	pop {r4, r5, r6, r7}
	bx lr

	ARM_FUNC_START setjmp
setjmp: @ 0x080001D0
	stm r0!, {r4, r5, r6, r7, r8, sb, sl, fp, ip, sp, lr}
	mov r0, #0
	tst lr, #1
	moveq pc, lr
	bx lr

	ARM_FUNC_START longjmp
longjmp: @ 0x080001E4
	ldm r0!, {r4, r5, r6, r7, r8, sb, sl, fp, ip, sp, lr}
	movs r0, r1
	moveq r0, #1
	tst lr, #1
	moveq pc, lr
	bx lr
