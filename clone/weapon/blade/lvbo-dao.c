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
                set("rigidity", 4);
                set("sharpness", 4);
                set("material", "steel"); 
                set("weapon_prop/parry", 4);
                set("long", "����һ�ѻ���͸�Ű���ɫ�������������������ȳ�����ζ��ȴƫƫ����¶������������֡�\n");
                set("value", 1);
                set("unique", 1);
                set("wield_neili", 800);
                set("wield_maxneili", 1300);
                set("wield_str", 23);
                set("wield_msg", HIG"$N�ӱ�����һ�ѱ�������������˸����������������������ó���㺮�⡣\n"NOR);            
                set("unwield_msg", HIG"$N˫��һ�ӣ�����㽫����ص����ڡ�\n"NOR);
                set("treasure",1);
              set("poisoned", "bing_poison");
              set("poison_number", 300);
        }
        init_blade(50);
        setup();
}
