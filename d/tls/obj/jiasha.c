#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIY "��˿ľ������" NOR, ({ "jia sha", "cloth","jiasha" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ���ý�˿��ߵĻ�ɫľ�����ġ�\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 40);
                set("wear_msg","��������һ������ǰ���һ����$N����һ��$n����ɫ��쵣���˿���塣\n");
                set("remove_msg","$N��$n����������������\n");
                set("tianlongsi",1);
        }
        setup();
}
