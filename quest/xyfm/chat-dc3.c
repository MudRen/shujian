// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/changan/duchang2
// by system_3cat 7/5/1997
inherit ROOM;


void create()
{
  set ("short", "破旧赌坊");
  set ("long", @LONG

这里摆着一个支离破碎的八仙桌，四处蜘蛛网连接。
LONG);

  set("item_desc",([
    "paizi" : "押头彩骰： gutou tc <amount> <money>\n"+ 
              "押双对骰： gutou sd <amount> <money>\n"+ 
              "押七星骰： gutou qx <amount> <money>\n"+ 
              "押散星骰： gutou sx <amount> <money>\n" 
  ])); 

  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"chat-dc1",
  ]));

  setup();
}
//是镜像
int is_mirror() { return 1; }
