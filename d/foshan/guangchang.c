// Room: /d/fuoshan/guangchang.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��ɽ�㳡");
	set("long", @LONG
������Ƿ�ɽ������ģ�һ���ܿ����Ĺ㳡��������ʯ���档��ɽ��
�������ɣ����£����ڲ��������Ĵ��򣬶˵�������︷�����ܷ�������
���������������ﲻ�������洫�����������������������л�ȭ�Ľк���
�������ԵñȽϰ����������������У�һ�ɷ�������
LONG
	);
        set("outdoors","��ɽ");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"dongjie",
  "south" : __DIR__"herohotel",
  "north" : __DIR__"beijie",
  "west" : __DIR__"xijie",
]));
	set("no_clean_up", 0);

	set("coor/x",0);
  set("coor/y",-530);
   set("coor/z",0);
   setup();
}
