// Room: /d/tianshan/ljgong.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "���չ�");
	set("long", @LONG
ʯ��������һ���޴��ʯ��ΡȻ�������������Ҹ���һͷʯ������գ���
���������࣬��๾�צ���񿥷Ƿ��������Ϸ�����һ�ң������չ�����������
������������ϸ�����·�����ż�ǿ�Ľ��⡣�����������������������ﾡ��
������翣�������������������ң�����㲻�ɵ�һ����ã��
LONG);
	 set("exits", ([
                "out" : __DIR__"jtbu",
		"north" : __DIR__"qiandian",
        ]));       
        set("objects", ([
             //   __DIR__"obj/****" : 1,
        ]));    

	set("outdoors", "��ɽ");
	setup();
}
