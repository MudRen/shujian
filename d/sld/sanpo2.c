// sanpo2.c
// ɽ��2
inherit ROOM;
void create()
{
	set("short","ɽ��");
	set("long",@long
ɽ·���˴��Ѿ�����������ȥ�ˣ�ɽ�µ�������һ���յأ��м���
����ɫ��װ���������䣬�ڿյر����м������ݣ������м�һ�������
��д�š������š������֡�
long);
	set("exits",([
	    "westdown" : __DIR__"sanroad4",
          "enter" : __DIR__"hlm",
]));
	set("outdoors", "������");
        set("coor/x",510);
  set("coor/y",430);
   set("coor/z",50);
   setup();
}
	    	
