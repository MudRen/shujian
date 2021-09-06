// automake group room , Sun May 26 22:40:20 2002
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","[0;32mÎäÁê[0;0m");
set("long","¡°ÎäÁêÉ½¡±Î»ÓÚ´¨¶õ½»½ç£¬µØÊÆÏÕ¾ş£¬±é²¼Ææ·å¡¢ĞüÑÂ¡¢Ï¿¹È¡¢¶´Ñ¨¡£
½úÌ«ÔªÖĞ£¬ÓĞÓæÈËÅ¼ÓöÌÒ»¨Ô´ÓÚ´Ë£¬Ì«ÊØ¹Î¹Î¿¨¼´Ç²ÈËËæÆäÍù£¬Ñ°Ïò
ËùÖ¾£¬ËìÃÔ£¬²»¸´µÃÂ·¡£Îäµ±Íò´ºÁ÷£¬¸ßÉĞÊ¿Ò²£¬ÎÅÖ®£¬ĞÀÈ»¹æÍù£¬
Ä©¹û£¬Ñ°²¡ÖÕ¡£ºóËìÎŞÎÊ½òÕß¡£
[0;0m");
set("exits",([
"up":__DIR__"1019055624.c","northeast":__DIR__"1019461907.c","south":"/d/group/entry/yzeroad1.c",
]));
set("objects",([
"/d/group/obj/biaozhi.c":1,"/d/group/obj/door.c":1,
]));
set("indoors","[1;35mÌÒ»¨Ô´[0;0m");
set("group1","taohua");
set("group2","[1;35mÌÒ»¨Ô´[0;0m");
setup();
setup_var();
}
