// /d/wudang/sanqingdan.c  �����
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIY"�����"NOR);
        set("long", @LONG
���������������������䵱�ɻ�͵ĵص㡣���ŵ�������Ԫʼ����
���鱦������������м��Ǹ�����Ĵ��㰸����ǽ���ż���̫ʦ�Σ����Ϸ�
�ż������š�����������ĵط����ϱ����䵱���ء�
LONG                           
        );
set("no_fight", 1);
        set("exits", ([
                "south" : __DIR__"xiaolu1",
                "out" :__DIR__"zhenqing",
                "north" :__DIR__"zoulang1",
        ]));

        set("objects",([
                CLASS_D("wudang") + "/song" : 1,
        ]));

	set("valid_startroom", 1);
 
        setup();
        "/clone/board/wudang_b"->foo();
}
