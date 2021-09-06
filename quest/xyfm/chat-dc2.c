// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/changan/duchang1
// by system_3cat 7/5/1997
inherit ROOM;


void create()
{
  set ("short", "破败卦场");
  set ("long", @LONG

乱世之中，人人求命于天，可如今，这解卦之人也不知何处逃生去了

LONG);

  set("item_desc",([
    "paizi" : "押大乾签： qian dqq <amount> <money>\n"+ 
              "押大坤签： qian dkq <amount> <money>\n"+ 
              "押小乾签： qian xqq <amount> <money>\n"+ 
              "押小坤签： qian xkq <amount> <money>\n"+ 
              "押乾签：   qian qq <amount> <money>\n"+ 
              "押坤签：   qian kq <amount> <money>\n",
  ])); 
  set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"chat-dc1",
  ]));

  setup();
}
//是镜像
int is_mirror() { return 1; }