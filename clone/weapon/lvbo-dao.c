// /clone/weapon/lvbo-dao �̲���¶��

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name(GRN"�̲���¶��"NOR, ({ "lvboxianglu dao","lvboxianglu","dao", "blade" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("rigidity", 9);
                set("sharpness", 5);
                set("material", "steel"); 
                set("weapon_prop/parry", 8);
                set("long", "����һ�ѻ���͸�Ű���ɫ�������������������ȳ�����ζ��ȴƫƫ����¶������������֡�\n");
                set("value", 1);
                set("unique", 1);
                set("wield_neili", 500);
                set("wield_maxneili", 1000);
                set("wield_str", 22);
                set("wield_msg", HIG"$N�ӱ�����һ�ѱ�������������˸����������������������ó���㺮�⡣\n"NOR);            
                set("unwield_msg", HIG"$N˫��һ�ӣ�����㽫����ص����ڡ�\n"NOR);
                set("treasure",1);
                set("poisoned", "lvbo_poison");
               set("poison_number", 200);
        }
 	init_blade(60);
        setup();
}
