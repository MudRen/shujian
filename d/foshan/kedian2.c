// Room: /d/fuoshan/kedian2.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��ջ��¥");
	set("long", @LONG
�����ǿ�ջ��¥�����ȣ��󲿷ֿͷ����Ŷ����ţ���ʱ��������Ĵ�
����������˷������ﲻ����
LONG
	);
        set("outdoors","��ɽ");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"kedian3",
  "down" : __DIR__"kedian",
]));

	set("coor/x",-10);
  set("coor/y",-550);
   set("coor/z",10);
   setup();
}
