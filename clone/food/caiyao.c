//Modify By Yanyang@SJ 2001.9.22

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

string *names = ({
                HIY"ÂéÀ±¶ÇË¿"NOR,
                HIY"ËÉÈÊÓñÃ×"NOR,
                RED"Ã·²Ë¿ÛÈâ"NOR,
                HIR"ÎåÏãÀ°³¦"NOR,
                HIM"ÓãÏãÈâË¿"NOR,
                HIY"ºìÓÍ¼¦Æ¬"NOR,
                HIW"Çå³´ÏºÈÊ"NOR,
                RED"Îå»¨ìËÈâ"NOR,
                CYN"ÇàË¿Ñ¬Óã"NOR,
                RED"ÌÇ´×ÅÅ¹Ç"NOR,
                RED"¾©½´ÈâË¿"NOR,
                YEL"ÓÍìÁ´óÏº"NOR,
                HIY"´àÆ¤¿¾Ñ¼"NOR,
                HIY"ºìÉÕËØ¶ì"NOR,
                HIW"¹¬±£¼¦¶¡"NOR,
                HIR"ºìÓÍ·ÎÆ¬"NOR,
                MAG"ÄÛÙàÖí¸Î"NOR,
                YEL"×ßÓÍ´à³¦"NOR,
                RED"±¬³´Ñü»¨"NOR,
                HIG"÷êÏã¶¬Ëñ"NOR,
                HIW"ôä´ä¶¹¸¯"NOR,
                HIW"ÂéÆÅ¶¹¸¯"NOR,
                YEL"ÈıÏÊ¸¯Öñ"NOR,
                RED"·¬ÇÑÑüÁø"NOR,
                HIR"×¥³´Àï¼¹"NOR,
                HIY"Æ¬Æ¤ÈéÖí"NOR,
                HIY"¹ø°ÍÈâÆ¬"NOR,
                HIC"ÁºÏª´à÷­"NOR,
                HIR"¸ÉìÔÓÈÓã"NOR,
                HIR"ÖØÇì»ğ¹ø"NOR,
                HIG"±ÌÂİ´º¾í"NOR,
});
                

void create()
{
  set_name("¸÷Àà²ËëÈ", ({"cai yao", "cai", "food"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "Ò»ÅÌÁîÈË´¹ÏÑµÄ²ËëÈ¡£\n");
    set("unit", "ÅÌ");
    set("value", 200);
    set("food_remaining", 5);
    set("food_supply", 35);
  }
}

void init()
{
  if (query("name")=="¸÷Àà²ËëÈ")
    set_name(names[random(sizeof(names))], ({"cai yao","cai","food"}));
  ::init();
}

