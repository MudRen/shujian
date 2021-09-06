// qixing-jian.c 七星宝剑
//只是为了参悟剑诀用，威力就弄成一般的好了。

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIB"七星剑"NOR,({ "qixing jian", "sword", "jian" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
//                set("treasure",1);
                set("unique", 1);
                set("value", 1);
                set("rigidity", 10);
                set("sharpness", 9);
                set("material", "steel");

                 set("wield_neili", 1300);
                set("wield_maxneili", 1700);
                set("wield_str", 28);
                set("wield_msg", HIY"$N“唰”的一声抽出七星剑，只见剑身到处寒芒吞吐，电闪星飞。\n"NOR);
                set("long", "这是一柄四尺来长的古剑，剑柄上镶着‘七星剑’三个篆文。\n只见剑身被篆刻上北斗七星不断变化的路径。\n");                
                set("unwield_msg", HIB "七星剑幻作一道蓝光，「唰」地飞入剑鞘，犹如北斗七星泯灭。\n" NOR);                
        }
        init_sword(20);
        setup();
}
