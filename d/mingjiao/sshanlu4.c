//sshanlu4.c ɽ·
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
        "southdown" : __DIR__"sshanlu3",
        "north" : __DIR__"xuanya1",
    ]));
    set("outdoors", "���̹�����");
    set("coor/x",-340);
  set("coor/y",100);
   set("coor/z",40);
   set("coor/x",-340);
 set("coor/y",100);
   set("coor/z",40);
   setup();
}
