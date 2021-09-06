//iron-falun ������
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
        set_name( BLU"������"NOR,({ "iron falun" ,"lun" ,"falun","tie falun","tiefalun" }));
        set_weight(25000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "ֻ");
                set("long","����һֻ���Ʒ��֣�Լ�г߰��С�������������ڷ�ħ���ԣ��ڲؾŸ�С����ɮ�����������õ�һ�ַ�����\n");
                set("value", 100);
                set("rigidity", 1);
                set("weapon_prop/dodge", -6);
                set("weapon_prop/parry", 2);    
                set("material", "iron");
                set("base_unit", "ֻ");
                set("base_weight", 18000);
                set("wield_msg", "$N�ӻ����ͳ�$n���˵�������������У������������á�\n");
                set("unwield_msg","$N�����е�$n���ػ��С�\n");
        }    
        set_amount(1);           
        init_hammer(40);
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
             ob->query_str() < 32)){
                message_vision("$N�ͳ�"+name()+"�����Է�����̫���ˣ������޷���ս�����������á�\n", ob);
                return 0;
                }
        if (living(ob) && query_amount() == 3 &&
            (ob->query_skill("xiangfu-lun", 1) < 100 ||
             ob->query_str() < 37)){
                message_vision("$N�ͳ�"+name()+"�����Է�����̫���ˣ������޷���ս�����������á�\n", ob);
                return 0;
                }

        if (living(ob) && query_amount() == 4 &&
            (ob->query_skill("xiangfu-lun", 1) < 150 ||
             ob->query_str() < 42)){
                message_vision("$N�ͳ�"+name()+"�����Է�����̫���ˣ������޷���ս�����������á�\n", ob);
                return 0;
                }

        if (living(ob) && query_amount() == 5 &&
            (ob->query_skill("xiangfu-lun", 1) < 200 ||
             ob->query_str() < 47)){
                message_vision("$N�ͳ�"+name()+"�����Է�����̫���ˣ������޷���ս�����������á�\n", ob);
                return 0;
                }

        if(!query("weapon_prop/damage")) return 0;
        return ::wield();
}

