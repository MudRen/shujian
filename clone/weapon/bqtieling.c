/*
 tie-ling.c 铁令
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
        set_name( HIB"阴"HIR"阳"HIC"九龙令"NOR, ({ "jiulong ling","ling" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("base_unit", "块");
                set("base_weight", 1000);
                set("long", "这是一柄两尺来长的令牌，寒光四射，令牌上面刻着九条五爪金龙，怒睛探爪，神韵十足。\n");
                set("value", 36000);
                set("material", "steel"); 
                set("base_damage", 100);
                set("rigidity", 1);
                set("base_rigidity", 4);
                set("wield_msg", "$N缓缓抽出一柄$n，只见寒芒吞吐，隐隐有龙吟之声。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
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
                message_vision("$N拿出"+name()+"看了看，却搞不懂怎么使用这个东西。\n", me);
                return 0;
        }           
        if( query_amount() > 2 ){
                message_vision("$N拿出"+name()+"看了看，却搞不懂怎么同时使用它。\n", me);
                return 0;
        }    
        if (query_amount() > 1){
                if (me->query_skill("shenghuo-lingfa", 1) < 80 || me->query_int() < 30){
                        message_vision("$N拿出"+name()+"看了看，却搞不懂怎么用它。\n", me);
                        return 0;
                }
        }
        if(!query("weapon_prop/damage")) return 0;
        return ::wield();
}
