// zhenwu-jian.c ���佣
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"���佣"NOR, ({"zhenwu jian", "sword", "zhenwu"}));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�Ѻ������۵ĹŽ�,��������Ļ������ƺ�������Щ����,�����Ͼ�Ȼ���м���ȱ�ڡ�\n");
                set("value", 1);
                set("unique", 1);
                set("rigidity", 5);
                set("sharpness", 5);
                set("material", "blacksteel");
                set("weapon_prop/parry", 4);
                set("treasure",1);       
                set("wield_neili", 900);
                set("wield_maxneili", 1400);
                set("wield_str", 24);
                set("wield_msg",HIW"\nֻ����ৡ���һ����$N�������һ�Ѻ�������ı����������䵱ɽ��ɽ֮�������佣����\n"NOR);
                set("unwield_msg",HIW"$N�����е����佣��ؽ��ʡ�\n"NOR);
        }
        init_sword(80);
        setup();
}       
