// zl2.c
// ����2
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@long
���ﵽ�����Ǹ߿ɼ�������ӣ���̫������ס�ˣ���λ�ӷ嶥����ʱ
���Դ������磬���������ļ�����һ�������ĺõط���
long);
	set("exits",([
	    "east" : __DIR__"zl1",
           "west"  : __DIR__"pt",
]));
	set("outdoors", "������");
        set("coor/x",480);
  set("coor/y",430);
   set("coor/z",80);
   setup();
}
	    	
