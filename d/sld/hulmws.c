// hulmws.c
// ����������
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@long
�˴��ǻ����ŵ����ң����еĲ��úܼ򵥣�ֻ�м�ֻ�󴲿�ǽ���ţ�
�����Ž�����Ϣ֮�á�
long);
	set("exits",([
	    "west" : __DIR__"hulm",
]));
      set("sleep_room", 1);
      set("no_fight",1);
//create_door("west", "С��", "east", DOOR_CLOSED);
      set("coor/x",510);
  set("coor/y",440);
   set("coor/z",70);
   setup();
}
	    	
