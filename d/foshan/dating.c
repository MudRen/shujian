// Room: dating.c 
 
inherit ROOM; 
 
void create() 
{
	set("short", "�︮����");
	set("long", @LONG
������Ƿ︮�Ĵ��������ɷǷ���װ���ݻ�������һ��̫ʦ�Σ�����һ��
���º��ƵĻ�Ƥ�������Ͽ������ڣ��������ֺ�ʦү�����ֹ��š���Ƥ���Ա�
����������ʯ���磬�������ĳ߸ߣ�ʯ��ɽˮľʯ�������ǻ�������һ�㡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"dayuan",
		"south" : __DIR__"shufang",
	]));

        set("objects", ([
		__DIR__"npc/dashou" : 2,
		__DIR__"npc/he" : 1,
	]));
	setup();
}
