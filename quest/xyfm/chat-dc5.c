inherit ROOM;

void create()
{
  set ("short", "荒地");
  set ("long", @LONG

这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG);

  set("item_desc",([
    "paizi" : "押长寿龟： sai cs <amount> <money>\n"+ 
              "押千年龟： sai qn <amount> <money>\n"+ 
              "押不老龟： sai bl <amount> <money>\n", 
  ])); 

  set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"chat-dc4",
  ]));
  setup();
}
//是镜像
int is_mirror() { return 1; }