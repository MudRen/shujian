// Room: /d/tianshan/zoulang1.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������չ���һ�����ȣ�ֻ��ÿ�����������о����Ĳʻ����羰�����
ɽˮ������Ӧ�о��С�
LONG);
	 set("exits", ([
		"north" : __DIR__"dadian",
		"south" : __DIR__"qiandian",
        ]));       
	setup();
}
