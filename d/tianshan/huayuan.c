// Room: /d/tianshan/huayuan.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
���������չ���԰�ƽ�����չ�Ů���Ӿ�����������Ϸ����������Կ�
������ͤ���ͤ���ƺ�������һ��Ů���ӣ���Լ������������̾Ϣ��
LONG);
	set("exits", ([
                "east" : __DIR__"dsqiao",
        ]));       
        set("objects", ([
             //   __DIR__"obj/****" : 1,
        ]));    

	set("outdoors", "��ɽ");
	setup();
}
