// Room: /d/emei/fuhushi.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������ɽ��һ��ɲ�������ڸߴ����ľ�ּ䣬�����ľ���죬���
ʮ�����ꡣ����������ׯ�ϣ���ģ��ʢ�����ÿ����ƶ�Ρ�롣��ɲ���ڸ���
����Ũ��֮�У�������ȴ��һƬ��Ҷ���������Ͻ����±��ǹ����á�
    ҹĻ�ʹ������췱�ǡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"milin2",
  "east" : __DIR__"milin",
]));

	setup();
}
