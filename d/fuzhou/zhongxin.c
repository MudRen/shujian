// Room: /d/fuzhou/zhongxin.c
// Lklv 2001.9.6

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǹ��ݳǵĳ����ģ������������������֡���Ϊ�Ƕ��ϵ�������һ
�����۳��У���������������������ɫɫ����������������Ҳ�кܶ����ŵ���
������������򡢴��ң�������·�����ƶ������У�������һ��������������
�ӡ�����ķ�����һ��ʯ��ֵ����������������������������������ˡ���
�Ϸ�����Լ��һ��С�
LONG
        );

        set("exits", ([
                "north" : __DIR__"beijie",
                "south" : __DIR__"nanjie",
                "east" : __DIR__"dongjie",
                "west" : __DIR__"xijie",
        ]));
        set("objects", ([
                __DIR__"npc/huo" : 1,
        ]));

        set("outdoors", "����");
	setup();
}
