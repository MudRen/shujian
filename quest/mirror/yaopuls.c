//make by yixiang
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "ҩ������");
        set("long", @LONG
����ҩ�̵����ң�����ҩ���ϰ������ҩ���������Ӿ��飬Ǳ��ѽ��
LONG
        );
        set("exits", ([
                "south" : __DIR__"yaopu",
                
]));
        setup();
}

//�Ǿ���
int is_mirror() { return 1; }