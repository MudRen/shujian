// banyueqiang.c ����ǹ

#include <ansi.h>
#include <weapon.h>
inherit SPEAR;

void create()
{
        set_name( "����ǹ" , ({ "banyue qiang", "qiang", "dagger","banyueqiang" }));
        set_weight(18000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�����ǹ�ڽ���ǹӧ���������һ�����������������˹��������ͷ�Χ��\n");
                set("value", 1500);
                set("material", "iron");
        }
        init_spear(40);
        setup();
}
