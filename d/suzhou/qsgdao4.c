inherit ROOM;

void create()
{
	set("short", "���Źٵ�");
	set("long",@long
������һ����ʯ����ϣ����������Ե÷ǳ���æ����ʱ������������Ҵ�
���������������һЩС��̯���ƺ���һ�����С�����ͨ�����ݳ����š�
long);
	set("outdoors", "����");
	set("exits",([
		"east" : __DIR__"qsgdao3",
		"west" : __DIR__"qsgdao5",
	]));
	set("objects", ([
		NPC_D("poorman") : 1,
	]));
	setup();
}
