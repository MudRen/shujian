#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW "����" NOR, ({ "bai yi", "cloth","yi","baiyi" }) );
        set_weight(3500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ��������ɴ���ѩ��ɫ������\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 35);
                set("wear_msg","$N��������һ����ɴ���$n�����������������\n");
                set("remove_msg","$N��$n����������������\n");
        }
        setup();
}
