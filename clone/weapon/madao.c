// madao.c ��

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name( "��" , ({ "ma dao", "dao", "blade","madao" }));
        set_weight(12000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��������ǳ����õı�������������̣����ڷ�����������㡣\n");
                set("value", 1500);
                set("material", "iron");
        }
        init_blade(20);
        setup();
}
