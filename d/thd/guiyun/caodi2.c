// /u/jpei/guiyun/caodi2.c

inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long",@LONG
һƬ���Ĳݵء��̲�����ï�ܵ������ţ��ݴԼ���һЩ��֪����С��
��������ȥ��Զ����һƬ���֡�
LONG
);
	set("exits",([
		"east" : __DIR__"caodi1",
		"north" : __DIR__"shulin2",
	]) );
	set("no_clean_up",0);
	set("outdoors", "����ׯ");
	setup();
}

