// sanroad8.c
// ɽ·8
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
	    "eastup" : __DIR__"sanpo6",
          "westdown" : __DIR__"sanroad5",
          "northdown" : __DIR__"sanpo5",
]));
	set("outdoors", "������");
        set("coor/x",510);
  set("coor/y",420);
   set("coor/z",50);
   setup();
}
	    	
