// sanroadb.c
// ɽ·11
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
	    "up" : __DIR__"sfd",
          "down" : __DIR__"sanroada",
]));
	set("outdoors", "������");
        set("coor/x",520);
  set("coor/y",430);
   set("coor/z",70);
   setup();
}
	    	
