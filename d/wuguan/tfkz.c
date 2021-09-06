//同福客栈

#include <ansi.h>
inherit ROOM;

void create()
{
     set("short", HIY"同福客栈"NOR);
     set("long", @LONG
这里就是传说中藏龙卧虎人见人怕的超级黑店同福客栈了。
据说当年大名鼎鼎的郭芙蓉郭女侠初入江湖，因为欠下钱财，
被困在这里终其一生。江湖，故事从这里开始了。。。
LONG
     );
     set("objects", ([
                 "/d/wuguan/npc/newshizhe" : 1,
          ]));
     set("exits", ([

             "out" : "/d/xiangyang/eroad1",
     ]));
     setup();
 }
