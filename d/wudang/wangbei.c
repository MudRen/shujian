// /d/wudang/wangbeipo.c ������
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"������"NOR);
        set("long", @LONG
ɽ�Ƶ���ͻȻ���ͣ����߶���������Ԩ����ɽ���˶���ץ�������ߵĴ���
����һ��һ�٣���ֻ�ܿ���ǰ���˵ı������ô����������ͷ��̽����Լ��
����ˮ�������������С�
LONG
        );
        set("outdoors","�䵱");

        set("exits", ([
                "southdown" : __DIR__"caihong",
                "northdown" :__DIR__"mozhen",
        ]));

        setup();
}
