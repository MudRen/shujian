#include <ansi.h>
#include <weapon.h>

inherit F_HAMMER;
inherit F_EQUIP;
inherit COMBINED_ITEM;
inherit F_UNIQUE;

void set_amount(int count)
{
    unequip();
        set("weapon_prop/damage", 22*count);
    ::set_amount(count);
}


void create()
{
        set_name( HIW "����" NOR,({ "yin lun" ,"lun" ,"yinlun" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
             set("value", 500000);
             set("unique", 5);
             set("rigidity", 3);
             set("base_weight", 15000);
             set("base_unit", "ֻ");
             set("unit", "Щ");
             set("long",HIY"���Ǿ����߰룬�ɰ������ɣ��������в��ĵ��������ԣ��вؾŸ�С��ķ��֣�����һ�����������ò�����\n" NOR);
             set("material", "silver");
             set("weapon_prop/dodge", -10);
             set("weapon_prop/parry", 2);
             set("wield_neili", 100);
             set("wield_maxneili", 1200);
             set("wield_str", 23); 
             set("wield_msg", HIW"\n������һ��������$N�ӻ���ȡ���������֡�����һ�����������ò�����\n\n"NOR);
             set("unwield_msg",HIW"$N��$n"HIY"һ�ڣ�������һ���죬�Ż����䡣\n"NOR);
        }
        set_amount(1);
        init_hammer(22);
        setup();
}

int wield()
{
        object ob = environment();
        int ret;

        if(!living(ob)) return 0;
        if((ob->query_str() < 25 && query_amount() == 2)
           || (ob->query_str() < 28 && query_amount() == 3)
           || (ob->query_str() < 31 && query_amount() == 4)
           || (ob->query_str() < 34 && query_amount() == 5)
           || query_amount() > 5)
                return 0;
          
        else if (ret=::wield())
        return ret;
}

