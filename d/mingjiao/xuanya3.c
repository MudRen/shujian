// xuanya3.c ջ��
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
        "southwest" : __DIR__"xuanya2",
        "southeast" : __DIR__"xuanya2a",
        "eastup" : __DIR__"sshanlu5",
    ]));
    set("objects",([
        __DIR__"npc/langzi"  :   1,
    ]));
    set("outdoors", "���̹�����");         
    set("coor/x",-320);
  set("coor/y",130);
   set("coor/z",40);
   set("coor/x",-320);
 set("coor/y",130);
   set("coor/z",40);
   setup();
}
