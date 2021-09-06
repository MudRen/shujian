//lead-falun.c Ǧ����
#include <ansi.h>
#include <weapon.h>
inherit F_HAMMER;
inherit F_EQUIP;
inherit COMBINED_ITEM;
inherit F_UNIQUE;

void set_amount(int count)
{
    unequip();
set("weapon_prop/damage", 20*count);
    ::set_amount(count);
}

void create()
{
        set_name( WHT"Ǧ����"NOR,({ "leaden falun" ,"lun" ,"falun","qian falun","qianfalun" }));
        set_weight(40000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "ֻ");
                set("long","����һֻǦ�Ʒ��֣�Լ�г߰��С�������������ڷ�ħ���ԣ��ڲؾŸ�С����ɮ�����������õ�һ�ַ�����\n");
                set("value", 50);
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 2);    
                set("material", "stannum");
                set("base_unit", "ֻ");
                set("base_weight", 18000);
                set("wield_msg", "$N�ӻ����ͳ�$n���˵�������������У������������á�\n");
                set("unwield_msg","$N�����е�$n���ػ��С�\n");
        }    
        set_amount(1);           
        init_hammer(25);
        setup();
}
int wield()
{
        object ob = environment();

	if (!userp(ob)) return ::wield();
        if (living(ob) && query_amount() >= 6 &&
             ob->query_str() < 60){
                message_vision("$N�ͳ�"+name()+"�����Է�����̫���ˣ������޷���ս�����������á�\n", ob);
                return 0;
                }

        if (living(ob) && query_amount() == 2 &&
            (ob->query_skill("xiangfu-lun", 1) < 50 ||
             ob->query_str() < 30)){
                message_vision("$N�ͳ�"+name()+"�����Է�����̫���ˣ������޷���ս�����������á�\n", ob);
                return 0;
                }
        if (living(ob) && query_amount() == 3 &&
            (ob->query_skill("xiangfu-lun", 1) < 100 ||
             ob->query_str() < 35)){
                message_vision("$N�ͳ�"+name()+"�����Է�����̫���ˣ������޷���ս�����������á�\n", ob);
                return 0;
                }

        if (living(ob) && query_amount() == 4 &&
            (ob->query_skill("xiangfu-lun", 1) < 150 ||
             ob->query_str() < 40)){
                message_vision("$N�ͳ�"+name()+"�����Է�����̫���ˣ������޷���ս�����������á�\n", ob);
                return 0;
                }

        if (living(ob) && query_amount() == 5 &&
            (ob->query_skill("xiangfu-lun", 1) < 200 ||
             ob->query_str() < 45)){
                message_vision("$N�ͳ�"+name()+"�����Է�����̫���ˣ������޷���ս�����������á�\n", ob);
                return 0;
                }

        if(!query("weapon_prop/damage")) return 0;
        return ::wield();
}
