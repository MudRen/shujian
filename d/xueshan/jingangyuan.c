// Room: jingangyuan.c

inherit ROOM;

void create()
{
	set("short", "���Ժ");
	set("long", @LONG
Ժ������ʮ�ɣ����������������ߡ�ľ�����ε������������������������
���ڹ���һ��ʯ�̽��( jingang)��ǰ���ĸ�������ʯ����ʯ��ǰ��ʯʨ��ʯ��
��һ�ԡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"fanyinge",
		"south" : __DIR__"kuxiuzhacang",
	]));

	set("item_desc", ([
	  "jingang" : "���ʯ��ո�Լ���ɣ������μ��У����ַ�ﵣ�ŭĿ���ӣ����׸�������������������׳����̾��¡�\n",
	]));
	setup();
}
