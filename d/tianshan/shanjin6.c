// Room: /d/tianshan/shanjin6.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ��ʯŪ��Ҳ�Ƶ�խ����Խ��Խ�ߣ��������֣���Լ�ɼ���������
���ʵ�ʯ�ڣ�����ֻ��һ�ߣ��㲻�ɵļӿ��˲�����
LONG);
	 set("exits", ([
                "northup" : __DIR__"pmfeng",
		"southdown" : __DIR__"shanjin5",
        ]));        
	set("outdoors", "��ɽ");
	setup();
}
