//ԡѪ����
#include <armor.h>
#include <ansi.h>

inherit CLOTH;
inherit F_UNIQUE;

void create()
{
        set_name(HIR"ԡѪ����"NOR, ({ "yuxue kaijia", "kaijia" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR"����һ���������������������ף���Ϊ��������Ԫ˧ԡѪɳ�������ױ�Ⱦ����Ѫ��ɫ��\n"NOR);
                set("material", "steel");
                set("unit", "��");
                set("unique", 1);
                set("value", 1000000);
                set("wear_msg", HIR "$N����һ��������ԡѪ���ף�һ������׳�������������ƺ������˶�־��\n" NOR);
                set("remove_msg", HIR "$N����ԡѪ���ף�����ɢȥ��ԡѪ��ʿ�ķ�ɡ�\n" NOR);
                set("treasure",1);
                set("armor_prop/armor", 50);
                set("armor_prop/parry", 10);
                set("armor_prop/dodge",-10);
        }
        setup();
}


