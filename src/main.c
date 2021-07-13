#include "global.h"

extern void gUnknown_03006560;
extern void gUnknown_03006570;

extern void sub_80386B8();
extern void sub_807AE00(u32 arg1, u32 arg2);
extern void sub_807AF94(void *ptr1, void *ptr2, u32 arg3);
extern u32 sub_807B008(void *ptr1, u32 arg1, u32 arg2);
extern u32 sub_807B1B0(void *ptr1, u32 arg);
extern u32 sub_807B1CC(void *ptr1, u32 arg1, u32 arg2);
extern u32 sub_807B250(void *ptr1, u32 arg);

void sub_807AC88() {
	sub_807AF94(&gUnknown_03006560, &gUnknown_03006570, 16);
}

void sub_807ACA0() {
	sub_807AE00(0, 0);
	sub_807AC88();
}

void AgbMain() {
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
