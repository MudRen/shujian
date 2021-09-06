// automake group room , Mon Apr 22 16:55:03 2002
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","[1;35mÌÒ»¨ÁÖ[0;0m");
set("long","    Ò»´óÆ¬ÌÒ»¨ÁÖ¡£¼Ğ°¶Êı°Ù²½£¬ÖĞÎŞÔÓÊ÷£¬·¼²İÏÊÃÀ£¬ÂäÓ¢çÍ·×¡£Äãºö
È»·¢ÏÖÒ»ÖêÌÒÊ÷ÉÏÒşÒşÔ¼Ô¼ÓĞ¿Ì×Å×Ö¼££º×ß½üÏ¸¿´£¬Ö»¼û±È»®×Ö¼£ÍáÍáĞ±
Ğ±Ã»ÓĞÕÂ·¨¼ä¼Ü£¬È»¶øºÜÓĞÁ¦µÀ£¬ÏóÊÇ¸öÎä·òËùĞ´£¡£¡
                     [0;33m´ó¸òó¡£¨Biaofeng£©µ½´ËÒ»ÓÎ
[0;0m");
set("exits",([
"south":__DIR__"1019461907.c",
]));
set("outdoors","[1;35mÌÒ»¨Ô´[0;0m");
set("group1","taohua");
set("group2","[1;35mÌÒ»¨Ô´[0;0m");
setup();
setup_var();
}
