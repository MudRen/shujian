// Room: /d/tianshan/fqzong.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "����ڣ");
	set("long", @LONG
���������չ��ķ���ڣ����ɽͯ����ɱ����������������Ⱥ�ۣ���������
�ı�������ڷ���ڣ�ڡ�
LONG);
	 set("exits", ([
		"south" : __DIR__"zoulang5",
        ]));       
        set("objects", ([
             //   __DIR__"obj/****" : 1,
        ]));    

	set("outdoors", "��ɽ");
	setup();
}
