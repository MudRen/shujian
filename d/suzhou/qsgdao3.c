inherit ROOM;

void create()
{
        set("short", "������ٵ�");
        set("long",@long
������һ����ʯ����ϣ����������Ե÷ǳ���æ����ʱ������������Ҵ�
���������������һЩС��̯���ƺ���һ�����С�����ͨ�����ݳǡ�
long);
	set("outdoors", "����");
	set("exits",([
		"east" : __DIR__"westgate",
		"west" : __DIR__"qsgdao4",
	]));
	setup();
}
