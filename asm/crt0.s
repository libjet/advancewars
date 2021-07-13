.include "asm/macro.inc"
.syntax unified

	arm_func_start Start
Start: @ 0x08000000
	b Init

.include "asm/rom_header.inc"

	arm_func_start Init
Init: @ 0x080000C0
	mov r0, #0x12
	msr cpsr_fc, r0
	ldr sp, _080000E8 @ =0x03007F80
	mov r0, #0x1f
	msr cpsr_fc, r0
	ldr sp, _080000EC @ =0x03007C00
	ldr r1, _080000F0 @ =0x0807ACB1
	mov lr, pc
	bx r1
	b Init

_080000E8: .4byte 0x03007F80
_080000EC: .4byte 0x03007C00
_080000F0: .4byte 0x0807ACB1
_080000F4: .4byte 0x03001EF0
_080000F8: .4byte 0x020104D4
_080000FC: .4byte 0x020104B4

	arm_func_start sub_08000100
sub_08000100: @ 0x08000100
	push {r4, r5, r6, r7}
	mov r7, #0x3e0
_08000108:
	ldr r0, _080000FC @ =0x020104B4
	add r0, r0, r7, lsr #5
	ldrsb r5, [r0]
	tst r5, r5
	beq _080001C0
	ldr r4, _080000F8 @ =0x020104D4
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
	ldr r1, _080000F4 @ =0x03001EF0
	add r1, r1, r6
	strh r0, [r1, r7]
	subs r6, r6, #2
	bpl _08000134
_080001C0:
	subs r7, r7, #0x20
	bpl _08000108
	pop {r4, r5, r6, r7}
	bx lr

	arm_func_start sub_080001d0
sub_080001d0: @ 0x080001D0
	stm r0!, {r4, r5, r6, r7, r8, sb, sl, fp, ip, sp, lr}
	mov r0, #0
	tst lr, #1
	moveq pc, lr
	bx lr

	arm_func_start sub_080001e4
sub_080001e4: @ 0x080001E4
	ldm r0!, {r4, r5, r6, r7, r8, sb, sl, fp, ip, sp, lr}
	movs r0, r1
	moveq r0, #1
	tst lr, #1
	moveq pc, lr
	bx lr
