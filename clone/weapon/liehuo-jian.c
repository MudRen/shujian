#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(RED"�һ�"NOR, ({ "liehuo jian", "jian", "liehuo", "sword" }) );        
        set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
           set("value", 10000000);
           set("rigidity", 2);
           set("sharpness", 2);
           set("unique", 1);
           set("treasure",1);
           set("wield_neili", 100);
           set("wield_maxneili", 1000);
           set("wield_str", 20);
           set("unit", "��");
           set("long", RED"�˽������������һ𣬽������������һ�������׭���������̵���̱��ƽʱ�������ڹ�������֮�ڡ�\n"NOR);
           }
        init_sword(50);
        setup();
}