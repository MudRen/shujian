inherit ITEM;

void create()
{
        set_name("���ᱸ����", ({ "ji fang", "medicine book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ĩ�����д�Ľ�������������顣\n");
                set("value", 2500);
                set("material", "paper");
                set("exp_required", 5000);
                set("jing_cost", 20);
                set("difficulty", 22);
                set("max_skill", 31);
        }
}
#include "m-book.h";
