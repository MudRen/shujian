// xfj.c
// �ɸ���
inherit ROOM;
void create()
{
	set("short","�ɸ���");
	set("long",@long
�����ǽ�������Ͼʱ��Ϣ����֮������ʱҲ�������޿��ˡ�
long);
	set("no_fight", 1);
	set("exits",([
          "out" : __DIR__"pt",
]));
	set("coor/x",490);
  set("coor/y",430);
   set("coor/z",100);
   setup();
}
	    	
