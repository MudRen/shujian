// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/southchl.c

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
                "down"  : __DIR__"southmen",
                "east"  : __DIR__"southjl2",
                "west"  : __DIR__"southjl1",
        ]));

        set("incity",1);
	setup();
}

