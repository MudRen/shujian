// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/westchl.c

inherit ROOM;

void create()
{
        set("short", "���ų�¥");
        set("long", @LONG
�����ϵĳ�¥���������Σ�����������ļ�¥��ͬ����������š�������
�ǳ��ǽ��Ǵ�����Ϣ����Ⱥ�����еķ������಻�ϣ������ﻹ������ϡ�Ŀ���
�����ĵ���¥����¥���������ĸ��ڣ����ܼ����ų���Χһ�ж�̬��
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "down"  : __DIR__"westmen",
                "south" : __DIR__"westjl2",
                "north" : __DIR__"westjl1",
        ]));

        set("incity",1);
	setup();
}

