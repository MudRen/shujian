// sanpo5.c
// ɽ��5
inherit ROOM;
void create()
{
	set("short","ɽ��");
	set("long",@long
ɽ·���˴��Ѿ����˾�ͷ����������ȥ�ˣ�ɽ�µ�������һ���յأ�
�м�������ɫ��װ���������䣬�ڿյر����м������ݣ������м�һ��
��������д�š������š������֡�
long);
	set("exits",([
	    "southup" : __DIR__"sanroad8",
          "enter" : __DIR__"qlm",
]));
	set("outdoors", "������");
        set("coor/x",510);
  set("coor/y",430);
   set("coor/z",40);
   setup();
}
	    	
