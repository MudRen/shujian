// sanroad2.c
// ɽ·2
inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@long
����һ���������۵�ɽ·��·��һ����һ��Ϫˮ���ȵ�ɽϪ����һ����һ
�ÿ���εĴ�����������һЩ���µ�С�ݣ�ʱ�����Կ�������������ҷɹ���
long);
	set("exits",([
	    "up" : __DIR__"sanpo1",
          "down" : __DIR__"sanroad1",
          "northup" : __DIR__"sanroad3",
]));
	set("outdoors", "������");
        set("coor/x",490);
  set("coor/y",420);
   set("coor/z",20);
   setup();
}
	    	
