// Room: /city/shuyuan.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
������ǹ�������������, ����̸�ĵ�������Ժ����һ̧ͷ���ͼ�������
����һ����Լ��ߣ���Լ����Ĵ󻭣������һ��Ƭɽˮ�������ݺᣬ������
ΰ���㲻���������ɡ�����ֻ�����ĸ����֣�����˽�ɽ�������ߵ���ǰ��ϸ
�ۿ���ֻ���󽭺ƺƶ���������������������׺��������ʯ��ֻ�ǻ���������
����ɽ��������ȴ����һ��֮�£����ܼ��������֮�����������������һ
������(zitie)��
LONG
	);

	set("exits", ([
        "up" : __DIR__"wizroom",
		"south" : __DIR__"dongdajie2",
	]));

	set("item_desc", ([
		"zitie" : "�����ϸ�Ѵ��ң����ºγ������ˡ�\nɽ�������ʱ��꣬�δ����ٲ���ϲ? \n\n"
	]));
	
	set("objects", ([
		__DIR__"npc/gu": 1,
		__DIR__"npc/boy": 1,
	]));

	set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
	me->delete_temp("mark/literate");
	return 1;
}
