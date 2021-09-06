// automake group room , Wed Aug  3 20:43:20 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/entry.h"
void create()
{
set("short","大道");
set("long","一条笔直的石板大道通向前方，路上不时的有南来北往的车马经过，不少
行人手持各种兵器，看来都是习武之人，大理段家上自皇爷，下至王子，数代
保留祖上武林传统，民间习武之风更是盛行。
");
set("exits",([
"south":"/d/dali/dadao3","north":"/d/dali/dadao1","northwest":"/d/group/SHTM/1312375400.c",
]));
set("outdoors","大理城北");
set("group",1);
setup();
}
