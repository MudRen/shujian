// xuanya1.c ջ��
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIR"ջ��"NOR);
    set("long",@LONG
������һ�������ͱڵ�С·��һ��������׵����£��ͱڱ�ֱ��������
�죬��û�п�������֮����ż������һ�����ط���ʯͻ�𣬵�ס���ȥ·����
���ͷ����ͨ����һ��������׵����£�����������䣬�����Ѷɣ�ֻ��ż
������������������������Ľ����������������С��������߹�ȥ��
LONG);
    set("exits",([
        "northeast" : __DIR__"xuanya2",
        "northwest" : __DIR__"xuanya2a",
        "south" : __DIR__"sshanlu4",
    ]));
    set("objects",([
        __DIR__"npc/you"  :   2,
    ]));
    set("outdoors", "���̹�����");
    set("coor/x",-340);
  set("coor/y",110);
   set("coor/z",40);
   set("coor/x",-340);
 set("coor/y",110);
   set("coor/z",40);
   setup();
}
