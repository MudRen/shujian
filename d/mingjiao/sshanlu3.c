// sshanlu3.c ɽ·
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", YEL"ɽ·"NOR);
    set("long",@LONG
����һ��һխ�ֶ���ɽ·��ɽ·���Գ����ָ����ӵ��Ҳ���������û��ͷ��
ż�����м�֦������ס���ȥ·��һ��С����ᱻ����ˡ�
LONG);
    set("exits",([
        "northup" : __DIR__"sshanlu4",
        "eastdown" : __DIR__"sshanlu2",
    ]));
    set("objects",([
          __DIR__"npc/langzi"  :   2,
    ]));
    set("outdoors", "���̹�����");
    set("coor/x",-340);
  set("coor/y",90);
   set("coor/z",30);
   set("coor/x",-340);
 set("coor/y",90);
   set("coor/z",30);
   setup();
}
