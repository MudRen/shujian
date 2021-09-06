// shoe.c Ä Ì¤Ñ©ÎÞºÛ 
#include <armor.h>
inherit BOOTS;
#include <ansi.h>

void create()
{
        set_name(GRN"Ì¤Ñ©ÎÞºÛ"NOR, ({ "shoes", "xie" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
                set("long","ÕâÊÇÒ»Ë«ÂÌÉ«µÄ²¼ÖÆ¿ìÑ¥¡£\n");
                set("value", 0);
                set("material", "boots");
                set("armor_prop/dodge", 20);
              }
         setup();
}

