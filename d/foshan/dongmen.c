// Room: /d/fuoshan/dongmen.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��ɽ����");
	set("long", @LONG
�����Ƿ�ɽ��Ķ��š��������߾�Ҫ�뿪��ɽ��ȥ�������ˡ�
����һ��������Ĵ���Ƿ�ɽ�����Ҫ�ֵ���
LONG
	);
        set("outdoors","��ɽ");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dongjie3",
    "east" : __DIR__"road8",
]));
	set("no_clean_up", 0);

	set("coor/x",40);
  set("coor/y",-530);
   set("coor/z",0);
   setup();
}
