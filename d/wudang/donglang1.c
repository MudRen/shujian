// Room: donglang2.c  ��������
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
������һ��ľ�ƽṹ�������ϣ�������һ����ݣ��ſڹ���һ��ǣ�����
(pai)�ǰ׵ġ���������һ��¥��
LONG
    );
        set("exits", ([
            "east" : __DIR__"xiaolu1",
            "south":__DIR__"xiuxishi2",
            "west" : __DIR__"jingge",
        ]));
                                                    
        set("item_desc",([
           "pai" : HIW"\t\t\t��\n"NOR,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        if ((me->query("gender") =="����") && dir =="south" )
           return notify_fail("��ѧ������ȥ͵�����˵Ĺ뷿ô����\n");
        return ::valid_leave(me, dir);
}
