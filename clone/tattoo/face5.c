#include <ansi.h>

inherit __DIR__"tattoo";

void create()
{
        set_name(NOR + WHT "????ͼ??" NOR, ({ "kulou tu", "kulou", "tu" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "????һ?Źžɵ?ͼƬ??????????Щ??????");
                set("unit", "??");
                set("value", 1500);
                set("material", "paper");
                set("tattoo_long", "һ????ɭɭ??????");
                set("can_tattoo", ({ "????", "?β?", "????", "?ұ?" }));
                set("tattoo_type", ({ "????" }));
                set("tattoo_str", 1);
        }
}
