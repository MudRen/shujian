// sanroad3.c
// ɽ·3
inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@long
����һ�����ܿ��ɽ·��·�������Ǹߴ����ľ��һ�ΰεĹ�ľ�ԣ�
ǰ�治Զ�ĵط�����һ��ƽ�£����ż������ݡ�
long);
	set("exits",([
	    "eastup" : __DIR__"sanroad4",
          "southdown" : __DIR__"sanroad2",
]));
	set("outdoors", "������");
        set("coor/x",490);
  set("coor/y",430);
   set("coor/z",30);
   setup();
}
	    	
