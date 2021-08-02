#include "global.h"

extern u8 gUnknown_0201226C[];
extern u8 gUnknown_02012EC0;
extern u8 gUnknown_02013EC0;
extern u8 gUnknown_02014B40;
extern u8 gUnknown_02014F40;

extern u8 gUnknown_030036AC;
extern s8 gUnknown_0300337C[];
extern u8 gUnknown_03004310[];

extern u8 *gUnknown_08282C30;
extern void gUnknown_0828AEA8;
extern void gUnknown_0828AF28;
extern void gUnknown_0828AFE8;
extern void gUnknown_0828B0B8;
extern void gUnknown_0828B2F8;
extern void gUnknown_0828B398;

extern void sub_800FBC0(void *ptr1);
extern void sub_80117C0(u8 arg1);
extern void sub_80131E0(void *ptr1, u32 arg2);
extern s8 sub_8015E10(u8 arg1);
extern void sub_8015E44(u16 arg1, u8 arg2);
extern void sub_8015FDC(void);
extern void sub_801780C(void);
extern void sub_8017830(void);
extern void sub_8018394(void *ptr1);
extern void sub_80183D4(void *ptr1);
extern void sub_8028B54(void);
extern void sub_802C33C(u32 arg1);
extern void sub_803495C(u32 arg1, u32 arg2, u32 arg3, u32 arg4);
extern void sub_8038214(void);
extern void sub_803DB40(void);

void sub_802C470(void) {
	sub_802C33C(0);
}

void sub_802C47C(void) {
	sub_802C33C(1);
}

void sub_802C488(void) {
	sub_802C33C(2);
}

void sub_802C494(u32 arg1) {
	switch (gUnknown_03004310[1]) {
		case 0:
			gUnknown_0201226C[31] = gUnknown_03004310[2] - 0x74;
			sub_803DB40();
			break;
		case 2:
			sub_803DB40();
			break;
		case 1:
			sub_8015FDC();
			sub_803DB40();
			break;
		case 3:
			sub_803DB40();
			break;
	}
}

void sub_802C4D8(void) {
	sub_8038214();
	sub_802C494(gUnknown_030036AC);
}

void sub_802C4F0(void) {
	sub_80131E0(&gUnknown_0828AEA8, 0);
}

void sub_802C504(void) {
	sub_80183D4(&gUnknown_0828AF28);
}

void sub_802C514(u8 arg1) {
	gUnknown_08282C30[arg1 * 0x68 + 0x2d] = 1;
}

void sub_802C530(void) {
	sub_802C514(gUnknown_030036AC);
	sub_8028B54();
}

void sub_802C548(void) {
	sub_802C514(gUnknown_030036AC);
	if (gUnknown_03004310[50] != 0) {
		sub_803495C(17, 0, 0, 0);
	}
}

void sub_802C574(void) {
	sub_80183D4(&gUnknown_0828AFE8);
}

void sub_802C584(void) {
	sub_80183D4(&gUnknown_0828B0B8);
}

void sub_802C594(void) {
	sub_8015E44(sub_8015E10(gUnknown_03004310[1]), 0);
}

// copy of memcpy? :P
void sub_802C5B4(u8 *dest, u8 *src, u32 count) {
	u32 i;
	for (i = count - 1; i != -1; i--) {
		*src++ = *dest++;
	}
}

void sub_802C5D8(void) {
	sub_802C5B4(&gUnknown_02014B40, &gUnknown_02012EC0, 0x180);
	sub_802C5B4(&gUnknown_02014F40, &gUnknown_02013EC0, 0x180);
	sub_80117C0(0);
	sub_80117C0(2);
}

void sub_802C614(void) {
	sub_800FBC0(&sub_8017830);
}

void sub_802C624(void) {
	sub_800FBC0(&sub_801780C);
}

void sub_802C634(void) {
	sub_80183D4(&gUnknown_0828B2F8);
}

void sub_802C644(void) {
	sub_8018394(&gUnknown_0828B2F8);
}

u32 sub_802C654(void *ptr1) {
	if (ptr1 == &gUnknown_0828B2F8) {
		return 1;
	}
	return 0;
}

void sub_802C668(void) {
	sub_80131E0(&gUnknown_0828B398, 0);
	gUnknown_0300337C[1] &= ~1;
}
