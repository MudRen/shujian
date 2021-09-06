// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/changan/duchang3
// by system_3cat 7/5/1997
inherit ROOM;


void create()
{
  set ("short", "破院");
  set ("long", @LONG

这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。


LONG);

  set("item_desc",([
    "paizi" : "押红冠鸡： dou hg <amount> <money>\n"+ 
              "押绿尾鸡： dou lw <amount> <money>\n", 
  ])); 

  set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"chat-dc1",
  ]));

  setup();
}
//是镜像
int is_mirror() { return 1; }