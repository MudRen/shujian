// Room: alleyway.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "С��");
	set("long",@LONG
����һ����ڵ�С��ӿ����ݵ�·�������������о��ܲ������
LONG
	);
        set("outdoors","��ɽ");
        set("exits", ([ 
            "west" : __DIR__"nanjie2",
            "south" : __DIR__"zhongjia",
]));
	set("no_clean_up", 0);

	set("coor/x",10);
  set("coor/y",-560);
   set("coor/z",0);
   setup();
}
