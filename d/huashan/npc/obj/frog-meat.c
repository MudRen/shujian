// ITEM: /d/huashan/npc/obj/frog-meat.c
// Date: Look 99/03/25

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("ÇàÍÜÈâ", ({"qingwa rou", "meat","rou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¿éÏÊÑªÁÜÀì·ÊµÄÇàÍÜÈâ¡£\n");
                set("unit", "¿é");
                set("value", 200);
                set("food_remaining", 3);
                set("food_supply", 36);
        }
}