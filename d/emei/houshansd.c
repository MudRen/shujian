// emei ����

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�������ͱ��ϵ�ɽ��������ں����ģ�һ��������ͷ�׷����������������
LONG
        );
        set("objects",([
		CLASS_D("emei") + "/guhongzi" : 1,
        ]));
        set("exits", ([
                "out" : __DIR__"houshandk",
                "eastdown": __DIR__"qingyinge",
        ]));

        setup();
}

