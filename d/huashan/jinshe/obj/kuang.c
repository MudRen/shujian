// Room: /d/huashan/jinshe/obj/kuang.c
// Date: Look 99/03/25

inherit ITEM;

void create()
{
	set_name("�ٿ�", ({ "teng kuang", "kuang", "tengkuang" }));
	set_weight(500);
        set_max_encumbrance(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����ٱ�ɵĿ��ӣ��������װ������\n");
set("value", 0);
	}
}

int is_container() { return 1; }
