// sanroad9.c
// ɽ·9
inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@long
����һ�����ܿ��ɽ·��·�������Ǽ�ϥ���Ӳݺ�һ�ΰεĹ�ľ�ԣ�
ǰ�治Զ�ĸߴ���һ��ƽ�£����ż������ݡ�
long);
	set("exits",([
	    "northup" : __DIR__"sanpo4",
           "eastup"  :  __DIR__"sanpo7",
          "southdown" : __DIR__"sanroad5",
]));
	set("outdoors", "������");
        set("coor/x",500);
  set("coor/y",430);
   set("coor/z",50);
   setup();
}
	    	
