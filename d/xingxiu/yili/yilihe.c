// Room: /d/xingxiu/yili.c
// Modify by Lklv 2001.10.16

inherit ROOM;
void quarter_pass();

void create()
{
	set("short", "�����");
        set("long", @LONG
�����λ����������ϣ�����ɽ���ܻ����µ�ѩˮ�㼯���ɡ�����������
���ö�������ǣ���ӱ���ˮ��Ϊ��һ�ε���;����׼������ˮ����͸�����
��ϥ��
LONG);
        set("outdoors", "����");
	set("exits", ([
		"south" : __DIR__"yili",
		"north" : __DIR__"yili1",
	]));
        set("objects", ([
		__DIR__"../npc/yang" : 1,
		__DIR__"../npc/hgirl" : 1,
        ]));
	setup();
}

#include "/d/xingxiu/job2.h";
