// Room: /d/chengdu/zijuefumen.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�Ӿ�����");
	set("long", @LONG
������һ����լۡ����ǰ������һ����ִ���д�š���Ϯ�Ӿ�����������
�������䣬�������Ҳ�ܾ�Զ�ˡ����ų����ţ��ſ��м����Ҷ������������
�ţ���֪�����ĸ����ҹ���ĸ��ڣ����ǿ������˱ȽϺÿ͡�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"north" : __DIR__"ddajie2",
                "south" : __DIR__"zjhall",
	]));

	set("incity",1);
	setup();
}
