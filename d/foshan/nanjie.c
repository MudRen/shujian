// Room: /d/fuoshan/nanjie.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��ɽ�Ͻ�");
	set("long", @LONG
��ɽ�Ͻ��ԵıȽϰ����������Ǵ󲿷ֶ���סլ��������һ�ҿ�ջ��
���������Ŀ��̶�ס�����������һ�Һ�լ�����������ɷǷ��������
��Ӣ��¥�������������������˴������Ρ�������һ����������ʯ��·��
LONG
	);
        set("outdoors","��ɽ");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"villa-gate",
  "west" : __DIR__"kedian",
  "north" : __DIR__"herohotel",
  "south" : __DIR__"nanjie2",
]));

	set("coor/x",0);
  set("coor/y",-550);
   set("coor/z",0);
   setup();
}
