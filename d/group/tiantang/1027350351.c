// automake group room , Tue Jul 23 00:23:40 2002
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","[1;33m±¦Îï¿â[0;0m");
set("long","[1;36mÒ»¸öÊ®¼¸Ã×¸ßµÄ[0;33m´óÌúÃÅ(Tie men)[1;36m³öÏÖÔÚÎÒÃÇÃæÇ°,ÃÅÉÏÓĞ
Ò»µÀÆæÌØµÄ·âÓ¡,ÕâÖÖ·âÓ¡Ö»ÓĞÌìÌÃÌÃÖ÷²ÅÄÜ´ò¿ª¡£ÔÚÇ½ÉÏÓĞ¸öÄ§·¨×öµÄ¹â
Çò,ÔÚ¹âÇòµÄÕÕÒ«ÏÂ,Ö»¼ûÃÅÄÚÊÇÒ»¸ö×ãÓĞ×ãÇò³¡´óĞ¡µÄÊ¯ÊÒ,ÀïÃæ¶ÑÂúÁË¸÷
ÖÖ¸÷ÑùµÄÆæÕäÒì±¦,³öÀïÃæµÄÈÎºÎÒ»Ñù¶«Î÷¶¼¼ÛÖµÁ¬³Ç¡£
[0;0m");
set("exits",([
"northwest":__DIR__"1027350275.c",
]));
set("objects",([
"/d/group/obj/qiangui.c":1,__DIR__"npc/1027354920.c":1,
]));
set("indoors","[0;35mÈË¼ä[0;36mÌìÌÃ[0;0m");
set("group1","tiantang");
set("group2","[0;35mÈË¼ä[0;36mÌìÌÃ[0;0m");
setup();
setup_var();
}
