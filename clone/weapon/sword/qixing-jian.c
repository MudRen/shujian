// qixing-jian.c ���Ǳ���
//ֻ��Ϊ�˲��򽣾��ã�������Ū��һ��ĺ��ˡ�

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIB"���ǽ�"NOR,({ "qixing jian", "sword", "jian" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
//                set("treasure",1);
                set("unique", 1);
                set("value", 1);
                set("rigidity", 10);
                set("sharpness", 9);
                set("material", "steel");

                 set("wield_neili", 1300);
                set("wield_maxneili", 1700);
                set("wield_str", 28);
                set("wield_msg", HIY"$N��ৡ���һ��������ǽ���ֻ����������â���£������Ƿɡ�\n"NOR);
                set("long", "����һ���ĳ������ĹŽ������������š����ǽ�������׭�ġ�\nֻ������׭���ϱ������ǲ��ϱ仯��·����\n");                
                set("unwield_msg", HIB "���ǽ�����һ�����⣬��ৡ��ط��뽣�ʣ����籱����������\n" NOR);                
        }
        init_sword(20);
        setup();
}
