// Room: ��� 2
// bbb 1997/06/11
// Modify By River 98/12 
inherit ROOM;

void create()
{
        set("short", "���");
	set("long", @LONG
һ����ֱ��ʯ����ͨ��ǰ����·�ϲ�ʱ�������������ĳ�����������
�����ֳָ��ֱ�������������ϰ��֮�ˣ�����μ����Ի�ү���������ӣ�����
�����������ִ�ͳ�����ϰ��֮�����ʢ�С�
LONG
	);
        set("outdoors", "����");
	set("exits", ([ /* sizeof() == 1 */
	    "north" : __DIR__"dadao1",
	    "south" : __DIR__"dadao3",
        ]));
	set("no_clean_up", 0);

	set("coor/x",-310);
  set("coor/y",-340);
   set("coor/z",-20);
   set("coor/x",-310);
  set("coor/y",-340);
   set("coor/z",-20);
   setup();
}
