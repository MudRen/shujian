// Room: /d/huashan/kongdi.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "�յ�");
	set("long",@long
�ưʹ������ʵ���һ�죬������һ���߷�ľ�����ֻ���嶥��һ��ܴ��
ƽ�أ����ܹ����������������֣���ǰ����������ʯ�ݡ�
long);
	set("exits",([
	"north" : __DIR__"shulin1",
	"southdown" : __DIR__"v-road-1",
	]));
	set("outdoors", "��ɽ");
	set("coor/x",40);
  set("coor/y",90);
   set("coor/z",0);
   setup();
}
