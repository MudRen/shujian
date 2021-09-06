// beike.c ±´¿Çº£ÂÝÀà
// by Lklv for girls :)
// 2001.9.27

#include <ansi.h>
inherit ITEM;

void create()
{
        switch(random(10)) {
               case 0 : set_name(HIY"º£ÂÝ"NOR, ({ "hai luo", "hailuo", "luo" }) ); break;
               case 1 : set_name(HIM"Ô§Ñì±´"NOR, ({ "yuanyang bei", "beike", "bei" }) ); break;
               case 2 : set_name(HIR"ÕäÖé±´"NOR, ({ "zhenzhu bei", "beike", "bei" }) ); break;
               case 3 : set_name(HIW"ÉÈ±´"NOR, ({ "bei ke", "beike", "bei" }) ); break;
               case 4 : set_name(HIG"ðÐðÄÂÝ"NOR, ({ "yingwu luo", "hailuo", "luo" }) ); break;
               case 5 : set_name(HIW"ºÉ»¨±´"NOR, ({ "hehua bei", "beike", "bei" }) ); break;
               case 6 : set_name(YEL"»¨Æ¿ÂÝ"NOR, ({ "huoping luo", "hailuo", "luo" }) ); break;
               case 7 : set_name(HIW"Áù½ÇÂÝ"NOR, ({ "liujiao luo", "hailuo", "luo" }) ); break;
               case 8 : set_name(HIC"Ò¹¹âÂÝ"NOR, ({ "yeguang luo", "hailuo", "luo" }) ); break;
               case 9 : set_name(HIR"²Ê"HIY"ºç"HIB"±´"NOR, ({ "caihong bei", "beike", "bei" }) ); break;
        }
	set("long", "Ò»¸öÉ«²ÊÏÊÑÞµÄ"+name()+"¡£\n");
	set_weight(200+random(100));
        set("value", 250+random(500));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
        }
        setup();
}