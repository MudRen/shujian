inherit ITEM;

void create()
{
        set_name("����ʶ��", ({ "sangang shilue", "medicine book" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ĩ������д�Ľ�������������顣\n");
		set("value", 6000);
                set("material", "paper");
                set("exp_required", 10000);
                set("jing_cost", 30);
                set("difficulty", 24);
                set("min_skill", 40);
                set("max_skill", 51);
        }
}

#include "m-book.h";
