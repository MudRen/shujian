// /u/beyond/hz/ruangongdun.c ���
#include <ansi.h>
 
inherit ROOM;
void create()
{
        set("short",HIY"���"NOR);
        set("long", @LONG
����ں���ͤ�����棬����Ľ������ڲ�ͬ�������������������Ƴɡ�
��¥��ͤ��ӳ�ڴ��̴��У����������š�����֮�С���ŮƵƵ���裬��Ů��
�����ŵĹ��٣���Ů�������衣
LONG
        );
        set("exits", ([
            "east" : __DIR__"huxinting",
]));
        setup();
}
