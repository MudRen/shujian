
inherit ROOM;

void create()
{
        set("short", "ӭЦͤ");
        set("long",@long
����������ɽ��ɽ�ϵ�һ��Сͤ�ӣ���ɽ����ɽ���ο͵������ﶼЪЪ
�š�����ɽ�¾�ɫ��Զ��һƬ�̲�����ˮ��֮�䣬������⣬ɷ�����ˡ�
long);
set("objects",([
__DIR__"npc/seng" : 1,
]));
set("exits",([
"westdown" : __DIR__"lingyanshan",
"southup" : __DIR__"shiyuan",
]));
set("coor/x",130);
  set("coor/y",-290);
   set("coor/z",10);
   setup();
}
