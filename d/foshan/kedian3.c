// Room: /d/fuoshan/kedian3.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "�͵��¥");
	set("long", @LONG
����һ��ɾ����᷿������ʮ�ּ�ª��һ��ľ�崲����ǽ�߷��š�
LONG
	);
        set("outdoors","��ɽ");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"kedian2",
]));
	set("hotel", 1);
	set("no_fight", 1);
	set("sleep_room", 1);

	setup();
}
