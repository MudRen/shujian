#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�ӹ�", ({ "nao gou", "gou", "naogou" }));
        set_weight(400);
        set("unit", "��");
		set("long", "����һ�������ӹ�������������ɽ��\n");
		set("value", 40);
		set("material", "wood");
        setup();
}