// Room: /d/fuoshan/villa-gate.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "�︮����");
	set("long", @LONG
����һ����ǽ���ߵĴ�լ�ڣ���������һ���ߵĴ��ң�д�š��Ϻ���ڡ�
�ĸ����֣�һ������������ΰ��
LONG
	);
        set("outdoors","��ɽ");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"dayuan",
		"west" : __DIR__"nanjie",
	]));

	setup();
}
