// Modify By River 98/12 
inherit ROOM;

void create()
{
        set("short","����");
	set("long", @LONG
������������֮�Ӷ��������ң����Ӳ��󣬴��ϱ��ӵ����������룬�ι� 
�Ӻþ�û�������ˣ�����������Щ�ҳ����Եþɾɵġ�
LONG
	);
	set("exits", ([ 
	    "east" : __DIR__"lang6",
	]));
	
        set("no_fight",1);
        set("sleep_room", 1);
	set("coor/x",-280);
  set("coor/y",-460);
   set("coor/z",-20);
   setup();
}
