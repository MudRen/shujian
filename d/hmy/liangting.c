// Room: /u/leon/hmy/liangting.c

inherit ROOM;

void create()
{
	set("short", "��ͤ");
	set("long", @LONG
���е�������ֻ��һ��СС��ͤ�����ǿ�Ұ�й�������Ϣ֮�ã�Ҳ�����
ʧ�ޣ�������Ϊ��ª��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shidao2",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiang" : 1,
]));

	setup();
}
