// Room: /d/tianshan/zoulang3.c
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
		"north" : __DIR__"bctang",
		"south" : __DIR__"lgfang",
		"west" : __DIR__"zoulang2",
        ]));       
        set("objects", ([
                __DIR__"npc/jujian" : 1,
        ]));    
	setup();
}
