// clmws.c
// ����������
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@long
�˴��ǳ����ŵ����ң����еĲ��úܼ򵥣�ֻ�м�ֻ�󴲿�ǽ���ţ�
�����Ž�����Ϣ֮�á�
long);
	set("exits",([
	    "west" : __DIR__"clm",
]));
      set("sleep_room", 1);
      set("no_fight",1);
//create_door("west", "С��", "east", DOOR_CLOSED);
      set("coor/x",500);
  set("coor/y",450);
   set("coor/z",20);
   setup();
}
	    	
