// jingang-zhao.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"ľ������"NOR, ({ "mumian jiasha", "mimian", "jiasha" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�����������ľ�����ģ�ͨ������ɽѩ��˿����˿ľ��֯�ɣ�����
�ޱȣ����������ˡ�������������ǰ�ɴ�Ħ����Я����ԭ��аħ��֮���ף�
���Ƿ�����Ͻ�ħ������\n");
                set("material", "silk");
                set("unit", "��");
                set("unique", 1);
                set("value", 1000000);
                set("wear_msg", HIY "ֻ����������һ����$Nչ��һ����������������������ϡ�
˲ʱ������Ϊ֮ʧɫ������ǧ�������ƶ�䣬һ��ׯ������\n" NOR);
                set("remove_msg", HIY "$N��$n"HIY"�����������������۵���СС��һ�š�\n" NOR);
        set("armor_prop/armor", 150);
        }
        setup();
}

