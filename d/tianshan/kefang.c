// Room: /d/tianshan/kefang.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
���������չ��Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����Сľ�������ٿ���
�����¶��ԡ�
LONG);
	set("exits", ([
		"south" : __DIR__"zoulang4",
        ]));
	set("sleep_room", 1);
	set("no_fight",1);
	setup();
}
