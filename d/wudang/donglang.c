// Room: donglang2.c  ��������
// by shang 97/6

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "��������");
    set("long", @LONG
������һ��ľ�ƽṹ�������ϣ��ϱ���������ݣ��ſڶ�����һ��ǣ�
�ϱߵ�����(menpai1)�����ģ����ߵ�(menpai2)�ǰ׵ġ�
LONG
    );
        set("exits", ([
            "south":__DIR__"xiuxishimen",
            "west" : __DIR__"xiaolu1",
    ]));
        setup();
}
