// sanroad6.c
// ɽ·6
inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@long
����һ�����ܿ��ɽ·��·�������Ǽ�ϥ���Ӳݺ�һ�ΰεĹ�ľ�ԣ�
ǰ�治Զ�ĵʹ���һ��ƽ�£����ż������ݡ�
long);
	set("exits",([
	    "south" : __DIR__"sanpo1",
          "northdown" : __DIR__"sanroad7",
]));
	set("outdoors", "������");
        set("coor/x",490);
  set("coor/y",430);
   set("coor/z",30);
   setup();
}
	    	
