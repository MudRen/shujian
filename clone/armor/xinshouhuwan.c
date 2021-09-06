// huwan.c 护腕

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
        set_name(HIR"新人护腕"NOR, ({ "hu wan", "huwan",}) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("long", "这是一件皮质的新人护腕，可以大幅增加命中、攻击、防御。\n"); 

                set("value", 100);
                set("material", "cloth");
                set("armor_prop/armor", 200);
              set("armor_prop/attack", 500);
              set("armor_prop/damage", 320);
               set("armor_prop/defense", 500);
        }
        setup();
}
int wear() 
{
        object me = environment();
        if (living(me) && me->query("combat_exp") >1500000){
            tell_object(me,"你已经不是新人了。\n");
            return 0;
        }           
        if(!query("armor_prop/damage")) return 0;
        return ::wear();
}

/*
int query_autoload()
{
        return 1;
}
*/
void owner_is_killed()
{
        destruct(this_object());
} 


