// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/biaoju2.c

inherit ROOM;

void create()
{
	set("short", "�ھִ���");
	set("long", @LONG
�����ǻ����ھֵĴ��������еĳ��裬ȫ��ʮ�־��µ���̴ľ�Ҿߣ�����
���Ⱦ޴�İ�ߡ���磬�������˸�ɫ�������ɼ��������İ���ͼ�����Ǻ���
�Ĺ��������������˲��������ˬ���㽻���ѣ��ҷǴ��ֲ�ʶ��Ŀ������
֮��������һ��Ƥ���Σ���������һ����ò���͵ĺ��ӡ�
LONG
	);
	set("exits", ([
		"north" : __DIR__"biaoju",
	]));

	set("objects", ([
		"/d/zhiye/npc/biaotou2" : 1,
	]));

	set("incity",1);
	setup();
}