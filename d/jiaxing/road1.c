inherit ROOM;

void create()
{
        set("short", "��ʯ�ٵ�");
        set("long",@long
������һ����ʯ����ϣ����������ǳ���æ����ʱ����������ҴҶ�����
����ͨ�����ݳǡ��������Ǽ��˳ǡ�
long);
	set("outdoors", "����");

	set("exits",([
		"northwest" : __DIR__"road2",
		"southeast" : __DIR__"beimen",
	]));
	setup();
}
