// qlmws.c
// ����������
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@long
�˴��������ŵ����ң����еĲ��úܼ򵥣�ֻ�м�ֻ�󴲿�ǽ���ţ�
�����Ž�����Ϣ֮�á�
long);
	set("exits",([
	    "west" : __DIR__"qlm",
]));
      set("sleep_room", 1);
      set("no_fight",1);
//create_door("west", "С��", "east", DOOR_CLOSED);
      set("coor/x",520);
  set("coor/y",430);
   set("coor/z",50);
   setup();
}
	    	
