// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/eastchl.c

inherit ROOM;

void create()
{
        set("short", "���ų�¥");
        set("long", @LONG
�����ϵĳ�¥���������Σ�����������ļ�¥��ͬ��ɶ������š�������
�ǳ��ǽ��Ǵ�����Ϣ����Ⱥ�����еķ������಻�ϣ������ﻹ������ϡ�Ŀ���
�����ĵ���¥����¥���������ĸ��ڣ����ܼ����ų���Χһ�ж�̬��
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "down"  : __DIR__"eastmen",
                "south" : __DIR__"eastjl2",
                "north" : __DIR__"eastjl1",
        ]));

        set("incity",1);
	setup();
}

