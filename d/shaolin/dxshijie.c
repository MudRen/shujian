//dxshijie.c
inherit ROOM;

void create()
{
	set("short", "̨��");
	set("long", @LONG
���۱���ǰ��ʯ�ף�����ƽ�е���ʯ��չ��ǰ����������һ��ʯ��·��
����Ʈ���������̡�����Ǵ��ڴ���ϢĬ����Ȼ��һ��һ�ݵ����۱���ȥ��
LONG
	);
       
	set("exits", ([
		      "northup" : __DIR__ "pingtai",
                      "south" : __DIR__ "stoneroad2",
//                      "north" : __DIR__ "stoneroad1",    
                                           ]));
        set("outdoors", "shaolin");
	set("coor/x",50);
  set("coor/y",280);
   set("coor/z",110);
   setup();
}
