// Room: /d/huashan/song.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@long
����һֻ����֦����һ�������������������������øߴ�Ծ��������
Զ��������ʯ���г��������������±ڡ�
long);

	set("exits",([
	"enter" : __DIR__"hole2",
	"down" : __DIR__"v-road-5",
	]));

	setup();
}