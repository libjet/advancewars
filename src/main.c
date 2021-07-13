#include "global.h"
#include "gba/io_reg.h"

extern u32 gUnknown_03000710;
extern void gUnknown_03000718;
extern void gUnknown_03006560;
extern void gUnknown_03006570;
extern void gUnknown_03006630;
extern u32 gUnknown_03007FFC;

extern void IntrMain;
extern void gUnknown_0827D308;
extern s16 gUnknown_0827D344[];

extern void sub_80386B8(void);
extern void sub_807AF94(void *ptr1, void *ptr2, u32 arg3);
extern u32 sub_807AFB8(void *ptr1);
extern u32 sub_807AFD4(void *ptr1);
extern u32 sub_807B008(void *ptr1, u32 arg2, u32 arg3);
extern void sub_807B030(void *ptr1, u32 arg2);
extern u32 sub_807B0DC(void *ptr1);
extern s32 sub_807B0F8(void *ptr1);
extern u32 sub_807B1B0(void *ptr1, u32 arg2);
extern u32 sub_807B1CC(void *ptr1, u32 arg2, u32 arg3);
extern u32 sub_807B250(void *ptr1, u32 arg2);
extern void sub_807B27C(void *ptr1, void *ptr2, u32 arg3);
extern void _call_via_r4(void);

void sub_807AE00(s32 arg1, u32 arg2);

void sub_807AC88(void) {
	sub_807AF94(&gUnknown_03006560, &gUnknown_03006570, 0x10);
}

void sub_807ACA0(void) {
	sub_807AE00(0, 0);
	sub_807AC88();
}

void AgbMain(void) {
	sub_807ACA0();
	sub_80386B8();
}

u32 sub_807ACBC(u32 arg1, u32 arg2) {
	u32 temp1 = sub_807B250(&gUnknown_03006560, arg1);
	if (temp1 == -1) {
		return sub_807B008(&gUnknown_03006560, arg1, arg2);
	} else {
		if (sub_807B1B0(&gUnknown_03006560, temp1) == arg2) {
			return temp1;
		} else {
			return sub_807B1CC(&gUnknown_03006560, temp1, arg2);
		}
	}
}

void sub_807AD04(u32 arg1) {
	sub_807B030(&gUnknown_03006560, arg1);
}

void sub_807AD14(void) {
	sub_807AD04(sub_807B0DC(&gUnknown_03006560));
}

void sub_807AD28(void) {
	u32 temp1 = sub_807AFB8(&gUnknown_03006560);
	while (temp1 != 0 && sub_807B0F8(&gUnknown_03006560) < 30) {
		_call_via_r4();
		temp1 = sub_807AFD4(&gUnknown_03006560);
	}

	while ((REG_DISPSTAT & 1) != 0)
		;
	while ((REG_DISPSTAT & 1) == 0)
		;

	while (temp1 != 0) {
		_call_via_r4();
		temp1 = sub_807AFD4(&gUnknown_03006560);
	}
}

void sub_807AD90(void) {
	while (1) {
		if ((REG_DISPSTAT & 1) == 0) {
			return;
		}
	}
}

void sub_807ADA4(void) {
	sub_807AD28();
	sub_807AD90();
}

void sub_807ADB0(void) {
}

void sub_807ADB4(void) {
	sub_807AE00(0, 0);
	sub_807B27C(&gUnknown_0827D308, &gUnknown_03006630, 30);
	sub_807B27C(&IntrMain, &gUnknown_03000718, 0x100);
	gUnknown_03007FFC = (u32)&gUnknown_03000718;
}

void sub_807ADF0(u32 arg1, u32 arg2) {
	u32 *temp = &gUnknown_03006630;
	temp[arg1] = arg2;
}

void sub_807AE00(s32 arg1, u32 arg2) {
	switch (arg1) {
		case 0:
			gUnknown_03000710 = arg2;
			break;
		case 1:
			gUnknown_03000710 &= arg2;
			break;
		case 2:
			gUnknown_03000710 |= arg2;
			break;
	}
	REG_IE = gUnknown_03000710;
	if ((gUnknown_03000710 & 0x10000) != 0) {
		REG_IME = 1;
	} else {
		REG_IME = 0;
	}
}

s16 sub_807AE74(s32 arg1) {
	s32 temp1 = arg1;
	s32 temp2;

	// Get temp2 between 0 and 359
	while (temp1 < 0) {
		temp1 += 360;
	}
	while (temp1 >= 360) {
		temp1 -= 360;
	}
	temp2 = temp1;

	// Get temp1 between 0 and 90
	if (temp1 >= 180) {
		temp1 -= 180;
	}
	if (temp1 > 90) {
		temp1 = 180 - temp1;
	}

	if (temp2 >= 180) {
		return -gUnknown_0827D344[temp1];
	} else {
		return gUnknown_0827D344[temp1];
	}
}

s16 sub_807AED0(s32 arg1) {
	return sub_807AE74(arg1 + 90);
}
