// Room: /city/wumiao.c
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "����");
    set("long", @LONG
�����������������������������Ϸ������������顰���Һ�ɽ����
���ҡ����������Ƕ�š����ұ������ĸ����֡����˵��ˣ��������������Ϲ�
�Ͼ���������ݡ��Ա��ƺ���һ�����š�

                           [1;31m������[2;37;0m

LONG
    );

    set("exits", ([
        "east" : __DIR__"beidajie2",
    ]));
        setup();
}
//�Ǿ���
int is_mirror() { return 1; }