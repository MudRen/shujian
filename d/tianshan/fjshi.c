// Room: /d/tianshan/fjshi.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������չ�������ȡ�����ͷ���֮�أ��㼯�����¸��ɹ��õĸ�����С� 
LONG);
	 set("exits", ([
		"south" : __DIR__"zoulang2",
        ]));        

	set("outdoors", "��ɽ");
	setup();
}
