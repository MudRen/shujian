// Room: /d/putian/houdian.c ���
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"���"NOR);
        set("long", @LONG
���������еĺ����õ�������ʱ��ǰһƬ������ֻ���������������
���򣬺�ֹ����ʮ֦����ǽ����һЩ��¯�͹�������Ϊû�п����ӣ�������Щ
�Ե��������ơ�
LONG
        );

        set("exits", ([
                "north" : __DIR__"zhongdian",
                "south" : __DIR__"xm-dian",
                "east" : __DIR__"fatang3",
                "west" : __DIR__"fatang2",

        ]));

        set("objects",([
                CLASS_D("putian") + "/yuanshang" : 1,
        ]));

        setup();
}
