// xuan-cloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIM "��" HIY "�" HIG "����" NOR, ({ "jia sha", "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "ǧ����������׹������ϡ�����\n
���������̲�粣�����������ر�\n
������˴Ӵ��������������Ȫ\n
�л����������ƣ�������ɮ���Ҵ�\n");
                set("unit", "��");
                set("material", "silk");
                set("armor_prop/armor", 40);
                set("wear_msg","$N�ó�һ��$n�������ϡ�\n");
                set("remove_msg","$N��$n����������������\n");
        }
        setup();
}
