// xuanya2.c ջ��
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
        "northeast" : __DIR__"xuanya3",
        "southwest" : __DIR__"xuanya1",
    ]));
    set("outer_times", 6);
    set("coor/x",-330);
  set("coor/y",120);
   set("coor/z",40);
   set("coor/x",-330);
 set("coor/y",120);
   set("coor/z",40);
   setup();
    set("outdoors", "���̹�����");
}

#include "npc/attacker.h";
