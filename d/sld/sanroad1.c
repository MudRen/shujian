// sanroad1.c
// ɽ·1
inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@long
����һ���������۵�ɽ·��·��һ����һ��Ϫˮ���ȵ�ɽϪ����һ��
��һ�ÿ���εĴ�����������һЩ���µ�С�ݣ�ʱ�����Կ������������
���Ϸɹ���
long);
	set("exits",([
	    "up" : __DIR__"sanroad2",
          "southdown" : __DIR__"kongdi",
]));
	set("outdoors", "������");
        set("coor/x",490);
  set("coor/y",420);
   set("coor/z",10);
   setup();
}
	    	
