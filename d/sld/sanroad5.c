// sanroad5.c
// ɽ·5
inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@long
����һ���������۵�ɽ·��·��һ����һ��Ϫˮ���ȵ�ɽϪ����һ��
���������ïʢ����ľ��������һЩ���µ�С�ݣ�ʱ�����Կ����������
�����Ϸɹ���
long);
	set("exits",([
	    "eastup" : __DIR__"sanroad8",
          "westdown" : __DIR__"sanpo1",
          "northup" : __DIR__"sanroad9",
]));
	set("outdoors", "������");
        set("coor/x",500);
  set("coor/y",420);
   set("coor/z",40);
   setup();
}
	    	
