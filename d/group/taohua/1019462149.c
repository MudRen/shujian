// automake group room , Mon Apr 22 16:42:16 2002
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","[1;35mÌÒ»¨ÁÖ[0;0m");
set("long","Ò»´óÆ¬ÌÒ»¨ÁÖ¡£¼Ğ°¶Êı°Ù²½£¬ÖĞÎŞÔÓÊ÷£¬·¼²İÏÊÃÀ£¬ÂäÓ¢çÍ·×¡£Äãºö
È»·¢ÏÖÒ»ÖêÌÒÊ÷ÉÏÒşÒşÔ¼Ô¼ÓĞ¿Ì×Å×Ö¼££º×ß½üÏ¸¿´£¬Ö»¼û±È»®²Ô¾¢ÓĞÁ¦£¬
¾¹ÏóÊÇÓÃÊÖÖ¸¿ÌÉÏÈ¥µÄ£¡£¡
                     ÈıÇØ£¨Action£©µ½´ËÒ»ÓÎ
[0;0m");
set("exits",([
"west":__DIR__"1019461907.c",
]));
set("outdoors","[1;35mÌÒ»¨Ô´[0;0m");
set("group1","taohua");
set("group2","[1;35mÌÒ»¨Ô´[0;0m");
setup();
setup_var();
}
