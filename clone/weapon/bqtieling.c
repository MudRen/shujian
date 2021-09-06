/*
 tie-ling.c ����
 by snowman@SJ 18/02/2000

*/

#include <weapon.h>
#include <ansi.h>

inherit F_DAGGER;
inherit COMBINED_ITEM;
inherit F_UNIQUE;
inherit F_EQUIP;

void set_amount(int v)
{
        object owner = environment();
        if (v >= 0) {
                set("weapon_prop/damage", v * (int)query("base_damage"));
                set("rigidity", v * query("base_rigidity"));
                if (query("equipped") && objectp(owner)) {
                        owner->set_temp("apply/damage", query("weapon_prop/damage") );
                }
        }
        ::set_amount(v);
}

void add_amount(int v) { set_amount((int)query_amount()+v); }

void create()
{
        set_name( HIB"��"HIR"��"HIC"������"NOR, ({ "jiulong ling","ling" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 1000);
                set("long", "����һ���������������ƣ��������䣬����������ž�����צ������ŭ��̽צ������ʮ�㡣\n");
                set("value", 36000);
                set("material", "steel"); 
                set("base_damage", 100);
                set("rigidity", 1);
                set("base_rigidity", 4);
                set("wield_msg", "$N�������һ��$n��ֻ����â���£�����������֮����\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        set_amount(1);
        init_dagger(45);
        setup();
}

int wield() 
{
        object me = environment();

        if (!userp(me)) return ::wield();
        if (living(me) && !me->query_skill("shenghuo-lingfa", 1)){
                message_vision("$N�ó�"+name()+"���˿���ȴ�㲻����ôʹ�����������\n", me);
                return 0;
        }           
        if( query_amount() > 2 ){
                message_vision("$N�ó�"+name()+"���˿���ȴ�㲻����ôͬʱʹ������\n", me);
                return 0;
        }    
        if (query_amount() > 1){
                if (me->query_skill("shenghuo-lingfa", 1) < 80 || me->query_int() < 30){
                        message_vision("$N�ó�"+name()+"���˿���ȴ�㲻����ô������\n", me);
                        return 0;
                }
        }
        if(!query("weapon_prop/damage")) return 0;
        return ::wield();
}
