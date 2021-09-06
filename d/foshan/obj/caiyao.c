// miantiao XiaoYao by 4/22/99

inherit ITEM;
inherit F_FOOD;

string *names = ({
                "ÂéÀ±¶ÇË¿",
                "ËÉÈÊÓñÃ×",
		"Ã·²Ë¿ÛÈâ",
		"ÎåÏãÀ°³¦",
		"ÓãÏãÈâË¿",
		"ºìÓÍ¼¦Æ¬",
		"Çå³´ÏºÈÊ",
		"Îå»¨ìËÈâ",
		"ÇàË¿Ñ¬Óã",
		"ÌÇ´×ÅÅ¹Ç",
		"¾©½´ÈâË¿",
		"ÓÍìÁ´óÏº",
		"´àÆ¤¿¾Ñ¼",
		"ºìÉÕËØ¶ì",
		"¹¬±£¼¦¶¡",
		"ÂéÀ±¶ÇË¿",
		"ºìÓÍ·ÎÆ¬",
		"ÄÛÙàÖí¸Î",
		"×ßÓÍ´à³¦",
		"±¬³´Ñü»¨",
		"÷êÏã¶¬Ëñ",
		"ôä´ä¶¹¸¯",
		"ÂéÆÅ¶¹¸¯",
		"ÈıÏÊ¸¯Öñ",
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
