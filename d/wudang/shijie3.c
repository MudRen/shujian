// /d/wudang/shijie3.c 
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",CYN"ʯ��"NOR);
        set("long", @LONG
������һ�����ӵ�ʯ���ϣ���ʱ���е�ʿ������������Զ����ײ������
�����š�̧ͷ��Լ�ɼ������������е������壬��֪���쵽ɽ���ˣ�һ�˷ܶ�
ʱ���˻����ƣ�롣
LONG
        );
        set("exits", ([
             "southup" : __DIR__"zxgdamen",
             "northdown" : __DIR__"zhanqi",
        ]));
        set("outdoors","�䵱");

        setup();
}
