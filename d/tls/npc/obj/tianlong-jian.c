// tianlong-jian.c ������

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name("������",({ "tianlong jian", "tianlong", "sword", "jian" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100000);
                set("treasure",1);
                set("material", "steel");
                set("long", "���ǰ�ʽ�����ӵı�������֪���ж�����ͷ�ˣ���������������һ���������У�����ɱ����\n");
                set("wield_msg", HIY "ֻ���������һ������ǰһ�����������,$N��������񽣣�������ˮ����ת������\n" NOR);
                set("unwield_msg", HIY "һ����â��ৡ������뽣��,ɱ����Ȼ��ʧ��\n" NOR);
                set("unequip_msg", HIY "һ����â��ৡ������뽣��,ɱ����Ȼ��ʧ��\n" NOR);
        }
init_sword(180);
        setup();
}
