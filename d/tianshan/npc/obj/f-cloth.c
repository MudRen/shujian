// Obj: /d/tianshan/npc/obj/f-cloth.c
// By Linux
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
string *color_name = ({
HIR"��ɫ",HIG"��ɫ",YEL"����ɫ",HIY"��ɫ",BLU"����ɫ",
HIB"��ɫ",MAG"��ɫ",HIM"�ۺ�ɫ",HIC"����ɫ",HIW"��ɫ",});

void create()
{
        set_name(color_name[random(sizeof(color_name))]+"С����"NOR, ({ "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "���Ǽ�С������\n");
                set("unit", "��");
                set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 10+random(15));
                set("armor_prop/personality", 1);
                set("female_only", 1);
        }
        setup();
}
