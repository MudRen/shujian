// sanpo3.c
// ɽ��3
inherit ROOM;
void create()
{
	set("short","ɽ��");
	set("long",@long
ɽ·���˴��Ѿ����˾�ͷ�������������죬ɽ�µ�������һ���յأ�
�м�������ɫ��װ���������䣬�ڿյر����м������ݣ������м�һ��
��������д�š������š������֡�
long);
	set("exits",([
	    "southup" : __DIR__"sanroad7",
          "enter" : __DIR__"clm",
]));
	set("outdoors", "������");
        set("coor/x",490);
  set("coor/y",450);
   set("coor/z",10);
   setup();
}
	    	
