// Room: yimogong.c

inherit ROOM;

void create()
{
	set("short", "��Ħ��");
	set("long", @LONG
����Ϊ�˲㶷�������磬��ͥ���ϱ�������ǰ�п���������̨��Χ
��͸��ש������������ıڻ��бڻ��������ϱڻ��о޷����칬ͼ����������
������ʮ���ˣ�����̬���죬����������
LONG
	);

	set("exits", ([
		"west" : __DIR__"huilang6",
	]));
        set("objects", ([
         __DIR__"npc/boluoxing" : 1,
	]));
	setup();
}
