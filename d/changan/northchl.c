// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/northchl.c

inherit ROOM;

void create()
{
        set("short", "���ų�¥");
        set("long", @LONG
�����ϵĳ�¥���������Σ�����������ļ�¥��ͬ��ɱ���Զ�š�������
�ǳ��ǽ��Ǵ�����Ϣ����Ⱥ�����еķ������಻�ϣ������ﻹ������ϡ�Ŀ���
�����ĵ���¥����¥���������ĸ��ڣ����ܼ����ų���Χһ�ж�̬��
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "down"  : __DIR__"northmen",
                "east"  : __DIR__"northjl2",
                "west"  : __DIR__"northjl1",
        ]));

        set("incity",1);
	setup();
}


