// /u/beyond/hangzhou/hongyuchi.c �����
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIR"�����"NOR);
        set("long", @LONG
�������԰�ڵ�����֮�أ��������м�ǧ�������㣬��������߳���ƾ
��Ͷ�Ⱥ�������ʳ�����᷵������΢�������Լ�ɽ���ӣ����ƾ��ף�ɽ
ˮ�ޱ����㡣
LONG
        );
        set("exits", ([
        "west" : __DIR__"hggyu",
]));
        setup();
}
