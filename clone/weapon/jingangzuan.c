// jingangzuan.c 
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name( HIW"������"NOR , ({ "jingang zuan", "jingangzuan","zuan","staff"}));
        set_weight(15000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIR"���ǲش�����е�һ�ַ�����Լ���߰˳ٳ������ֳ��أ�����������ġ�\n"NOR);
                set("value", 1000);
                set("material", "steel");
        }
        init_staff(30);
        setup();
}
