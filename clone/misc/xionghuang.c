//item xionghuang �ۻ�

inherit FIRE_ITEM;
#include <ansi.h>

void create()
{
        set_name( HIY"�ۻ�"NOR, ({ "xiong huang" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("long", "����һ����ڻ�ɽ֮�����ۻ�ʯ��ɱ����򳶾����޼«����\n");
                set("unit", "��");
                set("value", 1000);
        }
        setup();
}


