// /d/xingxiu/silk6.c

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�������������˿���̵�����ɳ������һƬ���������������������
ɽ��������������º�����һ�������ֻ���м��˺ϱ�֮�ֵĹ��Ϻ����
Ȼͦ���ڻ�ԭ�ϣ�Цӭ��ɳ��ƵƵ�к����ˡ�������һƬ��ɳ������ɳĮ��
���Ե�������ɽ����
LONG);
        set("outdoors", "����");

        set("exits", ([
		"southeast" : __DIR__"silk5",
		"northwest" : __DIR__"silk7",
		"southwest" : "/d/group/entry/mjshamo1",
        ]));

        set("objects", ([
		__DIR__"npc/shangren" : 1,
        ]));
	setup();
}

#include "/d/xingxiu/job2.h";
