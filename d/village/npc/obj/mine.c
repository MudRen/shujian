// mine.c ��ʯ
//Modified By ChinaNet
//By 2004/1/11

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("��ʯ", ({ "kuang shi", "shi","kuang","mine"})); 
       
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
                set("unit", "��");
                set("weight", 800);
		set("long", "����һ����ͨ�Ŀ�ʯ��\n");
		set("no_get","����ʯ��ô�أ���᲻������\n");
		set("no_drop","������ʯͷ���ҵ�����ô�죿\n");
		set("material", "stone");
		set("minejob",1);
		set("value",10000+random(5000));
	}
	setup();
}

