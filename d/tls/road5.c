inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
������һ��������ʯ��·�ϣ����Թ������죬����������ǰ����
һƬ�����֣�����·һֱͨ������ţ�·���������룬ż��������ɮ
�˴������д�������
LONG);
	set("exits", ([
           "north" : __DIR__"bzqs",
           "south" : __DIR__"shiyuan",   
        ]));
	set("outdoors", "������");
	set("coor/x",-390);
  set("coor/y",-300);
   set("coor/z",30);
   setup();
}
