// Room: /d/emei/heilongdao.c ������ ����ջ��

inherit ROOM;

void create()
{
	set("short", "����ջ��");
	set("long", @LONG
�������ٲ��Ϸ�һ��խխ��ɽ������Ȼ��ɡ�ʯ�������˹�
���һ�����ݡ����϶��˼���ľ׮�����ϴֳ���������Ϊ���֡�
�ٲ��ڽ��±��ڶ������ڲ�Զ��ɽ���»��һ����̶��
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"qingyinge",
		"southup" : __DIR__"qianfoan",
	]));

	set("outdoors", "shaolin");
	setup();
}



