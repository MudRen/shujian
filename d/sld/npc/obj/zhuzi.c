#include <armor.h>
#include <ansi.h>
inherit NECK;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"���S����"NOR, ({ "xianghuang zhuzi", "zhuzi","hate snake's zhu"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��΢΢���ŵ���ɫ�����ӣ���˵�������ϣ��ٶ����֡�\n");
                set("material", "silk");
                set("unit", "ֻ");
                set("unique", 1);
                set("value", 1000000);
                set("wear_msg", HIY "$N����������һ������ɫ�����Ӵ�������\n" NOR);
                set("remove_msg", HIY "$N�����ۻ����ӣ�С������ķ���������\n" NOR);
        set("armor_prop/neck", 50);
        }
        setup();
}