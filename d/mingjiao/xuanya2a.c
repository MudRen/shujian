// xuanya2a.c ջ��
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
        "northwest" : __DIR__"xuanya3",
        "southeast" : __DIR__"xuanya1",
    ]));
    set("outer_times", 6);
    setup();
    set("outdoors", "���̹�����");
}

#include "npc/attacker.h";
