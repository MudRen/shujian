// sanpo4.c
// ɽ��4
inherit ROOM;
void create()
{
	set("short","ɽ��");
	set("long",@long
ɽ·���˴��Ѿ����˾�ͷ������������չ��ɽ�µ�������һ���յأ�
�м�������ɫ��װ���������䣬�ڿյر����м������ݣ������м�һ��
��������д�š������š������֡�
long);
	set("exits",([
	    "southdown" : __DIR__"sanroad9",
          "enter" : __DIR__"hulm",
]));
	set("outdoors", "������");
        set("coor/x",500);
  set("coor/y",440);
   set("coor/z",60);
   setup();
}
	    	
