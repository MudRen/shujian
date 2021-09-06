// zhaohun.c ÕĞ»êá¦Ş

#include <weapon.h>
#include <ansi.h>
inherit WHIP;

void create()
{
        set_name(BLU"ÕĞ»êá¦"NOR, ({ "zhaohun fan", "fan","whip" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¸Ë");
                set("long", "ÕâÊÇÒ»¸Ë²åÔÚÁé×ùÉÏµÄÕĞ»êá¦¡£\n");
                set("value", 3000);
                set("rigidity", 5);
                set("material", "steel");
                set("wield_msg", BLU"$N³é³öÒ»±úÕĞ»êá¦ÎÕÔÚÊÖÖĞ£¬Ä£Ñù¹îÆæÎŞ±È£¬ÁîÈËÆøÎªÖ®¶á¡£\n"NOR);
                set("unwield_msg", "$N½«ÊÖÖĞµÄ$n±ğ»ØÑüºó¡£\n");
        }
        init_whip(38);
        setup();
}

