// sanroad4.c
// ɽ·4
inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@long
����һ�����ܿ��ɽ·��·�������Ǹߴ����ľ��һ�ΰεĹ�ľ�ԣ�ǰ��
��Զ�ĵط�����һ��ƽ�£����ż������ݡ�
long);
	set("exits",([
	    "eastup" : __DIR__"sanpo2",
          "westdown" : __DIR__"sanroad3",
]));
	set("outdoors", "������");
        set("coor/x",500);
  set("coor/y",430);
   set("coor/z",40);
   setup();
}
	    	
