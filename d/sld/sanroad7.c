// sanroad7.c
// ɽ·7
inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@long
����һ�����ܿ��ɽ·��·�������Ǽ�ϥ���Ӳݺ�һ�ΰεĹ�ľ�ԣ�
ǰ�治Զ�ĵʹ���һ��ƽ�£����ż������ݡ�
long);
	set("exits",([
	    "southup" : __DIR__"sanroad6",
          "northdown" : __DIR__"sanpo3",
]));
	set("outdoors", "������");
        set("coor/x",490);
  set("coor/y",440);
   set("coor/z",20);
   setup();
}
	    	
