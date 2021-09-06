#include <ansi.h>
#include <weapon.h>

inherit F_HAMMER;
inherit F_EQUIP;
inherit COMBINED_ITEM;
inherit F_UNIQUE;

void set_amount(int count)
{
    unequip();
        set("weapon_prop/damage", 25*count);
    ::set_amount(count);
}


void create()
{
       set_name( HIY "����" NOR,({ "jin falun" ,"lun" ,"jinlun" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
             set("value", 1000000);
             set("unique", 5);
             set("rigidity", 9);
             set("base_weight", 15000);
             set("base_unit", "ֻ");
             set("unit", "Щ");
             set("long",HIY"����־����߰룬�˻ƽ����ɣ��������в��ĵ��������ԣ��вؾŸ�С������һ�����������ò�����\n" NOR);
             set("material", "gold");
             set("weapon_prop/dodge", -10);
             set("weapon_prop/parry", 3);
             set("wield_neili", 100);
             set("wield_maxneili", 1500);
             set("wield_str", 23); 
             set("wield_msg", HIY"\n������һ��������$N�ӻ���ȡ���ƽ��֡�����־����߰룬�˻ƽ����ɣ��������в��ĵ��������ԣ�
�вؾŸ�С������һ�����������ò�����\n\n"NOR);
             set("unwield_msg",HIY"$N��$n"HIY"һ�ڣ�������һ���죬�Ż����䡣\n"NOR);
        }
      set_amount(1);
        init_hammer(25);
        setup();
}

int wield()
{
        object ob = environment();
        int ret;

        if(!living(ob)) return 0;
        if((ob->query_str() < 26 && query_amount() == 2)
           || (ob->query_str() < 29 && query_amount() == 3)
           || (ob->query_str() < 32 && query_amount() == 4)
           || (ob->query_str() < 35 && query_amount() == 5)
           || query_amount() > 5)
                return 0;
          
        else if (ret=::wield())
        return ret;
}

